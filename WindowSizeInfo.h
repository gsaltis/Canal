/*****************************************************************************
 * FILE NAME    : WindowSizeInfo.h
 * DATE         : August 18 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _windowsizeinfo_h_
#define _windowsizeinfo_h_

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

/*****************************************************************************!
 * Exported Class : WindowSizeInfo
 *****************************************************************************/
class WindowSizeInfo : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  WindowSizeInfo                ();

 //! Destructor
 public :
  ~WindowSizeInfo               ();

 //! Public Methods
 public :
  int                           GetWindowWidth          (void);
  void                          SetWindowWidth          (int InWindowWidth);
  std::vector<int>              GetColumnWidths         (void);
  void                          SetColumnWidths         (std::vector<int> InColumnWidths);
  void                          SetColumnWidths         (QList<int> InColumnWidths);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :
  int                           windowWidth;
  std::vector<int>              columnWidths;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _windowsizeinfo_h_*/
