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
 JSONObjectFormat*                      InFormat
) : QTreeWidgetItem()
{
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
  QStringList                           keys;
  setText(0, format->GetTag());
  keys = format->GetKeys();
  std::sort(keys.begin(), keys.end());

  for ( auto i = keys.begin(); i != keys.end(); i++ ) {
    QString                             key = *i;
    QTreeWidgetItem*                    item;
    item = new QTreeWidgetItem();
    item->setText(0, key);
    addChild(item);
  }
}

