/*****************************************************************************
 * FILE NAME    : JSONTagElementList.h
 * DATE         : August 13 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsontagelementlist_h_
#define _jsontagelementlist_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONTagElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : JSONTagElementList
 *****************************************************************************/
class JSONTagElementList : public QList<JSONTagElement*>
{
 //! Constructors
 public :
  JSONTagElementList            ();

 //! Destructor
 public :
  ~JSONTagElementList           ();

 //! Public Methods
 public :
  bool                          HasElement              (QString InTag, QJsonValue::Type InType);

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

#endif /* _jsontagelementlist_h_*/
