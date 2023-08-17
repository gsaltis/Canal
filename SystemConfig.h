/*****************************************************************************
 * FILE NAME    : SystemConfig.h
 * DATE         : August 12 2023
 * PROJECT      : Canal
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _systemconfig_h_
#define _systemconfig_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SystemConfig
 *****************************************************************************/
class SystemConfig : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SystemConfig                  ();

 //! Destructor
 public :
  ~SystemConfig                 ();

 //! Public Methods
 public :
  QList<int>
  GetWindowWidths
  ();

  void
  SetWindowWidths
  (QList<int> InWindowWidths);

  QString
  GetSystemName
  ();

  void
  Initialize
  ();

  void
  Save
  ();
  void                          Read                    (void);
  
 //! Public Data
 public :
  QString
  SystemName;

  QList<int>
  WindowWidths;
  
 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          ReadWindowInfo          (QJsonObject InObj);

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _systemconfig_h_*/
