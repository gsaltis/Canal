/*****************************************************************************
 * FILE NAME    : JSONFileTreeHeader.h
 * DATE         : August 13 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfiletreeheader_h_
#define _jsonfiletreeheader_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QHeaderView>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_TREE_HEADER_X          200
#define JSONFILE_TREE_HEADER_Y          200
#define JSONFILE_TREE_HEADER_WIDTH      200
#define JSONFILE_TREE_HEADER_HEIGHT     200

/*****************************************************************************!
 * Exported Class : JSONFileTreeHeader
 *****************************************************************************/
class JSONFileTreeHeader : public QHeaderView
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileTreeHeader            ();

 //! Destructor
 public :
  ~JSONFileTreeHeader           ();

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
  void                          paintEvent              (QPaintEvent* InEvent);
  
 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonfiletreeheader_h_*/
