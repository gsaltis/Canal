/*****************************************************************************
 * FILE NAME    : FunctionDefinition.cpp
 * DATE         : September 05 2023
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
#include "FunctionDefinition.h"

/*****************************************************************************!
 * Function : FunctionDefinition
 *****************************************************************************/
FunctionDefinition::FunctionDefinition
() : QWidget()
{
}

/*****************************************************************************!
 * Function : FunctionDefinition
 *****************************************************************************/
FunctionDefinition::FunctionDefinition
(QString InName, QString InFilename) : QWidget()
{
  Name          = InName;
  Filename      = InFilename;
}

/*****************************************************************************!
 * Function : ~FunctionDefinition
 *****************************************************************************/
FunctionDefinition::~FunctionDefinition
()
{
}

/*****************************************************************************!
 * Function : GetFilename
 *****************************************************************************/
QString
FunctionDefinition::GetFilename(void)
{
  return Filename;
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
FunctionDefinition::GetName(void)
{
  return Name;
}

/*****************************************************************************!
 * Function : SetSignature
 *****************************************************************************/
void
FunctionDefinition::SetSignature
(QString InSignature)
{
  Signature = InSignature;
}

/*****************************************************************************!
 * Function : GetSignature
 *****************************************************************************/
QString
FunctionDefinition::GetSignature(void)
{
  return Signature;
}
