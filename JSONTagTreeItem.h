/*****************************************************************************
 * FILE NAME    : JSONTagTreeItem.h
 * DATE         : August 13 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsontagtreeitem_h_
#define _jsontagtreeitem_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QString>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONTagElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONTAG_TREE_ITEM_X             200
#define JSONTAG_TREE_ITEM_Y             200
#define JSONTAG_TREE_ITEM_WIDTH         200
#define JSONTAG_TREE_ITEM_HEIGHT        200

/*****************************************************************************!
 * Exported Class : JSONTagTreeItem
 *****************************************************************************/
class JSONTagTreeItem : public QTreeWidgetItem
{

 //! Constructors
 public :
  JSONTagTreeItem               (JSONTagElement* InTag);

 //! Destructor
 public :
  ~JSONTagTreeItem              ();

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

 //! Private Data
 private :
  QString                       tag;

 //! Public Actions
 public :

};

#endif /* _jsontagtreeitem_h_*/
