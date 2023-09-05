/*****************************************************************************
 * FILE NAME    : FunctionParameter.h
 * DATE         : September 05 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _functionparameter_h_
#define _functionparameter_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : FunctionParameter
 *****************************************************************************/
class FunctionParameter : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  FunctionParameter             ();
  FunctionParameter             (QString InName, QString InType);

 //! Destructor
 public :
  ~FunctionParameter            ();

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
  QString                               Type;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _functionparameter_h_*/
