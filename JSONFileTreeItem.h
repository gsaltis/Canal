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
#define JSONFILE_TREE_ITEM_TOP          1
#define JSONFILE_TREE_ITEM_CHILD        2
#define JSONFILE_TREE_ITEM_INNER_TOP    3

/*****************************************************************************!
 * Exported Class : JSONFileTreeItem
 *****************************************************************************/
class JSONFileTreeItem : public QTreeWidgetItem
{
 //! Constructors
 public :
  JSONFileTreeItem              (int InType = JSONFILE_TREE_ITEM_TOP,
                                 QJsonObject* InObject = NULL);

 //! Destructor
 public :
  ~JSONFileTreeItem             ();

 //! Public Methods
 public :
  int                           GetType                 ();
  QJsonObject*                  GetObject               ();  

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
  QJsonObject*                  object;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonfiletreeitem_h_*/
