/*****************************************************************************
 * FILE NAME    : WindowSizeInfo.cpp
 * DATE         : August 18 2023
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
#include "WindowSizeInfo.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : WindowSizeInfo
 *****************************************************************************/
WindowSizeInfo::WindowSizeInfo
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~WindowSizeInfo
 *****************************************************************************/
WindowSizeInfo::~WindowSizeInfo
()
{
}

/*****************************************************************************!
 * Function : GetWindowWidth
 *****************************************************************************/
int
WindowSizeInfo::GetWindowWidth(void)
{
  return windowWidth;  
}

/*****************************************************************************!
 * Function : SetWindowWidth
 *****************************************************************************/
void
WindowSizeInfo::SetWindowWidth
(int InWindowWidth)
{
  windowWidth = InWindowWidth;  
}

/*****************************************************************************!
 * Function : GetColumnWidths
 *****************************************************************************/
std::vector<int>
WindowSizeInfo::GetColumnWidths(void)
{
  return columnWidths;  
}

/*****************************************************************************!
 * Function : SetColumnWidths
 *****************************************************************************/
void
WindowSizeInfo::SetColumnWidths
(std::vector<int> InColumnWidths)
{
  columnWidths = InColumnWidths;  
}

/*****************************************************************************!
 * Function : SetColumnWidths
 *****************************************************************************/
void
WindowSizeInfo::SetColumnWidths
(QList<int> InColumnWidths)
{
  columnWidths.clear();
  for ( int i = 0 ; i < InColumnWidths.size(); i++ ) {
    columnWidths.push_back(InColumnWidths[i]);
  }
}
