/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayTabWindow.h
 * DATE         : September 03 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfileobjectdisplaytabwindow_h_
#define _jsonfileobjectdisplaytabwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTabWidget>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileObjectDisplayTab.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_OBJECT_DISPLAY_TAB_WINDOW_X 200
#define JSONFILE_OBJECT_DISPLAY_TAB_WINDOW_Y 200
#define JSONFILE_OBJECT_DISPLAY_TAB_WINDOW_WIDTH 200
#define JSONFILE_OBJECT_DISPLAY_TAB_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : JSONFileObjectDisplayTabWindow
 *****************************************************************************/
class JSONFileObjectDisplayTabWindow : public QTabWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileObjectDisplayTabWindow ();

 //! Destructor
 public :
  ~JSONFileObjectDisplayTabWindow ();

 //! Public Methods
 public :
  void                          AddObject               (QJsonObject InObject);

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
  QHash<QString, JSONFileObjectDisplayTab*> Tabs;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonfileobjectdisplaytabwindow_h_*/
