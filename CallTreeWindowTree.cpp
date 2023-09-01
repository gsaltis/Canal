/*****************************************************************************
 * FILE NAME    : CallTreeWindowTree.cpp
 * DATE         : August 30 2023
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
#include "CallTreeWindowTree.h"
#include "CallTreeWindowTreeItem.h"

/*****************************************************************************!
 * Function : CallTreeWindowTree
 *****************************************************************************/
CallTreeWindowTree::CallTreeWindowTree
() : QTreeWidget()
{
  QTreeWidgetItem*                      head;
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);

  head = new QTreeWidgetItem();
  head->setText(0, "FUNCTION");
  setHeaderItem(head);
  resizeColumnToContents(0);
  
  initialize();
}

/*****************************************************************************!
 * Function : ~CallTreeWindowTree
 *****************************************************************************/
CallTreeWindowTree::~CallTreeWindowTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
CallTreeWindowTree::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
CallTreeWindowTree::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
CallTreeWindowTree::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
CallTreeWindowTree::resizeEvent
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
 * Function : SlotFunctionSelected
 *****************************************************************************/
void
CallTreeWindowTree::SlotFunctionSelected
(QJsonObject InObject)
{
  QString                               name;

  name = InObject["name"].toString();
  clear();
  FunctionNameItem = new CallTreeWindowTreeItem(CALL_TREE_WINDOW_TREE_ITEM_TYPE_FUNCTION);
  FunctionNameItem->setText(0, name);
  addTopLevelItem(FunctionNameItem);
}

/*****************************************************************************!
 * Function : SlotCallingFunctionFound
 *****************************************************************************/
void
CallTreeWindowTree::SlotCallingFunctionFound
(QString InFunctionName)
{
  QTreeWidgetItem*                      item;
  item = new CallTreeWindowTreeItem(CALL_TREE_WINDOW_TREE_ITEM_TYPE_CALLER);
  item->setText(0, InFunctionName);
  FunctionNameItem->addChild(item);
  FunctionNameItem->setExpanded(true);
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
CallTreeWindowTree::SlotClearChildren(void)
{
  clear();
}
