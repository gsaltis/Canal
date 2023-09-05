/*****************************************************************************
 * FILE NAME    : FunctionDefinition.h
 * DATE         : September 05 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _functiondefinition_h_
#define _functiondefinition_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "FunctionParameter.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : FunctionDefinition
 *****************************************************************************/
class FunctionDefinition : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  FunctionDefinition            ();

 //! Destructor
 public :
  ~FunctionDefinition           ();

 //! Public Methods
 public :

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
  QString                               Name;
  QString                               Filename;
  QString                               ReturnType;
  QList<FunctionParameter*>             Parameters;
  QList<class FunctionDefinition*>      CalledFunctionReferences;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _functiondefinition_h_*/
