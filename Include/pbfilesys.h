// ============ PBFILESYS.H ================

#ifndef PBFILESYS_H
#define PBFILESYS_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include "pberr.h"
#include "pbcextension.h"

// ================= Define ==================

#define PBFILESYS_FOLDERSEP '/'

// ================ Functions declaration ====================

// Join the paths in arguments 
// Ignore the empty paths
// Return the result path as a new string
// Take care of adding the folder separator where needed
char* _PBFSJoinPath(const int nbPath, ...);
#define PBFSJoinPath(...) \
  _PBFSJoinPath(__VA_NB_ARGS__(const char*, __VA_ARGS__), __VA_ARGS__)

// Get the root folder of the path 'path'
// Examples:
// PBFSGetRootPath("A/B") -> "A"
// PBFSGetRootPath("/A/B") -> "/A"
// PBFSGetRootPath("/A/B/") -> "/A/B"
// PBFSGetRootPath("A") -> ""
// PBFSGetRootPath("/A") -> "/"
// PBFSGetRootPath("/") -> "/"
// PBFSGetRootPath("") -> ""
// PBFSGetRootPath(NULL) -> NULL
char* PBFSGetRootPath(const char* path);

// ================ Inliner ====================

#if BUILDMODE != 0
#include "pbfilesys-inline.c"
#endif

#endif
