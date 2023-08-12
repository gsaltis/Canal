/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
 * DATE         : August 12 2023
 * PROJECT      : Canal
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
#include "MainDisplayWindow.h"

/*****************************************************************************!
 * Function : MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::MainDisplayWindow
() : QWidget()
{
  QPalette				pal;

  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(160, 160, 160)));
  setPalette(pal);
  setAutoFillBackground(true);

  Initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::~MainDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainDisplayWindow::Initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindow::InitializeSubWindows()
{
  splitter = NULL;
  tagWindow = NULL;
  fileWindow = NULL;
  elementWindow = NULL;
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  splitter = new MainSplitter();
  splitter->setParent(this);

  tagWindow = new MainTagWindow();
  fileWindow = new JSONFileWindow();
  elementWindow = new JSONElementWindow();

  splitter->addWidget(tagWindow);
  splitter->addWidget(fileWindow);
  splitter->addWidget(elementWindow);
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
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
  if ( splitter ) {
    splitter->resize(width, height);
  }
}
