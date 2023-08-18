/*****************************************************************************
 * FILE NAME    : JSONFileWindowSectionHeader.cpp
 * DATE         : August 17 2023
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
#include "JSONFileWindowSectionHeader.h"
#include "JSONFileWindowDialog.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : JSONFileWindowSectionHeader
 *****************************************************************************/
JSONFileWindowSectionHeader::JSONFileWindowSectionHeader
() : SectionHeader()
{
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileWindowSectionHeader
 *****************************************************************************/
JSONFileWindowSectionHeader::~JSONFileWindowSectionHeader
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileWindowSectionHeader::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  ActionResizePushed = new QAction("ResizePushed", this);
  connect(ActionResizePushed, SIGNAL(triggered()), this, SLOT(SlotResizePushed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileWindowSectionHeader::CreateSubWindows()
{
  //! Create the Resize button  
  ResizeButton = new QPushButton();
  ResizeButton->setParent(this);
  ResizeButton->setText("RESIZE");
  ResizeButton->move(100, 2);
  ResizeButton->resize(60,20);
  connect(ResizeButton, SIGNAL(pressed()), this, SLOT(SlotResizePushed()));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileWindowSectionHeader::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileWindowSectionHeader::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  HeaderText->resize(width - HeaderText->pos().x(), height);
  ResizeButton->move(width - (5 + ResizeButton->size().width()), 2);
}

/*****************************************************************************!
 * Function : SlotResizePushed
 *****************************************************************************/
void
JSONFileWindowSectionHeader::SlotResizePushed(void)
{
  JSONFileWindowDialog*                 dialog;

  dialog = new JSONFileWindowDialog();
  connect(dialog,
          SIGNAL(SignalSizeValueChanged(int)),
          this,
          SLOT(SlotSizeValueChanged(int)));
  
  dialog->exec();
  delete dialog;
}

/*****************************************************************************!
 * Function : SlotSizeValueChanged
 *****************************************************************************/
void
JSONFileWindowSectionHeader::SlotSizeValueChanged
(int InSize)
{
  emit SignalSizeValueChanged(InSize);
}
