/*****************************************************************************
 * FILE NAME    : MainDisplayFunctionSVGWindow.h
 * DATE         : August 25 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maindisplayfunctionsvgwindow_h_
#define _maindisplayfunctionsvgwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONObjectFormatList.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_DISPLAY_FUNCTION_SVGWINDOW_X 200
#define MAIN_DISPLAY_FUNCTION_SVGWINDOW_Y 200
#define MAIN_DISPLAY_FUNCTION_SVGWINDOW_WIDTH 200
#define MAIN_DISPLAY_FUNCTION_SVGWINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : MainDisplayFunctionSVGWindow
 *****************************************************************************/
class MainDisplayFunctionSVGWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayFunctionSVGWindow          (QWidget* InParent, QString InFilename, QString InBaseFilename, QJsonObject InMainJSONObject, JSONObjectFormatList* InObjectsFormats);

 //! Destructor
 public :
  ~MainDisplayFunctionSVGWindow ();

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
  QString                       filename;
  QString                       baseFilename;
  QJsonObject                   mainJSONObject;
  JSONObjectFormatList*         formatList;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _maindisplayfunctionsvgwindow_h_*/
