/*****************************************************************************
 FILE NAME      : main.cpp
 DATE           : August 12 2023
 PROJECT        : Canal
 COPYRIGHT      : Copyright (C) 2023 by Gregory R Saltis
******************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QtGui>
#include <QCommandLineParser>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"
#include "main.h"
#include "JSONObjectFormatList.h"
#include "common.h"
#include "trace.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void
MainExisting
(void);

void
MainInitialize
();

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
JSONObjectFormatList
MainObjectsFormats;

MainWindow*
mainWindow;

DirectoryManagement*
MainDirectoryManager = NULL;

SystemConfig*
MainSystemConfig = NULL;

QColor
MainTreeHeaderColor = QColor(128, 128, 128);

QList<QJsonObject>
MainTopLevelObjects;

int
MainFirstLocalElementIndex = 0;

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  QString                               MainSourceFilename;
  QStringList                           args;
  QApplication                          application(argc, argv);
  QCommandLineParser                    parser;

  MainInitialize();
  
  atexit(MainExisting);
  application.setApplicationName("Canal");
  application.setApplicationVersion("0.1.0");
  application.setOrganizationName("Greg Saltis");
  application.setOrganizationDomain("www.gsaltis.com");

  parser.addHelpOption();
  parser.addVersionOption();
  parser.setApplicationDescription("C/C++ Analyzer Helper");
  parser.addPositionalArgument("source", "Specify source input file");

  parser.process(application);
  args = parser.positionalArguments();

  if ( args.size() > 0 ) {
    MainSourceFilename = args[0];
  }

  if ( MainSourceFilename.isEmpty() ) {
    fprintf(stderr, "Missing input filename\n");
    return EXIT_FAILURE;
  }
  mainWindow = new MainWindow(NULL, MainSourceFilename, &MainObjectsFormats);
  mainWindow->resize(MainSystemConfig->GetMainWindowSize());
  mainWindow->move(MainSystemConfig->GetMainWindowPosition());
  mainWindow->setWindowTitle(MainSystemConfig->GetSystemName() +
                             QString ( " : ") +
                             MainSourceFilename);
  // w->showMaximized();
  mainWindow->show();
  return application.exec();
}

/*****************************************************************************!
 * Function : MainExisting
 *****************************************************************************/
void
MainExisting
(void)
{
  mainWindow->SaveAtExit();
  MainSystemConfig->Save();
}

/*****************************************************************************!
 * Function : MainInitialize
 *****************************************************************************/
void
MainInitialize
()
{
  MainDirectoryManager = new DirectoryManagement();
  MainSystemConfig = new SystemConfig();
  MainSystemConfig->Read();
}
