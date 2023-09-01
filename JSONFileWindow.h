/*****************************************************************************
 * FILE NAME    : JSONFileWindow.h
 * DATE         : August 12 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfilewindow_h_
#define _jsonfilewindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileTree.h"
#include "JSONFileWindowSectionHeader.h"
#include "CallTreeWindow.h"
#include "TranslationUnitObject.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_WINDOW_X               200
#define JSONFILE_WINDOW_Y               200
#define JSONFILE_WINDOW_WIDTH           200
#define JSONFILE_WINDOW_HEIGHT          200

/*****************************************************************************!
 * Exported Class : JSONFileWindow
 *****************************************************************************/
class JSONFileWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileWindow                (TranslationUnitObject* InTranslationUnit);

 //! Destructor
 public :
  ~JSONFileWindow               ();

 //! Public Methods
 public :
  QList<int>                    GetColumnWidths         (void);

  void
  SetColumnWidths
  (QList<int> InWidths);

  void
  ResizeColumns
  (QList<int> InWidths);
  void                          OpenNewFile             (TranslationUnitObject* InTranslationUnitxo);
  
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
  QString                       filename;
  QString                       basename;
  QJsonObject                   mainJSONObject;
  QJsonArray                    innerObj;
  JSONFileTree*                 fileTree;
  JSONFileWindowSectionHeader*  header;
  CallTreeWindow*               callTreeWindow;
  TranslationUnitObject*        TranslationUnit;
  
 //! Public Slots
 public slots :
  void                          SlotFileObjectSelected  (QJsonObject InObject);
  void                          SlotSizeValueChanged    (int InSize);
  void                          SlotLocalCountSet       (int InLocalCount);
  void                          SlotCallingFunctionFound (QString InFunctionName);
  void                          SlotClearChildren       (void);
  
 //! Public Signals
 signals :
  void                          SignalFileObjectSelected(QJsonObject InObject);
  void                          SignalSizeValueChanged  (int InSize);
  void                          SignalCallingFunctionFound (QString InFunctionName);
  void                          SignalClearChildren     (void);

 //! Public Actions
 public :

};

#endif /* _jsonfilewindow_h_*/
