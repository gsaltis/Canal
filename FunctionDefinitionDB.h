/*****************************************************************************
 * FILE NAME    : FunctionDefinitionDB.h
 * DATE         : September 06 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _functiondefinitiondb_h_
#define _functiondefinitiondb_h_

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
#include "FunctionDefinition.h"
#include "TranslationUnitObject.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : FunctionDefinitionDB
 *****************************************************************************/
class FunctionDefinitionDB : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  FunctionDefinitionDB          ();

 //! Destructor
 public :
  ~FunctionDefinitionDB         ();

 //! Public Methods
 public :
  void                          ReadFunctions           (TranslationUnitObject* InTranslationUnit);
  void                          AddFunction             (FunctionDefinition* InFunction);
  bool                          FunctionExists          (QString InFunctionName, QString InFilename);
  int                           GetFunctionCount        (void);
  void                          Save                    (QString InFilename);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          ReadFunctionDefinition  (QString InFilename, QJsonObject InJSONObject);

 //! Private Data
 private :
  TranslationUnitObject*        TranslationUnit;
  QJsonObject                   JSONObject;
  QList<FunctionDefinition*>    Functions;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _functiondefinitiondb_h_*/
