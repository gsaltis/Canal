/*****************************************************************************
 * FILE NAME    : CallTreeWindow.h
 * DATE         : August 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _calltreewindow_h_
#define _calltreewindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CallTreeWindowTree.h"
#include "SectionHeader.h"
#include "TranslationUnitObject.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define CALL_TREE_WINDOW_X              200
#define CALL_TREE_WINDOW_Y              200
#define CALL_TREE_WINDOW_WIDTH          200
#define CALL_TREE_WINDOW_HEIGHT         300

/*****************************************************************************!
 * Exported Class : CallTreeWindow
 *****************************************************************************/
class CallTreeWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  CallTreeWindow                (TranslationUnitObject* InTranslationUnit);

 //! Destructor
 public :
  ~CallTreeWindow               ();

 //! Public Methods
 public :
  void
  ClearLocal
  ();
  
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
  CallTreeWindowTree*           callTree;
  SectionHeader*                header;
  TranslationUnitObject*        TranslationUnit;
  
 //! Public Slots
 public slots :
  void                          SlotFunctionSelected    (QJsonObject InObject);
  void                          SlotCallingFunctionFound (QString InFunctionName);
  void                          SlotClearChildren       (void);
  void                          SlotCallingFunctionObjectSelected (QJsonObject InObject);
  void                          SlotClearLocal          (void);

 //! Public Signals
 signals :
  void                          SignalFunctionSelected  (QJsonObject InObject);
  void                          SignalCallingFunctionFound      (QString InFunctionName);
  void                          SignalClearChildren     ();
  void                          SignalCallingFunctionObjectSelected     (QJsonObject InObject);
 //! Public Actions
 public :

};

#endif /* _calltreewindow_h_*/
