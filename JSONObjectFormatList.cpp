/*****************************************************************************
 * FILE NAME    : JSONObjectFormatList.cpp
 * DATE         : August 14 2023
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
#include "JSONObjectFormatList.h"

/*****************************************************************************!
 * Function : JSONObjectFormatList
 *****************************************************************************/
JSONObjectFormatList::JSONObjectFormatList
()
{
}

/*****************************************************************************!
 * Function : ~JSONObjectFormatList
 *****************************************************************************/
JSONObjectFormatList::~JSONObjectFormatList
()
{
}

/*****************************************************************************!
 * Function : Contains
 *****************************************************************************/
bool
JSONObjectFormatList::Contains
(QString InTag, QStringList InKeys)
{
  for ( auto i = begin(); i != end() ; i++ ) {
    JSONObjectFormat*                   obj = *i;
    if ( obj->IsEqual(InTag, InKeys) ) {
      return true;
    }
  }
  return false;
}
