/*****************************************************************************
 * FILE NAME    : JSONObjectElementTree.cpp
 * DATE         : August 14 2023
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
#include "JSONObjectElementTree.h"
#include "JSONObjectElementTreeItem.h"
#include "common.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : JSONObjectElementTree
 *****************************************************************************/
JSONObjectElementTree::JSONObjectElementTree
(TranslationUnitObject* InTransationUnit) : QTreeWidget()
{
  TranslationUnit = InTransationUnit;
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONObjectElementTree
 *****************************************************************************/
JSONObjectElementTree::~JSONObjectElementTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONObjectElementTree::initialize()
{
  JSONObjectElementTreeItem*            item;
  QTreeWidgetItem*                      head;
  QBrush                                brush(MainTreeHeaderColor);
  JSONObjectFormatList*                 objectsFormats;
  
  head = new QTreeWidgetItem();
  head->setText(0, "OBJECTS");
  head->setBackground(0, brush);
  setHeaderItem(head);

  objectsFormats = TranslationUnit->GetObjectFormats();
  lastTreeItem = NULL;
  
  for ( auto i = objectsFormats->begin(); i != objectsFormats->end(); i++ ) {
    JSONObjectFormat*                           obj = *i;
    item = new JSONObjectElementTreeItem(obj);
    addTopLevelItem(item);
  }
  connect(this,
          SIGNAL(itemClicked(QTreeWidgetItem*, int)),
          this,
          SLOT(SlotItemClicked(QTreeWidgetItem*, int)));
}

/*****************************************************************************!
 * Function : SlotItemClicked
 *****************************************************************************/
void
JSONObjectElementTree::SlotItemClicked
(QTreeWidgetItem* InItem, int)
{
  QString                               text;
  JSONObjectElementTreeItem*            item = (JSONObjectElementTreeItem*)InItem;
  int                                   itemType = item->GetType();
  JSONObjectFormat*                     format;

  format = item->GetFormat();
  if ( itemType == JSONOBJECT_ELEMENT_TREE_ITEM_TYPE_TOP ) {
    emit SignalObjectFormatSelected(format);
    return;
  }
  text = item->text(0);
  emit SignalTypeSelected(text);
}

/*****************************************************************************!
 * Function : SlotFileElementSelected
 *****************************************************************************/
void
JSONObjectElementTree::SlotFileElementSelected
(QString InTag, QList<QString> InKeys)
{
  int                                   n;
  JSONObjectElementTreeItem*            treeItem;
  QList<QString>                        keys = InKeys;
  JSONObjectFormat*                     format;

  std::sort(keys.begin(), keys.end());
  n = topLevelItemCount();
  for (int i = 0; i < n; i++) {
    treeItem = (JSONObjectElementTreeItem*)topLevelItem(i);
    format = treeItem->GetFormat();
    if ( format->IsEqual(InTag, keys) ) {
      if ( lastTreeItem ) {
        lastTreeItem->setExpanded(false);
      }
      treeItem->setExpanded(true);
      scrollToItem(treeItem, QAbstractItemView::PositionAtTop);
      setCurrentItem(treeItem);
      lastTreeItem = treeItem;
    }
  }
}

/*****************************************************************************!
 * Function : SlotObjectFormatIdentified
 *****************************************************************************/
void
JSONObjectElementTree::SlotObjectFormatIdentified
(QString InTag, QStringList InKeys)
{
  JSONObjectFormat*                     format;
  int                                   i;
  int                                   n;
  JSONObjectElementTreeItem*            item;

  n = topLevelItemCount();
  for (i = 0; i < n; i++) {
    item = (JSONObjectElementTreeItem*)topLevelItem(i);
    format = item->GetFormat();
    if ( format->IsEqual(InTag, InKeys) ) {
      SelectItem(item);
      break;
    }
  }
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONObjectElementTree::SlotFileObjectSelected
(QJsonObject InObject)
{
  UnSelectItem();
  FileObjectSelected(InObject);
}

/*****************************************************************************!
 * Function : FileObjectSelected
 *****************************************************************************/
void
JSONObjectElementTree::FileObjectSelected
(QJsonObject InObject)
{
  QJsonValue                            value;
  QStringList                           keys;
  JSONObjectElementTreeItem*            treeItem;
  QJsonObject                           obj;
  QStringList                           k;

  keys = InObject.keys();
  for ( auto i = keys.begin(); i != keys.end(); i++ ) {
    QString                             key = *i;

    value = InObject[key];

    if ( value.isArray() ) {
      ProcessArray(key, value.toArray());
      continue;
    }
    
    if ( ! value.isObject() ) {
      continue;
    }

    obj = value.toObject();
    k = obj.keys();
    treeItem = FindItem(key, k);
    if ( treeItem == NULL ) {
      continue;
    }
    SelectItem(treeItem);
    FileObjectSelected(obj);
  }
}

/*****************************************************************************!
 * Function : FindItem
 *****************************************************************************/
JSONObjectElementTreeItem*
JSONObjectElementTree::FindItem
(QString InTag, QStringList InKeys)
{
  int                                   i, n;
  JSONObjectElementTreeItem*            item;
  JSONObjectFormat*                     format;
  n = topLevelItemCount();
  for (i = 0; i < n; i++) {
    item = (JSONObjectElementTreeItem*)topLevelItem(i);
    format = item->GetFormat();
    if ( format->IsEqual(InTag, InKeys) ) {
      return item;
    }
  }
  return NULL;
}

/*****************************************************************************!
 * Function : ProcessArray
 *****************************************************************************/
void
JSONObjectElementTree::ProcessArray
(QString InKey, QJsonArray InArray)
{
  QStringList                           keys;
  QString                               kind;
  QJsonValue                            value;
  QJsonObject                           obj;
  int                                   i;
  int                                   n;
  QString                               tag;
  JSONObjectElementTreeItem*            treeItem;
  
  n = InArray.count();
  for (i = 0; i < n; i++) {
    value = InArray[i];
    if ( ! value.isObject() ) {
      continue;
    }
    obj = value.toObject();
    kind = obj["kind"].toString();
    if ( kind.isEmpty() ) {
      continue;
    }
    keys = obj.keys();
    tag = QString("%1[%2]").arg(InKey).arg(kind);
    treeItem = FindItem(tag, keys);
    if ( treeItem == NULL ) {
      continue;
    }
    SelectItem(treeItem);
    FileObjectSelected(obj);
  }
}

/*****************************************************************************!
 * Function : SelectItem
 *****************************************************************************/
void
JSONObjectElementTree::SelectItem
(JSONObjectElementTreeItem* InItem)
{
  InItem->setForeground(0, QBrush(QColor(128, 0, 0)));
  InItem->setFont(0, QFont("Segoe UI", 10, QFont::Bold));
  InItem->setHidden(false);
}

/*****************************************************************************!
 * Function : UnSelectItem
 *****************************************************************************/
void
JSONObjectElementTree::UnSelectItem(void)
{
  JSONObjectElementTreeItem*            item;
  int                                   i;
  int                                   n;
  n = topLevelItemCount();
  for (i = 0; i < n; i++) {
    item = (JSONObjectElementTreeItem*)topLevelItem(i);
    item->setExpanded(false);
    item->setHidden(true);
    item->setForeground(0, QBrush(QColor(0, 0, 0)));
    item->setFont(0, QFont("Segoe UI", 10, QFont::Normal));
  }
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
JSONObjectElementTree::SlotClearChildren(void)
{
  clear();
}

/*****************************************************************************!
 * Function : DisplayObjectFormats
 *****************************************************************************/
void
JSONObjectElementTree::DisplayObjectFormats(void)
{
  JSONObjectElementTreeItem*            item;
  JSONObjectFormatList*                 objectsFormats = TranslationUnit->GetObjectFormats();
  
  for ( auto i = objectsFormats->begin(); i != objectsFormats->end(); i++ ) {
    JSONObjectFormat*                           obj = *i;
    item = new JSONObjectElementTreeItem(obj);
    addTopLevelItem(item);
  }
}
