/*****************************************************************************
 * FILE NAME    : JSONTagElementList.cpp
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
#include "JSONTagElementList.h"

/*****************************************************************************!
 * Function : JSONTagElementList
 *****************************************************************************/
JSONTagElementList::JSONTagElementList
()
{
}

/*****************************************************************************!
 * Function : ~JSONTagElementList
 *****************************************************************************/
JSONTagElementList::~JSONTagElementList
()
{
}

/*****************************************************************************!
 * Function : HasElement
 *****************************************************************************/
bool
JSONTagElementList::HasElement
(QString InTag, QJsonValue::Type InType)
{
  for ( auto i = begin() ; i != end()  ; i++ ) {
    JSONTagElement*                     element = *i;

    if ( element->Equals(InTag, InType) ) {
      return true;
    }
  }
  return false;
}
