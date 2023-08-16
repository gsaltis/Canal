/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayWindow.cpp
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
#include "JSONFileObjectDisplayWindow.h"

/*****************************************************************************!
 * Function : JSONFileObjectDisplayWindow
 *****************************************************************************/
JSONFileObjectDisplayWindow::JSONFileObjectDisplayWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileObjectDisplayWindow
 *****************************************************************************/
JSONFileObjectDisplayWindow::~JSONFileObjectDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::CreateSubWindows()
{
  fileTree = new JSONFileObjectDisplayTree();  
  fileTree->setParent(this);
  connect(this,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          fileTree,
          SLOT(SlotFileObjectSelected(QJsonObject)));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::InitializeSubWindows()
{
  fileTree = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  if ( fileTree ) {
    fileTree->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotFileObjectSelected
(QJsonObject InObject)
{
  emit SignalFileObjectSelected(InObject);
}

