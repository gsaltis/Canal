/*****************************************************************************
 * FILE NAME    : CallTreeWindowTreeItem.cpp
 * DATE         : August 31 2023
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
#include "CallTreeWindowTreeItem.h"

/*****************************************************************************!
 * Function : CallTreeWindowTreeItem
 *****************************************************************************/
CallTreeWindowTreeItem::CallTreeWindowTreeItem
(int InType) : QTreeWidgetItem()
{
  type = InType;
  initialize();
}

/*****************************************************************************!
 * Function : ~CallTreeWindowTreeItem
 *****************************************************************************/
CallTreeWindowTreeItem::~CallTreeWindowTreeItem
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
CallTreeWindowTreeItem::initialize()
{
}

/*****************************************************************************!
 * Function : GetType
 *****************************************************************************/
int
CallTreeWindowTreeItem::GetType(void)
{
  return type;  
}

/*****************************************************************************!
 * Function : SetType
 *****************************************************************************/
void
CallTreeWindowTreeItem::SetType
(int InType)
{
  type = InType;  
}
