/*****************************************************************************
 * FILE NAME    : JSONFileObjectDisplayWindow.cpp
 * DATE         : August 15 2023
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
#include "JSONFileObjectDisplayWindow.h"
#include "Trace.h"
#include "common.h"

/*****************************************************************************!
 * Function : JSONFileObjectDisplayWindow
 *****************************************************************************/
JSONFileObjectDisplayWindow::JSONFileObjectDisplayWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~JSONFileObjectDisplayWindow
 *****************************************************************************/
JSONFileObjectDisplayWindow::~JSONFileObjectDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::CreateSubWindows()
{
  fileTree = new JSONFileObjectDisplayTree();  
  fileTree->setParent(this);
  connect(this,
          SIGNAL(SignalFileObjectSelected(QJsonObject)),
          fileTree,
          SLOT(SlotFileObjectSelected(QJsonObject)));
  connect(fileTree,
          SIGNAL(SignalFileElementSelected(QString, QList<QString>)),
          this,
          SLOT(SlotFileElementSelected(QString, QList<QString>)));
  connect(fileTree,
          SIGNAL(SignalFileElementIdentified(QString, QList<QString>)),
          this,
          SLOT(SlotObjectFormatIdentified(QString, QList<QString>)));
  header = new SectionHeader();
  header->setParent(this);

  connect(this,
          SIGNAL(SignalExpandTree()),
          fileTree,
          SLOT(SlotExpandTree()));
  
  connect(this,
          SIGNAL(SignalCollapseTree()),
          fileTree,
          SLOT(SlotCollapseTree()));
  
  ExpandButton = new QPushButton("Expand", header);
  ExpandButton->resize(60, 20);
  connect(ExpandButton,
          SIGNAL(clicked(bool)),
          this,
          SLOT(SlotExpandButtonClicked(bool)));
  
  CollapseButton = new QPushButton("Collapse", header);
  CollapseButton->resize(60, 20);
  connect(CollapseButton,
          SIGNAL(clicked(bool)),
          this,
          SLOT(SlotCollapseButtonClicked(bool)));

  DisplayButton = new QPushButton("Display");
  DisplayButton->resize(60, 20);
  connect(DisplayButton,
          SIGNAL(clicked(bool)),
          this,
          SLOT(SlotDisplayButtonClicked(bool)));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::InitializeSubWindows()
{
  fileTree = NULL;  
  header = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   DisplayButtonX;
  int                                   DisplayButtonW;
  int                                   ExpandButtonX;
  int                                   ExpandButtonW;
  int                                   CollapseButtonX;
  int                                   CollapseButtonW;
  int                                   fileTreeH;
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  fileTreeH = height - SECTION_HEADER_HEIGHT;
  
  if ( fileTree ) {
    fileTree->resize(width, fileTreeH);
    fileTree->move(0, SECTION_HEADER_HEIGHT);
  }
  if ( header ) {
    header->resize(width, SECTION_HEADER_HEIGHT);
  }

  ExpandButtonW = ExpandButton->size().width();
  ExpandButtonX = width - (ExpandButtonW + 5);
  ExpandButton->move(ExpandButtonX, 1);
  ExpandButton->resize(ExpandButtonW, SECTION_HEADER_HEIGHT - 2);

  CollapseButtonW = CollapseButton->size().width();
  CollapseButtonX = width - (CollapseButtonW + ExpandButtonW + 10);
  CollapseButton->move(CollapseButtonX, 1);
  CollapseButton->resize(CollapseButtonW, SECTION_HEADER_HEIGHT - 2);

  DisplayButtonW = DisplayButton->size().width();
  DisplayButtonX = width - (DisplayButtonW + CollapseButtonW + ExpandButtonW + 15);
  DisplayButton->move(DisplayButtonX, 1);
  DisplayButton->resize(DisplayButtonW, SECTION_HEADER_HEIGHT - 2);
}

/*****************************************************************************!
 * Function : SlotFileObjectSelected
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotFileObjectSelected
(QJsonObject InObject)
{
  QString                               name;
  emit SignalFileObjectSelected(InObject);
  fileObject = InObject;
  name = InObject["name"].toString();
  FindCalls(name);
  header->SetText(name);
}

/*****************************************************************************!
 * Function : SlotFileElementSelected
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotFileElementSelected
(QString InTag, QList<QString> InKeys)
{
  emit SignalFileElementSelected(InTag, InKeys);
}

/*****************************************************************************!
 * 
 *****************************************************************************/
QList<int>
JSONFileObjectDisplayWindow::GetColumnWidths
()
{
  int                                   i;
  int                                   n;
  QList<int>                            widths;
  
  n = fileTree->columnCount();
  for (i = 0; i < n; i++) {
    widths << fileTree->columnWidth(i);
  }
  return widths;
}

/*****************************************************************************!
 * Function : SlotObjectFormatSelected
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotObjectFormatSelected
(JSONObjectFormat* InObjectFormat)
{
  (void)InObjectFormat;
}

/*****************************************************************************!
 * Function : SlotObjectFormatIdentified
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotObjectFormatIdentified
(QString InTag, QStringList InKeys)
{
  emit SignalFileElementIdentified(InTag, InKeys);  
}

/*****************************************************************************!
 * Function : SlotExpandButtonClicked
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotExpandButtonClicked
(bool)
{
  emit SignalExpandTree();
}

/*****************************************************************************!
 * Function : SlotCollapseButtonClicked
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotCollapseButtonClicked
(bool)
{
  emit SignalCollapseTree();
}

/*****************************************************************************!
 * Function : SlotDisplayButtonClicked
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotDisplayButtonClicked
(bool)
{
}

/*****************************************************************************!
 * Function : FindCalls
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::FindCalls
(QString InFunctionName)
{
  int                                   n;
  int                                   i;
  QJsonObject                           obj;

  n = MainTopLevelObjects.count();

  for (i = 0; i < n; i++) {
    obj = MainTopLevelObjects[i];
    if ( ObjectIsFunctionDefinition(obj) ) {
      break;
    }
  }
  if ( i == n ) {
    return;
  }
  
  ObjectContainsCall(obj, InFunctionName);
}

/*****************************************************************************!
 * Function : ObjectContainsCall
 *****************************************************************************/
bool
JSONFileObjectDisplayWindow::ObjectContainsCall
(QJsonObject InObject, QString InFunctionName)
{
  QJsonObject                           obj;
  int                                   n;
  int                                   i;
  QJsonArray                            innerArray;
  QString                               name;

  name = InObject["name"].toString();
  TRACE_FUNCTION_QSTRING(name);
  TRACE_FUNCTION_QSTRING(InFunctionName);

  innerArray = GetFunctionCompountStmtInternals(InObject);
  TRACE_FUNCTION_LOCATION();
  n = innerArray.count();
  TRACE_FUNCTION_LOCATION();
  for (i = 0; i < n; i++) {
    obj = innerArray[i].toObject();
    if ( ObjectElementContainsCall(obj, InFunctionName) ) {
      TRACE_FUNCTION_LOCATION();
    }
  }
  TRACE_FUNCTION_INT(innerArray.count());
  return true;
}

/*****************************************************************************!
 * Function : ObjectIsFunctionDefinition
 *****************************************************************************/
bool
JSONFileObjectDisplayWindow::ObjectIsFunctionDefinition
(QJsonObject InObject)
{
  int                                   i;
  int                                   n;
  QJsonArray                            innerArray;
  QJsonValue                            innerValue;
  QJsonObject                           obj;
  QString                               kind;

  kind = InObject["kind"].toString();
  if (  kind.isEmpty() ) {
    return false;
  }

  innerValue = InObject["inner"];
  if ( ! innerValue.isArray() ) {
    return false;
  }

  innerArray = innerValue.toArray();

  n = innerArray.count();

  for (i = 0; i < n; i++) {
    obj = innerArray[i].toObject();
    kind = obj["kind"].toString();
    if ( kind == "CompoundStmt" ) {
      return true;
    }
  }
  return false;
}


/*****************************************************************************!
 * Function : GetFunctionCompountStmtInternals
 *****************************************************************************/
QJsonArray
JSONFileObjectDisplayWindow::GetFunctionCompountStmtInternals
(QJsonObject InObject)
{
  QString                               kind;
  QJsonObject                           obj;
  int                                   i;
  int                                   n;
  QJsonArray                            innerArray;
  QJsonValue                            innerValue;

  TRACE_FUNCTION_LOCATION();
  innerValue = InObject["inner"];
  if ( ! innerValue.isArray() ) {
    TRACE_FUNCTION_LOCATION();
    return QJsonArray();
  }

  innerArray = innerValue.toArray();

  n = innerArray.count();

  for (i = 0; i < n; i++) {
    obj = innerArray[i].toObject();
    kind = obj["kind"].toString();
    TRACE_FUNCTION_QSTRING(kind);
    if ( kind == "CompoundStmt" ) {
      innerValue = obj["inner"];
      if ( innerValue.isArray() ) {
        TRACE_FUNCTION_LOCATION();
        return innerValue.toArray();
      }
    }
  }
  TRACE_FUNCTION_LOCATION();
  return QJsonArray();
}

/*****************************************************************************!
 * Function : ObjectElementContainsCall
 *****************************************************************************/
bool
JSONFileObjectDisplayWindow::ObjectElementContainsCall
(QJsonObject InObject, QString InFunctionName)
{
  QString                               kind;
  QJsonValue                            value;
  QStringList                           keys;
  QJsonArray                            array;

  kind = InObject["kind"].toString();
  TRACE_FUNCTION_QSTRING(kind);
  keys = InObject.keys();

  for ( auto i = keys.begin() ; i != keys.end() ; i++ ) {
    QString                             key = *i;
    value = InObject[key];

    TRACE_FUNCTION_QSTRING(key);
    if ( value.isObject() ) {
      kind = value.toObject()["kind"].toString();
      if ( kind == "CallExpr") {
        return true;
      }
    }
  }
  return false;
}
