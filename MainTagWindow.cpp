/*****************************************************************************
 * FILE NAME    : MainTagWindow.cpp
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
#include "MainTagWindow.h"

/*****************************************************************************!
 * Function : MainTagWindow
 *****************************************************************************/
MainTagWindow::MainTagWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(128, 0, 0)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainTagWindow
 *****************************************************************************/
MainTagWindow::~MainTagWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainTagWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainTagWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainTagWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainTagWindow::resizeEvent
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
