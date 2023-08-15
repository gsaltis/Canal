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
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  splitter = new MainSplitter();
  splitter->setParent(this);

  tagWindow = new MainTagWindow(mainJSONObject, objectsFormats);
  fileWindow = new JSONFileWindow(filename, baseFilename, mainJSONObject);
  elementWindow = new JSONElementWindow(objectsFormats);

  splitter->addWidget(tagWindow);
  splitter->addWidget(fileWindow);
  splitter->addWidget(elementWindow );

  connect(elementWindow, JSONElementWindow::SignalTypeFormatSelected,
          this, MainDisplayWindow::SlotFormatTypeSelected);
  connect(this, MainDisplayWindow::SignalFormatTypeSelected,
          tagWindow, MainTagWindow::SlotFormatTypeSelected);
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
