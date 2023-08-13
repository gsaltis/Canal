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
  JSONFileTree                  (QJsonObject InJSONFileObject, QString InFilename, QString InBaseFilename);

 //! Destructor
 public :
  ~JSONFileTree                 ();

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
  QJsonObject                   JSONFileObject;
  QString                       filename;
  QString                       baseFilename;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonfiletree_h_*/
