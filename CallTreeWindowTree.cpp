/*****************************************************************************
 * FILE NAME    : CallTreeWindowTree.cpp
 * DATE         : August 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

#define TRACE_USE
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CallTreeWindowTree.h"
#include "CallTreeWindowTreeItem.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : CallTreeWindowTree
 *****************************************************************************/
CallTreeWindowTree::CallTreeWindowTree
(TranslationUnitObject* InTranslationUnit) : QTreeWidget()
{
  QTreeWidgetItem*                      head;
  QPalette pal;
  TranslationUnit = InTranslationUnit;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);

  head = new QTreeWidgetItem();
  head->setText(0, "FUNCTION");
  setHeaderItem(head);
  resizeColumnToContents(0);
  
  initialize();
}

/*****************************************************************************!
 * Function : ~CallTreeWindowTree
 *****************************************************************************/
CallTreeWindowTree::~CallTreeWindowTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
CallTreeWindowTree::initialize()
{
  lastCallingFunctionSelected = NULL;
  locallyGenerated = false;
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
CallTreeWindowTree::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
CallTreeWindowTree::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
CallTreeWindowTree::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}

/*****************************************************************************!
 * Function : SlotFunctionSelected
 *****************************************************************************/
void
CallTreeWindowTree::SlotFunctionSelected
(QJsonObject InObject)
{
  if ( lastCallingFunctionSelected ) {
    return;
  }
  FunctionNameItem = new CallTreeWindowTreeItem(CALL_TREE_WINDOW_TREE_ITEM_TYPE_FUNCTION);
  FunctionNameItem->setText(0, InObject["name"].toString());
  clear();
  addTopLevelItem(FunctionNameItem);
}

/*****************************************************************************!
 * Function : SlotCallingFunctionFound
 *****************************************************************************/
void
CallTreeWindowTree::SlotCallingFunctionFound
(QString InFunctionName)
{
  QTreeWidgetItem*                      item;

  item = new CallTreeWindowTreeItem(CALL_TREE_WINDOW_TREE_ITEM_TYPE_CALLER);
  item->setText(0, InFunctionName);
  if ( lastCallingFunctionSelected ) {
    lastCallingFunctionSelected->addChild(item);
    lastCallingFunctionSelected->setExpanded(true);
    return;
  }
  FunctionNameItem->addChild(item);
  FunctionNameItem->setExpanded(true);
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
CallTreeWindowTree::SlotClearChildren(void)
{
  TRACE_FUNCTION_LOCATION();
  if ( ! locallyGenerated ) {
    clear();
  }
  locallyGenerated = false;
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
CallTreeWindowTree::CreateConnections(void)
{
  connect(this,
          SIGNAL(itemClicked(QTreeWidgetItem*, int)),
          this,
          SLOT(SlotItemSelected(QTreeWidgetItem*, int)));
}

/*****************************************************************************!
 * Function : SlotItemSelected
 *****************************************************************************/
void
CallTreeWindowTree::SlotItemSelected
(QTreeWidgetItem* InItem, int)
{
  QJsonObject                           obj;
  QString                               name;
  CallTreeWindowTreeItem*               item = (CallTreeWindowTreeItem*)InItem;
  int                                   type;

  locallyGenerated = true;
  type = item->GetType();
  if ( type != CALL_TREE_WINDOW_TREE_ITEM_TYPE_CALLER ) {
    return;
  }
  name = item->text(0);
  obj = TranslationUnit->FindFunctionDefinitionObjectByName(name);
  if ( obj.isEmpty() ) {
    return;
  }
  lastCallingFunctionSelected = item;
  if ( item->childCount() == 0 ) {
    emit SignalCallingFunctionObjectSelected(obj);
  }
}

/*****************************************************************************!
 * Function : ClearLocal
 *****************************************************************************/
void
CallTreeWindowTree::ClearLocal
()
{
  locallyGenerated = false;
  lastCallingFunctionSelected = NULL;
}
