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
  connect(fileTree,
          SIGNAL(SignalFileElementSelected(QString, QList<QString>)),
          this,
          SLOT(SlotFileElementSelected(QString, QList<QString>)));
  header = new SectionHeader();
  header->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::InitializeSubWindows()
{
  fileTree = NULL;  
  header = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   fileTreeH;
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  fileTreeH = height - SECTION_HEADER_HEIGHT;
  
  if ( fileTree ) {
    fileTree->resize(width, fileTreeH);
    fileTree->move(0, SECTION_HEADER_HEIGHT);
  }
  if ( header ) {
    header->resize(width, SECTION_HEADER_HEIGHT);
  }
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotFileObjectSelected
(QJsonObject InObject)
{
  QString                               name;
  emit SignalFileObjectSelected(InObject);
  
  name = InObject["name"].toString();
  header->SetText(name);
}

/*****************************************************************************!
 * Function : SlotFileElementSelected
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotFileElementSelected
(QString InTag, QList<QString> InKeys)
{
  emit SignalFileElementSelected(InTag, InKeys);
}
