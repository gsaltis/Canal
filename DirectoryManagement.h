/*****************************************************************************
 * FILE NAME    : DirectoryManagement.h
 * DATE         : August 17 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _directorymanagement_h_
#define _directorymanagement_h_

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
 * Exported Class : DirectoryManagement
 *****************************************************************************/
class DirectoryManagement : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  DirectoryManagement           ();

 //! Destructor
 public :
  ~DirectoryManagement          ();

 //! Public Methods
 public :
  QString
  GetSystemDir
  (void);

  void
  SetSystemDir
  (QString InSystemDirectory);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void
  Initialize
  ();
  
 //! Private Data
 private :
  QString
  systemDirectory;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _directorymanagement_h_*/
