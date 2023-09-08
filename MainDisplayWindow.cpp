/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
 * DATE         : August 12 2023
 * PROJECT      : Canal
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
#include "MainDisplayWindow.h"
#include "common.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::MainDisplayWindow
(TranslationUnitObject* InTranslationUnit, int InWindowIndex) : QWidget()
{
  QPalette                              pal;

  TranslationUnit = InTranslationUnit;
  windowIndex = InWindowIndex;
  if ( ! TranslationUnit->GetFilename().isEmpty() ) {
    HandleInputFilename();
  }
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(160, 160, 160)));
  setPalette(pal);
  setAutoFillBackground(true);

  Initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::~MainDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainDisplayWindow::Initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  SlotSelectWindow(windowIndex);
  CreateConnections();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindow::InitializeSubWindows()
{
  messageWindow = NULL;
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  QList<int>                            widths;

  treesWindow = new MainDisplayJSONTreesWindow(this, TranslationUnit);

  functionSVGWindow = new MainDisplayFunctionSVGWindow(this, TranslationUnit->GetFilename(),
                                                       TranslationUnit->GetBaseFilename(),
                                                       TranslationUnit->GetJSONObject(),
                                                       TranslationUnit->GetObjectFormats());
  functionSVGWindow->hide();
  messageWindow = new MainMessageWindow();
  messageWindow->setParent(this);
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   messageWindowY;
  int                                   h;
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();

  h = height - MAIN_MESSAGE_WINDOW_HEIGHT;

  if ( treesWindow ) {
    treesWindow->resize(width, h);
  }
  if ( functionSVGWindow ) {
    functionSVGWindow->resize(width, h);
  }
  messageWindowY = height - MAIN_MESSAGE_WINDOW_HEIGHT;
  
  if ( messageWindow ) {
    messageWindow->resize(width, MAIN_MESSAGE_WINDOW_HEIGHT);
    messageWindow->move(0, messageWindowY);
  }
}

/*****************************************************************************!
 * Function : HandleInputFilename
 *****************************************************************************/
void
MainDisplayWindow::HandleInputFilename(void)
{
  QJsonParseError                       jsonError;
  QByteArray                            array;
  QString                               filename = TranslationUnit->GetFilename();
  QFileInfo                             fileinfo(filename);
  QFile                                 file(filename);

  if ( !file.open(QIODevice::ReadOnly) ) {
    fprintf(stderr, "Could not open %s\n", filename.toStdString().c_str());
    return;
  }
  array = file.readAll();
  file.close();
  jsonDoc = QJsonDocument::fromJson(array, &jsonError);
  if ( jsonDoc.isEmpty() ) {
    printf("JSON Parser error : %d : %s\n", jsonError.offset, jsonError.errorString().toStdString().c_str());
    return;
  }
  TranslationUnit->SetJSONObject(jsonDoc.object());
  MainFunctionsDatabase->ReadFunctions(TranslationUnit);
  MainFunctionsDatabase->Save("Functions.txt");
}

/*****************************************************************************!
 * Function : SaveAtExit
 *****************************************************************************/
void
MainDisplayWindow::SaveAtExit
()
{
  treesWindow->SaveAtExit();
}

/*****************************************************************************!
 * Function : SlotSelectWindow
 *****************************************************************************/
void
MainDisplayWindow::SlotSelectWindow
(int InWindowIndex)
{
  if ( InWindowIndex == 1 ) {
    treesWindow->show();
    functionSVGWindow->hide();
    return;
  }
  if ( InWindowIndex == 2 ) {
    treesWindow->hide();
    functionSVGWindow->show();
    return;
  }
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
MainDisplayWindow::SlotClearChildren(void)
{
  emit SignalClearChildren();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainDisplayWindow::CreateConnections(void)
{
  connect(this,
          SIGNAL(SignalClearChildren()),
          treesWindow,
          SLOT(SlotClearChildren()));
  connect(this,
          SIGNAL(SignalSetMessageNormal(QString)),
          messageWindow,
          SLOT(SlotSetMessageNormal(QString)));
  connect(treesWindow,
          SIGNAL(SignalNormalMessage(QString)),
          messageWindow,
          SLOT(SlotSetMessageNormal(QString)));

  connect(treesWindow,
          SIGNAL(SignalProgressBarShow()),
          messageWindow,
          SLOT(SlotProgressBarShow()));
  
  connect(treesWindow,
          SIGNAL(SignalProgressBarHide()),
          messageWindow,
          SLOT(SlotProgressBarHide()));
  
  connect(treesWindow,
          SIGNAL(SignalProgressBarSet(int, int)),
          messageWindow,
          SLOT(SlotProgressBarSet(int, int)));
  
  connect(treesWindow,
          SIGNAL(SignalProgressBarUpdate(int)),
          messageWindow,
          SLOT(SlotProgressBarUpdate(int)));
  
}

/*****************************************************************************!
 * Function : OpenNewFile
 *****************************************************************************/
void
MainDisplayWindow::OpenNewFile
()
{
  HandleInputFilename();
  treesWindow->OpenNewFile(TranslationUnit);
}

/*****************************************************************************!
 * Function : SlotSetMessageNormal
 *****************************************************************************/
void
MainDisplayWindow::SlotSetMessageNormal
(QString InMessage)
{
  emit SignalSetMessageNormal(InMessage);
}

