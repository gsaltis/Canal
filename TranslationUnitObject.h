/*****************************************************************************
 * FILE NAME    : TranslationUnitObject.h
 * DATE         : August 31 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _translationunitobject_h_
#define _translationunitobject_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONObjectFormatList.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : TranslationUnitObject
 *****************************************************************************/
class TranslationUnitObject : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  TranslationUnitObject         ();

 //! Destructor
 public :
  ~TranslationUnitObject        ();

 //! Public Methods
 public :
  int                           GetFirstLocalItemIndex  (void);
  QJsonObject                   GetJSONObject           (void);
  void                          SetJSONObject           (QJsonObject InJSONObject);
  JSONObjectFormatList*         GetObjectFormats        (void);
  void                          SetObjectFormats        (JSONObjectFormatList* InObjectFormats);
  QString                       GetFilename             (void);
  void                          SetFilename             (QString InFilename);
  QString                       GetBaseFilename         (void);
  void                          SortObjectFormats       ();
  QJsonObject                   FindFunctionDefinitionObjectByName (QString InName);
  bool                          ObjectIsFunctionDefinition      (QJsonObject InObject);
  bool                          ObjectIsStatic                  (QJsonObject InObject);

  static QString                GetDeclStmtName         (QJsonObject InObject);
  static QString                GetFuncDeclName         (QJsonObject InObject);
  static QString                GetCallExprName         (QJsonObject InObject);
  static QString                GetEnumConstantDeclName (QJsonObject InObject);
  static QString                GetFieldDeclName        (QJsonObject InObject);
  static QString                GetIntegerLiteralValue  (QJsonObject InObject);
  static QString                GetImplicitCastExprReference    (QJsonObject InObject);
  static QString                GetDeclRefExprName              (QJsonObject InObject);
  static QString                GetMemberExprName               (QJsonObject InObject);
  static QString                GetFunctionSignature    (QJsonObject InObject);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize                      ();
  void                          FindFirstLocaiItemIndex         (void);
  
 //! Private Data
 private :
  int                           firstLocalItemIndex;
  QJsonObject                   JSONObject;
  JSONObjectFormatList*         objectFormats;
  QString                       Filename;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _translationunitobject_h_*/
