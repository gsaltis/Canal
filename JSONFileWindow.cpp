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
#include <QHeaderView>

#define TRACE_USE
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileWindow.h"
#include "Trace.h"
#include "common.h"

/*****************************************************************************!
 * Function : JSONFileWindow
 *****************************************************************************/
JSONFileWindow::JSONFileWindow
(TranslationUnitObject* InTranslationUnit) : QWidget()
{
  QPalette pal;

  TranslationUnit = InTranslationUnit;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 0, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
  fileTree->Set(TranslationUnit);
  SetColumnWidths(MainSystemConfig->GetColumnWidths(0));
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
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
JSONFileWindow::CreateConnections()
{
  connect(callTreeWindow,
          SIGNAL(SignalCallingFunctionObjectSelected(QJsonObject)),
          this,
          SLOT(SlotFileObjectSelected(QJsonObject)));

  connect(fileTree,
          SIGNAL(SignalFileObjectClicked()),
          callTreeWindow,
          SLOT(SlotClearLocal()));
  
  connect(fileTree,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          this,
          SLOT(SlotFileObjectSelected(QJsonObject)));
  connect(fileTree,
          SIGNAL(SignalFileObjectClicked()),
          this,
          SLOT(SlotFileObjectClicked()));
  connect(this,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          callTreeWindow,
          SLOT(SlotFunctionSelected(QJsonObject)));
  connect(this,
          SIGNAL(SignalCallingFunctionFound(QString)),
          callTreeWindow,
          SLOT(SlotCallingFunctionFound(QString)));
  connect(header,
          SIGNAL(SignalSizeValueChanged(int)),
          this,
          SLOT(SlotSizeValueChanged(int)));
  connect(this,
          SIGNAL(SignalSizeValueChanged(int)),
          fileTree,
          SLOT(SlotSizeValueChanged(int)));
  connect(fileTree,
          SIGNAL(SignalLocalCountSet(int)),
          this,
          SLOT(SlotLocalCountSet(int)));
  connect (this,
           SIGNAL(SignalCallingFunctionFound(QString)),
           fileTree,
           SLOT(SlotCallingFunctionFound(QString)));
  connect(this,
          SIGNAL(SignalClearChildren()),
          fileTree,
          SLOT(SlotClearChildren()));
  connect(this,
          SIGNAL(SignalClearChildren()),
          callTreeWindow,
          SLOT(SlotClearChildren()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileWindow::CreateSubWindows()
{
  fileTree = new JSONFileTree();
  fileTree->setParent(this);
  header = new JSONFileWindowSectionHeader();
  header->SetText("TRANSLATION UNIT");
  header->setParent(this);
  callTreeWindow = new CallTreeWindow(TranslationUnit);
  callTreeWindow->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileWindow::InitializeSubWindows()
{
  fileTree = NULL;  
  header = NULL;
  callTreeWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   callTreeWindowH;
  int                                   callTreeWindowY;
  int                                   callTreeWindowW;
  int                                   callTreeWindowX;
  QSize                                 size;  
  int                                   width;
  int                                   height;
  int                                   fileTreeH;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();
  fileTreeH = height - (SECTION_HEADER_HEIGHT + CALL_TREE_WINDOW_HEIGHT);

  callTreeWindowX = 0;
  callTreeWindowH = CALL_TREE_WINDOW_HEIGHT;
  callTreeWindowY = height - CALL_TREE_WINDOW_HEIGHT;
  callTreeWindowW = width;
  
  if ( fileTree ) {
    fileTree->move(0, SECTION_HEADER_HEIGHT);
    fileTree->resize(width, fileTreeH);
  }
  if ( header ) {
    header->move(0, 0);
    header->resize(width, SECTION_HEADER_HEIGHT);
  }
  if ( callTreeWindow ) {
    callTreeWindow->move(callTreeWindowX, callTreeWindowY);
    callTreeWindow->resize(callTreeWindowW, callTreeWindowH);
  }
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONFileWindow::SlotFileObjectSelected
(QJsonObject InObject)
{
  TRACE_FUNCTION_LOCATION();
  emit SignalFileObjectSelected(InObject);
}

/*****************************************************************************!
 * Function : GetColumnWidths
 *****************************************************************************/
QList<int>
JSONFileWindow::GetColumnWidths(void)
{
  int                                   i;
  int                                   n;
  QList<int>                            widths;
  
  n = fileTree->columnCount();
  for (i = 0; i < n; i++) {
    widths << fileTree->columnWidth(i);
  }
  return widths;
}

/*****************************************************************************!
 * Function : SetColumnWidths
 *****************************************************************************/
void
JSONFileWindow::SetColumnWidths
(QList<int> InWidths)
{
  fileTree->setColumnWidth(0, InWidths[0]);
  fileTree->setColumnWidth(1, InWidths[1]);
}

/*****************************************************************************!
 * Function : SlotSizeValueChanged
 *****************************************************************************/
void
JSONFileWindow::SlotSizeValueChanged
(int InSize)
{
  emit SignalSizeValueChanged(InSize);
}

/*****************************************************************************!
 * Function : SlotLocalCountSet
 *****************************************************************************/
void
JSONFileWindow::SlotLocalCountSet
(int InLocalCount)
{
  header->SetInnerCount(InLocalCount);
}

/*****************************************************************************!
 * Function : SlotCallingFunctionFound
 *****************************************************************************/
void
JSONFileWindow::SlotCallingFunctionFound
(QString InFunctionName)
{
  emit SignalCallingFunctionFound(InFunctionName);
}


/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
JSONFileWindow::SlotClearChildren(void)
{
  TRACE_FUNCTION_LOCATION();
  emit SignalClearChildren();
}

/*****************************************************************************!
 * Function : OpenNewFile
 *****************************************************************************/
void
JSONFileWindow::OpenNewFile
(TranslationUnitObject* InTranslationUnit)
{
  TranslationUnit = InTranslationUnit;
  fileTree->Set(TranslationUnit);
}

/*****************************************************************************!
 * Function : SlotFileObjectClicked
 *****************************************************************************/
void
JSONFileWindow::SlotFileObjectClicked(void)
{
  emit SignalFileObjectClicked();
}
