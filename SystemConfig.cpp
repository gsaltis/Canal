/*****************************************************************************
 * FILE NAME    : SystemConfig.cpp
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
#include "SystemConfig.h"
#include "common.h"
#include "MainDisplayWindow.h"
#include "Trace.h"

/*****************************************************************************!
 * Static Data
 *****************************************************************************/

/*****************************************************************************!
 * Function : SystemConfig
 *****************************************************************************/
SystemConfig::SystemConfig
() : QWidget()
{
  Initialize();
}

/*****************************************************************************!
 * Function : ~SystemConfig
 *****************************************************************************/
SystemConfig::~SystemConfig
()
{
}

/*****************************************************************************!
 * Function : GetWindowWidth
 *****************************************************************************/
QList<int>
SystemConfig::GetWindowWidths
()
{
  return WindowWidths;
}

/*****************************************************************************!
 * Function : SetWindowWidths
 *****************************************************************************/
void
SystemConfig::SetWindowWidths
(QList<int> InWindowWidths)
{
  WindowWidths = InWindowWidths;
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
SystemConfig::Initialize
()
{
  SystemName = "Canal";
  WindowWidths = QList<int>();
}

/*****************************************************************************!
 * Function : GetSystemName
 *****************************************************************************/
QString
SystemConfig::GetSystemName
()
{
  return SystemName;
}

/*****************************************************************************!
 * Function : Save
 *****************************************************************************/
void
SystemConfig::Save
()
{
  QJsonDocument                         jsonDoc;
  QString                               st;
  QString                               filename;
  QFile                                 file;
  QJsonObject                           obj;
  QJsonObject                           obj2;
  QJsonArray                            array1;
  QList<int>                            width;
  
  filename = QString("%1%2.json").
    arg(MainDirectoryManager->GetSystemDir()).
    arg(MainSystemConfig->GetSystemName());

  array1.append(QJsonValue(WindowWidths[0]));
  array1.append(QJsonValue(WindowWidths[1]));
  array1.append(QJsonValue(WindowWidths[2]));
  array1.append(QJsonValue(WindowWidths[3]));

  obj2.insert("Widths", QJsonValue(array1));
  obj.insert("Window", QJsonValue(obj2));

  jsonDoc = QJsonDocument(obj);
  st = QString(jsonDoc.toJson());
  file.setFileName(filename);
  if ( ! file.open(QIODevice::ReadWrite | QIODevice::Truncate) ) {
    return;
  }
  file.close();
  
  if ( ! file.open(QIODevice::ReadWrite)) {
    return;
  }

  file.write(st.toLatin1());
  file.close();
}

/*****************************************************************************!
 * Function : Read
 *****************************************************************************/
void
SystemConfig::Read(void)
{
  QJsonObject                           windowObj;
  QJsonObject                           obj;
  QJsonDocument                         doc;
  QFile                                 file;
  QString                               filename;

  filename = QString("%1%2.json").
    arg(MainDirectoryManager->GetSystemDir()).
    arg(MainSystemConfig->GetSystemName());
  
  file.setFileName(filename);
  if ( ! file.open(QIODevice::ReadOnly) ) {
    return;
  }

  doc = QJsonDocument::fromJson(file.readAll());
  obj = doc.object();
  if ( obj.isEmpty() ) {
    return;
  }

  windowObj = obj["Window"].toObject();
  if ( ! windowObj.isEmpty() ) {
    ReadWindowInfo(windowObj);
  }
  file.close();
}

/*****************************************************************************!
 * Function : ReadWindowInfo
 *****************************************************************************/
void
SystemConfig::ReadWindowInfo
(QJsonObject InObj)
{
  int                                   width;
  QJsonArray                            sizesArray;
  if ( InObj.isEmpty() ) {
    return;
  }

  sizesArray = InObj["Widths"].toArray();
  if ( sizesArray.count() != MAIN_DISPLAY_WINDOW_COUNT ) {
    return;
  }
  WindowWidths.clear();

  for ( int i = 0; i < sizesArray.count() ; i++ ) {
    width = sizesArray[i].toInt();
    WindowWidths << width;
  }
}
