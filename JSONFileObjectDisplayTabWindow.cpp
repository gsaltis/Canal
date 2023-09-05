/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayTabWindow.cpp
 * DATE         : September 03 2023
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
#include "JSONFileObjectDisplayTabWindow.h"

/*****************************************************************************!
 * Function : JSONFileObjectDisplayTabWindow
 *****************************************************************************/
JSONFileObjectDisplayTabWindow::JSONFileObjectDisplayTabWindow
() : QTabWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileObjectDisplayTabWindow
 *****************************************************************************/
JSONFileObjectDisplayTabWindow::~JSONFileObjectDisplayTabWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::resizeEvent
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
}

/*****************************************************************************!
 * Function : AddObject
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::AddObject
(QJsonObject InObject)
{
  JSONFileObjectDisplayTab*             tab;
  QString                               name;

  name = InObject["name"].toString();
  if ( Tabs.contains(name) ) {
    tab = Tabs[name];
    setCurrentWidget(tab);
    return;
  }
    
  tab = new JSONFileObjectDisplayTab(InObject);
  Tabs[tab->GetName()] = tab;
  addTab(tab, tab->GetName());
  setCurrentWidget(tab);
}
