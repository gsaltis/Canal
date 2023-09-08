QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC                       = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

#QMAKE_LFLAGS_WINDOWS            += -mwindows
QMAKE_LFLAGS_WINDOWS            += -Wl,--subsystem,console

QMAKE_CXXFLAGS                  += -g

QMAKE_LIBS                      = 

RESOURCES                       += CanalImages.qrc

TARGET                          = canal

VERSION                         = "0.2.0"
QMAKE_TARGET_COMPANY            = "Greg Saltis"

QMAKE_TARGET_PRODUCT            = "Canal"

QMAKE_TARGET_COPYRIGHT          = "Copyright (C) 2023 Greg Saltis"

QT                              += core gui widgets

DEFINES                         += \

SOURCES                         += \
				   CallTreeWindow.cpp                           \
				   CallTreeWindowTree.cpp                       \
				   CallTreeWindowTreeItem.cpp                   \
				   CalledFunction.cpp                           \
				   CanalDB.cpp                                  \
				   DirectoryManagement.cpp                      \
				   DisplayFunctionSVGNamePane.cpp               \
				   FunctionDefinition.cpp                       \
				   FunctionDefinitionDB.cpp                     \
				   FunctionParameter.cpp                        \
				   JSONElementWindow.cpp                        \
				   JSONElementWindowSectionHeader.cpp           \
				   JSONFileObjectDisplayTab.cpp                 \
				   JSONFileObjectDisplayTabWindow.cpp           \
				   JSONFileObjectDisplayTree.cpp                \
				   JSONFileObjectDisplayTreeItem.cpp            \
				   JSONFileObjectDisplayWindow.cpp              \
				   JSONFileObjectElementDisplayWindow.cpp       \
				   JSONFileTree.cpp                             \
				   JSONFileTreeHeader.cpp                       \
				   JSONFileTreeItem.cpp                         \
				   JSONFileWindow.cpp                           \
				   JSONFileWindowDialog.cpp                     \
				   JSONFileWindowSectionHeader.cpp              \
				   JSONNavigate.cpp                             \
				   JSONObjectElementTree.cpp                    \
				   JSONObjectElementTreeItem.cpp                \
				   JSONObjectFormat.cpp                         \
				   JSONObjectFormatList.cpp                     \
				   JSONTagElement.cpp                           \
				   JSONTagElementList.cpp                       \
				   JSONTagTree.cpp                              \
				   JSONTagTreeItem.cpp                          \
				   MainDisplayFunctionSVGWindow.cpp             \
				   MainDisplayJSONTreesWindow.cpp               \
				   MainDisplayWindow.cpp                        \
				   MainMessageWindow.cpp                        \
				   MainSplitter.cpp                             \
				   MainStacker.cpp                              \
				   MainTagWindow.cpp                            \
				   MainTagWindowSectionHeader.cpp               \
				   MainWindow.cpp                               \
				   SectionHeader.cpp                            \
				   SystemConfig.cpp                             \
				   TranslationUnitObject.cpp                    \
				   WindowSizeInfo.cpp                           \
				   main.cpp                                     \
				   sqlite3.c                                    \

HEADERS                         += \
				   CallTreeWindow.h                             \
				   CallTreeWindowTree.h                         \
				   CallTreeWindowTreeItem.h                     \
				   CalledFunction.h                             \
				   CanalDB.h                                    \
				   DirectoryManagement.h                        \
				   DisplayFunctionSVGNamePane.h                 \
				   FunctionDefinition.h                         \
				   FunctionDefinitionDB.h                       \
				   FunctionParameter.h                          \
				   JSONElementWindow.h                          \
				   JSONElementWindowSectionHeader.h             \
				   JSONFileObjectDisplayTab.h                   \
				   JSONFileObjectDisplayTabWindow.h             \
				   JSONFileObjectDisplayTree.h                  \
				   JSONFileObjectDisplayTreeItem.h              \
				   JSONFileObjectDisplayWindow.h                \
				   JSONFileObjectElementDisplayWindow.h         \
				   JSONFileTree.h                               \
				   JSONFileTreeHeader.h                         \
				   JSONFileTreeItem.h                           \
				   JSONFileWindow.h                             \
				   JSONFileWindowDialog.h                       \
				   JSONFileWindowSectionHeader.h                \
				   JSONNavigate.h                               \
				   JSONObjectElementTree.h                      \
				   JSONObjectElementTreeItem.h                  \
				   JSONObjectFormat.h                           \
				   JSONObjectFormatList.h                       \
				   JSONTagElement.h                             \
				   JSONTagElementList.h                         \
				   JSONTagTree.h                                \
				   JSONTagTreeItem.h                            \
				   MainDisplayFunctionSVGWindow.h               \
				   MainDisplayJSONTreesWindow.h                 \
				   MainDisplayWindow.h                          \
				   MainMessageWindow.h                          \
				   MainSplitter.h                               \
				   MainStacker.h                                \
				   MainTagWindow.h                              \
				   MainTagWindowSectionHeader.h                 \
				   MainWindow.h                                 \
				   SectionHeader.h                              \
				   SystemConfig.h                               \
				   TranslationUnitObject.h                      \
				   WindowSizeInfo.h                             \
				   sqlite3.h                                    \

FORMS                           += \

QMAKE_EXTRA_TARGETS             += junkclean
junkclean.target                = junkclean
junkclean.commands              = @echo Removing junk                           \
                                  && rm -rf $(wildcard core* *~)
junkclean.depends               = 

QMAKE_EXTRA_TARGETS             += cleanall
cleanall.target                 = cleanall
cleanall.commands               = 
cleanall.depends                = junkclean                                     \
                                  clean
