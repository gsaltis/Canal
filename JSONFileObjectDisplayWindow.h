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
#include "JSONFileObjectElementDisplayWindow.h"
#include "TranslationUnitObject.h"
#include "JSONFileObjectDisplayTabWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_OBJECT_DISPLAY_WINDOW_X 200
#define JSONFILE_OBJECT_DISPLAY_WINDOW_Y 200
#define JSONFILE_OBJECT_DISPLAY_WINDOW_WIDTH 200
#define JSONFILE_OBJECT_DISPLAY_WINDOW_HEIGHT 200

#define JSON_FILE_OBJECT_DISPLAY_WINDOW_INDEX   3

/*****************************************************************************!
 * Exported Class : JSONFileObjectDisplayWindow
 *****************************************************************************/
class JSONFileObjectDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileObjectDisplayWindow   (TranslationUnitObject* InTranslationUnit);

 //! Destructor
 public :
  ~JSONFileObjectDisplayWindow  ();

 //! Public Methods
 public :
  QList<int>
  GetColumnWidths
  ();
  
  void                          FindCalls               (QString InFunctionName);

  void
  OpenNewFile
  (TranslationUnitObject* InTranslationUnit);
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
  bool                          ObjectContainsCall      (QJsonObject InObject, QString InFunctionName);
  QJsonArray                    GetFunctionCompountStmtInternals (QJsonObject InObject);
  bool                          ContainsCallExpr        (QJsonObject InObject, QString InName);
  void                          CreateConnections       ();
  void                          CreateAction            ();

  bool                          FunctionContainsReference
  (QJsonObject InFunctionObject, QString InFunctionName);
  
  bool                          ObjectElementContainsCall
  (QJsonObject InObject, QString InFunctionName);

  bool                          CheckCallExpr           (QJsonObject InObject, QString InFunctionName);

  bool                          ObjectContainsReference
  (QString InObjectName, QJsonObject InObject, QString InFunctionName);

  void
  SetColumnWidths
  (QList<int> InWidths);
  void                          DisplayParmVarDecl      (QJsonObject InObject);
  
 //! Private Data
 private :
  JSONFileObjectDisplayTree*    fileTree;
  SectionHeader*                header;
  QJsonObject                   fileObject;
  QPushButton*                  DisplayButton;
  QToolBar*                     Toolbar;
  TranslationUnitObject*        TranslationUnit;
  JSONFileObjectElementDisplayWindow* elementDisplayWindow;
  JSONFileObjectDisplayTabWindow* tabWindow;

 //! Public Slots
 public slots :
  void                          SlotFileObjectSelected          (QJsonObject);
  void                          SlotFileElementSelected         (QString InTag, QList<QString> InKeys);
  void                          SlotObjectFormatSelected        (JSONObjectFormat* InObjectFormat);
  void                          SlotObjectFormatIdentified      (QString InTag, QStringList InKeys);
  void                          SlotDisplayButtonClicked        (bool InChecked);
  void                          SlotCollapseElements            (void);
  void                          SlotExpandElements              (void);
  void                          SlotValueSelected               (QJsonValue InValue);
  void                          SlotClearChildren               (void);
  void                          SlotNormalMessage               (QString InMessage);
  void                          SlotCloseTab                    (void);
  void                          SlotProgressBarShow             (void);
  void                          SlotProgressBarHide             (void);
  void                          SlotProgressBarSet              (int InMinimum, int InMaximum);
  void                          SlotProgressBarUpdate           (int InValue);

 //! Public Signals
 signals :
  void                          SignalFileObjectSelected        (QJsonObject);
  void                          SignalFileElementSelected       (QString InTag, QList<QString> InKeys);
  void                          SignalFileElementIdentified     (QString InSearchTag, QStringList InKeys);
  void                          SignalExpandTree                (void);
  void                          SignalCollapseTree              (void);
  void                          SignalCallingFunctionFound      (QString InFunctionName);
  void                          SignalClearChildren             (void);
  void                          SignalNormalMessage             (QString InMessage);
  void                          SignalCloseTab                  (void);
  void                          SignalProgressBarShow           (void);
  void                          SignalProgressBarHide           (void);
  void                          SignalProgressBarSet            (int InMinimum, int InMaximum);
  void                          SignalProgressBarUpdate         (int InValue);

 //! Public Actions
 public :
  
  QAction*                      ActionCollapseElements;
  QAction*                      ActionExpandElements;
  QAction*                      ActionCloseTab;

};

#endif /* _jsonfileobjectdisplaywindow_h_*/
