/*****************************************************************************
 * FILE NAME    : JSONFileWindowDialog.h
 * DATE         : August 18 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _jsonfilewindowdialog_h_
#define _jsonfilewindowdialog_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QPushButton>
#include <QSpinBox>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define JSONFILE_WINDOW_DIALOG_WIDTH            300
#define JSONFILE_WINDOW_DIALOG_HEIGHT           400

/*****************************************************************************!
 * Exported Class : JSONFileWindowDialog
 *****************************************************************************/
class JSONFileWindowDialog : public QDialog
{
  Q_OBJECT;

 //! Constructors
 public :
  JSONFileWindowDialog          ();

 //! Destructor
 public :
  ~JSONFileWindowDialog         ();

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
  void                          Initialize              (void);
  void                          CreateConnections       (void);
  void                          CreateSubWindows        (void);
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  QPushButton*                  OKButton;
  QPushButton*                  CancelButton;
  QSpinBox*                     spinBox;

 //! Public Slots
 public slots :
  void                          SlotOKButtonPressed     ();
  void                          SlotCancelButtonPressed ();
  void                          SlotSizeValueChanged    (int InSize);

 //! Public Signals
 signals :
  void                          SignalSizeValueChanged  (int InSize);

 //! Public Actions
 public :

};

#endif /* _jsonfilewindowdialog_h_*/
