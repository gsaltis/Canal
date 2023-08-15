/*****************************************************************************
 * FILE NAME    : JSONFileWindow.cpp
 * DATE         : August 12 2023
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
#include "JSONFileWindow.h"

/*****************************************************************************!
 * Function : JSONFileWindow
 *****************************************************************************/
JSONFileWindow::JSONFileWindow
(
 QString                                InFilename,
 QString                                InBasename,
 QJsonObject                            InMainJSONObject
) : QWidget()
{
  QPalette pal;

  mainJSONObject = InMainJSONObject;
  basename = InBasename;
  filename = InFilename;

  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 0, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileWindow
 *****************************************************************************/
JSONFileWindow::~JSONFileWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileWindow::initialize()
{
  innerObj = mainJSONObject["inner"].toArray();
  printf("%s %d : %lld\n", __FUNCTION__, __LINE__, innerObj.size());
  InitializeSubWindows();  
  CreateSubWindows();
  connect(fileTree,
          SIGNAL(SignalFileObjectSelected(QJsonObject*)),
          this,
          SLOT(SlotFileObjectSelected(QJsonObject*)));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileWindow::CreateSubWindows()
{
  fileTree = new JSONFileTree(mainJSONObject, filename, basename);
  fileTree->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileWindow::InitializeSubWindows()
{
  fileTree = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileWindow::resizeEvent
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
  if ( fileTree ) {
    fileTree->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONFileWindow::SlotFileObjectSelected
(QJsonObject* InObject)
{
  emit SignalFileObjectSelected(InObject);
}
