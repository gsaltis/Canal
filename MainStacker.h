/*****************************************************************************
 * FILE NAME    : MainStacker.h
 * DATE         : August 15 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainstacker_h_
#define _mainstacker_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QStackedWidget>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_STACKER_X                  200
#define MAIN_STACKER_Y                  200
#define MAIN_STACKER_WIDTH              200
#define MAIN_STACKER_HEIGHT             200

/*****************************************************************************!
 * Exported Class : MainStacker
 *****************************************************************************/
class MainStacker : public QStackedWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainStacker                   ();

 //! Destructor
 public :
  ~MainStacker                  ();

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
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _mainstacker_h_*/
