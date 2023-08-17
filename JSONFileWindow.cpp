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
  InitializeSubWindows();  
  CreateSubWindows();
  connect(fileTree,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          this,
          SLOT(SlotFileObjectSelected(QJsonObject)));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileWindow::CreateSubWindows()
{
  fileTree = new JSONFileTree(mainJSONObject, filename, basename);
  fileTree->setParent(this);
  header = new JSONFileWindowSectionHeader();
  header->SetText("TRANSLATION UNIT");
  header->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileWindow::InitializeSubWindows()
{
  fileTree = NULL;  
  header = NULL;
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
  int                                   fileTreeH;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();
  fileTreeH = height - SECTION_HEADER_HEIGHT;
  
  if ( fileTree ) {
    fileTree->move(0, SECTION_HEADER_HEIGHT);
    fileTree->resize(width, fileTreeH);
  }
  if ( header ) {
    header->move(0, 0);
    header->resize(width, SECTION_HEADER_HEIGHT);
  }
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONFileWindow::SlotFileObjectSelected
(QJsonObject InObject)
{
  emit SignalFileObjectSelected(InObject);
}
