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

#define TRACE_USE
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileObjectDisplayTreeItem.h"
#include "TranslationUnitObject.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : JSONFileObjectDisplayTreeItem
 *****************************************************************************/
JSONFileObjectDisplayTreeItem::JSONFileObjectDisplayTreeItem
(QString InTag, QJsonValue InValue) : QTreeWidgetItem()
{
  name = QString();
  value = InValue;
  tag = InTag;
  Create();
}

/*****************************************************************************!
 * Function : JSONFileObjectDisplayTreeItem
 *****************************************************************************/
JSONFileObjectDisplayTreeItem::JSONFileObjectDisplayTreeItem
(QString InTag, QString InName, QJsonValue InValue) : QTreeWidgetItem()
{
  name = InName;
  value = InValue;
  tag = InTag;
  Create();
}

/*****************************************************************************!
 * Function : Create
 *****************************************************************************/
void
JSONFileObjectDisplayTreeItem::Create
()
{
  QBrush                                b;
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
      if ( ! name.isEmpty() ) {
        setText(1, name);
        setFont(1, QFont("Segoe UI", -1, QFont::Bold));
      }
      b = QBrush(QColor(128, 0, 0));
      HandleObject(value.toObject());
      break;
    }
    case QJsonValue::Array : {
      setText(1, "");
      b = QBrush(QColor(0, 128, 0));
      HandleArray(value.toArray());
      break;
    }
    case QJsonValue::Double : {
      int                       i;
      double                    d;

      d = value.toDouble();
      if ( d != 0 ) {
        setText(1, QString("%1").arg(d));
        break;
      }
      i = value.toInt();
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
  setForeground(1, b);
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
  QString                               objName;
  JSONFileObjectDisplayTreeItem*        item;
  QStringList                           keys;
  QString                               tag;
  QJsonValue                            value;
  
  keys = InObject.keys();
  for ( auto i = keys.begin(); i != keys.end(); i++ ) {
    objName = QString();
    tag = *i;
    value = InObject[tag];
    if ( tag == "DeclStmt" ) {
      TRACE_FUNCTION_LOCATION();
      objName = TranslationUnitObject::GetDeclStmtName(value.toObject());
    }
    item = new JSONFileObjectDisplayTreeItem(tag, objName, value);
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
  QString                               name;

  for ( auto i = 0 ; i < InArray.count(); i++ ) {
    value = InArray[i];
    name = QString();
    if ( value.isObject() ) {
      QJsonObject                       obj = value.toObject();
      QString                           kind;

      kind = obj["kind"].toString();
      if ( kind.isEmpty() ) {
        tag = QString("%1").arg(i);
      } else {
        tag = kind;
        if ( kind == "ParmVarDecl" ) {
          name = obj["name"].toString();
        } else if ( kind == "DeclStmt" ) {
          name = TranslationUnitObject::GetDeclStmtName(value.toObject());
        } else if ( kind == "CallExpr" ) {
          name = TranslationUnitObject::GetCallExprName(value.toObject());
        } else if ( kind == "EnumConstantDecl" ) {
          name = TranslationUnitObject::GetEnumConstantDeclName(value.toObject());
        } else if ( kind == "FieldDecl" ) {
          name = TranslationUnitObject::GetFieldDeclName(value.toObject());
        }
      }
    }
    item = new JSONFileObjectDisplayTreeItem(tag, name, value);
    addChild(item);
  }
}

/*****************************************************************************!
 * Function : GetValue
 *****************************************************************************/
QJsonValue
JSONFileObjectDisplayTreeItem::GetValue(void)
{
  return value;
}
