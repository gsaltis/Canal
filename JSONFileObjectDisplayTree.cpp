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
#include <QTreeWidgetItemIterator>

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
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
JSONFileObjectDisplayTree::CreateConnections
()
{
  connect(this,
          SIGNAL(itemExpanded(QTreeWidgetItem*)),
          this,
          SLOT(SlotItemExpanded(QTreeWidgetItem*)));
  
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
  ExpandInnerCompoundStmt();
  
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

  emit SignalValueSelected(value);
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
  emit SignalFileElementIdentified(searchTag, keys);
}

/*****************************************************************************!
 * Function : SlotExpandTree
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotExpandTree(void)
{
  QString                               s;
  int                                   n = 0;
  int                                   k = 0;
  k = GetItemCount();
  QTreeWidgetItemIterator               i(this);

  emit SignalProgressBarShow();
  emit SignalProgressBarSet(0, k);
  while (*i) {
    (*i)->setExpanded(true);
    i++;
    n++;
    if ( n % 100 == 0 ) {
      QCoreApplication::processEvents();
      s = QString("Process element %1 of %2").arg(n).arg(k);
      emit SignalNormalMessage(s);
      emit SignalProgressBarUpdate(n);
    }
  }
  emit SignalNormalMessage(QString());
  emit SignalProgressBarHide();
}

/*****************************************************************************!
 * Function : SlotCollapseTree
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotCollapseTree(void)
{
  QTreeWidgetItemIterator               i(this);
  while (*i) {
    (*i)->setExpanded(false);
    i++;
  }
}

/*****************************************************************************!
 * Function : ExpandInnerCompoundStmt
 *****************************************************************************/
void
JSONFileObjectDisplayTree::ExpandInnerCompoundStmt(void)
{
  int                                   i, n;
  bool                                  found = false;
  JSONFileObjectDisplayTreeItem*        item;
  JSONFileObjectDisplayTreeItem*        item2;
  JSONFileObjectDisplayTreeItem*        item3;

  n = topLevelItemCount();
  for (i = 0; i < n; i++) {
    item = (JSONFileObjectDisplayTreeItem*)topLevelItem(i);
    if ( item->text(0) == "inner" ) {
      found = true;
      break;
    }
  }
  if ( ! found ) {
    return;
  }

  found = false;
  n = item->childCount();
  for (i = 0; i < n; i++) {
    item2 = (JSONFileObjectDisplayTreeItem*)item->child(i);
    if ( item2->text(0) == "CompoundStmt" ) {
      found = true;
      break;
    }
  }
  if ( ! found ) {
    return;
  }

  n = item2->childCount();
  for (i = 0; i < n; i++) {
    item3 = (JSONFileObjectDisplayTreeItem*)item2->child(i);
    if ( item3->text(0) == "inner" ) {
      item3->setExpanded(true);
      item2->setExpanded(true);
      return;
    }
  }
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotClearChildren(void)
{
  clear();
}

/*****************************************************************************!
 * Function : GetItemCount
 *****************************************************************************/
int
JSONFileObjectDisplayTree::GetItemCount(void)
{
  int                                   k = 0;
  QTreeWidgetItemIterator               i(this);

  while (*i) {
    i++;
    k++;
  }
  return k;
}

/*****************************************************************************!
 * Function : SlotItemExpanded
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotItemExpanded
(QTreeWidgetItem* InItem)
{
  QString                               text;
  JSONFileObjectDisplayTreeItem*        item;

  item = (JSONFileObjectDisplayTreeItem*)InItem;

  text = item->text(0);
  if ( text == "BinaryOperator" ) {
    OpenBinaryOperator(item);
    return;
  }

  if ( text == "CompoundStmt" ) {
    OpenCompoundStmt(item);
    return;
  }

  if ( text == "IfStmt" ) {
    OpenIfStmt(item);
    return;
  }
}

/*****************************************************************************!
 * Function : OpenBinaryOperator
 *****************************************************************************/
void
JSONFileObjectDisplayTree::OpenBinaryOperator
(JSONFileObjectDisplayTreeItem* InItem)
{
  JSONFileObjectDisplayTreeItem*        item;
  int                                   n;
  int                                   i;
  QJsonValue                            innerValue;

  n = InItem->childCount();
  for ( i = 0 ; i < n ; i++ ) {
    item = (JSONFileObjectDisplayTreeItem*)InItem->child(i);
    if ( item->text(0) == "inner" ) {
      item->setExpanded(true);
    }
  }
}

/*****************************************************************************!
 * Function : OpenIfStmt
 *****************************************************************************/
void
JSONFileObjectDisplayTree::OpenIfStmt
(JSONFileObjectDisplayTreeItem* InItem)
{
  JSONFileObjectDisplayTreeItem*        item;
  int                                   n;
  int                                   i;
  QJsonValue                            innerValue;

  n = InItem->childCount();
  for ( i = 0 ; i < n ; i++ ) {
    item = (JSONFileObjectDisplayTreeItem*)InItem->child(i);
    if ( item->text(0) == "inner" ) {
      item->setExpanded(true);
    }
  }
}

/*****************************************************************************!
 * Function : OpenCompoundStmt
 *****************************************************************************/
void
JSONFileObjectDisplayTree::OpenCompoundStmt
(JSONFileObjectDisplayTreeItem* InItem)
{
  JSONFileObjectDisplayTreeItem*        item;
  int                                   n;
  int                                   i;
  QJsonValue                            innerValue;

  n = InItem->childCount();
  for ( i = 0 ; i < n ; i++ ) {
    item = (JSONFileObjectDisplayTreeItem*)InItem->child(i);
    if ( item->text(0) == "inner" ) {
      item->setExpanded(true);
    }
  }
}

/*****************************************************************************!
 * Function : SlotProgressBarShow
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotProgressBarShow(void)
{
  TRACE_FUNCTION_LOCATION();
  emit SignalProgressBarShow();  
}

/*****************************************************************************!
 * Function : SlotProgressBarHide
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotProgressBarHide(void)
{
  TRACE_FUNCTION_LOCATION();
  emit SignalProgressBarHide();
}

/*****************************************************************************!
 * Function : SlotProgressBarSet
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotProgressBarSet
(int InMinimum, int InMaximum)
{
  TRACE_FUNCTION_LOCATION();
  emit SignalProgressBarSet(InMinimum, InMaximum);
}

/*****************************************************************************!
 * Function : SlotProgressBarUpdate
 *****************************************************************************/
void
JSONFileObjectDisplayTree::SlotProgressBarUpdate
(int InValue)
{
  TRACE_FUNCTION_LOCATION();
  emit SignalProgressBarUpdate(InValue);
}
