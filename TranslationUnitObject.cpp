/*****************************************************************************
 * FILE NAME    : TranslationUnitObject.cpp
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
#include "TranslationUnitObject.h"

/*****************************************************************************!
 * Function : TranslationUnitObject
 *****************************************************************************/
TranslationUnitObject::TranslationUnitObject
() : QWidget()
{
  objectFormats = new JSONObjectFormatList();
}

/*****************************************************************************!
 * Function : ~TranslationUnitObject
 *****************************************************************************/
TranslationUnitObject::~TranslationUnitObject
()
{
}

/*****************************************************************************!
 * Function : GetFirstFunctionIndex
 *****************************************************************************/
int
TranslationUnitObject::GetFirstFunctionIndex(void)
{
  return firstFunctionIndex;  
}

/*****************************************************************************!
 * Function : SetFirstFunctionIndex
 *****************************************************************************/
void
TranslationUnitObject::SetFirstFunctionIndex
(int InFirstFunctionIndex)
{
  firstFunctionIndex = InFirstFunctionIndex;  
}

/*****************************************************************************!
 * Function : GetJSONObject
 *****************************************************************************/
QJsonObject
TranslationUnitObject::GetJSONObject(void)
{
  return JSONObject;  
}

/*****************************************************************************!
 * Function : SetJSONObject
 *****************************************************************************/
void
TranslationUnitObject::SetJSONObject
(QJsonObject InJSONObject)
{
  JSONObject = InJSONObject;  
}

/*****************************************************************************!
 * Function : GetObjectFormats
 *****************************************************************************/
JSONObjectFormatList*
TranslationUnitObject::GetObjectFormats(void)
{
  return objectFormats;  
}

/*****************************************************************************!
 * Function : SetObjectFormats
 *****************************************************************************/
void
TranslationUnitObject::SetObjectFormats
(JSONObjectFormatList* InObjectFormats)
{
  objectFormats = InObjectFormats;  
}

/*****************************************************************************!
 * Function : GetFilename
 *****************************************************************************/
QString
TranslationUnitObject::GetFilename(void)
{
  return Filename;  
}

/*****************************************************************************!
 * Function : GetBaseFilename
 *****************************************************************************/
QString
TranslationUnitObject::GetBaseFilename
()
{
  QFileInfo                     fileinfo(Filename);

  return fileinfo.completeBaseName();
}

/*****************************************************************************!
 * Function : SetFilename
 *****************************************************************************/
void
TranslationUnitObject::SetFilename
(QString InFilename)
{
  Filename = InFilename;  
}

/*****************************************************************************!
 * Function : SortObjectFormats
 *****************************************************************************/
void
TranslationUnitObject::SortObjectFormats
()
{
  std::sort(objectFormats->begin(), objectFormats->end(),
            [] (JSONObjectFormat* InF1, JSONObjectFormat* InF2) {
              if ( InF1->GetTag() == InF2->GetTag() ) {
                return InF1->GetKeys().size() < InF2->GetKeys().size();
              }
              return InF1->GetTag() < InF2->GetTag();
            });
}

/*****************************************************************************!
 * Function : FindFunctionDefinitionObjectByName
 *****************************************************************************/
QJsonObject
TranslationUnitObject::FindFunctionDefinitionObjectByName
(QString InName)
{
  QJsonObject                           obj;
  int                                   i;
  int                                   n;
  QJsonArray                            inner;

  inner = JSONObject["inner"].toArray();
  n = inner.count();
  for ( i = firstFunctionIndex ; i < n ; i++ ) {
    obj = inner[i].toObject();
    if ( obj["name"].toString() == InName && ObjectIsFunctionDefinition(obj) ) {
      return obj;
    }
  }
  return QJsonObject();
}

/*****************************************************************************!
 * Function : ObjectIsFunctionDefinition
 *****************************************************************************/
bool
TranslationUnitObject::ObjectIsFunctionDefinition
(QJsonObject InObject)
{
  int                                   i;
  int                                   n;
  QJsonArray                            innerArray;
  QJsonValue                            innerValue;
  QJsonObject                           obj;
  QString                               kind;

  kind = InObject["kind"].toString();
  if (  kind.isEmpty() ) {
    return false;
  }

  innerValue = InObject["inner"];
  if ( ! innerValue.isArray() ) {
    return false;
  }

  innerArray = innerValue.toArray();

  n = innerArray.count();

  for (i = 0; i < n; i++) {
    obj = innerArray[i].toObject();
    kind = obj["kind"].toString();
    if ( kind == "CompoundStmt" ) {
      return true;
    }
  }
  return false;
}


/*****************************************************************************!
 * Function : ObjectIsStatic
 *****************************************************************************/
bool
TranslationUnitObject::ObjectIsStatic
(QJsonObject InObject)
{
  QJsonValue                            val;

  val = InObject["storageClass"];
  if ( ! val.isString() ) {
    return false;
  }
  if ( val.toString() == "static" ) {
    return true;
  }
  return false;
}
