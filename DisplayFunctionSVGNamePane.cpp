/*****************************************************************************
 * FILE NAME    : DisplayFunctionSVGNamePane.cpp
 * DATE         : August 28 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

#define TRACE_USE
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "DisplayFunctionSVGNamePane.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : DisplayFunctionSVGNamePane
 *****************************************************************************/
DisplayFunctionSVGNamePane::DisplayFunctionSVGNamePane
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~DisplayFunctionSVGNamePane
 *****************************************************************************/
DisplayFunctionSVGNamePane::~DisplayFunctionSVGNamePane
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
DisplayFunctionSVGNamePane::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
DisplayFunctionSVGNamePane::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
DisplayFunctionSVGNamePane::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
DisplayFunctionSVGNamePane::resizeEvent
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
 * Function : paintEvent
 *****************************************************************************/
void
DisplayFunctionSVGNamePane::paintEvent
(QPaintEvent* InEvent)
{
  QPainter                      painter(this);
  QSize                         s = size();
  QPen                          darkPen;
  QPen                          lightPen;
  QBrush                        brush;
  QLinearGradient               gradient(0, 0, 0, s.height());
  int                           i;
  int                           width = 3;
  
  (void)InEvent;
  gradient.setColorAt(0, QColor(255, 255, 240));
  gradient.setColorAt(1, QColor(192, 192, 180));
  
  painter.setBrush(QBrush(gradient));
  painter.drawRect(0, 0, s.width(), s.height());

  darkPen = QPen(QColor(224, 224, 224));
  darkPen.setWidth(1);

  lightPen = QPen(QColor(128, 128, 128));
  lightPen.setWidth(1);

  painter.setPen(darkPen);
  for ( i = 0 ; i < width ; i++ ) {
    painter.drawLine(i, i,  s.width() - 1, i);
  }
  for ( i = 0 ; i < width ; i++ ) {
    painter.drawLine(s.width() - i, i, s.width() - i, s.height() - i);
  }
  painter.setPen(lightPen);
  for ( i = 0 ; i < width ; i++ ) {
    painter.drawLine(i, s.height() - i,  s.width() - i, s.height() - i);
  }
  for ( i = 0 ; i < width ; i++ ) {
    painter.drawLine(i, i,  i, s.height() - i);
  }

  painter.end();
}
