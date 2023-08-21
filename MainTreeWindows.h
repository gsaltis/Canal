/*****************************************************************************
 * FILE NAME    : MainTreeWindows.h
 * DATE         : August 21 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maintreewindows_h_
#define _maintreewindows_h_

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
#define MAIN_TREE_WINDOWS_X             200
#define MAIN_TREE_WINDOWS_Y             200
#define MAIN_TREE_WINDOWS_WIDTH         200
#define MAIN_TREE_WINDOWS_HEIGHT        200

/*****************************************************************************!
 * Exported Class : MainTreeWindows
 *****************************************************************************/
class MainTreeWindows : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainTreeWindows               ();

 //! Destructor
 public :
  ~MainTreeWindows              ();

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

#endif /* _maintreewindows_h_*/
