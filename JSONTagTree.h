/*****************************************************************************
 * FILE NAME    : JSONTagTree.h
 * DATE         : August 13 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsontagtree_h_
#define _jsontagtree_h_

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

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONTAG_TREE_X                  200
#define JSONTAG_TREE_Y                  200
#define JSONTAG_TREE_WIDTH              200
#define JSONTAG_TREE_HEIGHT             200

/*****************************************************************************!
 * Exported Class : JSONTagTree
 *****************************************************************************/
class JSONTagTree : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONTagTree                   ();

 //! Destructor
 public :
  ~JSONTagTree                  ();

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
  void                          SlotClearChildren       (void);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsontagtree_h_*/
