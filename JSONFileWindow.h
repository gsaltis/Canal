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
  JSONFileWindow                (QString InFilename, QString InBasename, QJsonObject InMainJSONObject);

 //! Destructor
 public :
  ~JSONFileWindow               ();

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

 //! Private Data
 private :
  QString                       filename;
  QString                       basename;
  QJsonObject                   mainJSONObject;
  QJsonArray                    innerObj;
  JSONFileTree*                 fileTree;

 //! Public Slots
 public slots :
  void                          SlotFileObjectSelected  (QJsonObject InObject);
  
 //! Public Signals
 signals :
  void                          SignalFileObjectSelected(QJsonObject InObject);

 //! Public Actions
 public :

};

#endif /* _jsonfilewindow_h_*/
