/*****************************************************************************
 * FILE NAME    : MainTagWindow.cpp
 * DATE         : August 12 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainTagWindow.h"
#include "JSONTagTreeItem.h"
#include "common.h"

/*****************************************************************************!
 * Function : MainTagWindow
 *****************************************************************************/
MainTagWindow::MainTagWindow
(TranslationUnitObject* InTranslationUnit) : QWidget()
{
  TranslationUnit = InTranslationUnit;
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(128, 0, 0)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
  SetColumnWidths(MainSystemConfig->GetColumnWidths(1));
}

/*****************************************************************************!
 * Function : ~MainTagWindow
 *****************************************************************************/
MainTagWindow::~MainTagWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainTagWindow::initialize()
{
  BuildTagList(TranslationUnit->GetJSONObject(), "TranslationUnitDecl");
  InitializeSubWindows();  
  CreateSubWindows();
  PopulateTree();
  header->SetText("JSON ELEMENTS");
  SlotElementCountChanged(tagTree->topLevelItemCount());
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainTagWindow::CreateSubWindows()
{
  tagTree = new JSONTagTree();  
  tagTree->setParent(this);
  header = new MainTagWindowSectionHeader();
  header->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainTagWindow::InitializeSubWindows()
{
  tagTree = NULL;  
  header = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainTagWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   tagTreeH;
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  tagTreeH = height - SECTION_HEADER_HEIGHT;
  if ( tagTree ) {
    tagTree->move(0, SECTION_HEADER_HEIGHT);
    tagTree->resize(width, tagTreeH);
  }
  if ( header ) {
    header->move(0, 0);
    header->resize(width, SECTION_HEADER_HEIGHT);
  }
}

/*****************************************************************************!
 * Function : BuildTagList
 *****************************************************************************/
void
MainTagWindow::BuildTagList
(QJsonObject InObject, QString InTag)
{
  QJsonArray                            array;
  QStringList                           keys;

  keys = InObject.keys();

  if ( ! TranslationUnit->GetObjectFormats()->Contains(InTag, keys) ) {
    JSONObjectFormat*                   objFormat = new JSONObjectFormat(InTag, keys);
    TranslationUnit->GetObjectFormats()->append(objFormat);
  }
  for ( auto keyi = keys.begin() ; keyi != keys.end() ; keyi++ ) {
    QString                             key = *keyi;
    QJsonValue                          value = InObject[key];

    if ( ! jsonTags.HasElement(key, value.type()) ) {
      jsonTags << new JSONTagElement(key, value.type());;
    }
    if ( value.isObject() ) {
      BuildTagList(value.toObject(), key);
      continue;
    }
    if ( value.isArray() ) {
      ProcessArrayTagList(value.toArray(), key);
    }
  }
}

/*****************************************************************************!
 * Function : ProcessArrayTagList
 *****************************************************************************/
void
MainTagWindow::ProcessArrayTagList
(QJsonArray InArray, QString InTag)
{
  QString                               tag;
  QString                               kind;
  for (int i = 0 ; i < InArray.size(); i++ ) {
    QJsonValue                          v = InArray[i];
    QJsonObject                         obj;
    
    if ( v.isObject() ) {
      obj = v.toObject();
      kind = obj["kind"].toString();
      tag = QString("%1[%2]").arg(InTag).arg(kind);
      if ( ! jsonTags.HasElement(tag, QJsonValue::Object) ) {
        jsonTags << new JSONTagElement(tag, QJsonValue::Object);
      }        
      BuildTagList(v.toObject(), tag);
    }
  }
}

/*****************************************************************************!
 * Function : PopulateTree
 *****************************************************************************/
void
MainTagWindow::PopulateTree(void)
{
  std::sort(jsonTags.begin(), jsonTags.end(),
            [] (JSONTagElement* InElement1, JSONTagElement* InElement2) {
              return InElement1->GetTag() < InElement2->GetTag();
            });
  for ( auto tagi = jsonTags.begin() ; tagi != jsonTags.end() ; tagi++ ) {
    JSONTagElement*                     tag = *tagi;
    JSONTagTreeItem*                    item;

    item = new JSONTagTreeItem(tag);
    tagTree->addTopLevelItem(item);
  }
}

/*****************************************************************************!
 * Function : SlotFormatTypeSelected
 *****************************************************************************/
void
MainTagWindow::SlotFormatTypeSelected
(QString InType)
{
  JSONTagTreeItem*                              item;

  item = FindItemByName(InType);
  if ( NULL == item ) {
    return;
  }
  tagTree->scrollToItem(item);
  tagTree->setCurrentItem(item);
}

/*****************************************************************************!
 * Function : FindItemByName
 *****************************************************************************/
JSONTagTreeItem*
MainTagWindow::FindItemByName
(QString InTag)
{
  QList<QTreeWidgetItem*>                       items;

  items = tagTree->findItems(InTag, Qt::MatchExactly, 0);
  if ( items.count() != 1 ) {
    return NULL;
  }
  return (JSONTagTreeItem*)items[0];
}
    
/*****************************************************************************!
 * Function : GetColumnWidths
 *****************************************************************************/
QList<int>
MainTagWindow::GetColumnWidths
()
{
  int                                   i;
  int                                   n;
  QList<int>                            widths;
  
  n = tagTree->columnCount();
  for (i = 0; i < n; i++) {
    widths << tagTree->columnWidth(i);
  }
  return widths;
}

/*****************************************************************************!
 * Function : SlotElementCountChanged
 *****************************************************************************/
void
MainTagWindow::SlotElementCountChanged
(int InCount)
{
  header->SetInnerCount(InCount);
}

/*****************************************************************************!
 * Function : SetColumnWidths
 *****************************************************************************/
void
MainTagWindow::SetColumnWidths
(QList<int> InWidths)
{
  tagTree->setColumnWidth(0, InWidths[0]);
  tagTree->setColumnWidth(1, InWidths[1]);
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
MainTagWindow::SlotClearChildren(void)
{
  emit SignalClearChildren();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainTagWindow::CreateConnections(void)
{
  connect(this,
          SIGNAL(SignalClearChildren()),
          tagTree,
          SLOT(SlotClearChildren()));
}

/*****************************************************************************!
 * Function : OpenNewFile
 *****************************************************************************/
void
MainTagWindow::OpenNewFile(TranslationUnitObject* InTranslationUnit)
{
  TranslationUnit = InTranslationUnit;
  BuildTagList(InTranslationUnit->GetJSONObject(), "TranslationUnitDecl");
  PopulateTree();
  SlotElementCountChanged(tagTree->topLevelItemCount());
}
