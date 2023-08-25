/*****************************************************************************
 * FILE NAME    : MainDisplayFunctionSVGWindow.cpp
 * DATE         : August 25 2023
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
#include "MainDisplayFunctionSVGWindow.h"

/*****************************************************************************!
 * Function : MainDisplayFunctionSVGWindow
 *****************************************************************************/
MainDisplayFunctionSVGWindow::MainDisplayFunctionSVGWindow
(QWidget* InParent, QString InFilename, QString InBaseFilename, QJsonObject InMainJSONObject, JSONObjectFormatList* InObjectsFormats) :
  QWidget(InParent)
{
  QPalette pal;
  filename = InFilename;
  baseFilename = InBaseFilename;
  mainJSONObject = InMainJSONObject;
  formatList = InObjectsFormats;
  
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 0, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayFunctionSVGWindow
 *****************************************************************************/
MainDisplayFunctionSVGWindow::~MainDisplayFunctionSVGWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainDisplayFunctionSVGWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayFunctionSVGWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayFunctionSVGWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayFunctionSVGWindow::resizeEvent
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
