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
 * Function : Initialize
 *****************************************************************************/
void
SystemConfig::Initialize
()
{

  for (int i = 0 ; i < 4; i++ ) {
    WindowsInfo.push_back(new WindowSizeInfo());
  }
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
  QJsonArray                            columnArray;
  QJsonObject                           widthObj;
  QJsonArray                            widths;
  QJsonDocument                         jsonDoc;
  QString                               st;
  QString                               filename;
  QFile                                 file;
  QJsonObject                           obj;
  QJsonObject                           obj2;
  QJsonArray                            array1;
  QList<int>                            width;
  QJsonObject                           windowObj;
  
  filename = QString("%1%2.json").
    arg(MainDirectoryManager->GetSystemDir()).
    arg(MainSystemConfig->GetSystemName());

  obj = QJsonObject();
  windowObj = QJsonObject();
  
  widths = QJsonArray();

  for ( int i = 0 ; i < 4; i++ ) {
    WindowSizeInfo*                     w = WindowsInfo[i];
    std::vector<int>                    columnWidths;
    
    widthObj = QJsonObject();
    widthObj.insert("Width", QJsonValue(w->GetWindowWidth()));
    columnWidths = w->GetColumnWidths();
    columnArray = QJsonArray();
    for ( unsigned long int k = 0; k < columnWidths.size() ; k++ ) {
      columnArray.append(QJsonValue(columnWidths[k]));
    }
    widthObj.insert("Columns", QJsonValue(columnArray));
    widths.append(QJsonValue(widthObj));
  }
  windowObj.insert("Widths", QJsonValue(widths));
  obj.insert("Window", QJsonValue(windowObj));

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
  QJsonArray                            columns;
  QJsonObject                           info;
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
    WindowSizeInfo*                     sizeinfo = WindowsInfo[i];
    QList<int>                          columnWidths;
    
    info = sizesArray[i].toObject();
    width = info["Width"].toInt();
    sizeinfo->SetWindowWidth(width);

    columns = info["Columns"].toArray();
    for ( int k = 0 ; k < columns.size(); k++ ) {
      columnWidths << columns[k].toInt();
    }
    sizeinfo->SetColumnWidths(columnWidths);
  }
}

/*****************************************************************************!
 * Function : GetWindowWidths
 *****************************************************************************/
QList<int>
SystemConfig::GetWindowWidths
()
{
  QList<int>                    widths;
  
  for ( unsigned long int i = 0 ; i < WindowsInfo.size() ; i++ ) {
    widths << WindowsInfo[i]->GetWindowWidth();
  }
  return widths;
}

/*****************************************************************************!
 * Function : GetColumnWidths
 *****************************************************************************/
QList<int>
SystemConfig::GetColumnWidths
(int InIndex)
{
  QList<int>                    columnWidths;

  if ( InIndex > (int)WindowsInfo.size() ) {
    return columnWidths;
  }

  std::vector<int>              n = WindowsInfo[InIndex]->GetColumnWidths();
  for ( unsigned long int i = 0; i < n.size(); i++ ) {
    columnWidths << n[i];
  }
  return columnWidths;
}

/*****************************************************************************!
 * Function : SetWindowSizeInfo
 *****************************************************************************/
void
SystemConfig::SetWindowSizeInfo
(int InIndex, int InWindowWidth, QList<int> InColumnWidths)
{
  if ( InIndex > (int)WindowsInfo.size() ) {
    return;
  }
  WindowsInfo[InIndex]->SetWindowWidth(InWindowWidth);
  WindowsInfo[InIndex]->SetColumnWidths(InColumnWidths);
}

