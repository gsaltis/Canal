/*****************************************************************************
 * FILE NAME    : JSONElementWindow.cpp
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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONElementWindow.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : JSONElementWindow
 *****************************************************************************/
JSONElementWindow::JSONElementWindow
(
 JSONObjectFormatList*                  InObjectsFormats
) : QWidget()
{
  objectsFormats = InObjectsFormats;
  std::sort(objectsFormats->begin(), objectsFormats->end(),
            [] (JSONObjectFormat* InF1, JSONObjectFormat* InF2) {
              if ( InF1->GetTag() == InF2->GetTag() ) {
                return InF1->GetKeys().size() < InF2->GetKeys().size();
              }
              return InF1->GetTag() < InF2->GetTag();
            });
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONElementWindow
 *****************************************************************************/
JSONElementWindow::~JSONElementWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONElementWindow::initialize()
{
  InitializeSubWindows();
  CreateSubWindows();
  header->SetInnerCount(elementTree->topLevelItemCount());
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONElementWindow::CreateSubWindows()
{
  elementTree = new JSONObjectElementTree(objectsFormats);  
  elementTree->setParent(this);
  header = new JSONElementWindowSectionHeader();
  header->setParent(this);
  header->SetText("OBJECTS");
  
#if 0
  connect(elementTree, JSONObjectElementTree::SignalTypeSelected,
          this, JSONElementWindow::SlotTypeFormatSelected);
#endif
  connect(this,
          SIGNAL(SignalFileElementSelected(QString, QList<QString>)),
          elementTree,
          SLOT(SlotFileElementSelected(QString, QList<QString>)));
  
  connect(this,
          SIGNAL(SignalFileElementIdentified(QString, QList<QString>)),
          elementTree,
          SLOT(SlotObjectFormatIdentified(QString, QList<QString>)));
  
  connect(this,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          elementTree,
          SLOT(SlotFileObjectSelected(QJsonObject)));
  
  connect(elementTree,
          SIGNAL(SignalTypeSelected(QString)),
          this,
          SLOT(SlotTypeFormatSelected(QString)));

  connect(elementTree,
          SIGNAL(SignalObjectFormatSelected(JSONObjectFormat*)),
          this,
          SLOT(SlotObjectFormatSelected(JSONObjectFormat*)));
  connect(this,
          SIGNAL(SignalClearChildren()),
          elementTree,
          SLOT(SlotClearChildren()));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONElementWindow::InitializeSubWindows()
{
  elementTree = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONElementWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;
  int                                   elementTreeH;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();
  elementTreeH = height - SECTION_HEADER_HEIGHT;
  
  if ( elementTree ) {
    elementTree->move(0, SECTION_HEADER_HEIGHT);
    elementTree->resize(width, elementTreeH);
  }
  if ( header ) {
    header->move(0, 0);
    header->resize(width, SECTION_HEADER_HEIGHT);
  }
}

/*****************************************************************************!
 * Function : SlotTypeFormatSelected
 *****************************************************************************/
void
JSONElementWindow::SlotTypeFormatSelected
(QString InType)
{
  emit SignalTypeFormatSelected(InType);
}

/*****************************************************************************!
 * Function : SlotFileElementSelected
 *****************************************************************************/
void
JSONElementWindow::SlotFileElementSelected
(QString InTag, QList<QString> InKeys)
{
  emit SignalFileElementSelected(InTag, InKeys);
}

/*****************************************************************************!
 * 
 *****************************************************************************/
QList<int>
JSONElementWindow::GetColumnWidths
()
{
  int                                   i;
  int                                   n;
  QList<int>                            widths;
  
  n = elementTree->columnCount();
  for (i = 0; i < n; i++) {
    widths << elementTree->columnWidth(i);
  }
  return widths;
}

/*****************************************************************************!
 * Function : SlotObjectFormatSelected
 *****************************************************************************/
void
JSONElementWindow::SlotObjectFormatSelected
(JSONObjectFormat* InObjectFormat)
{
  emit(SignalObjectFormatSelected(InObjectFormat));
}

/*****************************************************************************!
 * Function : SlotObjectFormatIdentified
 *****************************************************************************/
void
JSONElementWindow::SlotObjectFormatIdentified
(QString InTag, QStringList InKeys)
{
  emit SignalFileElementIdentified(InTag, InKeys);
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONElementWindow::SlotFileObjectSelected
(QJsonObject InObject)
{
  emit SignalFileObjectSelected(InObject);
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
JSONElementWindow::SlotClearChildren(void)
{
  emit SignalClearChildren();
}

/*****************************************************************************!
 * Function : OpenNewFile
 *****************************************************************************/
void
JSONElementWindow::OpenNewFile
()
{
  elementTree->DisplayObjectFormats();
  header->SetInnerCount(elementTree->topLevelItemCount());
}
