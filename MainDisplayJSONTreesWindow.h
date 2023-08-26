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
  MainDisplayJSONTreesWindow                    (QWidget* InParent, QString InFilename, QString InBaseFilename, QJsonObject InMainJSONObject, JSONObjectFormatList* InObjectsFormats);

 //! Destructor
 public :
  ~MainDisplayJSONTreesWindow                   ();

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
  void                          CreateConnections       (void);

 //! Private Data
 private :
  MainSplitter*                 splitter;

  MainTagWindow*                elementsWindow;
  JSONFileWindow*               fileWindow;
  JSONElementWindow*            objectsWindow;
  JSONFileObjectDisplayWindow*  objectDisplayWindow;

  JSONObjectFormatList*         objectsFormats;

  QString                       filename;
  QString                       baseFilename;
  QJsonDocument                 jsonDoc;
  QJsonObject                   mainJSONObject;
  
 //! Public Slots
 public slots :
  void                          SlotFormatTypeSelected  (QString InType);
  void                          SlotFileObjectSelected  (QJsonObject InObject);
  void                          SlotFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SlotObjectFormatSelected (JSONObjectFormat* InObjectFormat);
  void                          SlotObjectFormatIdentified (QString InTag, QStringList InKeys);
  void                          SlotCallingFunctionFound (QString InFunctionName);

 //! Public Signals
 signals :
  void                          SignalFormatTypeSelected(QString InType);
  void                          SignalFileObjectSelected(QJsonObject);
  void                          SignalFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SignalObjectFormatSelected (JSONObjectFormat* InObjectFormat);
  void                          SignalFileElementIdentified (QString InSearchTag, QStringList InKeys);
  void                          SignalCallingFunctionFound (QString InFunctionName);

 //! Public Actions
 public :

};

#endif /* _maindisplayjsontreeswindow_h_*/