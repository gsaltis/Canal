/*****************************************************************************
 * FILE NAME    : CallTreeWindowTree.h
 * DATE         : August 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _calltreewindowtree_h_


/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CallTreeWindowTreeItem.h"
#include "TranslationUnitObject.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define CALL_TREE_WINDOW_TREE_X         200
#define CALL_TREE_WINDOW_TREE_Y         200
#define CALL_TREE_WINDOW_TREE_WIDTH     200
#define CALL_TREE_WINDOW_TREE_HEIGHT    200

/*****************************************************************************!
 * Exported Class : CallTreeWindowTree
 *****************************************************************************/
class CallTreeWindowTree : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  CallTreeWindowTree            (TranslationUnitObject* InTranslationUnit);

 //! Destructor
 public :
  ~CallTreeWindowTree           ();

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
  CallTreeWindowTreeItem*       FunctionNameItem;
  CallTreeWindowTreeItem*       lastCallingFunctionSelected;
  TranslationUnitObject*        TranslationUnit;
  bool                          locallyGenerated;
  
 //! Public Slots
 public slots :
  void                          SlotFunctionSelected    (QJsonObject InObject);
  void                          SlotCallingFunctionFound (QString InFunctionName);
  void                          SlotClearChildren       (void);
  void                          SlotItemSelected        (QTreeWidgetItem* InItem, int InColumn);

 //! Public Signals
 signals :
  void                          SignalCallingFunctionObjectSelected (QJsonObject InObject);

 //! Public Actions
 public :

};

#define _calltreewindowtree_h_

#endif /* _calltreewindowtree_h_*/
