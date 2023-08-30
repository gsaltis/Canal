/*****************************************************************************
 * FILE NAME    : JSONTagTree.cpp
 * DATE         : August 13 2023
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
#include "JSONTagTree.h"
#include "common.h"

/*****************************************************************************!
 * Function : JSONTagTree
 *****************************************************************************/
JSONTagTree::JSONTagTree
() : QTreeWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONTagTree
 *****************************************************************************/
JSONTagTree::~JSONTagTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONTagTree::initialize()
{
  setColumnCount(2);

  QTreeWidgetItem*                      head;
  QBrush                                brush(MainTreeHeaderColor);
  
  head = new QTreeWidgetItem();
  head->setText(0, "NAME");
  head->setBackground(0, brush);

  head->setText(1, "TYPE");
  head->setBackground(1, brush);
  setHeaderItem(head);

  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONTagTree::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONTagTree::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONTagTree::resizeEvent
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
 * Function : SlotClearChildren
 *****************************************************************************/
void
JSONTagTree::SlotClearChildren(void)
{
  clear();
}
