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

  bool
  ObjectElementContainsCall
  (QJsonObject InObject, QString InFunctionName);
  
 //! Private Data
 private :
  JSONFileObjectDisplayTree*    fileTree;
  SectionHeader*                header;
  QJsonObject                   fileObject;
  QPushButton*                  ExpandButton;
  QPushButton*                  CollapseButton;
  QPushButton*                  DisplayButton;
  
 //! Public Slots
 public slots :
  void                          SlotFileObjectSelected  (QJsonObject);
  void                          SlotFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SlotObjectFormatSelected (JSONObjectFormat* InObjectFormat);
  void                          SlotObjectFormatIdentified (QString InTag, QStringList InKeys);
  void                          SlotExpandButtonClicked (bool InChecked);
  void                          SlotCollapseButtonClicked (bool InChecked);
  void                          SlotDisplayButtonClicked (bool InChecked);

 //! Public Signals
 signals :
  void                          SignalFileObjectSelected  (QJsonObject);
  void                          SignalFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SignalFileElementIdentified (QString InSearchTag, QStringList InKeys);
  void                          SignalExpandTree        (void);
  void                          SignalCollapseTree        (void);

 //! Public Actions
 public :
  
};

#endif /* _jsonfileobjectdisplaywindow_h_*/
