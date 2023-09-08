/*****************************************************************************
 * FILE NAME    : FunctionDefinitionDB.cpp
 * DATE         : September 06 2023
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
#include "FunctionDefinitionDB.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : FunctionDefinitionDB
 *****************************************************************************/
FunctionDefinitionDB::FunctionDefinitionDB
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~FunctionDefinitionDB
 *****************************************************************************/
FunctionDefinitionDB::~FunctionDefinitionDB
()
{
}

/*****************************************************************************!
 * Function : ReadFunctions
 *****************************************************************************/
void
FunctionDefinitionDB::ReadFunctions
(TranslationUnitObject* InTranslationUnit)
{
  QJsonObject                           obj;
  QJsonValue                            value;
  int                                   n;
  int                                   i;
  int                                   firstIndex;
  QJsonArray                            innerArray;
  
  TranslationUnit = InTranslationUnit;
  JSONObject = TranslationUnit->GetJSONObject();
  firstIndex = TranslationUnit->GetFirstLocalItemIndex();

  innerArray = JSONObject["inner"].toArray();
  n = innerArray.count();
  for ( i = firstIndex ; i < n ; i++ ) {
    value = innerArray[i];
    obj = value.toObject();
    if ( ! TranslationUnit->ObjectIsFunctionDefinition(obj) ) {
      continue;
    }
    ReadFunctionDefinition(InTranslationUnit->GetFilename(), obj);
  }
}

/*****************************************************************************!
 * Function : AddFunction
 *****************************************************************************/
void
FunctionDefinitionDB::AddFunction
(FunctionDefinition* InFunction)
{
  if ( NULL == InFunction ) {
    return;
  }
  
  Functions << InFunction;
}

/*****************************************************************************!
 * Function : FunctionExists
 *****************************************************************************/
bool
FunctionDefinitionDB::FunctionExists
(QString InFunctionName, QString InFilename)
{
  for ( auto i = Functions.begin() ; i != Functions.end(); i++ ) {
    if ( (*i)->GetFilename() == InFilename && (*i)->GetName() == InFunctionName ) {
      return true;
    }
  }
  return false;
}

/*****************************************************************************!
 * Function : ReadFunctionDefinition
 *****************************************************************************/
void
FunctionDefinitionDB::ReadFunctionDefinition
(QString InFilename, QJsonObject InJSONObject)
{
  QString                               sig;
  QString                               name;
  QStringList                           keys;
  FunctionDefinition*                   func;

  keys = InJSONObject.keys();
  name = InJSONObject["name"].toString();
  sig = TranslationUnitObject::GetFunctionSignature(InJSONObject);
  
  func = new FunctionDefinition(InFilename, name);
  func->SetSignature(sig);
  Functions << func;
}

/*****************************************************************************!
 * Function : GetFunctionCount
 *****************************************************************************/
int
FunctionDefinitionDB::GetFunctionCount(void)
{
  return Functions.count();
}

/*****************************************************************************!
 * Function : Save
 *****************************************************************************/
void
FunctionDefinitionDB::Save
(QString InFilename)
{
  QString                               st;
  QFile                                 file = QFile(InFilename);

  if ( ! file.open(QIODevice::ReadWrite | QIODevice::Truncate) ) {
    return;
  }
  file.close();

  if ( ! file.open(QIODevice::ReadWrite | QIODevice::Truncate) ) {
    return;
  }

  for ( auto i = Functions.begin() ; i != Functions.end() ; i++ ) {
    FunctionDefinition*                         def = *i;
    st = QString("%1\t%2\t%3\n").arg(def->GetName()).arg(def->GetFilename()).
      arg(def->GetSignature());
                                                         
    file.write(st.toLatin1());
  }
    
  file.close();
}
