/*****************************************************************************
 * FILE NAME    : JSONTagElement.h
 * DATE         : August 13 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsontagelement_h_
#define _jsontagelement_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QString>
#include <QJsonDocument>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : JSONTagElement
 *****************************************************************************/
class JSONTagElement : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONTagElement                (QString InTag, QJsonValue::Type InType);

 //! Destructor
 public :
  ~JSONTagElement               ();

 //! Public Methods
 public :
  bool                          Equals                  (QString InTag, QJsonValue::Type InType);
  QString                       GetTag                  ();
  QJsonValue::Type              GetType                 ();
  
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
  QJsonValue::Type              type;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsontagelement_h_*/
