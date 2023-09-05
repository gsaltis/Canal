/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayTab.cpp
 * DATE         : September 03 2023
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
#include "JSONFileObjectDisplayTab.h"
#include "TranslationUnitObject.h"
#include "Common.h"

/*****************************************************************************!
 * Function : JSONFileObjectDisplayTab
 *****************************************************************************/
JSONFileObjectDisplayTab::JSONFileObjectDisplayTab
(
 QJsonObject                            InElementObject
) : QWidget()
{
  QPalette pal;

  elementObject = InElementObject;
  name = TranslationUnitObject::GetFuncDeclName(elementObject);
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
  displayTree->SlotFileObjectSelected(elementObject);
}

/*****************************************************************************!
 * Function : ~JSONFileObjectDisplayTab
 *****************************************************************************/
JSONFileObjectDisplayTab::~JSONFileObjectDisplayTab
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileObjectDisplayTab::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayTab::CreateSubWindows()
{
  displayTree = new JSONFileObjectDisplayTree();  
  SetColumnWidths(MainSystemConfig->GetColumnWidths(3));
  displayTree->setParent(this);
}

/*****************************************************************************!
 * Function : SetColumnWidths
 *****************************************************************************/
void
JSONFileObjectDisplayTab::SetColumnWidths
(QList<int> InWidths)
{
  displayTree->setColumnWidth(0, InWidths[0]);
  displayTree->setColumnWidth(1, InWidths[1]);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayTab::InitializeSubWindows()
{
  displayTree = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileObjectDisplayTab::resizeEvent
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
  if ( displayTree ) {
    displayTree->move(0, 0);
    displayTree->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
JSONFileObjectDisplayTab::GetName(void)
{
  
  return name;
}

