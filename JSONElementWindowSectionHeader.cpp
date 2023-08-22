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
() : JSONFileWindowSectionHeader()
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
