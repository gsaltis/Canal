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

/*****************************************************************************!
 * Function : JSONFileObjectDisplayTree
 *****************************************************************************/
JSONFileObjectDisplayTree::JSONFileObjectDisplayTree
() : QTreeWidget()
{
  initialize();
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
  setColumnCount(2);
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
  }
}
