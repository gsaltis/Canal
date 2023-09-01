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
#include "MainMessageWindow.h"
#include "TranslationUnitObject.h"

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
  MainDisplayWindow             (TranslationUnitObject* InTranslationUnit, int InWindowIndex);

 //! Destructor
 public :
  ~MainDisplayWindow            ();

 //! Public Methods
 public :
  void                          SaveAtExit              ();
  void                          OpenNewFile             ();
  
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
  MainDisplayJSONTreesWindow*   treesWindow;
  MainDisplayFunctionSVGWindow* functionSVGWindow;
  MainMessageWindow*            messageWindow;

  TranslationUnitObject*        TranslationUnit;
  QJsonDocument                 jsonDoc;
  int                           windowIndex;

 //! Public Slots
 public slots :
  void                          SlotSelectWindow        (int InWindowIndex);
  void                          SlotClearChildren       (void);
  void                          SlotSetMessageNormal    (QString InMessage);
  
 //! Public Signals
 signals :
  void                          SignalClearChildren     (void);
  void                          SignalSetMessageNormal  (QString InMessage);
  
 //! Public Actions
 public :

};

#endif /* _maindisplaywindow_h_*/
