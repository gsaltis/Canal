/*****************************************************************************
 * FILE NAME    : DisplayFunctionSVGNamePane.h
 * DATE         : August 28 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _displayfunctionsvgnamepane_h_
#define _displayfunctionsvgnamepane_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define DISPLAY_FUNCTION_SVGNAME_PANE_X 0
#define DISPLAY_FUNCTION_SVGNAME_PANE_Y 0
#define DISPLAY_FUNCTION_SVGNAME_PANE_WIDTH 400
#define DISPLAY_FUNCTION_SVGNAME_PANE_HEIGHT 200

/*****************************************************************************!
 * Exported Class : DisplayFunctionSVGNamePane
 *****************************************************************************/
class DisplayFunctionSVGNamePane : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  DisplayFunctionSVGNamePane    ();

 //! Destructor
 public :
  ~DisplayFunctionSVGNamePane   ();

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

#endif /* _displayfunctionsvgnamepane_h_*/
