/*****************************************************************************
 * FILE NAME    : CanalDB.h
 * DATE         : August 17 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _canaldb_h_
#define _canaldb_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "sqlite3.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : CanalDB
 *****************************************************************************/
class CanalDB : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  CanalDB                       ();

 //! Destructor
 public :
  ~CanalDB                      ();

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

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _canaldb_h_*/
