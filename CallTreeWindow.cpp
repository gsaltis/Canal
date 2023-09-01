/*****************************************************************************
 * FILE NAME    : CallTreeWindow.cpp
 * DATE         : August 30 2023
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
#include "CallTreeWindow.h"

/*****************************************************************************!
 * Function : CallTreeWindow
 *****************************************************************************/
CallTreeWindow::CallTreeWindow
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
 * Function : ~CallTreeWindow
 *****************************************************************************/
CallTreeWindow::~CallTreeWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
CallTreeWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
CallTreeWindow::CreateConnections
(void)
{
  connect(this,
          SIGNAL(SignalFunctionSelected(QJsonObject)),
          callTree,
          SLOT(SlotFunctionSelected(QJsonObject)));
  connect(this,
          SIGNAL(SignalCallingFunctionFound(QString)),
          callTree,
          SLOT(SlotCallingFunctionFound(QString)));
  connect(this,
          SIGNAL(SignalClearChildren()),
          callTree,
          SLOT(SlotClearChildren()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
CallTreeWindow::CreateSubWindows()
{
  callTree = new CallTreeWindowTree();  
  callTree->setParent(this);
  header = new SectionHeader();
  header->setParent(this);
  header->SetText("CALLING FUNCTIONS");
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
CallTreeWindow::InitializeSubWindows()
{
  callTree = NULL;  
  header = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
CallTreeWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  if ( callTree ) {
    callTree->move(0, SECTION_HEADER_HEIGHT);
    callTree->resize(width, height - SECTION_HEADER_HEIGHT);
  }
  if ( header ) {
    header->move(0, 0);
    header->resize(width, SECTION_HEADER_HEIGHT);
  }
}

/*****************************************************************************!
 * Function : SlotFunctionSelected
 *****************************************************************************/
void
CallTreeWindow::SlotFunctionSelected
(QJsonObject InObject)
{
  emit SignalFunctionSelected(InObject);
}

/*****************************************************************************!
 * Function : SlotCallingFunctionFound
 *****************************************************************************/
void
CallTreeWindow::SlotCallingFunctionFound
(QString InFunctionName)
{
  emit SignalCallingFunctionFound(InFunctionName);
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
CallTreeWindow::SlotClearChildren(void)
{
  emit SignalClearChildren();
}

