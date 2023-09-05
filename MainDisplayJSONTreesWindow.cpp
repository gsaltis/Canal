/*****************************************************************************
 * FILE NAME    : MainDisplayJSONTreesWindow.cpp
 * DATE         : August 21 2023
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
#include "MainDisplayJSONTreesWindow.h"
#include "common.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : MainDisplayJSONTreesWindow
 *****************************************************************************/
MainDisplayJSONTreesWindow::MainDisplayJSONTreesWindow
(QWidget* InParent, TranslationUnitObject* InTranslationUnit) : QWidget(InParent)
{
  QPalette pal;
  TranslationUnit = InTranslationUnit;
  
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 0, 0)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayJSONTreesWindow
 *****************************************************************************/
MainDisplayJSONTreesWindow::~MainDisplayJSONTreesWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::CreateSubWindows()
{
  QList<int>                            widths;
  splitter = new MainSplitter();
  splitter->setParent(this);

  widths = MainSystemConfig->GetWindowWidths();

  translationUnitWindow = new JSONFileWindow(TranslationUnit);
  elementsWindow        = new MainTagWindow(TranslationUnit);
  objectsWindow         = new JSONElementWindow(TranslationUnit);
  objectDisplayWindow   = new JSONFileObjectDisplayWindow(TranslationUnit);

  splitter->addWidget(translationUnitWindow);
  splitter->addWidget(elementsWindow);
  splitter->addWidget(objectsWindow);
  splitter->addWidget(objectDisplayWindow);
  splitter->setSizes(widths);
}

/*****************************************************************************!
 * Function : SaveSplitterSizes
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SaveSplitterSizes
()
{
  QList<int>                    splitterSizes;
  QList<int>                    columnSizes;

  splitterSizes = splitter->sizes();

  columnSizes = translationUnitWindow->GetColumnWidths();
  MainSystemConfig->SetWindowSizeInfo(0, splitterSizes[0], columnSizes);

  columnSizes = elementsWindow->GetColumnWidths();
  MainSystemConfig->SetWindowSizeInfo(1, splitterSizes[1], columnSizes);

  columnSizes = objectsWindow->GetColumnWidths();
  MainSystemConfig->SetWindowSizeInfo(2, splitterSizes[2], columnSizes);

  columnSizes = objectDisplayWindow->GetColumnWidths();
  MainSystemConfig->SetWindowSizeInfo(3, splitterSizes[3], columnSizes);

  MainSystemConfig->Save();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
  if ( splitter ) {
    splitter->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::CreateConnections(void)
{

  connect(objectDisplayWindow,
          SIGNAL(SignalCallingFunctionFound(QString)),
          this,
          SLOT(SlotCallingFunctionFound(QString)));

  connect(objectDisplayWindow,
          SIGNAL(SignalNormalMessage(QString)),
          this,
          SLOT(SlotNormalMessage(QString)));

  connect(this,
          SIGNAL(SignalCallingFunctionFound(QString)),
          translationUnitWindow,
          SLOT(SlotCallingFunctionFound(QString)));
  
  connect(objectsWindow,
          SIGNAL(SignalTypeFormatSelected(QString)),
          this,
          SLOT(SlotFormatTypeSelected(QString)));

  connect(this,
          SIGNAL(SignalFormatTypeSelected(QString)),
          elementsWindow,
          SLOT(SlotFormatTypeSelected(QString)));
  
  connect(translationUnitWindow,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          this,
          SLOT(SlotFileObjectSelected(QJsonObject)));

  connect(this,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          objectDisplayWindow,
          SLOT(SlotFileObjectSelected(QJsonObject)));

  connect(this,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          objectsWindow,
          SLOT(SlotFileObjectSelected(QJsonObject)));
  
  connect(objectDisplayWindow,
          SIGNAL(SignalFileElementSelected(QString, QList<QString>)),
          this,
          SLOT(SlotFileElementSelected(QString, QList<QString>)));

  connect(this,
          SIGNAL(SignalFileElementSelected(QString, QList<QString>)),
          objectsWindow,
          SLOT(SlotFileElementSelected(QString, QList<QString>)));

  connect(objectsWindow,
          SIGNAL(SignalObjectFormatSelected(JSONObjectFormat*)),
          this,
          SLOT(SlotObjectFormatSelected(JSONObjectFormat*)));

  connect(this,
          SIGNAL(SignalObjectFormatSelected(JSONObjectFormat*)),
          objectDisplayWindow,
          SLOT(SlotObjectFormatSelected(JSONObjectFormat*)));

  connect(objectDisplayWindow,
          SIGNAL(SignalFileElementIdentified(QString, QList<QString>)),
          this,
          SLOT(SlotObjectFormatIdentified(QString, QList<QString>)));
  connect(this,
          SIGNAL(SignalFileElementIdentified(QString, QList<QString>)),
          objectsWindow,
          SLOT(SlotObjectFormatIdentified(QString, QList<QString>)));

  connect(this,
          SIGNAL(SignalClearChildren()),
          translationUnitWindow,
          SLOT(SlotClearChildren()));

  connect(this,
          SIGNAL(SignalClearChildren()),
          elementsWindow,
          SLOT(SlotClearChildren()));

  connect(this,
          SIGNAL(SignalClearChildren()),
          objectsWindow,
          SLOT(SlotClearChildren()));
  connect(this,
          SIGNAL(SignalClearChildren()),
          objectDisplayWindow,
          SLOT(SlotClearChildren()));

  connect(objectDisplayWindow,
          SIGNAL(SignalProgressBarShow()),
          this,
          SLOT(SlotProgressBarShow()));
  
  connect(objectDisplayWindow,
          SIGNAL(SignalProgressBarHide()),
          this,
          SLOT(SlotProgressBarHide()));
  
  connect(objectDisplayWindow,
          SIGNAL(SignalProgressBarSet(int, int)),
          this,
          SLOT(SlotProgressBarSet(int, int)));
  
  connect(objectDisplayWindow,
          SIGNAL(SignalProgressBarUpdate(int)),
          this,
          SLOT(SlotProgressBarUpdate(int)));
  
}

/*****************************************************************************!
 * Function : SlotFormatTypeSelected
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotFormatTypeSelected
(QString InType)
{
  emit SignalFormatTypeSelected(InType);
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotFileObjectSelected
(QJsonObject InObject)
{
  emit SignalFileObjectSelected(InObject);
}

/*****************************************************************************!
 * Function : SlotFileElementSelected
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotFileElementSelected
(QString InTag, QList<QString> InKeys)
{
  emit SignalFileElementSelected(InTag, InKeys);
}

/*****************************************************************************!
 * Function : SlotObjectFormatSelected
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotObjectFormatSelected
(JSONObjectFormat* InObjectFormat)
{
  emit SignalObjectFormatSelected(InObjectFormat);
}

/*****************************************************************************!
 * Function : SlotObjectFormatIdentified
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotObjectFormatIdentified
(QString InTag, QStringList InKeys)
{
  emit SignalFileElementIdentified(InTag, InKeys);
}

/*****************************************************************************!
 * Function : SlotCallingFunctionFound
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotCallingFunctionFound
(QString InFunctionName)
{
  emit SignalCallingFunctionFound(InFunctionName);
}

/*****************************************************************************!
 * Function : SaveAtExit 
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SaveAtExit
()
{
  SaveSplitterSizes();  
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotClearChildren(void)
{
  emit SignalClearChildren();
}

/*****************************************************************************!
 * Function : OpenNewFile
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::OpenNewFile
(TranslationUnitObject* InTranslationUnit)
{
  TranslationUnit = InTranslationUnit;
  translationUnitWindow->OpenNewFile(TranslationUnit);
  elementsWindow->OpenNewFile(TranslationUnit);
  objectsWindow->OpenNewFile(TranslationUnit);
  objectDisplayWindow->OpenNewFile(TranslationUnit);
}

/*****************************************************************************!
 * Function : SlotNormalMessage
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotNormalMessage(QString InMessage)
{
  emit SignalNormalMessage(InMessage);
}

/*****************************************************************************!
 * Function : SlotProgressBarShow
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotProgressBarShow(void)
{
  emit SignalProgressBarShow();  
}

/*****************************************************************************!
 * Function : SlotProgressBarHide
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotProgressBarHide(void)
{
  emit SignalProgressBarHide();
}

/*****************************************************************************!
 * Function : SlotProgressBarSet
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotProgressBarSet
(int InMinimum, int InMaximum)
{
  emit SignalProgressBarSet(InMinimum, InMaximum);
}

/*****************************************************************************!
 * Function : SlotProgressBarUpdate
 *****************************************************************************/
void
MainDisplayJSONTreesWindow::SlotProgressBarUpdate
(int InValue)
{
  emit SignalProgressBarUpdate(InValue);
}
