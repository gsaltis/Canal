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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayJSONTreesWindow.h"
#include "common.h"

/*****************************************************************************!
 * Function : MainDisplayJSONTreesWindow
 *****************************************************************************/
MainDisplayJSONTreesWindow::MainDisplayJSONTreesWindow
(QWidget* InParent, QString InFilename, QString InBaseFilename, QJsonObject InMainJSONObject, JSONObjectFormatList* InObjectsFormats) :
  QWidget(InParent)
{
  QPalette pal;
  filename = InFilename;
  
  QFileInfo                             fileinfo(filename);

  mainJSONObject = InMainJSONObject;
  
  objectsFormats = InObjectsFormats;
  baseFilename = InBaseFilename;
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

  fileWindow            = new JSONFileWindow(filename, baseFilename, mainJSONObject);
  elementsWindow        = new MainTagWindow(mainJSONObject, objectsFormats);
  objectsWindow         = new JSONElementWindow(objectsFormats);
  objectDisplayWindow   = new JSONFileObjectDisplayWindow();

  splitter->addWidget(fileWindow);
  splitter->addWidget(elementsWindow);
  splitter->addWidget(objectsWindow);
  splitter->addWidget(objectDisplayWindow);
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

  connect(this,
          SIGNAL(SignalCallingFunctionFound(QString)),
          fileWindow,
          SLOT(SlotCallingFunctionFound(QString)));
  
  connect(objectsWindow,
          SIGNAL(SignalTypeFormatSelected(QString)),
          this,
          SLOT(SlotFormatTypeSelected(QString)));

  connect(this, SIGNAL(SignalFormatTypeSelected(QString)),
          elementsWindow,
          SLOT(SlotFormatTypeSelected(QString)));

  connect(fileWindow,
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

