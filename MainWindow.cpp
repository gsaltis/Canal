/*****************************************************************************
 * FILE NAME    : MainWindow.cpp
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
#include <QMenuBar>
#include <QStatusBar>
#include <QFileDialog>

#define TRACE_USE
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"
#include "Trace.h"
#include "common.h"

/*****************************************************************************!
 * Function : MainWindow
 *****************************************************************************/
MainWindow::MainWindow
(QString InFilename,  JSONObjectFormatList* InObjectsFormats, int InWindowIndex) : QMainWindow()
{
  windowIndex = InWindowIndex;
  objectsFormats = InObjectsFormats;
  Initialize();
  filename = InFilename;
}

/*****************************************************************************!
 * Function : MainWindow
 *****************************************************************************/
MainWindow::MainWindow
(QWidget* parent, QString InFilename, JSONObjectFormatList* InObjectsFormats, int InWindowIndex) : QMainWindow(parent)
{
  windowIndex = InWindowIndex;
  objectsFormats = InObjectsFormats;
  Initialize();
  filename = InFilename;
  CreateActions();
  CreateMenus();
  InitializeSubWindows();
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : ~MainWindow
 *****************************************************************************/
MainWindow::~MainWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainWindow::Initialize()
{
  pathName = "./";
  filename = QString();
  setWindowTitle(MainSystemConfig->GetSystemName());  
}

/*****************************************************************************!
 * Function : CreateSubWindows
 * Purpose  : Create Sub Windows
 *****************************************************************************/
void
MainWindow::CreateSubWindows()
{
  displayWindow = new MainDisplayWindow(filename, objectsFormats, windowIndex);
  displayWindow->setParent(this);
  statusbar = statusBar();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 * Purpose  : Create Sub Windows
 *****************************************************************************/
void
MainWindow::InitializeSubWindows()
{
  displayWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 * Purpose  : Handle Resize Event
 *****************************************************************************/
void
MainWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   width;
  int                                   height;
  QSize                                 size;
  QSize                                 statusbar_size;
  QSize                                 menu_size;
  size = InEvent->size();  
  menu_size = menubar->size();
  statusbar_size = statusbar->size();
  width = size.width();
  height = size.height() - (menu_size.height() + statusbar_size.height());
  if ( displayWindow ) {
    displayWindow->move(0, menu_size.height());
    displayWindow->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : CreateActions
 * Purpose  : Create New Actions
 *****************************************************************************/
void
MainWindow::CreateActions()
{
  ActionExit = new QAction("E&xit", this);
  connect(ActionExit, SIGNAL(triggered()), this, SLOT(SlotExit()));

  ActionSelectJSONWindow = new QAction("JSON Window", this);
  connect(ActionSelectJSONWindow, SIGNAL(triggered()), this, SLOT(SlotSelectJSONWindow()));
  ActionSelectJSONWindow->setCheckable(true);
  if ( windowIndex == 1 ) {
    ActionSelectJSONWindow->setChecked(true);
  }
  
  ActionSelectDisplayWindow = new QAction("Display Window", this);
  connect(ActionSelectDisplayWindow, SIGNAL(triggered()), this, SLOT(SlotSelectDisplayWindow()));
  ActionSelectDisplayWindow->setCheckable(true);
  if ( windowIndex == 2 ) {
    ActionSelectDisplayWindow->setChecked(true);
  }
  ActionFileOpen = new QAction("Open", this);
  connect(ActionFileOpen, SIGNAL(triggered()), this, SLOT(SlotFileOpen()));
}

/*****************************************************************************!
 * Function : CreateMenus
 * Purpose  : Create New Menus
 *****************************************************************************/
void
MainWindow::CreateMenus()
{
  QMenu*                                windowMenu;
  menubar = menuBar();  
  fileMenu = menubar->addMenu("&File");
  fileMenu->addAction(ActionFileOpen);
  
  fileMenu->addAction(ActionExit);
  windowMenu = menubar->addMenu("&Windows");
  windowMenu->addAction(ActionSelectJSONWindow);
  windowMenu->addAction(ActionSelectDisplayWindow);
}

/*****************************************************************************!
 * Function : SlotExit
 *****************************************************************************/
void
MainWindow::SlotExit(void)
{
  exit(EXIT_SUCCESS);  
}

/*****************************************************************************!
 * Function : SaveAtExit
 *****************************************************************************/
void
MainWindow::SaveAtExit
()
{
  displayWindow->SaveAtExit();
}

/*****************************************************************************!
 * Function : SlotSelectJSONWindow
 *****************************************************************************/
void
MainWindow::SlotSelectJSONWindow(void)
{
  ActionSelectDisplayWindow->setChecked(false);  
  emit SignalSelectWindow(1);
}

/*****************************************************************************!
 * Function : SlotSelectDisplayWindow
 *****************************************************************************/
void
MainWindow::SlotSelectDisplayWindow(void)
{
  ActionSelectJSONWindow->setChecked(false);
  emit SignalSelectWindow(2);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainWindow::CreateConnections()
{
  connect(this,
          SIGNAL(SignalSelectWindow(int)),
          displayWindow,
          SLOT(SlotSelectWindow(int)));
  connect(this,
          SIGNAL(SignalClearChildren()),
          displayWindow,
          SLOT(SlotClearChildren()));
  connect(this,
          SIGNAL(SignalSetMessageNormal(QString)),
          displayWindow,
          SLOT(SlotSetMessageNormal(QString)));
}

/*****************************************************************************!
 * Function : SlotFileOpen
 *****************************************************************************/
void
MainWindow::SlotFileOpen(void)
{
  QString                               fname;
  QString                               fileNameTmp;

  fileNameTmp = QFileDialog::getOpenFileName(this,
                                             tr("Open JSON File"),
                                             pathName,
                                             tr("JSON Files (*.json);;Any file (*)"));
  emit SignalClearChildren();
  filename = fileNameTmp;
  QFileInfo                             fileInfo(filename);

  pathName = fileInfo.path();
  fname = fileInfo.fileName();
  
  setWindowTitle(MainSystemConfig->GetSystemName() +
                 QString ( " : ") +
                 fname);
  setCursor(Qt::WaitCursor);
  emit SignalSetMessageNormal("Reading File");
  QCoreApplication::processEvents();
  displayWindow->OpenNewFile(filename);
  setCursor(Qt::ArrowCursor);
}
