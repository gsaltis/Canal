/*****************************************************************************
 * FILE NAME    : MainDisplayJSONTreesWindow.h
 * DATE         : August 21 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maindisplayjsontreeswindow_h_
#define _maindisplayjsontreeswindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainSplitter.h"
#include "JSONFileWindow.h"
#include "MainTagWindow.h"
#include "JSONElementWindow.h"
#include "JSONFileObjectDisplayWindow.h"
#include "JSONObjectFormatList.h"
#include "TranslationUnitObject.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_TREE_WINDOWS_X             200
#define MAIN_TREE_WINDOWS_Y             200
#define MAIN_TREE_WINDOWS_WIDTH         200
#define MAIN_TREE_WINDOWS_HEIGHT        200

/*****************************************************************************!
 * Exported Class : MainDisplayJSONTreesWindow
 *****************************************************************************/
class MainDisplayJSONTreesWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayJSONTreesWindow                    (QWidget* InParent, TranslationUnitObject* InTranslationUnit);

 //! Destructor
 public :
  ~MainDisplayJSONTreesWindow                   ();

 //! Public Methods
 public :

  void
  SaveAtExit
  ();
  void                          OpenNewFile             (TranslationUnitObject* InTranslationUnit);
  
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
  void                          CreateConnections       (void);
  void                          SaveSplitterSizes       ();

 //! Private Data
 private :
  MainSplitter*                 splitter;

  MainTagWindow*                elementsWindow;
  JSONFileWindow*               translationUnitWindow;
  JSONElementWindow*            objectsWindow;
  JSONFileObjectDisplayWindow*  objectDisplayWindow;

  QJsonDocument                 jsonDoc;
  TranslationUnitObject*        TranslationUnit;
  
 //! Public Slots
 public slots :
  void                          SlotFormatTypeSelected  (QString InType);
  void                          SlotFileObjectSelected  (QJsonObject InObject);
  void                          SlotFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SlotObjectFormatSelected (JSONObjectFormat* InObjectFormat);
  void                          SlotObjectFormatIdentified (QString InTag, QStringList InKeys);
  void                          SlotCallingFunctionFound (QString InFunctionName);
  void                          SlotClearChildren       (void);

  
 //! Public Signals
 signals :
  void                          SignalFormatTypeSelected(QString InType);
  void                          SignalFileObjectSelected(QJsonObject);
  void                          SignalFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SignalObjectFormatSelected (JSONObjectFormat* InObjectFormat);
  void                          SignalFileElementIdentified (QString InSearchTag, QStringList InKeys);
  void                          SignalCallingFunctionFound (QString InFunctionName);
  void                          SignalClearChildren     (void);

 //! Public Actions
 public :

};

#endif /* _maindisplayjsontreeswindow_h_*/
