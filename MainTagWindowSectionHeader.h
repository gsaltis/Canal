/*****************************************************************************
 * FILE NAME    : MainTagWindowSectionHeader.h
 * DATE         : August 17 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maintagwindowsectionheader_h_
#define _maintagwindowsectionheader_h_

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
#define MAIN_TAG_WINDOW_SECTION_HEADER_X 200
#define MAIN_TAG_WINDOW_SECTION_HEADER_Y 200
#define MAIN_TAG_WINDOW_SECTION_HEADER_WIDTH 200
#define MAIN_TAG_WINDOW_SECTION_HEADER_HEIGHT 200

/*****************************************************************************!
 * Exported Class : MainTagWindowSectionHeader
 *****************************************************************************/
class MainTagWindowSectionHeader : public SectionHeader
{
  Q_OBJECT;

 //! Constructors
 public :
  MainTagWindowSectionHeader    ();

 //! Destructor
 public :
  ~MainTagWindowSectionHeader   ();

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

#endif /* _maintagwindowsectionheader_h_*/
