/*****************************************************************************
 * FILE NAME    : JSONFileTreeItem.h
 * DATE         : August 12 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfiletreeitem_h_
#define _jsonfiletreeitem_h_

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
#define JSONFILE_TREE_ITEM_X            200
#define JSONFILE_TREE_ITEM_Y            200
#define JSONFILE_TREE_ITEM_WIDTH        200
#define JSONFILE_TREE_ITEM_HEIGHT       200

/*****************************************************************************!
 * Exported Class : JSONFileTreeItem
 *****************************************************************************/
class JSONFileTreeItem : public QTreeWidgetItem
{
 //! Constructors
 public :
  JSONFileTreeItem              ();

 //! Destructor
 public :
  ~JSONFileTreeItem             ();

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

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonfiletreeitem_h_*/
