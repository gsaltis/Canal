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
  int                           GetFirstFunctionIndex   (void);
  void                          SetFirstFunctionIndex   (int InFirstFunctionIndex);
  QJsonObject                   GetJSONObject           (void);
  void                          SetJSONObject           (QJsonObject InJSONObject);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :
  int                           firstFunctionIndex;
  QJsonObject                   JSONObject;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _translationunitobject_h_*/
