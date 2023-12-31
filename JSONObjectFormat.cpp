/*****************************************************************************
 * FILE NAME    : JSONObjectFormat.cpp
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
#include "JSONObjectFormat.h"

/*****************************************************************************!
 * Function : JSONObjectFormat
 *****************************************************************************/
JSONObjectFormat::JSONObjectFormat
(
 QString                                InTag,
 QStringList                            InKeys
) : QWidget()
{
  keys = InKeys;
  tag = InTag;
  std::sort(keys.begin(), keys.end());
}

/*****************************************************************************!
 * Function : ~JSONObjectFormat
 *****************************************************************************/
JSONObjectFormat::~JSONObjectFormat
()
{
}

/*****************************************************************************!
 * Function : IsEqual
 *****************************************************************************/
bool
JSONObjectFormat::IsEqual
(QString InTag, QStringList InKeys)
{
  QStringList                           testKeys = InKeys;
  std::sort(testKeys.begin(), testKeys.end());

  if ( ! (tag == InTag) ) {
    return false;
  }

  if ( testKeys != keys ) {
    return false;
  }
  return true;
}

/*****************************************************************************!
 * Function : GetTag
 *****************************************************************************/
QString
JSONObjectFormat::GetTag(void)
{
  return tag;
}

/*****************************************************************************!
 * Function : GetKeys
 *****************************************************************************/
QStringList
JSONObjectFormat::GetKeys(void)
{
  return keys;
}
