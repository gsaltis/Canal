/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayTree.cpp
 * DATE         : August 15 2023
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
#include "JSONFileObjectDisplayTree.h"
#include "JSONFileObjectDisplayTreeItem.h"
#include "Trace.h"
#include "common.h"

/*****************************************************************************!
 * Function : JSONFileObjectDisplayTree
 *****************************************************************************/
JSONFileObjectDisplayTree::JSONFileObjectDisplayTree
() : QTreeWidget()
{
  initialize();
  connect(this,
          SIGNAL(itemClicked(QTreeWidgetItem*, int)),
          this,
          SLOT(SlotItemSelected(QTreeWidgetItem*, int)));
}

/*****************************************************************************!
 * Function : ~JSONFileObjectDisplayTree
 *****************************************************************************/
JSONFileObjectDisplayTree::~JSONFileObjectDisplayTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileObjectDisplayTree::initialize()
{
  QTreeWidgetItem*                      head;
  QBrush                                brush(MainTreeHeaderColor);
  
  setColumnCount(2);
  head = new QTreeWidgetItem();
  head->setText(0, "TAG");
  head->setBackground(0, brush);
  head->setText(1, "VALUE");
  head->setBackground(1, brush);
  setHeaderItem(head);
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotFileObjectSelected
(QJsonObject InObject)
{
  QJsonValue                            value;
  QStringList                           keys;

  clear();
  keys = InObject.keys();
  for ( auto i = keys.begin(); i != keys.end() ; i++ ) {
    QString                             key = *i;
    value = InObject[key];
    JSONFileObjectDisplayTreeItem*      item = new JSONFileObjectDisplayTreeItem(key, value);
    addTopLevelItem(item);
    if ( key == "inner" ) {
      item->setExpanded(true);
    }
  }
}

/*****************************************************************************!
 * Function : SlotItemSelected
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotItemSelected
(QTreeWidgetItem* InItem, int)
{
  QList<QString>                        keys;
  QString                               searchTag;
  QString                               tag;
  QTreeWidgetItem*                      p;
  QString                               pTag;
  QJsonObject                           obj;
  JSONFileObjectDisplayTreeItem*        item;
  QJsonValue                            value;

  item = (JSONFileObjectDisplayTreeItem*)InItem;
  value = item->GetValue();

  if ( ! value.isObject() ) {
    return;
  }

  obj = value.toObject();
  tag = InItem->text(0);
  p = item->parent();
  if ( p ) {
    pTag = p->text(0);
  }
  searchTag = tag;
  if ( pTag == "inner" ) {
    searchTag = pTag + QString("[") + tag + QString("]");
  }
  keys = obj.keys();
  emit SignalFileElementSelected(searchTag, keys);
}
