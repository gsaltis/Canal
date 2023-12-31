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

#define TRACE_USE
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONFileObjectDisplayWindow.h"
#include "Trace.h"
#include "common.h"
#include "JSONNavigate.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define TOOLBAR_WIDTH                   34

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
  SetColumnWidths(MainSystemConfig->GetColumnWidths(JSON_FILE_OBJECT_DISPLAY_WINDOW_INDEX));
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
  CreateConnections();
  CreateAction();
}

/*****************************************************************************!
 * Function : CreateAction
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::CreateAction
()
{
  ActionCollapseElements = new QAction(QIcon(":/Images/Collapse.png"), "Collapse Elements", this);
  connect(ActionCollapseElements, SIGNAL(triggered()), this, SLOT(SlotCollapseElements()));

  ActionExpandElements = new QAction(QIcon(":/Images/Expand.png"), "Expand Elements", this);
  connect(ActionExpandElements, SIGNAL(triggered()), this, SLOT(SlotExpandElements()));

  ActionCloseTab = new QAction(QIcon(":/Images/Close.png"), "Close Tab", this);
  connect(ActionCloseTab, SIGNAL(triggered()), this, SLOT(SlotCloseTab()));

  Toolbar->addAction(ActionExpandElements);
  Toolbar->addAction(ActionCollapseElements);
  Toolbar->addAction(ActionCloseTab);
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::CreateSubWindows()
{
  fileTree = new JSONFileObjectDisplayTree();  
  fileTree->setParent(this);

  header = new SectionHeader();
  header->setParent(this);

  Toolbar = new QToolBar(this);
  Toolbar->setOrientation(Qt::Vertical);
  Toolbar->setIconSize(QSize(32, 32));

  DisplayButton = new QPushButton("Display");
  DisplayButton->resize(60, 20);

  elementDisplayWindow = new JSONFileObjectElementDisplayWindow();
  elementDisplayWindow->setParent(this);

  tabWindow = new JSONFileObjectDisplayTabWindow();
  tabWindow->setParent(this);
}

/*****************************************************************************!
 * Funtion : CreateConnections
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::CreateConnections
()
{
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

  connect(tabWindow,
          SIGNAL(SignalNormalMessage(QString)),
          this,
          SLOT(SlotNormalMessage(QString)));

  connect(this,
          SIGNAL(SignalCloseTab()),
          tabWindow,
          SLOT(SlotCloseTab()));
  
  connect(this,
          SIGNAL(SignalExpandTree()),
          tabWindow,
          SLOT(SlotExpandTree()));
  
  connect(this,
          SIGNAL(SignalCollapseTree()),
          tabWindow,
          SLOT(SlotCollapseTree()));
  
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
  
  connect(DisplayButton,
          SIGNAL(clicked(bool)),
          this,
          SLOT(SlotDisplayButtonClicked(bool)));

  connect(tabWindow,
          SIGNAL(SignalProgressBarShow()),
          this,
          SLOT(SlotProgressBarShow()));
  
  connect(tabWindow,
          SIGNAL(SignalProgressBarHide()),
          this,
          SLOT(SlotProgressBarHide()));
  
  connect(tabWindow,
          SIGNAL(SignalProgressBarUpdate(int)),
          this,
          SLOT(SlotProgressBarUpdate(int)));
  
  connect(tabWindow,
          SIGNAL(SignalProgressBarSet(int, int)),
          this,
          SLOT(SlotProgressBarSet(int, int)));
  
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
  tabWindow = NULL;
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

  toolbarW = TOOLBAR_WIDTH;
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
  if ( tabWindow ) {
    tabWindow->resize(fileTreeW, fileTreeH);
    tabWindow->move(0, SECTION_HEADER_HEIGHT);
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
  tabWindow->AddObject(InObject);
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

  for (i = TranslationUnit->GetFirstLocalItemIndex(); i < n; i++) {
    obj = MainTopLevelObjects[i];
    name = obj["name"].toString();
    if ( TranslationUnit->ObjectIsFunctionDefinition(obj) ) {
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

/*****************************************************************************!
 * Function : SlotNormalMessage
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotNormalMessage
(QString InMessage)
{
  emit SignalNormalMessage(InMessage);
}

/*****************************************************************************!
 * Function : SlotCloseTab
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotCloseTab(void)
{
  emit SignalCloseTab();
}

/*****************************************************************************!
 * Function : SlotProgressBarShow
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotProgressBarShow(void)
{
  emit SignalProgressBarShow();  
}

/*****************************************************************************!
 * Function : SlotProgressBarHide
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotProgressBarHide(void)
{
  emit SignalProgressBarHide();
}

/*****************************************************************************!
 * Function : SlotProgressBarSet
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotProgressBarSet
(int InMinimum, int InMaximum)
{
  emit SignalProgressBarSet(InMinimum, InMaximum);
}

/*****************************************************************************!
 * Function : SlotProgressBarUpdate
 *****************************************************************************/
void
JSONFileObjectDisplayWindow::SlotProgressBarUpdate
(int InValue)
{
  emit SignalProgressBarUpdate(InValue);
}
