/*****************************************************************************
 * FILE NAME    : TranlationUnitObject.cpp
 * DATE         : August 31 2023
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
#include "TranlationUnitObject.h"

/*****************************************************************************!
 * Function : TranlationUnitObject
 *****************************************************************************/
TranlationUnitObject::TranlationUnitObject
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~TranlationUnitObject
 *****************************************************************************/
TranlationUnitObject::~TranlationUnitObject
()
{
}

/*****************************************************************************!
 * Function : GetFirstFunctionIndex
 *****************************************************************************/
int
TranlationUnitObject::GetFirstFunctionIndex(void)
{
  return firstFunctionIndex;  
}

/*****************************************************************************!
 * Function : SetFirstFunctionIndex
 *****************************************************************************/
void
TranlationUnitObject::SetFirstFunctionIndex
(int InFirstFunctionIndex)
{
  firstFunctionIndex = InFirstFunctionIndex;  
}

/*****************************************************************************!
 * Function : GetJSONObject
 *****************************************************************************/
QJsonObject
TranlationUnitObject::GetJSONObject(void)
{
  return JSONObject;  
}

/*****************************************************************************!
 * Function : SetJSONObject
 *****************************************************************************/
void
TranlationUnitObject::SetJSONObject
(QJsonObject InJSONObject)
{
  JSONObject = InJSONObject;  
}
