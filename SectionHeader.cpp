/*****************************************************************************
 * FILE NAME    : SectionHeader.cpp
 * DATE         : August 16 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SectionHeader.h"
#include "common.h"

/*****************************************************************************!
 * Function : SectionHeader
 *****************************************************************************/
SectionHeader::SectionHeader
() : QFrame()
{
  QPalette pal;
  pal = palette();

  backgroundColor = MainSystemConfig->GetSectionHeaderBackgroundColor();
  textColor = QColor(Qt::white);
  pal.setBrush(QPalette::Window, QBrush(backgroundColor));
  setPalette(pal);
  setAutoFillBackground(true);
  setFrameShadow(QFrame::Sunken);
  setFrameShape(QFrame::Box);
  initialize();
}

/*****************************************************************************!
 * Function : ~SectionHeader
 *****************************************************************************/
SectionHeader::~SectionHeader
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SectionHeader::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SectionHeader::CreateSubWindows()
{
  QPalette                              pal;
  //! Create label
  HeaderText = new QLabel();
  HeaderText->setParent(this);
  HeaderText->move(5, 0);
  HeaderText->resize(100, 20);
  HeaderText->setText("None");
  HeaderText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  HeaderText->setFont(QFont("Segoe UI", 12, QFont::Normal));
  pal = HeaderText->palette();
  pal.setBrush(QPalette::WindowText, QColor(textColor));
  HeaderText->setPalette(pal);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SectionHeader::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SectionHeader::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();

  SetBackgroundColor(height);
  
  HeaderText->resize(width - HeaderText->pos().x(), height);
}

/*****************************************************************************!
 * Function : SetText
 *****************************************************************************/
void
SectionHeader::SetText
(QString InText)
{
  HeaderText->setText(InText);
}

/*****************************************************************************!
 * Function : SetBackgroundColor
 *****************************************************************************/
void
SectionHeader::SetBackgroundColor
(int InHeight)
{
  QPalette                              pal;
  QLinearGradient                       grad = QLinearGradient(0, 0, 0, InHeight);
  grad.setColorAt(0, backgroundColor.darker(135));
  grad.setColorAt(1, backgroundColor);
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(grad));
  setPalette(pal);
}

  
