/*****************************************************************************
 * FILE NAME    : JSONFileTree.cpp
 * DATE         : August 12 2023
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
#include "JSONFileTree.h"
#include "JSONFileTreeItem.h"
#include "JSONFileTreeHeader.h"

/*****************************************************************************!
 * Function : JSONFileTree
 *****************************************************************************/
JSONFileTree::JSONFileTree
(
 QJsonObject                            InJSONFileObject,
 QString                                InFilename,
 QString                                InBaseFilename
) : QTreeWidget()
{
  QTreeWidgetItem*                      head;
  QPalette pal;
  QBrush                                brush(QColor("black"));
  QHeaderView*                          h;
  
  head = new QTreeWidgetItem();

  head->setText(0, "TAG");
  head->setBackground(0, brush);
  
  head->setText(1, "VALUE");
  head->setBackground(1, brush);

  h = header();
  setHeaderItem(head);
  h->setStretchLastSection(true);
  setHeader(h);
  baseFilename = InBaseFilename;
  filename = InFilename;
  JSONFileObject = InJSONFileObject;

  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileTree
 *****************************************************************************/
JSONFileTree::~JSONFileTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileTree::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  setColumnCount(2);
  QStringList                           keys;

  keys = JSONFileObject.keys();
  
  for ( int i = 0 ; i < keys.size() ; i++ ) {
    JSONFileTreeItem*                   item = new JSONFileTreeItem();
    QJsonValue                          value = JSONFileObject[keys[i]];
    
    item->setText(0, keys[i]);
    if ( value.isString() ) {
      item->setText(1, value.toString());
    } else if ( value.isDouble() ) {
      QString s = QString("%1").arg(value.toInt());
      item->setText(1, s);
    }
    addTopLevelItem(item);
    if ( keys[i] == "inner" ) {
      SetInnerItem(item, &value);
    }
  }
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileTree::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : SetInnerItem
 *****************************************************************************/
void
JSONFileTree::SetInnerItem
(JSONFileTreeItem* InItem, QJsonValue* InValue)
{
  QString                               name;
  QString                               kind;
  int                                   n;
  QJsonArray                            array;

  array = InValue->toArray();
  n = array.size();
  for (int i = 0; i < n; i++) {
    QJsonValue                          v = array[i];
    QJsonObject                         obj = v.toObject();
    JSONFileTreeItem*                   item;
    
    kind = obj["kind"].toString();
    name = obj["name"].toString();
    item = new JSONFileTreeItem();
    item->setText(0, kind);
    item->setText(1, name);
    InItem->addChild(item);
    if ( kind == "FunctionDecl" ) {
      AddInnerObject(item, obj);
    }
  }
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileTree::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileTree::resizeEvent
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

/*****************************************************************************!
 * Function : AddInnerObject
 *****************************************************************************/
void
JSONFileTree::AddInnerObject
(JSONFileTreeItem* InItem, QJsonObject InObject)
{
  QStringList                           keys;
  keys = InObject.keys();
  
  for ( int i = 0 ; i < keys.size() ; i++ ) {
    JSONFileTreeItem*                   item = new JSONFileTreeItem();
    QJsonValue                          value = InObject[keys[i]];
    
    item->setText(0, keys[i]);
    if ( value.isString() ) {
      item->setText(1, value.toString());
    } else if ( value.isDouble() ) {
      QString s = QString("%1").arg(value.toInt());
      item->setText(1, s);
    }
    InItem->addChild(item);
    if ( keys[i] == "loc" ) {
      AddInnerObject(item, value.toObject());
      continue;
    }
    if ( keys[i] == "range" ) {
      AddInnerObject(item, value.toObject());
      continue;
    }
    if ( keys[i] == "inner" ) {
      SetInnerItem(item, &value);
    }
  }
}

  