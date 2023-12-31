/*****************************************************************************
 * FILE NAME    : SectionHeader.h
 * DATE         : August 16 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _sectionheader_h_
#define _sectionheader_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SECTION_HEADER_X                200
#define SECTION_HEADER_Y                200
#define SECTION_HEADER_WIDTH            200
#define SECTION_HEADER_HEIGHT           30

/*****************************************************************************!
 * Exported Class : SectionHeader
 *****************************************************************************/
class SectionHeader : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  SectionHeader                 ();

 //! Destructor
 public :
  ~SectionHeader                ();

 //! Public Methods
 public :
  void                          SetText                 (QString InText);

 //! Public Data
 public :

 //! Protected Methods
 protected :
  void
  SetBackgroundColor
  (int InHeight);

 //! Protected Data
 protected :
  QLabel*                       HeaderText;
  QColor                        backgroundColor;
  QColor                        textColor;
  
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

#endif /* _sectionheader_h_*/
