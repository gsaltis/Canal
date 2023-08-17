/*****************************************************************************
 * FILE NAME    : JSONElementWindowSectionHeader.h
 * DATE         : August 17 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonelementwindowsectionheader_h_
#define _jsonelementwindowsectionheader_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SectionHeader.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : JSONElementWindowSectionHeader
 *****************************************************************************/
class JSONElementWindowSectionHeader : public SectionHeader
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONElementWindowSectionHeader ();

 //! Destructor
 public :
  ~JSONElementWindowSectionHeader ();

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

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _jsonelementwindowsectionheader_h_*/
