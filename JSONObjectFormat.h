/*****************************************************************************
 * FILE NAME    : JSONObjectFormat.h
 * DATE         : August 14 2023
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
#include <QStringList>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

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
  JSONObjectFormat              (QString InTag, QStringList InKeys);

 //! Destructor
 public :
  ~JSONObjectFormat             ();

 //! Public Methods
 public :
  bool                          IsEqual                 (QString InTag, QStringList InKeys);
  QString                       GetTag                  (void);
  QStringList                   GetKeys                 (void);
  
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
  QString                       tag;
  QStringList                   keys;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonobjectformat_h_*/
