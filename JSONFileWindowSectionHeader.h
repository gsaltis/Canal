/*****************************************************************************
 * FILE NAME    : JSONFileWindowSectionHeader.h
 * DATE         : August 17 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfilewindowsectionheader_h_
#define _jsonfilewindowsectionheader_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QAction>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SectionHeader.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : JSONFileWindowSectionHeader
 *****************************************************************************/
class JSONFileWindowSectionHeader : public SectionHeader
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileWindowSectionHeader   ();

 //! Destructor
 public :
  ~JSONFileWindowSectionHeader  ();

 //! Public Methods
 public :
  void                          SetInnerCount           (int InCount);

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
  QPushButton*                  ResizeButton;
  QLabel*                       ElementCountLabel;

 //! Public Slots
 public slots :
  void                          SlotResizePushed        (void);
  void                          SlotSizeValueChanged    (int InSize);

 //! Public Signals
 signals :
  void                          SignalSizeValueChanged  (int InSize);

 //! Public Actions
 public :
  QAction*                      ActionResizePushed;

};

#endif /* _jsonfilewindowsectionheader_h_*/
