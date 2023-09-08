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
#include "JSONFileObjectDisplayTreeItem.h"

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
  void                          initialize                      ();
  void                          ExpandItem                      (JSONFileObjectDisplayTreeItem* InItem);
  void                          ExpandInnerCompoundStmt         (void);
  int                           GetItemCount                    (void);
  void                          CollapseItem                    (JSONFileObjectDisplayTreeItem* InItem);
  void                          CreateConnections               ();
  void                          OpenBinaryOperator              (JSONFileObjectDisplayTreeItem* InItem);
  void                          OpenIfStmt                      (JSONFileObjectDisplayTreeItem* InItem);
  void                          OpenCompoundStmt                (JSONFileObjectDisplayTreeItem* InItem);
  void                          OpenCallExpr                    (JSONFileObjectDisplayTreeItem* InItem);
  void                          OpenObjectInner                 (JSONFileObjectDisplayTreeItem* InItem);
  
 //! Private Data
 private :

 //! Public Slots
 public slots :
  void                          SlotFileObjectSelected          (QJsonObject);
  void                          SlotItemSelected                (QTreeWidgetItem* InItem, int InColumn);
  void                          SlotExpandTree                  (void);
  void                          SlotCollapseTree                (void);
  void                          SlotClearChildren               (void);
  void                          SlotItemExpanded                (QTreeWidgetItem* InItem);
  void                          SlotProgressBarShow             (void);
  void                          SlotProgressBarHide             (void);
  void                          SlotProgressBarSet              (int InMinimum, int InMaximum);
  void                          SlotProgressBarUpdate           (int InValue);
  
 //! Public Signals
 signals :
  void                          SignalFileElementSelected       (QString InTag, QList<QString> InKeys);
  void                          SignalFileElementIdentified     (QString InSearchTag, QStringList InKeys);
  void                          SignalValueSelected             (QJsonValue InValue);
  void                          SignalNormalMessage             (QString InMessage);
  void                          SignalProgressBarShow           (void);
  void                          SignalProgressBarHide           (void);
  void                          SignalProgressBarSet            (int InMinimum, int InMaximum);
  void                          SignalProgressBarUpdate         (int InValue);

 //! Public Actions
 public :

};

#endif /* _jsonfileobjectdisplaytree_h_*/
