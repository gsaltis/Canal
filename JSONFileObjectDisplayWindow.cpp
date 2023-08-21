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
#include "Trace.h"

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
  connect(fileTree,
          SIGNAL(SignalFileElementIdentified(QString, QList<QString>)),
          this,
          SLOT(SlotObjectFormatIdentified(QString, QList<QString>)));
  header = new SectionHeader();
  header->setParent(this);

  connect(this,
          SIGNAL(SignalExpandTree()),
          fileTree,
          SLOT(SlotExpandTree()));
  
  ExpandButton = new QPushButton("Expand", header);
  ExpandButton->resize(60, 20);
  connect(ExpandButton,
          SIGNAL(clicked(bool)),
          this,
          SLOT(SlotExpandButtonClicked(bool)));
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
  int                                   ExpandButtonX;
  int                                   ExpandButtonW;
  int                                   fileTreeH;
  QSize                                 size;  
  int                                   width;
  int                                   height;

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

  ExpandButtonW = ExpandButton->size().width();
  ExpandButtonX = width - (ExpandButtonW + 5);
  ExpandButton->move(ExpandButtonX, 1);
  ExpandButton->resize(ExpandButtonW, SECTION_HEADER_HEIGHT - 2);
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
  fileObject = InObject;
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

/*****************************************************************************!
 * 
 *****************************************************************************/
QList<int>
JSONFileObjectDisplayWindow::GetColumnWidths
()
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
 * Function : SlotObjectFormatSelected
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotObjectFormatSelected
(JSONObjectFormat* InObjectFormat)
{
  (void)InObjectFormat;
}

/*****************************************************************************!
 * Function : SlotObjectFormatIdentified
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotObjectFormatIdentified
(QString InTag, QStringList InKeys)
{
  emit SignalFileElementIdentified(InTag, InKeys);  
}

/*****************************************************************************!
 * Function : SlotExpandButtonClicked
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotExpandButtonClicked
(bool)
{
  emit SignalExpandTree();
}
