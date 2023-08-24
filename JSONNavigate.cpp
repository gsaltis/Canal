/*****************************************************************************
 * FILE NAME    : JSONNavigate.cpp
 * DATE         : August 23 2023
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
#include "JSONNavigate.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : JSONNavigate
 *****************************************************************************/
JSONNavigate::JSONNavigate
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~JSONNavigate
 *****************************************************************************/
JSONNavigate::~JSONNavigate
()
{
}

/*****************************************************************************!
 * Function : GetStringElement
 *****************************************************************************/
QString
JSONNavigate::GetStringElement
(QJsonObject InObject, QString InSearchString)
{
  QStringList                           st2;
  int                                   index;
  QJsonArray                            array;
  QJsonValue                            jsonValue;
  QJsonObject                           obj2;
  QString                               suffix;
  QString                               tag;
  QStringList                           tags;
  QStringList                           searchElements;
  QString                               value;
  bool                                  inObject;
  QJsonObject                           obj;
  int                                   n;
  QString                               rValue;
  bool                                  b;
  
  inObject = true;
  obj = InObject;
  
  searchElements = InSearchString.split(".");
  for ( auto i = searchElements.begin() ; i != searchElements.end() ; i++ ) {
    value = *i;
    n = value.length();
    suffix = value.last(2);
    tag = value.first(n - 2);
    tags = tag.split("|");
    if ( inObject ) {
      jsonValue = obj[tags[0]];
      if ( suffix == "[]" ) {
        inObject = false;
        array = jsonValue.toArray();
        continue;
      }
      if ( suffix == "{}" ) {
        obj = jsonValue.toObject();
        continue;
      }
      rValue = jsonValue.toString();
      break;
    }
    // inObject == false;
    index = tag.toInt(&b, 10);
    if ( b ) {
      jsonValue = array[index];
      if ( suffix == "{}" ) {
        obj = jsonValue.toObject();
        inObject = true;
        continue;
      }
      array = jsonValue.toArray();
      continue;
    }
    st2 = tag.split("|");
  }
  return rValue;
}
