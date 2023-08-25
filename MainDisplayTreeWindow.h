/*****************************************************************************
 * FILE NAME    : MainDisplayTreeWindow.h
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
#include "MainSplitter.h"
#include "JSONFileWindow.h"
#include "MainTagWindow.h"
#include "JSONElementWindow.h"
#include "JSONFileObjectDisplayWindow.h"
#include "JSONObjectFormatList.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_TREE_WINDOWS_X             200
#define MAIN_TREE_WINDOWS_Y             200
#define MAIN_TREE_WINDOWS_WIDTH         200
#define MAIN_TREE_WINDOWS_HEIGHT        200

/*****************************************************************************!
 * Exported Class : MainDisplayTreeWindow
 *****************************************************************************/
class MainDisplayTreeWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayTreeWindow               (QString InFilename, JSONObjectFormatList* InObjectsFormats);

 //! Destructor
 public :
  ~MainDisplayTreeWindow              ();

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
  MainSplitter*                 splitter;
  MainTagWindow*                tagWindow;
  JSONFileWindow*               fileWindow;
  JSONElementWindow*            elementWindow;
  JSONFileObjectDisplayWindow*  objectDisplayWindow;
  JSONObjectFormatList*         objectsFormats;

  QString                       filename;
  QString                       baseFilename;
  QJsonDocument                 jsonDoc;
  QJsonObject                   mainJSONObject;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _maintreewindows_h_*/
