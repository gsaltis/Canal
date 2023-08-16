/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayTreeItem.cpp
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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileObjectDisplayTreeItem.h"

/*****************************************************************************!
 * Function : JSONFileObjectDisplayTreeItem
 *****************************************************************************/
JSONFileObjectDisplayTreeItem::JSONFileObjectDisplayTreeItem
(QString InTag, QJsonValue InValue) : QTreeWidgetItem()
{
  QBrush                                b;
  value = InValue;
  tag = InTag;

  setFont(0, QFont("Segoe UI", -1, QFont::Medium));
  b = QBrush(QColor(0, 0, 128));
  setText(0, tag);
  switch (value.type()) {
    case QJsonValue::Bool : {
      setText(1, QString("%1").arg(value.toBool() ? "true" : "false"));
      break;
    }
    case QJsonValue::String : {
      setText(1, value.toString());
      break;
    }
    case QJsonValue::Object : {
      b = QBrush(QColor(128, 0, 0));
      HandleObject(value.toObject());
      break;
    }
    case QJsonValue::Array : {
      b = QBrush(QColor(0, 128, 0));
      HandleArray(value.toArray());
      break;
    }
    case QJsonValue::Double : {
      int                       i;
      double                    d;

      d = InValue.toDouble();
      if ( d != 0 ) {
        setText(1, QString("%1").arg(d));
        break;
      }
      i = InValue.toInt();
      setText(1, QString("%1").arg(i));
      break;
    }
    case QJsonValue::Null : {
      setText(1, QString("null"));
      break;
    }
    case QJsonValue::Undefined : {
      break;
    }
  }
  setForeground(0, b);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileObjectDisplayTreeItem
 *****************************************************************************/
JSONFileObjectDisplayTreeItem::~JSONFileObjectDisplayTreeItem
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileObjectDisplayTreeItem::initialize()
{
}

/*****************************************************************************!
 * Function : HandleObject
 *****************************************************************************/
void
JSONFileObjectDisplayTreeItem::HandleObject
(QJsonObject InObject)
{
  JSONFileObjectDisplayTreeItem*        item;
  QStringList                           keys;
  QString                               tag;
  QJsonValue                            value;
  
  keys = InObject.keys();
  for ( auto i = keys.begin(); i != keys.end(); i++ ) {
    tag = *i;
    value = InObject[tag];
    item = new JSONFileObjectDisplayTreeItem(tag, value);
    addChild(item);
  }
}

/*****************************************************************************!
 * Function : HandleArray
 *****************************************************************************/
void
JSONFileObjectDisplayTreeItem::HandleArray
(QJsonArray InArray)
{
  JSONFileObjectDisplayTreeItem*        item;
  QString                               tag;
  QJsonValue                            value;
  
  for ( auto i = 0 ; i < InArray.count(); i++ ) {
    value = InArray[i];
    if ( value.isObject() ) {
      QJsonObject                       obj = value.toObject();
      QString                           kind;

      kind = obj["kind"].toString();
      if ( kind.isEmpty() ) {
        tag = QString("%1").arg(i);
      } else {
        tag = kind;
      }
    }
    item = new JSONFileObjectDisplayTreeItem(tag, value);
    addChild(item);
  }
}

