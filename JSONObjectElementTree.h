/*****************************************************************************
 * FILE NAME    : JSONObjectElementTree.h
 * DATE         : August 14 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonobjectelementtree_h_
#define _jsonobjectelementtree_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONObjectFormatList.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONOBJECT_ELEMENT_TREE_X       200
#define JSONOBJECT_ELEMENT_TREE_Y       200
#define JSONOBJECT_ELEMENT_TREE_WIDTH   200
#define JSONOBJECT_ELEMENT_TREE_HEIGHT  200

/*****************************************************************************!
 * Exported Class : JSONObjectElementTree
 *****************************************************************************/
class JSONObjectElementTree : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONObjectElementTree         (JSONObjectFormatList* InObjectsFormats);

 //! Destructor
 public :
  ~JSONObjectElementTree        ();

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
  void                          SlotItemClicked         (QTreeWidgetItem* InItem, int InColumn);
  
 //! Private Data
 private :
  JSONObjectFormatList*         objectsFormats;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :
  void                          SignalTypeSelected      (QString InType);

 //! Public Actions
 public :

};

#endif /* _jsonobjectelementtree_h_*/
