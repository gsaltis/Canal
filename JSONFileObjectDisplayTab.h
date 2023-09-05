/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayTab.h
 * DATE         : September 03 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfileobjectdisplaytab_h_
#define _jsonfileobjectdisplaytab_h_

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
#include "JSONFileObjectDisplayTree.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_OBJECT_DISPLAY_TAB_X   200
#define JSONFILE_OBJECT_DISPLAY_TAB_Y   200
#define JSONFILE_OBJECT_DISPLAY_TAB_WIDTH 200
#define JSONFILE_OBJECT_DISPLAY_TAB_HEIGHT 200

/*****************************************************************************!
 * Exported Class : JSONFileObjectDisplayTab
 *****************************************************************************/
class JSONFileObjectDisplayTab : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileObjectDisplayTab     (QJsonObject InElementObject);

 //! Destructor
 public :
  ~JSONFileObjectDisplayTab     ();

 //! Public Methods
 public :
  QString                       GetName                 (void);

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
  void                          SetColumnWidths         (QList<int> InColumnWidths);
  void                          CreateConnections       ();
  
 //! Private Data
 private :
  QString                       name;
  QJsonObject                   elementObject;
  JSONFileObjectDisplayTree*    displayTree;

 //! Public Slots
 public slots :
  void                          SlotExpandTree          (void);
  void                          SlotCollapseTree        (void);
  void                          SlotNormalMessage       (QString InMessage);

 //! Public Signals
 signals :
  void                          SignalNormalMessage     (QString InMessage);

 //! Public Actions
 public :

};

#endif /* _jsonfileobjectdisplaytab_h_*/
