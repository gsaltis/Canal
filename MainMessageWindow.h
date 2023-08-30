/*****************************************************************************
 * FILE NAME    : MainMessageWindow.h
 * DATE         : August 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainmessagewindow_h_
#define _mainmessagewindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QTimer>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_MESSAGE_WINDOW_X           200
#define MAIN_MESSAGE_WINDOW_Y           200
#define MAIN_MESSAGE_WINDOW_WIDTH       200
#define MAIN_MESSAGE_WINDOW_HEIGHT      25

/*****************************************************************************!
 * Exported Class : MainMessageWindow
 *****************************************************************************/
class MainMessageWindow : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  MainMessageWindow             ();

 //! Destructor
 public :
  ~MainMessageWindow            ();

 //! Public Methods
 public :
  void                          SetMessageNormal        (QString InMessage);
  void                          SetMessageError         (QString InMessage);
  void                          ClearMessage            ();
  
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
  void                          SetMessage              (QString InText, QColor InColor);
  void                          CreateConnections       ();
  
 //! Private Data
 private :
  QLabel*                       message;
  QColor                        NormalColor;
  QColor                        ErrorColor;
  QTimer*                       timer;
  
 //! Public Slots
 public slots :
  void                          SlotSetMessageNormal    (QString InMessage);
  void                          SlotTimeout             (void);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _mainmessagewindow_h_*/
