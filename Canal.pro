QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC                       = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

#QMAKE_LFLAGS_WINDOWS            += -mwindows
QMAKE_LFLAGS_WINDOWS            += -Wl,--subsystem,console

QMAKE_CXXFLAGS                  += 

QMAKE_LIBS                      = 

TARGET                          = canal

VERSION                         = "0.1.0"
QMAKE_TARGET_COMPANY            = "Greg Saltis"

QMAKE_TARGET_PRODUCT            = "Canal"

QMAKE_TARGET_COPYRIGHT          = "Copyright (C) 2023 Greg Saltis"

QT                              += core gui widgets

DEFINES                         += \

SOURCES                         += \
				   JSONElementWindow.cpp                        \
				   JSONFileTree.cpp                             \
				   JSONFileTreeHeader.cpp                       \
				   JSONFileTreeItem.cpp                         \
				   JSONFileWindow.cpp                           \
				   JSONObjectFormat.cpp                         \
				   JSONTagElement.cpp                           \
				   JSONTagElementList.cpp                       \
				   JSONTagTree.cpp                              \
				   JSONTagTreeItem.cpp                          \
				   MainDisplayWindow.cpp                        \
				   MainSplitter.cpp                             \
				   MainTagWindow.cpp                            \
				   MainWindow.cpp                               \
				   SystemConfig.cpp                             \
				   main.cpp                                     \

HEADERS                         += \
				   JSONElementWindow.h                          \
				   JSONFileTree.h                               \
				   JSONFileTreeHeader.h                         \
				   JSONFileTreeItem.h                           \
				   JSONFileWindow.h                             \
				   JSONObjectFormat.h                           \
				   JSONTagElement.h                             \
				   JSONTagElementList.h                         \
				   JSONTagTree.h                                \
				   JSONTagTreeItem.h                            \
				   MainDisplayWindow.h                          \
				   MainSplitter.h                               \
				   MainTagWindow.h                              \
				   MainWindow.h                                 \
				   SystemConfig.h                               \

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
