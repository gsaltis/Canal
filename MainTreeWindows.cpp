/*****************************************************************************
 * FILE NAME    : MainTreeWindows.cpp
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
#include "MainTreeWindows.h"
#include "common.h"

/*****************************************************************************!
 * Function : MainTreeWindows
 *****************************************************************************/
MainTreeWindows::MainTreeWindows
(QString InFilename, JSONObjectFormatList* InObjectsFormats) : QWidget()
{
  QPalette pal;
  filename = InFilename;
  QFileInfo                             fileinfo(filename);

  objectsFormats = InObjectsFormats;
  baseFilename = fileinfo.completeBaseName();
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainTreeWindows
 *****************************************************************************/
MainTreeWindows::~MainTreeWindows
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainTreeWindows::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainTreeWindows::CreateSubWindows()
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
MainTreeWindows::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainTreeWindows::resizeEvent
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
