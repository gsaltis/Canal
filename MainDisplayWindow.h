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
#include "MainStacker.h"
#include "MainTagWindow.h"
#include "JSONFileWindow.h"
#include "JSONElementWindow.h"
#include "JSONObjectFormatList.h"
#include "JSONFileObjectDisplayWindow.h"
#include "MainDisplayJSONTreesWindow.h"
#include "MainDisplayFunctionSVGWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_DISPLAY_WINDOW_COUNT               4

/*****************************************************************************!
 * Exported Class : MainDisplayWindow
 *****************************************************************************/
class MainDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayWindow             (QString InFilename, JSONObjectFormatList* InObjectsFormats, int InWindowIndex);

 //! Destructor
 public :
  ~MainDisplayWindow            ();

 //! Public Methods
 public :
  void                          SaveAtExit              ();
  void                          OpenNewFile             (QString InFilename);
  
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
  void                          CreateConnections       (void);

 //! Private Data
 private :
  QString                       filename;
  QString                       baseFilename;
  QJsonDocument                 jsonDoc;
  QJsonObject                   mainJSONObject;
  JSONObjectFormatList*         objectsFormats;
  int                           windowIndex;
  MainDisplayJSONTreesWindow*   treesWindow;
  MainDisplayFunctionSVGWindow* functionSVGWindow;

 //! Public Slots
 public slots :
  void                          SlotSelectWindow        (int InWindowIndex);
  void                          SlotClearChildren       (void);
  
 //! Public Signals
 signals :
  void                          SignalClearChildren     (void);
  
 //! Public Actions
 public :

};

#endif /* _maindisplaywindow_h_*/
