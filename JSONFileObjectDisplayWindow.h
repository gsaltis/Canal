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
#include <QJsonObject>
#include <QPushButton>
#include <QToolBar>
#include <QAction>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileObjectDisplayTree.h"
#include "JSONObjectFormat.h"
#include "SectionHeader.h"

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
  QList<int>
  GetColumnWidths
  ();
  
  void                          FindCalls               (QString InFunctionName);
  
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
  bool                          ObjectIsFunctionDefinition      (QJsonObject InObject);
  bool                          ObjectContainsCall      (QJsonObject InObject, QString InFunctionName);
  QJsonArray                    GetFunctionCompountStmtInternals (QJsonObject InObject);
  bool                          ContainsCallExpr        (QJsonObject InObject, QString InName);


  bool                          FunctionContainsReference
  (QJsonObject InFunctionObject, QString InFunctionName);
  
  bool                          ObjectElementContainsCall
  (QJsonObject InObject, QString InFunctionName);

  bool                          CheckCallExpr           (QJsonObject InObject, QString InFunctionName);

  bool                          ObjectContainsReference
  (QString InObjectName, QJsonObject InObject, QString InFunctionName);
  
 //! Private Data
 private :
  JSONFileObjectDisplayTree*    fileTree;
  SectionHeader*                header;
  QJsonObject                   fileObject;
  QPushButton*                  DisplayButton;
  QToolBar*                     Toolbar;
  
 //! Public Slots
 public slots :
  void                          SlotFileObjectSelected  (QJsonObject);
  void                          SlotFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SlotObjectFormatSelected (JSONObjectFormat* InObjectFormat);
  void                          SlotObjectFormatIdentified (QString InTag, QStringList InKeys);
  void                          SlotDisplayButtonClicked (bool InChecked);
  void                          SlotCollapseElements    (void);
  void                          SlotExpandElements      (void);

 //! Public Signals
 signals :
  void                          SignalFileObjectSelected  (QJsonObject);
  void                          SignalFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SignalFileElementIdentified (QString InSearchTag, QStringList InKeys);
  void                          SignalExpandTree        (void);
  void                          SignalCollapseTree        (void);
  void                          SignalCallingFunctionFound (QString InFunctionName);

 //! Public Actions
 public :
  
  QAction*                      ActionCollapseElements;
  QAction*                      ActionExpandElements;

};

#endif /* _jsonfileobjectdisplaywindow_h_*/
