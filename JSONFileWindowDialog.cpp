/*****************************************************************************
 * FILE NAME    : JSONFileWindowDialog.cpp
 * DATE         : August 18 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileWindowDialog.h"

/*****************************************************************************!
 * Function : JSONFileWindowDialog
 *****************************************************************************/
JSONFileWindowDialog::JSONFileWindowDialog
() : QDialog()
{
  QPalette				pal;

  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(160, 160, 180)));
  setPalette(pal);
  setAutoFillBackground(true);
  Initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileWindowDialog
 *****************************************************************************/
JSONFileWindowDialog::~JSONFileWindowDialog
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
JSONFileWindowDialog::Initialize(void)
{
  setWindowTitle("RESIZE COLUMN");
  CreateSubWindows();  
  CreateConnections();
  resize(JSONFILE_WINDOW_DIALOG_WIDTH, JSONFILE_WINDOW_DIALOG_HEIGHT);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
JSONFileWindowDialog::CreateConnections(void)
{
  connect(OKButton, SIGNAL(pressed()), this, SLOT(SlotOKButtonPressed()));  
  connect(CancelButton, SIGNAL(pressed()), this, SLOT(SlotCancelButtonPressed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileWindowDialog::CreateSubWindows(void)
{
  QLabel*                               label;
  int                                   buttonHeight;
  int                                   buttonGap;
  int                                   cancelButtonX;
  int                                   okButtonX;
  int                                   buttonY;
  int                                   cancelButtonWidth;
  int                                   okButtonWidth;
  
  okButtonWidth = 40;
  cancelButtonWidth = 60;
  buttonGap = 5;
  buttonHeight = 20;
  okButtonX = JSONFILE_WINDOW_DIALOG_WIDTH - (okButtonWidth + cancelButtonWidth + (2 * buttonGap));
  cancelButtonX = JSONFILE_WINDOW_DIALOG_WIDTH - (cancelButtonWidth + buttonGap);
  buttonY = JSONFILE_WINDOW_DIALOG_HEIGHT - (buttonGap + buttonHeight);
 
  OKButton = new QPushButton();
  OKButton->setParent(this);
  OKButton->setText("OK");
  OKButton->move(okButtonX, buttonY);
  OKButton->resize(okButtonWidth, buttonHeight);
  
  CancelButton = new QPushButton();
  CancelButton->setParent(this);
  CancelButton->setText("Cancel");
  CancelButton->move(cancelButtonX, buttonY);
  CancelButton->resize(cancelButtonWidth, buttonHeight);

  //!
  spinBox = new QSpinBox(this);
  spinBox->move(5, 30);
  connect(spinBox,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotSizeValueChanged(int)));
  
  //! Create label  
  label = new QLabel();
  label->setParent(this);
  label->move(5, 5);
  label->resize(200, 20);
  label->setText("RESIZE");
  label->setAlignment(Qt::AlignLeft);
  label->setFont(QFont("Segoe UI", 13, QFont::Bold));
}

/*****************************************************************************!
 * Function : SlotOKButtonPressed
 *****************************************************************************/
void
JSONFileWindowDialog::SlotOKButtonPressed()
{
  accept();
}

/*****************************************************************************!
 * Function : SlotCancelButtonPressed
 *****************************************************************************/
void
JSONFileWindowDialog::SlotCancelButtonPressed()
{
  reject();
}

/*****************************************************************************!
 * Function : resize
 *****************************************************************************/
void
JSONFileWindowDialog::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   w;
  int                                   h;
  QSize                                 s = InEvent->size();
  int                                   width;
  width = s.width();

  w = width - 10;
  h = spinBox->size().height();

  spinBox->resize(w, h);
  spinBox->move(5, spinBox->pos().y());
  spinBox->setMaximum(200);
  spinBox->setMinimum(10);
  spinBox->setSingleStep(10);
}

/*****************************************************************************!
 * Function : SlotSizeValueChanged
 *****************************************************************************/
void
JSONFileWindowDialog::SlotSizeValueChanged
(int InSize)
{
  emit SignalSizeValueChanged(InSize);
}
