/*****************************************************************************
 * FILE NAME    : JSONObjectFormatList.h
 * DATE         : August 14 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonobjectformatlist_h_
#define _jsonobjectformatlist_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONObjectFormat.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : JSONObjectFormatList
 *****************************************************************************/
class JSONObjectFormatList : public QList<JSONObjectFormat*>
{
  
 //! Constructors
 public :
  JSONObjectFormatList          ();

 //! Destructor
 public :
  ~JSONObjectFormatList         ();

 //! Public Methods
 public :
  bool                          Contains                (QString InTag, QStringList InKeys);

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

#endif /* _jsonobjectformatlist_h_*/
