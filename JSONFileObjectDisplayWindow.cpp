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
#include "JSONNavigate.h"

/*****************************************************************************!
 * Function : JSONFileObjectDisplayWindow
 *****************************************************************************/
JSONFileObjectDisplayWindow::JSONFileObjectDisplayWindow
(TranslationUnitObject* InTranslationUnit) : QWidget()
{
  TranslationUnit = InTranslationUnit;
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
  SetColumnWidths(MainSystemConfig->GetColumnWidths(3));
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
  ActionCollapseElements = new QAction(QIcon(":/Images/Collapse.png"), "CollapseElements", this);
  connect(ActionCollapseElements, SIGNAL(triggered()), this, SLOT(SlotCollapseElements()));
  ActionExpandElements = new QAction(QIcon(":/Images/Expand.png"), "ExpandElements", this);
  connect(ActionExpandElements, SIGNAL(triggered()), this, SLOT(SlotExpandElements()));
  Toolbar->addAction(ActionExpandElements);
  Toolbar->addAction(ActionCollapseElements);
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

  connect(fileTree,
          SIGNAL(SignalValueSelected(QJsonValue)),
          this,
          SLOT(SlotValueSelected(QJsonValue)));

  connect(this,
          SIGNAL(SignalClearChildren()),
          fileTree,
          SLOT(SlotClearChildren()));
  
  Toolbar = new QToolBar(this);
  Toolbar->resize(34, 100);
  Toolbar->move(0, 0);
  Toolbar->setOrientation(Qt::Vertical);
  Toolbar->setIconSize(QSize(32, 32));
  DisplayButton = new QPushButton("Display");
  DisplayButton->resize(60, 20);
  connect(DisplayButton,
          SIGNAL(clicked(bool)),
          this,
          SLOT(SlotDisplayButtonClicked(bool)));
  elementDisplayWindow = new JSONFileObjectElementDisplayWindow();
  elementDisplayWindow->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::InitializeSubWindows()
{
  fileTree = NULL;  
  header = NULL;
  elementDisplayWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   elementDisplayWindowW;
  int                                   elementDisplayWindowY;
  int                                   elementDisplayWindowH;
  int                                   elementDisplayWindowX;
  int                                   fileTreeW;
  int                                   DisplayButtonX;
  int                                   DisplayButtonW;
  int                                   fileTreeH;
  QSize                                 size;  
  int                                   width;
  int                                   height;
  int                                   toolbarW;
  int                                   toolbarH;
  int                                   toolbarX;
  int                                   toolbarY;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();

  toolbarW = Toolbar->size().width();
  toolbarX = width - toolbarW;
  toolbarH = height - SECTION_HEADER_HEIGHT;
  toolbarY = SECTION_HEADER_HEIGHT;
  
  fileTreeH = height - (SECTION_HEADER_HEIGHT + JSONFILE_OBJECT_ELEMENT_DISPLAY_WINDOW_HEIGHT);
  fileTreeW = width - toolbarW;

  elementDisplayWindowX = 0;
  elementDisplayWindowH = JSONFILE_OBJECT_ELEMENT_DISPLAY_WINDOW_HEIGHT;
  elementDisplayWindowY = height - elementDisplayWindowH;
  elementDisplayWindowW = width - toolbarW;
  
  if ( fileTree ) {
    fileTree->resize(fileTreeW, fileTreeH);
    fileTree->move(0, SECTION_HEADER_HEIGHT);
  }
  if ( header ) {
    header->resize(width, SECTION_HEADER_HEIGHT);
  }

  Toolbar->move(toolbarX, toolbarY);
  Toolbar->resize(toolbarW, toolbarH);
  
  DisplayButtonW = DisplayButton->size().width();
  DisplayButtonX = width - (DisplayButtonW + 5);
  DisplayButton->move(DisplayButtonX, 1);
  DisplayButton->resize(DisplayButtonW, SECTION_HEADER_HEIGHT - 2);
  if ( elementDisplayWindow ) {
    elementDisplayWindow->move(elementDisplayWindowX, elementDisplayWindowY);
    elementDisplayWindow->resize(elementDisplayWindowW, elementDisplayWindowH);
  }
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
  QString                               name;
  int                                   n;
  int                                   i;
  QJsonObject                           obj;

  n = MainTopLevelObjects.count();

  for (i = TranslationUnit->GetFirstFunctionIndex(); i < n; i++) {
    obj = MainTopLevelObjects[i];
    name = obj["name"].toString();
    if ( ObjectIsFunctionDefinition(obj) ) {
      FunctionContainsReference(obj, InFunctionName);
    }
  }
}

/*****************************************************************************!
 * Function : FunctionContainsReference
 *****************************************************************************/
bool
JSONFileObjectDisplayWindow::FunctionContainsReference
(QJsonObject InFunctionObject, QString InFunctionName)
{
  QString                               objectName;

  objectName = InFunctionObject["name"].toString();
  return ObjectContainsReference(objectName, InFunctionObject, InFunctionName);
}

/*****************************************************************************!
 * Function : ObjectContainsReference
 *****************************************************************************/
bool
JSONFileObjectDisplayWindow::ObjectContainsReference
(QString InObjectName, QJsonObject InObject, QString InFunctionName)
{
  QString                               kind;
  QString                               name;
  QJsonArray                            array;
  QJsonValue                            val2;
  int                                   n;
  QJsonValue                            val;
  QJsonObject                           obj;
  QString                               declName;
  QStringList                           keys;

  keys = InObject.keys();
  for ( auto i = keys.begin() ; i != keys.end() ; i++ ) {
    QString                             key = *i;
    if ( key == "referencedDecl" ) {
      obj = InObject[key].toObject();
      declName = obj["name"].toString();
      if ( declName == InFunctionName ) {
        emit SignalCallingFunctionFound(InObjectName);
        return true;
      }
    }
    val = InObject[key];
    if ( val.isObject() ) {
      if ( ObjectContainsReference(InObjectName, val.toObject(), InFunctionName) ) {
        return true;
      }
      continue;
    }

    if ( val.isArray() ) {
      array = val.toArray();
      n = array.count();
      for ( int k = 0 ; k < n ; k++ ) {
        val2 = array[k];
        if ( val2.isObject() ) {
          if ( ObjectContainsReference(InObjectName, val2.toObject(), InFunctionName) ) {
            return true;
          } 
        }
      }
    }
  }
  return false;
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

  innerArray = GetFunctionCompountStmtInternals(InObject);
  n = innerArray.count();
  for (i = 0; i < n; i++) {
    obj = innerArray[i].toObject();
    if ( ObjectElementContainsCall(obj, InFunctionName) ) {
    }
  }
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

  innerValue = InObject["inner"];
  if ( ! innerValue.isArray() ) {
    return QJsonArray();
  }

  innerArray = innerValue.toArray();

  n = innerArray.count();

  for (i = 0; i < n; i++) {
    obj = innerArray[i].toObject();
    kind = obj["kind"].toString();
    if ( kind == "CompoundStmt" ) {
      innerValue = obj["inner"];
      if ( innerValue.isArray() ) {
        return innerValue.toArray();
      }
    }
  }
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
  keys = InObject.keys();

  if ( kind == "CallExpr" ) {
    if (  CheckCallExpr(InObject, InFunctionName) ) {
      return true;
    }
  }
  for ( auto i = keys.begin() ; i != keys.end() ; i++ ) {
    QString                             key = *i;
    value = InObject[key];

    if ( value.isObject() ) {
      kind = value.toObject()["kind"].toString();
      if ( kind == "CallExpr") {
        return true;
      }
    }
  }
  return false;
}

/*****************************************************************************!
 * Function : CheckCallExpr
 *****************************************************************************/
bool
JSONFileObjectDisplayWindow::CheckCallExpr
(QJsonObject InObject, QString InFunctionName)
{
  QJsonObject                           refDeclObj;
  QString                               kind;
  QJsonObject                           nameDeclObj;
  QJsonObject                           nameObj;
  QString                               name;
  QJsonArray                            innerArray;

  nameObj = InObject["inner"].toArray()[0].toObject();
  kind = nameObj["kind"].toString();
  if ( kind != "ImplicitCastExpr" ) {
    return false;
  }
  nameDeclObj = nameObj["inner"].toArray()[0].toObject();
  kind = nameDeclObj["kind"].toString();
  if ( kind != "DeclRefExpr" ) {
    return false;
  }
  refDeclObj = nameDeclObj["referencedDecl"].toObject();
  name = refDeclObj["name"].toString();
  return name == InFunctionName;
}

/*****************************************************************************!
 * Function : ContainsCallExpr
 *****************************************************************************/
bool
JSONFileObjectDisplayWindow::ContainsCallExpr
(QJsonObject InObject, QString InName)
{
  QJsonValue                            val2;
  int                                   n;
  QJsonArray                            array;
  QStringList                           keys;
  QJsonValue                            val;
  QJsonObject                           obj;

  if ( InObject["kind"].toString() == "CallExpr" ) {
    return CheckCallExpr(InObject, InName);
  }

  keys = InObject.keys();
  for ( auto i = keys.begin(); i != keys.end() ; i++ ) {
    QString                             key = *i;
    val = InObject[key];
    if ( val.isObject() ) {
      obj = val.toObject();
      if ( ContainsCallExpr(obj, InName) ) {
        return true;
      }
      continue;
    }
    if ( val.isArray() ) {
      array = val.toArray();
      n = array.count();
      for (int k = 0; k < n; k++) {
        val2 = array[k];
        if ( ! val2.isObject() ) {
          continue;
        }
        obj = val2.toObject();
        if ( ContainsCallExpr(obj, InName) ) {
          return true;
        }
      }
    }
  }
  return false;
}

/*****************************************************************************!
 * Function : SlotCollapseElements
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotCollapseElements(void)
{
  emit SignalCollapseTree();  
}

/*****************************************************************************!
 * Function : SlotExpandElements
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotExpandElements(void)
{
  emit SignalExpandTree();
}

/*****************************************************************************!
 * Function : SetColumnWidths
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SetColumnWidths
(QList<int> InWidths)
{
  fileTree->setColumnWidth(0, InWidths[0]);
  fileTree->setColumnWidth(1, InWidths[1]);
}

/*****************************************************************************!
 * Function : SlotValueSelected
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotValueSelected
(QJsonValue InValue)
{
  QJsonObject                           obj;
  QString                               kind;
  if ( InValue.type() != QJsonValue::Object ) {
    return;
  }

  obj = InValue.toObject();
  kind = obj["kind"].toString();
  if ( kind == "ParmVarDecl" ) {
    DisplayParmVarDecl(obj);
    return;
  }
}

/*****************************************************************************!
 * Function : DisplayParmVarDecl
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::DisplayParmVarDecl
(QJsonObject InObject)
{
  QJsonObject                           typeObj;
  QString                               name;
  QString                               type;

  name = InObject["name"].toString();
  typeObj = InObject["type"].toObject();
  type = typeObj["qualType"].toString();

  TRACE_FUNCTION_QSTRING(name);
  TRACE_FUNCTION_QSTRING(type);
}

/*****************************************************************************!
 * Function : SlotClearChildren
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotClearChildren(void)
{
  header->SetText("");
  emit SignalClearChildren();
}

/*****************************************************************************!
 * Function : OpenNewFile
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::OpenNewFile
(TranslationUnitObject* InTranslationUnit)
{
  TranslationUnit = InTranslationUnit;
}
