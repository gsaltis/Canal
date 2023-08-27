/*****************************************************************************
 * FILE NAME    : SystemConfig.h
 * DATE         : August 12 2023
 * PROJECT      : Canal
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _systemconfig_h_
#define _systemconfig_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"
#include "WindowSizeInfo.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SystemConfig
 *****************************************************************************/
class SystemConfig : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SystemConfig                  ();

 //! Destructor
 public :
  ~SystemConfig                 ();

 //! Public Methods
 public :
  QList<int>
  GetWindowWidths
  ();

  QList<int>
  GetColumnWidths
  (int InIndex);
  
  void
  SetWindowSizeInfo
  (int InIndex, int InWindowWidth, QList<int> InColumnWidths);
  
  QString
  GetSystemName
  ();

  void
  Initialize
  ();

  void
  Save
  ();

  void
  Read
  (void);

  QColor
  GetSectionHeaderBackgroundColor
  ();

  QSize
  GetMainWindowSize
  ();

  QPoint
  GetMainWindowPosition
  ();
  
 //! Public Data
 public :
  QString
  SystemName;

  QList<int>
  WindowWidths;

  QColor
  SectionHeaderBackgroundColor;
  
 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void
  ReadWindowInfo
  (QJsonObject InObj);

 //! Private Data
 private :
  std::vector<WindowSizeInfo*>
  WindowsInfo;

  QSize
  MainWindowSize;

  QPoint
  MainWindowPosition;
    
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _systemconfig_h_*/
