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
#include "Trace.h"

/*****************************************************************************!
 * Function : TranslationUnitObject
 *****************************************************************************/
TranslationUnitObject::TranslationUnitObject
() : QWidget()
{
  Initialize();
  objectFormats = new JSONObjectFormatList();
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
TranslationUnitObject::Initialize
()
{
  firstLocalItemIndex = 0;
  objectFormats = NULL;
  Filename = QString();
}

/*****************************************************************************!
 * Function : ~TranslationUnitObject
 *****************************************************************************/
TranslationUnitObject::~TranslationUnitObject
()
{
}

/*****************************************************************************!
 * Function : GetFirstLocalItemIndex
 *****************************************************************************/
int
TranslationUnitObject::GetFirstLocalItemIndex(void)
{
  return firstLocalItemIndex;  
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
  FindFirstLocaiItemIndex();
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
  for ( i = firstLocalItemIndex ; i < n ; i++ ) {
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

/*****************************************************************************!
 * Function : GetDeclStmtName
 *****************************************************************************/
QString
TranslationUnitObject::GetDeclStmtName
(QJsonObject InObject)
{
  QString                               kind;
  QJsonObject                           obj;
  int                                   i;
  QJsonValue                            val;
  int                                   n;
  QJsonArray                            inner;
  QString                               name;
  QJsonValue                            innerVal;

  innerVal = InObject["inner"];

  if ( ! innerVal.isArray() ) {
    return name;
  }

  inner = innerVal.toArray();

  n = inner.count();

  for (i = 0; i < n; i++) {
    val = inner[i];
    if ( ! val.isObject() ) {
      continue;
    }
    obj = val.toObject();
    kind = obj["kind"].toString();
    if ( kind != "VarDecl" ) {
      continue;
    }
    name = obj["name"].toString();
    break;
  }
  return name;
}

/*****************************************************************************!
 * Function : GetCallExprName
 *****************************************************************************/
QString
TranslationUnitObject::GetCallExprName
(QJsonObject InObject)
{
  QString                               name;
  QJsonObject                           refDeclObj;
  QString                               kind;
  QJsonObject                           nameDeclObj;
  QJsonObject                           nameObj;

  name = QString();
  
  nameObj = InObject["inner"].toArray()[0].toObject();
  kind = nameObj["kind"].toString();
  if ( kind != "ImplicitCastExpr" ) {
    return name;
  }
  nameDeclObj = nameObj["inner"].toArray()[0].toObject();
  kind = nameDeclObj["kind"].toString();
  if ( kind != "DeclRefExpr" ) {
    return name;
  }
  refDeclObj = nameDeclObj["referencedDecl"].toObject();
  name = refDeclObj["name"].toString();
  return name;
}

/*****************************************************************************!
 * Function : GetEnumConstantDeclName
 *****************************************************************************/
QString
TranslationUnitObject::GetEnumConstantDeclName
(QJsonObject InObject)
{
  return InObject["name"].toString();
}

/*****************************************************************************!
 * Function : GetFieldDeclName
 *****************************************************************************/
QString
TranslationUnitObject::GetFieldDeclName
(QJsonObject InObject)
{
  return InObject["name"].toString();
}

/*****************************************************************************!
 * Function : GetFuncDeclName
 *****************************************************************************/
QString
TranslationUnitObject::GetFuncDeclName
(QJsonObject InObject)
{
  return InObject["name"].toString();
}

/*****************************************************************************!
 * Function : GetIntegerLiteralValue
 *****************************************************************************/
QString
TranslationUnitObject::GetIntegerLiteralValue
(QJsonObject InObject)
{
  return InObject["value"].toString();
}

/*****************************************************************************!
 * Function : GetImplicitCastExprReference
 *****************************************************************************/
QString
TranslationUnitObject::GetImplicitCastExprReference
(QJsonObject InObject)
{
  QString                               name;
  QJsonObject                           obj2;
  QJsonObject                           obj;
  QString                               kind;
  QJsonArray                            innerArray;
  QJsonValue                            value;

  value = InObject["inner"];
  if ( ! value.isArray() ) {
    return QString();
  }
  innerArray = value.toArray();
  value = innerArray[0];
  if ( ! value.isObject() ) {
    return QString();
  }
  obj = value.toObject();
  kind = obj["kind"].toString();
  if ( kind == "DeclRefExpr" ) {
    return GetDeclRefExprName(obj);
  }
  if ( kind == "MemberExpr" ) {
    return GetMemberExprName(obj);
  }
  if ( kind == "implicitCastExpr" ) {
    return GetImplicitCastExprReference(obj);
  }
  return QString();
}

/*****************************************************************************!
 * Function : GetDeclRefExprName
 *****************************************************************************/
QString
TranslationUnitObject::GetDeclRefExprName
(QJsonObject InObject)
{
  QString                               name;
  QJsonObject                           obj;
  QJsonValue                            value;

  value = InObject["referencedDecl"];

  if ( ! value.isObject() ) {
    return QString();
  }
  
  obj = value.toObject();
  name = obj["name"].toString();
  return name;
}

/*****************************************************************************!
 * Function : GetMemberExprName
 *****************************************************************************/
QString
TranslationUnitObject::GetMemberExprName
(QJsonObject InObject)
{
  QString                               name;
  
  name = InObject["name"].toString();
  return name;
}

/*****************************************************************************!
 * Function : FindFirstLocaiItemIndex
 *****************************************************************************/
void
TranslationUnitObject::FindFirstLocaiItemIndex(void)
{
  QJsonObject                           locObj;
  QJsonObject                           obj;
  QJsonValue                            value;
  int                                   n;
  int                                   i;
  QJsonArray                            innerArray;
  QString                               filename;
  QString                               baseFilename;

  baseFilename = GetBaseFilename();
  value = JSONObject["inner"];
  innerArray = value.toArray();

  n = innerArray.count();

  for (i = 0; i < n; i++) {
    value = innerArray[i];
    obj = value.toObject();
    locObj = obj["loc"].toObject();
    filename = locObj["file"].toString();
    if ( filename == baseFilename ) {
      firstLocalItemIndex = i;
      return;
    }
  }
}

/*****************************************************************************!
 * Function : GetFunctionSignature
 *****************************************************************************/
QString
TranslationUnitObject::GetFunctionSignature
(QJsonObject InFunctionObject)
{
  QJsonObject                           typeObj;
  QString                               siq;
  
  if ( InFunctionObject["kind"].toString() != "FunctionDecl" ) {
    return siq;
  }

  typeObj = InFunctionObject["type"].toObject();
  return typeObj["qualType"].toString();
}
