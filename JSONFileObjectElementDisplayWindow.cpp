/*****************************************************************************
 * FILE NAME    : JSONFileObjectElementDisplayWindow.cpp
 * DATE         : August 29 2023
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
#include "JSONFileObjectElementDisplayWindow.h"

/*****************************************************************************!
 * Function : JSONFileObjectElementDisplayWindow
 *****************************************************************************/
JSONFileObjectElementDisplayWindow::JSONFileObjectElementDisplayWindow
() : QWidget()
{
  QPalette                                      pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileObjectElementDisplayWindow
 *****************************************************************************/
JSONFileObjectElementDisplayWindow::~JSONFileObjectElementDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileObjectElementDisplayWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileObjectElementDisplayWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileObjectElementDisplayWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileObjectElementDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QPalette                              pal;
  QSize                                 size;  
  int                                   height;

  size = InEvent->size();
  height = size.height();

  QLinearGradient                       grad(0, 0, 0, height);
  grad.setColorAt(0, QColor(240, 240, 240));
  grad.setColorAt(1, QColor(208, 208, 208));
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(grad));
  setPalette(pal);
}
