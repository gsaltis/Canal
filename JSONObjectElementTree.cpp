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
(
 JSONObjectFormatList*                  InObjectsFormats
) : QTreeWidget()
{
  objectsFormats = InObjectsFormats;
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
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
  for ( auto i = objectsFormats->begin(); i != objectsFormats->end(); i++ ) {
    JSONObjectFormat*                           obj = *i;

    item = new JSONObjectElementTreeItem(obj);
    addTopLevelItem(item);
  }
  connect(this, JSONObjectElementTree::itemClicked, this, JSONObjectElementTree::SlotItemClicked);
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
  printf("%s::%s:%d : %s\n", __FILE__, __FUNCTION__, __LINE__, text.toStdString().c_str());
  emit SignalTypeSelected(text);

}

