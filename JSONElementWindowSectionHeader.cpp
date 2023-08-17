/*****************************************************************************
 * FILE NAME    : JSONElementWindowSectionHeader.cpp
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
#include "JSONElementWindowSectionHeader.h"

/*****************************************************************************!
 * Function : JSONElementWindowSectionHeader
 *****************************************************************************/
JSONElementWindowSectionHeader::JSONElementWindowSectionHeader
() : SectionHeader()
{
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONElementWindowSectionHeader
 *****************************************************************************/
JSONElementWindowSectionHeader::~JSONElementWindowSectionHeader
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONElementWindowSectionHeader::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONElementWindowSectionHeader::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONElementWindowSectionHeader::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONElementWindowSectionHeader::resizeEvent
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
}
