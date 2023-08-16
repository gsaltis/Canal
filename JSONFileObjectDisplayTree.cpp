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
  QString                               kind;
  QString                               name;
  QJsonValue                            value;
  
  printf("%s::%s:%d\n", __FILE__, __FUNCTION__, __LINE__);

  value = InObject.value("kind");
  kind = value.toString();
  value = InObject.value("name");
  name = value.toString();

  printf("%s::%s:%d : %s %s\n", __FILE__, __FUNCTION__, __LINE__,
         name.toStdString().c_str(),
         kind.toStdString().c_str());
}
