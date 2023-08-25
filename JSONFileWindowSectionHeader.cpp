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
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileWindowSectionHeader::CreateSubWindows()
{

  //! Create label
  ElementCountLabel = new QLabel();
  ElementCountLabel->setParent(this);
  ElementCountLabel->move(10, 3);
  ElementCountLabel->resize(100, 20);
  ElementCountLabel->setText("Count");
  ElementCountLabel->setAlignment(Qt::AlignRight);
  ElementCountLabel->setFont(QFont("Segoe UI", 12, QFont::Normal));
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
  int                                   headerW;
  QSize                                 size;  
  int                                   width;
  int                                   height;
  int                                   labelX;
  int                                   labelW;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  
  SetBackgroundColor(height);
  labelW = ElementCountLabel->size().width();
  labelX = width - (labelW + 5);
  headerW = width - (labelW + 10);
  
  HeaderText->resize(headerW, height);
  ElementCountLabel->resize(labelW, height);
  ElementCountLabel->move(labelX, ElementCountLabel->pos().y());
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

/*****************************************************************************!
 * Function : SetInnerCount
 *****************************************************************************/
void
JSONFileWindowSectionHeader::SetInnerCount
(int InCount)
{
  ElementCountLabel->setText(QString("%1").arg(InCount));
}
