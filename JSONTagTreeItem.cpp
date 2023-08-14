/*****************************************************************************
 * FILE NAME    : JSONTagTreeItem.cpp
 * DATE         : August 13 2023
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
#include "JSONTagTreeItem.h"

/*****************************************************************************!
 * Function : JSONTagTreeItem
 *****************************************************************************/
JSONTagTreeItem::JSONTagTreeItem
(JSONTagElement* InElement) : QTreeWidgetItem()
{
  QJsonValue::Type                              type;
  QString                                       typeString;
  
  type = InElement->GetType();
  switch (type) {
    case QJsonValue::Bool : 
    {
      typeString = "Bool";
      break;
    }
    case QJsonValue::Double : 
    {
      typeString = "Double";
      break;
    }
    case QJsonValue::String : 
    {
      typeString = "String";
      break;
    }
    case QJsonValue::Object : 
    {
      typeString = "Object";
      break;
    }
    case QJsonValue::Array : 
    {
      typeString = "Array";
      break;
    }
    case QJsonValue::Null : 
    {
      typeString = "Null";
      break;
    }
    case QJsonValue::Undefined : 
    {
      typeString = "Undefined";
      break;
    }
  }
  QString t = InElement->GetTag();
  setText(0, t);
  setText(1, typeString);
}

/*****************************************************************************!
 * Function : ~JSONTagTreeItem
 *****************************************************************************/
JSONTagTreeItem::~JSONTagTreeItem
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONTagTreeItem::initialize()
{
  setText(0, tag);
}

