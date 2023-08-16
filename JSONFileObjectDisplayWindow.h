/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayWindow.h
 * DATE         : August 15 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfileobjectdisplaywindow_h_
#define _jsonfileobjectdisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileObjectDisplayTree.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_OBJECT_DISPLAY_WINDOW_X 200
#define JSONFILE_OBJECT_DISPLAY_WINDOW_Y 200
#define JSONFILE_OBJECT_DISPLAY_WINDOW_WIDTH 200
#define JSONFILE_OBJECT_DISPLAY_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : JSONFileObjectDisplayWindow
 *****************************************************************************/
class JSONFileObjectDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileObjectDisplayWindow   ();

 //! Destructor
 public :
  ~JSONFileObjectDisplayWindow  ();

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
  JSONFileObjectDisplayTree*    fileTree;

 //! Public Slots
 public slots :
  void                          SlotFileObjectSelected  (QJsonObject);

 //! Public Signals
 signals :
  void                          SignalFileObjectSelected  (QJsonObject);

 //! Public Actions
 public :
  
};

#endif /* _jsonfileobjectdisplaywindow_h_*/
