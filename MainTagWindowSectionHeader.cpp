/*****************************************************************************
 * FILE NAME    : MainTagWindowSectionHeader.cpp
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
#include "MainTagWindowSectionHeader.h"

/*****************************************************************************!
 * Function : MainTagWindowSectionHeader
 *****************************************************************************/
MainTagWindowSectionHeader::MainTagWindowSectionHeader
() : JSONFileWindowSectionHeader()
{
  initialize();
}

/*****************************************************************************!
 * Function : ~MainTagWindowSectionHeader
 *****************************************************************************/
MainTagWindowSectionHeader::~MainTagWindowSectionHeader
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainTagWindowSectionHeader::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainTagWindowSectionHeader::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainTagWindowSectionHeader::InitializeSubWindows()
{
  
}

