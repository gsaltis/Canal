/*****************************************************************************
 * FILE NAME    : MainTagWindow.h
 * DATE         : August 12 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maintagwindow_h_
#define _maintagwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "JSONTagTree.h"
#include "JSONTagTreeItem.h"
#include "JSONTagElementList.h"
#include "JSONObjectFormatList.h"
#include "MainTagWindowSectionHeader.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_TAG_WINDOW_X               200
#define MAIN_TAG_WINDOW_Y               200
#define MAIN_TAG_WINDOW_WIDTH           200
#define MAIN_TAG_WINDOW_HEIGHT          200

/*****************************************************************************!
 * Exported Class : MainTagWindow
 *****************************************************************************/
class MainTagWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainTagWindow                 (QJsonObject InJsonObject, JSONObjectFormatList* InObjectsFormats);

 //! Destructor
 public :
  ~MainTagWindow                ();

 //! Public Methods
 public :
  QList<int>
  GetColumnWidths
  ();

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          BuildTagList            (QJsonObject InObject, QString InTag);
  void                          PopulateTree            (void);
  void                          ProcessArrayTagList     (QJsonArray InArray, QString InTag);
  JSONTagTreeItem*              FindItemByName          (QString InTag);

  void
  SetColumnWidths
  (QList<int> InWidths);

 //! Private Data
 private :
  QJsonObject                   jsonObject;
  JSONTagElementList            jsonTags;
  JSONTagTree*                  tagTree;
  JSONObjectFormatList*         objectsFormats;
  MainTagWindowSectionHeader*   header;

 //! Public Slots
 public slots :
  void                          SlotFormatTypeSelected  (QString InType);
  void                          SlotElementCountChanged (int InCount);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _maintagwindow_h_*/
