/*****************************************************************************
 * FILE NAME    : CallTreeWindowTreeItem.h
 * DATE         : August 31 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _calltreewindowtreeitem_h_


/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define CALL_TREE_WINDOW_TREE_ITEM_X    200
#define CALL_TREE_WINDOW_TREE_ITEM_Y    200
#define CALL_TREE_WINDOW_TREE_ITEM_WIDTH 200
#define CALL_TREE_WINDOW_TREE_ITEM_HEIGHT 200

#define CALL_TREE_WINDOW_TREE_ITEM_TYPE_FUNCTION        1
#define CALL_TREE_WINDOW_TREE_ITEM_TYPE_CALLER          2

/*****************************************************************************!
 * Exported Class : CallTreeWindowTreeItem
 *****************************************************************************/
class CallTreeWindowTreeItem : public QTreeWidgetItem
{
 //! Constructors
 public :
  CallTreeWindowTreeItem        (int InType = CALL_TREE_WINDOW_TREE_ITEM_TYPE_FUNCTION);

 //! Destructor
 public :
  ~CallTreeWindowTreeItem       ();

 //! Public Methods
 public :
  int                           GetType                 (void);
  void                          SetType                 (int InType);

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
  int                           type;

};

#define _calltreewindowtreeitem_h_

#endif /* _calltreewindowtreeitem_h_*/
