/*****************************************************************************
 * FILE NAME    : MainStacker.cpp
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
#include "MainStacker.h"

/*****************************************************************************!
 * Function : MainStacker
 *****************************************************************************/
MainStacker::MainStacker
() : QStackedWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainStacker
 *****************************************************************************/
MainStacker::~MainStacker
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainStacker::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainStacker::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainStacker::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainStacker::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  printf("%s::%s:%d %d %d\n", __FILE__, __FUNCTION__, __LINE__, width, height);
  (void)height;
  (void)width;
}
