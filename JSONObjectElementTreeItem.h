/*****************************************************************************
 * FILE NAME    : JSONObjectElementTreeItem.h
 * DATE         : August 14 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonobjectelementtreeitem_h_
#define _jsonobjectelementtreeitem_h_

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
#include "JSONObjectFormat.h"
#include "JSONObjectElementTreeItem.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONOBJECT_ELEMENT_TREE_ITEM_TYPE_TOP           1
#define JSONOBJECT_ELEMENT_TREE_ITEM_TYPE_CHILD         2

/*****************************************************************************!
 * Exported Class : JSONObjectElementTreeItem
 *****************************************************************************/
class JSONObjectElementTreeItem : public QTreeWidgetItem
{
 //! Constructors
 public :
  JSONObjectElementTreeItem     (JSONObjectFormat* InFormat, int InType = JSONOBJECT_ELEMENT_TREE_ITEM_TYPE_TOP);

 //! Destructor
 public :
  ~JSONObjectElementTreeItem    ();

 //! Public Methods
 public :
  int                           GetType                 (void);
  JSONObjectFormat*             GetFormat               (void);

 //! Public Data
 public :
  
 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();

 //! Private Data
 private :
  JSONObjectFormat*             format;
  int                           type;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonobjectelementtreeitem_h_*/
