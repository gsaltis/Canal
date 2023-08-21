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
#include "JSONObjectElementTreeItem.h"

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
  JSONObjectElementTreeItem*    FindItem                (QString InTag, QStringList InKeys);
  void                          ProcessArray            (QString InKey, QJsonArray InArray);
  void                          SelectItem              (JSONObjectElementTreeItem* InItem);
  void                          UnSelectItem            (void);
  void                          FileObjectSelected      (QJsonObject InObject);
  
 //! Private Data
 private :
  JSONObjectFormatList*         objectsFormats;
  JSONObjectElementTreeItem*    lastTreeItem;
  
 //! Public Slots
 public slots :
  void                          SlotItemClicked         (QTreeWidgetItem* InItem, int InColumn);
  void                          SlotFileElementSelected (QString InTag, QList<QString> InKeys);
  void                          SlotObjectFormatIdentified (QString InTag, QStringList InKeys);
  void
  SlotFileObjectSelected
  (QJsonObject InObject);

 //! Public Signals
 signals :
  void                          SignalTypeSelected      (QString InType);
  void                          SignalObjectFormatSelected (JSONObjectFormat* InObjectFormat);

 //! Public Actions
 public :

};

#endif /* _jsonobjectelementtree_h_*/
