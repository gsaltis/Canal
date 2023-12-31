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
#include "common.h"

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
  pal.setBrush(QPalette::Window, MainSystemConfig->GetDisplayWindowBackgroundColor());
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
  functionNamesWindow = new DisplayFunctionSVGNamePane();
  functionNamesWindow->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayFunctionSVGWindow::InitializeSubWindows()
{
  functionNamesWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayFunctionSVGWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   functionNamesWindowH;
  int                                   functionNamesWindowW;
  int                                   functionNamesWindowY;
  int                                   functionNamesWindowX;
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)width;

  functionNamesWindowX = 0;
  functionNamesWindowY = 0;
  functionNamesWindowW = DISPLAY_FUNCTION_SVGNAME_PANE_WIDTH;
  functionNamesWindowH = height;
    
  if ( functionNamesWindow ) {
    functionNamesWindow->move(functionNamesWindowX, functionNamesWindowY);
    functionNamesWindow->resize(functionNamesWindowW, functionNamesWindowH);
  }
}
