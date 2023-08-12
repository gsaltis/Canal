/*****************************************************************************
 * FILE NAME    : JSONFileWindow.cpp
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
#include "JSONFileWindow.h"

/*****************************************************************************!
 * Function : JSONFileWindow
 *****************************************************************************/
JSONFileWindow::JSONFileWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 0, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileWindow
 *****************************************************************************/
JSONFileWindow::~JSONFileWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileWindow::resizeEvent
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
