/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"
#include "common.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::MainDisplayWindow
(QString InFilename, JSONObjectFormatList* InObjectsFormats) : QWidget()
{
  objectsFormats = InObjectsFormats;
  QPalette				pal;

  filename = InFilename;
  if ( ! filename.isEmpty() ) {
    HandleInputFilename();
  }
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(160, 160, 160)));
  setPalette(pal);
  setAutoFillBackground(true);

  Initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::~MainDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainDisplayWindow::Initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindow::InitializeSubWindows()
{
  splitter = NULL;
  tagWindow = NULL;
  fileWindow = NULL;
  elementWindow = NULL;
  objectDisplayWindow = NULL;
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  QList<int>                            widths;
  
  splitter = new MainSplitter();
  splitter->setParent(this);

  widths = MainSystemConfig->GetWindowWidths();

  fileWindow            = new JSONFileWindow(filename, baseFilename, mainJSONObject);
  tagWindow             = new MainTagWindow(mainJSONObject, objectsFormats);
  elementWindow         = new JSONElementWindow(objectsFormats);
  objectDisplayWindow   = new JSONFileObjectDisplayWindow();

  splitter->addWidget(fileWindow);
  splitter->addWidget(tagWindow);
  splitter->addWidget(elementWindow);
  splitter->addWidget(objectDisplayWindow);
  splitter->setSizes(widths);
  
  connect(elementWindow,
          SIGNAL(SignalTypeFormatSelected(QString)),
          this,
          SLOT(SlotFormatTypeSelected(QString)));

  connect(this, SIGNAL(SignalFormatTypeSelected(QString)),
          tagWindow,
          SLOT(SlotFormatTypeSelected(QString)));

  connect(fileWindow,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          this,
          SLOT(SlotFileObjectSelected(QJsonObject)));

  connect(this,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          objectDisplayWindow,
          SLOT(SlotFileObjectSelected(QJsonObject)));

  connect(objectDisplayWindow,
          SIGNAL(SignalFileElementSelected(QString, QList<QString>)),
          this,
          SLOT(SlotFileElementSelected(QString, QList<QString>)));

  connect(this,
          SIGNAL(SignalFileElementSelected(QString, QList<QString>)),
          elementWindow,
          SLOT(SlotFileElementSelected(QString, QList<QString>)));
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
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
  if ( splitter ) {
    splitter->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : HandleInputFilename
 *****************************************************************************/
void
MainDisplayWindow::HandleInputFilename(void)
{
  QJsonParseError                       jsonError;
  QByteArray                            array;
  QFileInfo                             fileinfo(filename);
  QFile                                 file(filename);

  if ( !file.open(QIODevice::ReadOnly) ) {
    fprintf(stderr, "Could not open %s\n", filename.toStdString().c_str());
    return;
  }
  array = file.readAll();
  file.close();
  jsonDoc = QJsonDocument::fromJson(array, &jsonError);
  if ( jsonDoc.isEmpty() ) {
    printf("JSON Parser error : %d : %s\n", jsonError.offset, jsonError.errorString().toStdString().c_str());
    return;
  }
  baseFilename = fileinfo.completeBaseName();
  mainJSONObject = jsonDoc.object();
}

/*****************************************************************************!
 * Function : SlotFormatTypeSelected
 *****************************************************************************/
void
MainDisplayWindow::SlotFormatTypeSelected
(QString InType)
{
  emit SignalFormatTypeSelected(InType);
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
MainDisplayWindow::SlotFileObjectSelected
(QJsonObject InObject)
{
  emit SignalFileObjectSelected(InObject);
}

/*****************************************************************************!
 * Function : SaveAtExit
 *****************************************************************************/
void
MainDisplayWindow::SaveAtExit
()
{
  QList<int>                    splitterSizes;
  QList<int>                    columnSizes;
  
  splitterSizes = splitter->sizes();

  columnSizes = fileWindow->GetColumnWidths();
  MainSystemConfig->SetWindowSizeInfo(0, splitterSizes[0], columnSizes);

  columnSizes = tagWindow->GetColumnWidths();
  MainSystemConfig->SetWindowSizeInfo(1, splitterSizes[1], columnSizes);

  columnSizes = elementWindow->GetColumnWidths();
  MainSystemConfig->SetWindowSizeInfo(2, splitterSizes[2], columnSizes);

  columnSizes = objectDisplayWindow->GetColumnWidths();
  MainSystemConfig->SetWindowSizeInfo(3, splitterSizes[3], columnSizes);

  MainSystemConfig->Save();
}

/*****************************************************************************!
 * Function : SlotFileElementSelected
 *****************************************************************************/
void
MainDisplayWindow::SlotFileElementSelected
(QString InTag, QList<QString> InKeys)
{
  emit SignalFileElementSelected(InTag, InKeys);
}

/*****************************************************************************!
 * Function : ResizeColumns
 *****************************************************************************/
void
MainDisplayWindow::ResizeColumns
()
{
  fileWindow->SetColumnWidths(MainSystemConfig->GetColumnWidths(0));
}


  
