/*****************************************************************************
 * FILE NAME    : JSONFileTreeItem.cpp
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
#include "JSONFileTreeItem.h"

/*****************************************************************************!
 * Function : JSONFileTreeItem
 *****************************************************************************/
JSONFileTreeItem::JSONFileTreeItem
(int InType, int InElementType, QJsonObject InObject) : QTreeWidgetItem()
{
  type = InType;
  elementType = InElementType;
  object = InObject;
  initialize();
}

/*****************************************************************************!
 * Function : JSONFileTreeItem
 *****************************************************************************/
JSONFileTreeItem::JSONFileTreeItem
(QString InTitle, int InType, int InElementType, QJsonObject InObject) : QTreeWidgetItem()
{
  setText(0, InTitle);
  type = InType;
  elementType = InElementType;
  object = InObject;
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileTreeItem
 *****************************************************************************/
JSONFileTreeItem::~JSONFileTreeItem
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileTreeItem::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileTreeItem::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileTreeItem::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileTreeItem::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}

/*****************************************************************************!
 * Function : GetType
 *****************************************************************************/
int
JSONFileTreeItem::GetType
()
{
  return type;
}

/*****************************************************************************!
 * Function : GetObject
 *****************************************************************************/
QJsonObject
JSONFileTreeItem::GetObject
()
{
  return object;
}

/*****************************************************************************!
 * Function : GetElementType
 *****************************************************************************/
int
JSONFileTreeItem::GetElementType
()
{
  return elementType;
}
