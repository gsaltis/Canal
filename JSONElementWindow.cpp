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
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONElementWindow::CreateSubWindows()
{
  elementTree = new JSONObjectElementTree(objectsFormats);  
  elementTree->setParent(this);
#if 0
  connect(elementTree, JSONObjectElementTree::SignalTypeSelected,
          this, JSONElementWindow::SlotTypeFormatSelected);
#endif
  connect(elementTree,
          SIGNAL(SignalTypeSelected(QString)),
          this,
          SLOT(SlotTypeFormatSelected(QString)));
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
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  if ( elementTree ) {
    elementTree->resize(width, height);
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
