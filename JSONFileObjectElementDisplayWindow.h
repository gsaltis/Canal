/*****************************************************************************
 * FILE NAME    : JSONFileObjectElementDisplayWindow.h
 * DATE         : August 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfileobjectelementdisplaywindow_h_
#define _jsonfileobjectelementdisplaywindow_h_

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
#define JSONFILE_OBJECT_ELEMENT_DISPLAY_WINDOW_X 200
#define JSONFILE_OBJECT_ELEMENT_DISPLAY_WINDOW_Y 200
#define JSONFILE_OBJECT_ELEMENT_DISPLAY_WINDOW_WIDTH 200
#define JSONFILE_OBJECT_ELEMENT_DISPLAY_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : JSONFileObjectElementDisplayWindow
 *****************************************************************************/
class JSONFileObjectElementDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileObjectElementDisplayWindow ();

 //! Destructor
 public :
  ~JSONFileObjectElementDisplayWindow ();

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

#endif /* _jsonfileobjectelementdisplaywindow_h_*/
