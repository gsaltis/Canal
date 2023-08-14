/*****************************************************************************
 * FILE NAME    : MainTagWindow.cpp
 * DATE         : August 12 2023
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
#include "MainTagWindow.h"
#include "JSONTagTreeItem.h"

/*****************************************************************************!
 * Function : MainTagWindow
 *****************************************************************************/
MainTagWindow::MainTagWindow
(QJsonObject InJsonObject) : QWidget()
{
  jsonObject = InJsonObject;
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(128, 0, 0)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainTagWindow
 *****************************************************************************/
MainTagWindow::~MainTagWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainTagWindow::initialize()
{
  BuildTagList(jsonObject);
  InitializeSubWindows();  
  CreateSubWindows();
  PopulateTree();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainTagWindow::CreateSubWindows()
{
  tagTree = new JSONTagTree();  
  tagTree->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainTagWindow::InitializeSubWindows()
{
  tagTree = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainTagWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  if ( tagTree ) {
    tagTree->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : BuildTagList
 *****************************************************************************/
void
MainTagWindow::BuildTagList
(QJsonObject InObject)
{
  QJsonArray                            array;
  QStringList                           keys;

  keys = InObject.keys();
  for ( auto keyi = keys.begin() ; keyi != keys.end() ; keyi++ ) {
    QString                             key = *keyi;
    QJsonValue                          value = InObject[key];

    if ( ! jsonTags.HasElement(key, value.type()) ) {
      jsonTags << new JSONTagElement(key, value.type());;
    }
    if ( value.isObject() ) {
      BuildTagList(value.toObject());
      continue;
    }
    if ( value.isArray() ) {
      array = value.toArray();
      for (int i = 0 ; i < array.size(); i++ ) {
        QJsonValue                      v = array[i];
        if ( v.isObject() ) {
          BuildTagList(v.toObject());
        }
      }
    }
  }
}

/*****************************************************************************!
 * Function : PopulateTree
 *****************************************************************************/
void
MainTagWindow::PopulateTree(void)
{
  std::sort(jsonTags.begin(), jsonTags.end(),
            [] (JSONTagElement* InElement1, JSONTagElement* InElement2) {
              return InElement1->GetTag() < InElement2->GetTag();
            });
  for ( auto tagi = jsonTags.begin() ; tagi != jsonTags.end() ; tagi++ ) {
    JSONTagElement*                     tag = *tagi;
    JSONTagTreeItem*                    item;

    item = new JSONTagTreeItem(tag);
    tagTree->addTopLevelItem(item);
  }
}
