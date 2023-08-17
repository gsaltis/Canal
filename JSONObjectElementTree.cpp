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
(JSONObjectFormatList* InObjectsFormats) : QTreeWidget()
{
  objectsFormats = InObjectsFormats;
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
  
  head = new QTreeWidgetItem();
  head->setText(0, "OBJECTS");
  head->setBackground(0, brush);
  setHeaderItem(head);

  lastTreeItem = NULL;
  
  for ( auto i = objectsFormats->begin(); i != objectsFormats->end(); i++ ) {
    JSONObjectFormat*                           obj = *i;
    item = new JSONObjectElementTreeItem(obj);
    addTopLevelItem(item);
  }
#if 0
  connect(this,
          JSONObjectElementTree::itemClicked,
          this,
          JSONObjectElementTree::SlotItemClicked);
#endif
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

  if ( itemType == JSONOBJECT_ELEMENT_TREE_ITEM_TYPE_TOP ) {
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
