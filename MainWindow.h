/*****************************************************************************
 * FILE NAME    : MainWindow.h
 * DATE         : August 12 2023
 * PROJECT      : Canal
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainwindow_h_
#define _mainwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include <QAction>
#include <QString>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"
#include "SystemConfig.h"
#include "JSONObjectFormatList.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_WINDOW_WIDTH                       640
#define MAIN_WINDOW_HEIGHT                      480
#define MAIN_WINDOW_Y                           100
#define MAIN_WINDOW_X                           100

/*****************************************************************************!
 * Exported Class : MainWindow
 *****************************************************************************/
class MainWindow : public QMainWindow
{
  Q_OBJECT;

 //! Constructors
 public :
  MainWindow                    (QString InFilename, JSONObjectFormatList* InObjectsFormats, int InWindowIndex);
  MainWindow                    (QWidget*, QString InFilename, JSONObjectFormatList* InObjectsFormats, int InWindowIndex);

 //! Destructor
 public :
  ~MainWindow                   ();

 //! Public Methods
 public :
  void                          SaveAtExit              ();
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          CreateActions           ();
  void                          CreateMenus             ();
  void                          CreateConnections       ();
  
 //! Private Data
 private :
  MainDisplayWindow*            displayWindow;
  QMenuBar*                     menubar;
  QMenu*                        fileMenu;
  QMenu*                        windowMenu;
  QStatusBar*                   statusbar;
  QString                       filename;
  JSONObjectFormatList*         objectsFormats;
  int                           windowIndex;
  QString                       pathName;
  
 //! Public Slots
 public slots :
  void                          SlotExit                (void);
  void                          SlotSelectJSONWindow    (void);
  void                          SlotSelectDisplayWindow (void);
  void                          SlotFileOpen            (void);

 //! Public Signals
 signals :
  void                          SignalSelectWindow      (int InWindowIndex);
  void                          SignalClearChildren     (void);
  void                          SignalSetMessageNormal  (QString InMessage);

 //! Public Actions
 public :
  QAction*                      ActionExit;
  QAction*                      ActionSelectJSONWindow;
  QAction*                      ActionSelectDisplayWindow;
  QAction*                      ActionFileOpen;

};

#endif /* _mainwindow_h_*/
