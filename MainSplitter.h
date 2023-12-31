/*****************************************************************************
 * FILE NAME    : MainSplitter.h
 * DATE         : August 12 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainsplitter_h_
#define _mainsplitter_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QSplitter>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_SPLITTER_X                 200
#define MAIN_SPLITTER_Y                 200
#define MAIN_SPLITTER_WIDTH             200
#define MAIN_SPLITTER_HEIGHT            200

/*****************************************************************************!
 * Exported Class : MainSplitter
 *****************************************************************************/
class MainSplitter : public QSplitter
{
  Q_OBJECT;

 //! Constructors
 public :
  MainSplitter                  ();

 //! Destructor
 public :
  ~MainSplitter                 ();

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
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _mainsplitter_h_*/
