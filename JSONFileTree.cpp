/*****************************************************************************
 * FILE NAME    : JSONFileTree.cpp
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

#define TRACE_USE
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileTree.h"
#include "JSONFileTreeItem.h"
#include "JSONFileTreeHeader.h"
#include "common.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : JSONFileTree
 *****************************************************************************/
JSONFileTree::JSONFileTree
() : QTreeWidget()
{
  QTreeWidgetItem*                      head;
  QPalette pal;
  QBrush                                brush(MainTreeHeaderColor);

  setColumnCount(2);
  head = new QTreeWidgetItem();
  head->setText(0, "TAG");
  head->setBackground(0, brush);
  resizeColumnToContents(0);
  
  head->setText(1, "VALUE");
  head->setBackground(1, brush);
  setHeaderItem(head);

  header()->setStretchLastSection(true);
  
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileTree
 *****************************************************************************/
JSONFileTree::~JSONFileTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileTree::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  setColumnCount(2);
}

/*****************************************************************************!
 * Function : SetObject
 *****************************************************************************/
void
JSONFileTree::SetObject
()
{
  QStringList                           keys;

  keys = JSONFileObject.keys();
  
  for ( int i = 0 ; i < keys.size() ; i++ ) {
    JSONFileTreeItem*                   item = new JSONFileTreeItem();
    QJsonValue                          value = JSONFileObject[keys[i]];
    
    item->setText(0, keys[i]);
    if ( value.isString() ) {
      item->setText(1, value.toString());
    } else if ( value.isDouble() ) {
      QString s = QString("%1").arg(value.toInt());
      item->setText(1, s);
    }
    addTopLevelItem(item);
    if ( keys[i] == "inner" ) {
      item->setExpanded(true);
      SetInnerItem(item, &value);
    }
  }
  connect(this,
          SIGNAL(itemClicked(QTreeWidgetItem*, int)),
          this,
          SLOT(SlotItemClicked(QTreeWidgetItem*, int)));
}

/*****************************************************************************!
 * Function : Set
 *****************************************************************************/
void
JSONFileTree::Set
(QJsonObject InJSONFileObject, QString InFilename, QString InBaseFilename)
{
  baseFilename = InBaseFilename;
  filename = InFilename;
  JSONFileObject = InJSONFileObject;

  SetObject();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileTree::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : SetInnerItem
 *****************************************************************************/
void
JSONFileTree::SetInnerItem
(JSONFileTreeItem* InItem, QJsonValue* InValue)
{
  QColor                                color;
  QJsonArray                            inner;
  QString                               name;
  QString                               kind;
  int                                   n;
  QJsonArray                            array;
  QJsonObject                           locObj;
  bool                                  outFileFound = false;
  int                                   localCount = 0;
  int                                   elementType;
  
  array = InValue->toArray();
  n = array.size();
  for (int i = 0; i < n; i++) {
    QJsonValue                          v = array[i];
    QJsonObject                         obj = v.toObject();
    JSONFileTreeItem*                   item;
    elementType = JSONFILE_TREE_ITEM_TYPE_NONE;
    
    kind = obj["kind"].toString();
    if ( kind == "FunctionDecl" ) {
      elementType = JSONFILE_TREE_ITEM_TYPE_FUNCTION_DECL;
    }
    name = obj["name"].toString();
    inner = obj["inner"].toArray();
    for ( int j = 0; j < inner.size() ; j++ ) {
      color = QColor(0, 0, 128);
      QJsonObject                       obj = inner[j].toObject();
      QString                           k = obj["kind"].toString();
      if ( k == "CompoundStmt" ) {
        elementType = JSONFILE_TREE_ITEM_TYPE_FUNCTION_DEF;
        color = QColor(128, 0, 0);
        break;
      }
    }
      
    locObj = obj["loc"].toObject();
    filename = locObj["file"].toString();
    if ( filename == baseFilename ) {
      outFileFound = true;
    }
    if ( outFileFound ) {
      localCount++;
      item = new JSONFileTreeItem(JSONFILE_TREE_ITEM_INNER_TOP, elementType, obj);
      MainTopLevelObjects << obj;
      item->setForeground(0, QBrush(color));
      item->setForeground(1, QBrush(color));
      item->setText(0, kind);
      item->setText(1, name);
      InItem->addChild(item);
    }
  }
  emit SignalLocalCountSet(localCount);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileTree::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileTree::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}

/*****************************************************************************!
 * Function : AddInnerObject
 *****************************************************************************/
void
JSONFileTree::AddInnerObject
(JSONFileTreeItem* InItem, QJsonObject InObject)
{
  QStringList                           keys;
  keys = InObject.keys();
  
  for ( int i = 0 ; i < keys.size() ; i++ ) {
    JSONFileTreeItem*                   item = new JSONFileTreeItem(JSONFILE_TREE_ITEM_CHILD);
    QJsonValue                          value = InObject[keys[i]];
    
    item->setText(0, keys[i]);
    if ( value.isString() ) {
      item->setText(1, value.toString());
    } else if ( value.isDouble() ) {
      QString s = QString("%1").arg(value.toInt());
      item->setText(1, s);
    }
    InItem->addChild(item);
    if ( keys[i] == "loc" ) {
      AddInnerObject(item, value.toObject());
      continue;
    }
    if ( keys[i] == "range" ) {
      AddInnerObject(item, value.toObject());
      continue;
    }
    if ( keys[i] == "inner" ) {
      SetInnerItem(item, &value);
    }
  }
}

/*****************************************************************************!
 * Function : SlotItemClicked
 *****************************************************************************/
void
JSONFileTree::SlotItemClicked
(QTreeWidgetItem* InItem, int)
{
  QString                               kind;
  QJsonObject                           object;
  int                                   type;
  JSONFileTreeItem*                     item;

  item = (JSONFileTreeItem*)InItem;
  type = item->GetType();
  object = item->GetObject();
  ResetNameFonts();
  if ( type == JSONFILE_TREE_ITEM_INNER_TOP ) {
    kind = object.value("kind").toString();
    emit SignalFileObjectSelected(object);
  }
}

/*****************************************************************************!
 * Function : SlotSizeValueChanged
 *****************************************************************************/
void
JSONFileTree::SlotSizeValueChanged
(int InSize)
{
  header()->resizeSection(0, InSize); 
}

/*****************************************************************************!
 * Function : SlotCallingFunctionFound
 *****************************************************************************/
void
JSONFileTree::SlotCallingFunctionFound
(QString InFunctionName)
{
  int                                   n;
  int                                   i;
  JSONFileTreeItem*                     item;
  JSONFileTreeItem*                     topItem;
  QFont                                 font;

  topItem = FindTopLevelItemByName("inner");
  n = topItem->childCount();
  for (i = 0; i < n; i++) {
    item = (JSONFileTreeItem*)topItem->child(i);
    if ( item->GetElementType() != JSONFILE_TREE_ITEM_TYPE_FUNCTION_DEF ) {
      continue;
    }
    if ( item->text(1) == InFunctionName ) {
      font = item->font(0);
      font.setWeight(QFont::Bold);
      item->setFont(0, font);
      item->setFont(1, font);
    }
  }
}

/*****************************************************************************!
 * Function : FindTopLevelItemByName
 *****************************************************************************/
JSONFileTreeItem*
JSONFileTree::FindTopLevelItemByName
(QString InName)
{
  JSONFileTreeItem*                     item;
  int                                   i;
  int                                   n;

  n = topLevelItemCount();

  for (i = 0; i < n; i++) {
    item = (JSONFileTreeItem*)topLevelItem(i);
    if ( item->text(0) == InName ) {
      return item;
    }
  }
  return NULL;
}

/*****************************************************************************!
 * Function : ResetNameFonts
 *****************************************************************************/
void
JSONFileTree::ResetNameFonts(void)
{
  int                                   n;
  int                                   i;
  JSONFileTreeItem*                     item;
  JSONFileTreeItem*                     topItem;
  QFont                                 font;

  topItem = FindTopLevelItemByName("inner");
  n = topItem->childCount();
  for (i = 0; i < n; i++) {
    item = (JSONFileTreeItem*)topItem->child(i);
    font = item->font(0);
    font.setWeight(QFont::Normal);
    item->setFont(0, font);
    item->setFont(1, font);
  }
}
