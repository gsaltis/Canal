/*****************************************************************************
 * FILE NAME    : common.h
 * DATE         : August 17 2023
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _common_h_
#define _common_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "DirectoryManagement.h"
#include "SystemConfig.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/
extern
DirectoryManagement*
MainDirectoryManager;

extern
SystemConfig*
MainSystemConfig;

extern
QColor
MainTreeHeaderColor;

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/

#endif /* _common_h_*/