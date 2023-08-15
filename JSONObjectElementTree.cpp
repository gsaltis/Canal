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
  QBrush                                brush(QColor("#800000"));
  
  head = new QTreeWidgetItem();
  head->setText(0, "OBJECTS");
  head->setBackground(0, brush);
  setHeaderItem(head);

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

  printf("%s:%s : %d\n", __FILE__, __FUNCTION__, __LINE__);
  if ( itemType == JSONOBJECT_ELEMENT_TREE_ITEM_TYPE_TOP ) {
    return;
  }
  text = item->text(0);
  emit SignalTypeSelected(text);

}

