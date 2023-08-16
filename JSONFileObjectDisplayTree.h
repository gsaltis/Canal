/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayTree.h
 * DATE         : August 15 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfileobjectdisplaytree_h_
#define _jsonfileobjectdisplaytree_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include <QWidget>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_OBJECT_DISPLAY_TREE_X  200
#define JSONFILE_OBJECT_DISPLAY_TREE_Y  200
#define JSONFILE_OBJECT_DISPLAY_TREE_WIDTH 200
#define JSONFILE_OBJECT_DISPLAY_TREE_HEIGHT 200

/*****************************************************************************!
 * Exported Class : JSONFileObjectDisplayTree
 *****************************************************************************/
class JSONFileObjectDisplayTree : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileObjectDisplayTree     ();

 //! Destructor
 public :
  ~JSONFileObjectDisplayTree    ();

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

 //! Public Slots
 public slots :
  void                          SlotFileObjectSelected  (QJsonObject);
  
 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonfileobjectdisplaytree_h_*/
