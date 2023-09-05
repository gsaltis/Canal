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

#define TRACE_USE
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileObjectDisplayTabWindow.h"
#include "Trace.h"

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
  connect(tab,
          SIGNAL(SignalNormalMessage(QString)),
          this,
          SLOT(SlotNormalMessage(QString)));
  connect(tab,
          SIGNAL(SignalProgressBarShow()),
          this,
          SLOT(SlotProgressBarShow()));
  
  connect(tab,
          SIGNAL(SignalProgressBarHide()),
          this,
          SLOT(SlotProgressBarHide()));
  
  connect(tab,
          SIGNAL(SignalProgressBarSet(int, int)),
          this,
          SLOT(SlotProgressBarSet(int, int)));
  
  connect(tab,
          SIGNAL(SignalProgressBarUpdate(int)),
          this,
          SLOT(SlotProgressBarUpdate(int)));
  
  
  Tabs[tab->GetName()] = tab;
  addTab(tab, tab->GetName());
  setCurrentWidget(tab);
}

/*****************************************************************************!
 * Function : SlotExpandTree
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::SlotExpandTree(void)
{
  JSONFileObjectDisplayTab*             tab;

  tab = (JSONFileObjectDisplayTab*)currentWidget();
  if ( NULL == tab ) {
    return;
  }
  
  tab->SlotExpandTree();
}

/*****************************************************************************!
 * Function : SlotCollapseTree
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::SlotCollapseTree(void)
{
  JSONFileObjectDisplayTab*             tab;

  tab = (JSONFileObjectDisplayTab*)currentWidget();
  if ( NULL == tab ) {
    return;
  }

  tab->SlotCollapseTree();
  
}

/*****************************************************************************!
 * Function : SlotNormalMessage
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::SlotNormalMessage
(QString InMessage)
{
  emit SignalNormalMessage(InMessage);
}

/*****************************************************************************!
 * Function : SlotCloseTab
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::SlotCloseTab(void)
{
  QString                               name;
  int                                   n;
  JSONFileObjectDisplayTab*             tab;
  
  n = currentIndex();
  tab = (JSONFileObjectDisplayTab*)widget(n);
  removeTab(n);

  name = tab->GetName();
  Tabs.remove(name);

  delete tab;
}

/*****************************************************************************!
 * Function : SlotProgressBarShow
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::SlotProgressBarShow(void)
{
  emit SignalProgressBarShow();  
}

/*****************************************************************************!
 * Function : SlotProgressBarHide
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::SlotProgressBarHide(void)
{
  emit SignalProgressBarHide();
}

/*****************************************************************************!
 * Function : SlotProgressBarSet
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::SlotProgressBarSet
(int InMinimum, int InMaximum)
{
  emit SignalProgressBarSet(InMinimum, InMaximum);
}

/*****************************************************************************!
 * Function : SlotProgressBarUpdate
 *****************************************************************************/
void
JSONFileObjectDisplayTabWindow::SlotProgressBarUpdate
(int InValue)
{
  emit SignalProgressBarUpdate(InValue);
}
