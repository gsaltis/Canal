/*****************************************************************************
 * FILE NAME    : MainDisplayJSONTreesWindow.cpp
 * DATE         : August 21 2023
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
#include "MainDisplayJSONTreesWindow.h"
#include "common.h"

/*****************************************************************************!
 * Function : MainDisplayJSONTreesWindow
 *****************************************************************************/
MainDisplayJSONTreesWindow::MainDisplayJSONTreesWindow
(QWidget* InParent, QString InFilename, QString InBaseFilename, QJsonObject InMainJSONObject, JSONObjectFormatList* InObjectsFormats) :
  QWidget(InParent)
{
  QPalette pal;
  filename = InFilename;
  
  QFileInfo                             fileinfo(filename);

  mainJSONObject = InMainJSONObject;
  
  objectsFormats = InObjectsFormats;
  baseFilename = InBaseFilename;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 0, 0)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayJSONTreesWindow
 *****************************************************************************/
MainDisplayJSONTreesWindow::~MainDisplayJSONTreesWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::CreateSubWindows()
{
  QList<int>                            widths;
  splitter = new MainSplitter();
  splitter->setParent(this);

  widths = MainSystemConfig->GetWindowWidths();

  fileWindow            = new JSONFileWindow(filename, baseFilename, mainJSONObject);
  tagWindow             = new MainTagWindow(mainJSONObject, objectsFormats);
  elementWindow         = new JSONElementWindow(objectsFormats);
  objectDisplayWindow   = new JSONFileObjectDisplayWindow();

  splitter->addWidget(fileWindow);
  splitter->addWidget(tagWindow);
  splitter->addWidget(elementWindow);
  splitter->addWidget(objectDisplayWindow);
  splitter->setSizes(widths);  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::resizeEvent
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
  if ( splitter ) {
    splitter->resize(width, height);
  }
}
