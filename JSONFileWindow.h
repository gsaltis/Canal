/*****************************************************************************
 * FILE NAME    : JSONFileWindow.h
 * DATE         : August 12 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfilewindow_h_
#define _jsonfilewindow_h_

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
#define JSONFILE_WINDOW_X               200
#define JSONFILE_WINDOW_Y               200
#define JSONFILE_WINDOW_WIDTH           200
#define JSONFILE_WINDOW_HEIGHT          200

/*****************************************************************************!
 * Exported Class : JSONFileWindow
 *****************************************************************************/
class JSONFileWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileWindow                ();

 //! Destructor
 public :
  ~JSONFileWindow               ();

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

#endif /* _jsonfilewindow_h_*/
