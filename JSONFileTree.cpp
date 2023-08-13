/*****************************************************************************
 * FILE NAME    : JSONFileTree.cpp
 * DATE         : August 12 2023
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
#include "JSONFileTree.h"
#include "JSONFileTreeItem.h"

/*****************************************************************************!
 * Function : JSONFileTree
 *****************************************************************************/
JSONFileTree::JSONFileTree
(
 QJsonObject                            InJSONFileObject,
 QString                                InFilename,
 QString                                InBaseFilename
) : QTreeWidget()
{
  QPalette pal;
  
  baseFilename = InBaseFilename;
  filename = InFilename;
  JSONFileObject = InJSONFileObject;

  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileTree
 *****************************************************************************/
JSONFileTree::~JSONFileTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileTree::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  setColumnCount(2);
  QStringList                           keys;

  keys = JSONFileObject.keys();
  
  for ( int i = 0 ; i < keys.size() ; i++ ) {
    JSONFileTreeItem*                   item = new JSONFileTreeItem();
    QJsonValue                          value = JSONFileObject[keys[i]];
    
    item->setText(0, keys[i]);
    if ( value.isString() ) {
      item->setText(1, value.toString());
    }
    addTopLevelItem(item);
  }
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileTree::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileTree::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileTree::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}
