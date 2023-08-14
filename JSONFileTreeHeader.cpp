/*****************************************************************************
 * FILE NAME    : JSONFileTreeHeader.cpp
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
#include "JSONFileTreeHeader.h"

/*****************************************************************************!
 * Function : JSONFileTreeHeader
 *****************************************************************************/
JSONFileTreeHeader::JSONFileTreeHeader
() : QHeaderView(Qt::Horizontal)
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(192, 0, 192)));
  setPalette(pal);
  setAutoFillBackground(true);
  setStretchLastSection(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileTreeHeader
 *****************************************************************************/
JSONFileTreeHeader::~JSONFileTreeHeader
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileTreeHeader::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileTreeHeader::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileTreeHeader::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileTreeHeader::resizeEvent
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

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
JSONFileTreeHeader::paintEvent
(QPaintEvent* InEvent)
{
  (void)InEvent;
}

