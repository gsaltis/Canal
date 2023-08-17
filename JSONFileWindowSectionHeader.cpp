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
}
