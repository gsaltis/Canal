/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.h
 * DATE         : August 12 2023
 * PROJECT      : Canal
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maindisplaywindow_h_
#define _maindisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStackedWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainSplitter.h"
#include "MainTagWindow.h"
#include "JSONFileWindow.h"
#include "JSONElementWindow.h"
#include "JSONObjectFormatList.h"
#include "JSONFileObjectDisplayWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MainDisplayWindow
 *****************************************************************************/
class MainDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayWindow             (QString InFilename, JSONObjectFormatList* InObjectsFormats);

 //! Destructor
 public :
  ~MainDisplayWindow            ();

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
  void                          Initialize              ();
  void                          InitializeSubWindows    ();
  void                          CreateSubWindows        ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          HandleInputFilename     (void);

 //! Private Data
 private :
  MainSplitter*                 splitter;
  QSplitter*                    splitter2;
  MainTagWindow*                tagWindow;
  JSONFileWindow*               fileWindow;
  JSONElementWindow*            elementWindow;
  QString                       filename;
  QString                       baseFilename;
  QJsonDocument                 jsonDoc;
  QJsonObject                   mainJSONObject;
  JSONObjectFormatList*         objectsFormats;
  JSONFileObjectDisplayWindow*  objectDisplayWindow;
  QStackedWidget*               stacker;
  
 //! Public Slots
 public slots :
  void                          SlotFormatTypeSelected  (QString InType);
  void                          SlotFileObjectSelected  (QJsonObject* InObject);
  
 //! Public Signals
 signals :
  void                          SignalFormatTypeSelected(QString InType);

 //! Public Actions
 public :

};

#endif /* _maindisplaywindow_h_*/
