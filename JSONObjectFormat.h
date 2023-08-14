/*****************************************************************************
 * FILE NAME    : JSONObjectFormat.h
 * DATE         : August 13 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonobjectformat_h_
#define _jsonobjectformat_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QString>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONTagElementList.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : JSONObjectFormat
 *****************************************************************************/
class JSONObjectFormat : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONObjectFormat              (QString InName);

 //! Destructor
 public :
  ~JSONObjectFormat             ();

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
  QString                       name;
  QList<JSONTagElement*>        elements;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonobjectformat_h_*/
