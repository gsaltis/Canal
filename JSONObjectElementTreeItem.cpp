/*****************************************************************************
 * FILE NAME    : JSONObjectElementTreeItem.cpp
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
#include "JSONObjectElementTreeItem.h"

/*****************************************************************************!
 * Function : JSONObjectElementTreeItem
 *****************************************************************************/
JSONObjectElementTreeItem::JSONObjectElementTreeItem
(
 JSONObjectFormat*                      InFormat,
 int                                    InType
) : QTreeWidgetItem()
{
  type = InType;
  format = InFormat;
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONObjectElementTreeItem
 *****************************************************************************/
JSONObjectElementTreeItem::~JSONObjectElementTreeItem
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONObjectElementTreeItem::initialize()
{
  if ( type == JSONOBJECT_ELEMENT_TREE_ITEM_TYPE_CHILD ) {
    return;
  }
  QStringList                           keys;
  setText(0, format->GetTag());
  keys = format->GetKeys();
  std::sort(keys.begin(), keys.end());

  for ( auto i = keys.begin(); i != keys.end(); i++ ) {
    QString                             key = *i;
    JSONObjectElementTreeItem*          item;
    item = new JSONObjectElementTreeItem(NULL, JSONOBJECT_ELEMENT_TREE_ITEM_TYPE_CHILD);
    item->setText(0, key);
    addChild(item);
  }
}

/*****************************************************************************!
 * Function : GetType
 *****************************************************************************/
int
JSONObjectElementTreeItem::GetType(void)
{
  return type;
}
