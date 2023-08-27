@echo off
doskey m=make -j 4 -f Makefile.Release $T make -j 4 -f Makefile.Debug
doskey mr=cls $T color $T make -j 4 -f Makefile.Release
doskey md=make -j 4 -f Makefile.Debug
doskey mc=make cleanall
doskey mq=qmake
doskey ca=cls $T color $T release\canal $*
doskey cad=debug\canal $*
title Canal
