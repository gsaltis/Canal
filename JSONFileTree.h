/*****************************************************************************
 * FILE NAME    : JSONFileTree.h
 * DATE         : August 12 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfiletree_h_
#define _jsonfiletree_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include <QWidget>
#include <QJsonObject>
#include <QString>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileTreeItem.h"
#include "TranslationUnitObject.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_TREE_X                 200
#define JSONFILE_TREE_Y                 200
#define JSONFILE_TREE_WIDTH             200
#define JSONFILE_TREE_HEIGHT            200

/*****************************************************************************!
 * Exported Class : JSONFileTree
 *****************************************************************************/
class JSONFileTree : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileTree                  ();

 //! Destructor
 public :
  ~JSONFileTree                 ();

 //! Public Methods
 public :
  void                          Set(TranslationUnitObject* InTranslationUnit);
  
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
  void                          SetInnerItem            (QJsonValue* InValue);
  void                          AddInnerObject          (JSONFileTreeItem* InItem, QJsonObject InObject);
  void                          SetObject               ();
  JSONFileTreeItem*             FindTopLevelItemByName  (QString InName);
  void                          ResetNameFonts          (void);
  void                          SortItems               (void);
  
 //! Private Data
 private :
  TranslationUnitObject*        TranslationUnit;
  JSONFileTreeItem*             EnumItems;
  JSONFileTreeItem*             RecordItems;
  JSONFileTreeItem*             TypeDefItems;
  JSONFileTreeItem*             VariableItems;
  JSONFileTreeItem*             FunctionDeclItems;
  JSONFileTreeItem*             FunctionDefItems;
  JSONFileTreeItem*             OtherItems;
  JSONFileTreeItem*             NonLocalItems;

 //! Public Slots
 public slots :
  void                          SlotItemClicked         (QTreeWidgetItem*, int);
  void                          SlotSizeValueChanged    (int InSize);
  void                          SlotCallingFunctionFound (QString InFunctionName);
  void                          SlotClearChildren       (void);
  
 //! Public Signals
 signals :
  void                          SignalFileObjectSelected(QJsonObject);
  void                          SignalLocalCountSet     (int InLocalInnerCount);
  void                          SignalFileObjectClicked (void);
  
 //! Public Actions
 public :

};

#endif /* _jsonfiletree_h_*/
