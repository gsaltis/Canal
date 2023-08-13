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

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  QString                               MainSourceFilename;
  QStringList                           args;
  QApplication 				application(argc, argv);
  MainWindow* 				w;
  QCommandLineParser                    parser;

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
    printf("%s\n", MainSourceFilename.toStdString().c_str());
  }
  w = new MainWindow(NULL, MainSourceFilename);
  w->resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
  w->move(MAIN_WINDOW_X, MAIN_WINDOW_Y);
  w->showMaximized();
  w->show();
  
  return application.exec();
}
