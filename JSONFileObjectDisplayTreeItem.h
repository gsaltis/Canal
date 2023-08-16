/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayTreeItem.h
 * DATE         : August 16 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfileobjectdisplaytreeitem_h_
#define _jsonfileobjectdisplaytreeitem_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QWidget>
#include <QJsonValue>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_OBJECT_DISPLAY_TREE_ITEM_X 200
#define JSONFILE_OBJECT_DISPLAY_TREE_ITEM_Y 200
#define JSONFILE_OBJECT_DISPLAY_TREE_ITEM_WIDTH 200
#define JSONFILE_OBJECT_DISPLAY_TREE_ITEM_HEIGHT 200

/*****************************************************************************!
 * Exported Class : JSONFileObjectDisplayTreeItem
 *****************************************************************************/
class JSONFileObjectDisplayTreeItem : public QTreeWidgetItem
{
 //! Constructors
 public :
  JSONFileObjectDisplayTreeItem (QString InTag, QJsonValue InValue);

 //! Destructor
 public :
  ~JSONFileObjectDisplayTreeItem ();

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
  void                          HandleObject            (QJsonObject InObject);
  void                          HandleArray             (QJsonArray InArray);
  
 //! Private Data
 private :
  QJsonValue                    value;
  QString                       tag;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonfileobjectdisplaytreeitem_h_*/
