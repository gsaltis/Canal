/*****************************************************************************
 * FILE NAME    : MainMessageWindow.cpp
 * DATE         : August 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainMessageWindow.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define MESSAGE_TIMEOUT_PERIOD          (30 * 1000)

/*****************************************************************************!
 * Function : MainMessageWindow
 *****************************************************************************/
MainMessageWindow::MainMessageWindow
() : QFrame()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainMessageWindow
 *****************************************************************************/
MainMessageWindow::~MainMessageWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainMessageWindow::initialize()
{
  NormalColor = QColor(0, 0, 0);
  ErrorColor = QColor(128, 0, 0);
  timer = new QTimer();
  timer->setSingleShot(true);
  setFrameShape(QFrame::Box);
  setFrameShadow(QFrame::Sunken);
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainMessageWindow::CreateConnections
()
{
  connect(timer,
          SIGNAL(timeout()),
          this,
          SLOT(SlotTimeout()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainMessageWindow::CreateSubWindows()
{

  //! Create label  
  message = new QLabel();
  message->setParent(this);
  message->move(10, 1);
  message->resize(100, 23);
  message->setText("None");
  message->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  message->setFont(QFont("Segoe UI", 10, QFont::Bold));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainMessageWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainMessageWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   messageW;
  int                                   messageX;
  int                                   messageY;
  int                                   messageH;
  QSize                                 size;  
  int                                   width;

  size = InEvent->size();
  width = size.width();
  messageW = width - 5;
  messageX = 5;
  messageY = message->pos().y();
  messageH = message->size().height();

  message->resize(messageW, messageH);
  message->move(messageX, messageY);
}

/*****************************************************************************!
 * Function : SetMessageNormal
 *****************************************************************************/
void
MainMessageWindow::SetMessageNormal
(QString InMessage)
{
  SetMessage(InMessage, NormalColor);
}

/*****************************************************************************!
 * Function : SetMessageError
 *****************************************************************************/
void
MainMessageWindow::SetMessageError
(QString InMessage)
{
  SetMessage(InMessage, ErrorColor);
}

/*****************************************************************************!
 * Function : ClearMessage
 *****************************************************************************/
void
MainMessageWindow::ClearMessage
()
{
  SetMessage("", NormalColor);
}

/*****************************************************************************!
 * Function : SetMessage
 *****************************************************************************/
void
MainMessageWindow::SetMessage
(QString InMessage, QColor InColor)
{
  QPalette                              pal;

  timer->start(MESSAGE_TIMEOUT_PERIOD);
  pal = message->palette();
  pal.setBrush(QPalette::WindowText, QBrush(InColor));
  message->setPalette(pal);
  message->setText(InMessage);
}

/*****************************************************************************!
 * Function : SlotSetMessageNormal
 *****************************************************************************/
void
MainMessageWindow::SlotSetMessageNormal
(QString InMessage)
{
  SetMessageNormal(InMessage);
}

/*****************************************************************************!
 * Function : SlotTimeout
 *****************************************************************************/
void
MainMessageWindow::SlotTimeout(void)
{
  ClearMessage();
}
