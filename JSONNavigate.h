/*****************************************************************************
 * FILE NAME    : JSONNavigate.h
 * DATE         : August 23 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonnavigate_h_
#define _jsonnavigate_h_

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
 * Exported Class : JSONNavigate
 *****************************************************************************/
class JSONNavigate : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONNavigate                  ();

 //! Destructor
 public :
  ~JSONNavigate                 ();

 //! Public Methods
 public :
  static QString
  GetStringElement
  (QJsonObject InObject, QString InSearchString);

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

#endif /* _jsonnavigate_h_*/
