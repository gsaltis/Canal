/*****************************************************************************
 * FILE NAME    : JSONElementWindow.h
 * DATE         : August 12 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonelementwindow_h_
#define _jsonelementwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONObjectFormatList.h"
#include "JSONObjectElementTree.h"
#include "JSONElementWindowSectionHeader.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONELEMENT_WINDOW_X            200
#define JSONELEMENT_WINDOW_Y            200
#define JSONELEMENT_WINDOW_WIDTH        200
#define JSONELEMENT_WINDOW_HEIGHT       200

/*****************************************************************************!
 * Exported Class : JSONElementWindow
 *****************************************************************************/
class JSONElementWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONElementWindow
  (JSONObjectFormatList* InObjectsFormats);

 //! Destructor
 public :
  ~JSONElementWindow
  ();

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
  void
  initialize
  ();

  void
  CreateSubWindows
  ();

  void
  InitializeSubWindows
  ();

  void
  resizeEvent
  (QResizeEvent* InEvent);

 //! Private Data
 private :
  JSONObjectFormatList*                 objectsFormats;
  JSONObjectElementTree*                elementTree;
  JSONElementWindowSectionHeader*       header;
  
 //! Public Slots
 public slots :
  void
  SlotTypeFormatSelected
  (QString InType);

  void
  SlotFileElementSelected
  (QString InTag, QList<QString> InKeys);

 //! Public Signals
 signals :
  void
  SignalTypeFormatSelected
  (QString InType);

  void
  SignalFileElementSelected
  (QString InTag, QList<QString> InKeys);
  
 //! Public Actions
 public :

};

#endif /* _jsonelementwindow_h_*/
