// ============ GRADAUTOMATON.H ================

#ifndef GRADAUTOMATON_H
#define GRADAUTOMATON_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "pberr.h"
#include "pbmath.h"
#include "gset.h"
#include "grad.h"
#include "neuranet.h"

// -------------- GrACell

// ================= Define ==================

// ================= Data structure ===================

typedef struct GrACell {

  // Index of the current status of the cell
  unsigned char curStatus;

  // Pointer toward the supporting GradCell
  GradCell* gradCell;

} GrACell;

typedef struct GrACellShort {

  // Parent GrACell
  GrACell gradAutomatonCell;

  // Double buffered status of the cell
  VecShort* status[2];

} GrACellShort;

typedef struct GrACellFloat {

  // Parent GrACell
  GrACell gradAutomatonCell;

  // Double buffered status of the cell
  VecFloat* status[2];

} GrACellFloat;

// ================ Functions declaration ====================

// Create a new static GradAutomatonCell
GrACell GradAutomatonCellCreateStatic(
  GradCell* const gradCell);

// Create a new GrACellShort with a status vector of dimension 'dim'
// for the GradCell 'gradCell'
GrACellShort* GrACellCreateShort(
       const long dim,
  GradCell* const gradCell);

// Create a new GrACellFloat with a status vector of dimension 'dim'
// for the GradCell 'gradCell'
GrACellFloat* GrACellCreateFloat(
       const long dim,
  GradCell* const gradCell);

// Free the memory used by the GrACellShort 'that'
void _GrACellShortFree(GrACellShort** that);

// Free the memory used by the GrACellFloat 'that'
void _GrACellFloatFree(GrACellFloat** that);

// Switch the current status of the GrACell 'that'
#if BUILDMODE != 0
static inline
#endif
void _GrACellSwitchStatus(GrACell* const that);

// Return the current status of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
VecShort* _GrACellShortCurStatus(const GrACellShort* const that);

// Return the current status of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
VecFloat* _GrACellFloatCurStatus(const GrACellFloat* const that);

// Return the previous status of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
VecShort* _GrACellShortPrevStatus(const GrACellShort* const that);

// Return the previous status of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
VecFloat* _GrACellFloatPrevStatus(const GrACellFloat* const that);

// Return the 'iVal'-th value of the previous status of the
// GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
short _GrACellShortGetPrevStatus(
  const GrACellShort* const that,
        const unsigned long iVal);

// Return the 'iVal'-th value of the previous status of the
// GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
float _GrACellFloatGetPrevStatus(
  const GrACellFloat* const that,
        const unsigned long iVal);

// Set the 'iVal'-th value of the previous status of the
// GrACellShort 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif
void _GrACellShortSetPrevStatus(
  const GrACellShort* const that,
        const unsigned long iVal,
                const short val);

// Set the 'iVal'-th value of the previous status of the
// GrACellFloat 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif
void _GrACellFloatSetPrevStatus(
  const GrACellFloat* const that,
        const unsigned long iVal,
                const float val);

// Return the 'iVal'-th value of the current status of the
// GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
short _GrACellShortGetCurStatus(
  const GrACellShort* const that,
        const unsigned long iVal);

// Return the 'iVal'-th value of the current status of the
// GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
float _GrACellFloatGetCurStatus(
  const GrACellFloat* const that,
        const unsigned long iVal);

// Set the 'iVal'-th value of the current status of the
// GrACellShort 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif
void _GrACellShortSetCurStatus(
  const GrACellShort* const that,
        const unsigned long iVal,
                const short val);

// Set the 'iVal'-th value of the current status of the
// GrACellFloat 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif
void _GrACellFloatSetCurStatus(
  const GrACellFloat* const that,
        const unsigned long iVal,
                const float val);

// Return the GradCell of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
GradCell* _GrACellShortGradCell(const GrACellShort* const that);

// Return the GradCell of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
GradCell* _GrACellFloatGradCell(const GrACellFloat* const that);

// ================= Polymorphism ==================

#define GrACellFree(G) _Generic(G, \
  GrACellShort**: _GrACellShortFree, \
  GrACellFloat**: _GrACellFloatFree, \
  default: PBErrInvalidPolymorphism)(G)

#define GrACellSwitchStatus(G) _Generic(G, \
  GrACell*: _GrACellSwitchStatus, \
  GrACellShort*: _GrACellSwitchStatus, \
  GrACellFloat*: _GrACellSwitchStatus, \
  default: PBErrInvalidPolymorphism)((GrACell*)(G))

#define GrACellCurStatus(G) _Generic(G, \
  GrACellShort*: _GrACellShortCurStatus, \
  const GrACellShort*: _GrACellShortCurStatus, \
  GrACellFloat*: _GrACellFloatCurStatus, \
  const GrACellFloat*: _GrACellFloatCurStatus, \
  default: PBErrInvalidPolymorphism)(G)

#define GrACellPrevStatus(G) _Generic(G, \
  GrACellShort*: _GrACellShortPrevStatus, \
  const GrACellShort*: _GrACellShortPrevStatus, \
  GrACellFloat*: _GrACellFloatPrevStatus, \
  const GrACellFloat*: _GrACellFloatPrevStatus, \
  default: PBErrInvalidPolymorphism)(G)

#define GrACellGetCurStatus(G, I) _Generic(G, \
  GrACellShort*: _GrACellShortGetCurStatus, \
  const GrACellShort*: _GrACellShortGetCurStatus, \
  GrACellFloat*: _GrACellFloatGetCurStatus, \
  const GrACellFloat*: _GrACellFloatGetCurStatus, \
  default: PBErrInvalidPolymorphism)(G, I)

#define GrACellGetPrevStatus(G, I) _Generic(G, \
  GrACellShort*: _GrACellShortGetPrevStatus, \
  const GrACellShort*: _GrACellShortGetPrevStatus, \
  GrACellFloat*: _GrACellFloatGetPrevStatus, \
  const GrACellFloat*: _GrACellFloatGetPrevStatus, \
  default: PBErrInvalidPolymorphism)(G, I)

#define GrACellSetCurStatus(G, I, V) _Generic(G, \
  GrACellShort*: _GrACellShortSetCurStatus, \
  GrACellFloat*: _GrACellFloatSetCurStatus, \
  default: PBErrInvalidPolymorphism)(G, I, V)

#define GrACellSetPrevStatus(G, I, V) _Generic(G, \
  GrACellShort*: _GrACellShortSetPrevStatus, \
  GrACellFloat*: _GrACellFloatSetPrevStatus, \
  default: PBErrInvalidPolymorphism)(G, I, V)

#define GrACellGradCell(G) _Generic(G, \
  GrACellShort*: _GrACellShortGradCell, \
  const GrACellShort*: _GrACellShortGradCell, \
  GrACellFloat*: _GrACellFloatGradCell, \
  const GrACellFloat*: _GrACellFloatGradCell, \
  default: PBErrInvalidPolymorphism)(G)

// -------------- GrAFun

// ================= Define ==================

// ================= Data structure ===================

typedef enum GrAFunType {

  GrAFunTypeDummy,
  GrAFunTypeWolframOriginal,
  GrAFunTypeNeuraNet

} GrAFunType;

typedef struct GrAFun {

  // Type of GrAFun
  GrAFunType type;

} GrAFun;

// ================ Functions declaration ====================

// Create a static GrAFun with type 'type'
GrAFun GrAFunCreateStatic(const GrAFunType type);

// Free the memory used by the GrAFun 'that'
void _GrAFunFreeStatic(GrAFun* that);

// Return the type of the GrAFun 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunType _GrAFunGetType(const GrAFun* const that);

// -------------- GrAFunDummy

// ================= Define ==================

// ================= Data structure ===================

typedef struct GrAFunDummy {

  // GrAFun
  GrAFun grAFun;

} GrAFunDummy;

// ================ Functions declaration ====================

// Create a new GrAFunDummy
GrAFunDummy* GrAFunCreateDummy(void);

// Free the memory used by the GrAFunDummy 'that'
void _GrAFunDummyFree(GrAFunDummy** that);

// -------------- GrAFunWolframOriginal

// ================= Define ==================

// ================= Data structure ===================

typedef struct GrAFunWolframOriginal {

  // GrAFun
  GrAFun grAFun;

  // Rule, cf "A new kind of science" p.53
  unsigned char rule;

} GrAFunWolframOriginal;

// ================ Functions declaration ====================

// Create a new GrAFunWolframOriginal
GrAFunWolframOriginal* GrAFunCreateWolframOriginal(
  const unsigned char rule);

// Free the memory used by the GrAFunWolframOriginal 'that'
void _GrAFunWolframOriginalFree(GrAFunWolframOriginal** that);

// Return the rule of the GrAFunWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
unsigned char GrAFunWolframOriginalGetRule(
  GrAFunWolframOriginal* const that);

// Apply the step function for the GrAFunWolframOriginal 'that'
// to the GrACellShort 'cell' in the GradSquare 'grad'
void _GrAFunWolframOriginalApply(
  GrAFunWolframOriginal* const that,
             GradSquare* const grad,
           GrACellShort* const cell);

// -------------- GrAFunNeuraNet

// ================= Define ==================

// ================= Data structure ===================

typedef struct GrAFunNeuraNet {

  // GrAFun
  GrAFun grAFun;

  // NeuraNet applied to the cells
  NeuraNet* nn;

} GrAFunNeuraNet;

// ================ Functions declaration ====================

// Create a new GrAFunNeuraNet
GrAFunNeuraNet* GrAFunCreateNeuraNet(
  NeuraNet* const nn);

// Free the memory used by the GrAFunNeuraNet 'that'
void _GrAFunNeuraNetFree(GrAFunNeuraNet** that);

// Return the NeuraNet of the GrAFunNeuraNet 'that'
#if BUILDMODE != 0
static inline
#endif
NeuraNet* GrAFunNeuraNetNN(
  GrAFunNeuraNet* const that);

// Apply the step function for the GrAFunNeuraNet 'that'
// to the GrACellShort 'cell' in the GradSquare 'grad'
void _GrAFunNeuraNetApply(
  GrAFunNeuraNet* const that,
            Grad* const grad,
    GrACellFloat* const cell);

// ================= Polymorphism ==================

#define GrAFunFree(G) _Generic(G, \
  GrAFun*: _GrAFunFreeStatic, \
  GrAFunDummy**: _GrAFunDummyFree, \
  GrAFunWolframOriginal**: _GrAFunWolframOriginalFree, \
  GrAFunNeuraNet**: _GrAFunNeuraNetFree, \
  default: PBErrInvalidPolymorphism)(G)

#define GrAFunGetType(G) _Generic(G, \
  GrAFun*: _GrAFunGetType, \
  const GrAFun*: _GrAFunGetType, \
  GrAFunDummy*: _GrAFunGetType, \
  const GrAFunDummy*: _GrAFunGetType, \
  GrAFunWolframOriginal*: _GrAFunGetType, \
  const GrAFunWolframOriginal*: _GrAFunGetType, \
  GrAFunNeuraNet*: _GrAFunGetType, \
  const GrAFunNeuraNet*: _GrAFunGetType, \
  default: PBErrInvalidPolymorphism)((const GrAFun*)(G))

#define GrAFunApply(F, G, C) _Generic(F, \
  GrAFunWolframOriginal*: _GrAFunWolframOriginalApply, \
  GrAFunNeuraNet*: _GrAFunNeuraNetApply, \
  default: PBErrInvalidPolymorphism)(F, G, C)

// -------------- GradAutomaton

// ================= Define ==================

// ================= Data structure ===================

typedef enum GradAutomatonType {

  GradAutomatonTypeDummy,
  GradAutomatonTypeWolframOriginal,
  GradAutomatonTypeNeuraNet

} GradAutomatonType;

typedef struct GradAutomaton {

  // Type of the GradAutomaton
  GradAutomatonType type;

  // Dimension of the status vector of each cell
  long dim;

  // Grad
  Grad* grad;

  // GrAFun
  GrAFun* fun;

} GradAutomaton;

// ================ Functions declaration ====================

// Create a new static GradAutomaton
GradAutomaton GradAutomatonCreateStatic(
  const GradAutomatonType type,
              Grad* const grad,
            GrAFun* const fun);

// Return the Grad of the GradAutomaton 'that'
#if BUILDMODE != 0
static inline
#endif
Grad* _GradAutomatonGrad(const GradAutomaton* const that);

// Return the GrACellShort at position 'pos' for the
// GradAutomaton 'that'
#if BUILDMODE != 0
static inline
#endif
GrACell* _GradAutomatonCellPos(
     GradAutomaton* const that,
  const VecShort2D* const pos);

// Return the GrACellShort at index 'iCell' for the GradAutomaton 'that'
#if BUILDMODE != 0
static inline
#endif
GrACell* _GradAutomatonCellIndex(
  GradAutomaton* const that,
            const long iCell);

// Switch the status of all the cells of the GradAutomaton 'that'
void _GradAutomatonSwitchAllStatus(GradAutomaton* const that);

// -------------- GradAutomatonDummy

// ================= Define ==================

// ================= Data structure ===================

// GradSquare (2x2, no diag), GraFunDummy, GrACellShort dimension 1
typedef struct GradAutomatonDummy {

  // Parent GradAutomaton
  GradAutomaton gradAutomaton;

} GradAutomatonDummy;

// ================ Functions declaration ====================

// Create a new static GradAutomaton
GradAutomaton GradAutomatonCreateStatic(
  const GradAutomatonType type,
              Grad* const grad,
            GrAFun* const fun);

// Create a new GradAutomatonDummy
GradAutomatonDummy* GradAutomatonCreateDummy();

// Free the memory used by the GradAutomatonDummy 'that'
void GradAutomatonDummyFree(GradAutomatonDummy** that);

// Step the GradAutomatonDummy
void _GradAutomatonDummyStep(GradAutomatonDummy* const that);

// Return the Grad of the GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GradSquare* _GradAutomatonDummyGrad(
  const GradAutomatonDummy* const that);

// Return the GrAFun of the GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunDummy* _GradAutomatonDummyFun(
  const GradAutomatonDummy* const that);

// Return the GrACellShort at position 'pos' for the
// GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellShort* _GradAutomatonDummyCellPos(
  GradAutomatonDummy* const that,
    const VecShort2D* const pos);

// Return the GrACellShort at index 'iCell' for the GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellShort* _GradAutomatonDummyCellIndex(
  GradAutomatonDummy* const that,
                 const long iCell);

// -------------- GradAutomatonWorlframOriginal

// ================= Define ==================

// ================= Data structure ===================

// GradSquare (Nx1, no diag), GraFunWolframOriginal, GrACellShort dimension 1
typedef struct GradAutomatonWolframOriginal {

  // Parent GradAutomaton
  GradAutomaton gradAutomaton;

} GradAutomatonWolframOriginal;

// ================ Functions declaration ====================

// Create a new GradAutomatonWolframOriginal
GradAutomatonWolframOriginal* GradAutomatonCreateWolframOriginal(
  const unsigned char rule,
           const long size);

// Free the memory used by the GradAutomatonWolframOriginal 'that'
void GradAutomatonWolframOriginalFree(
  GradAutomatonWolframOriginal** that);

// Step the GradAutomatonWolframOriginal
void _GradAutomatonWolframOriginalStep(
  GradAutomatonWolframOriginal* const that);

// JSON encoding of GradAutomatonWolframOriginal 'that'
JSONNode* _GradAutomatonWolframOriginalEncodeAsJSON(
  const GradAutomatonWolframOriginal* const that);

// Function which decode from JSON encoding 'json' to 'that'
bool _GradAutomatonWolframOriginalDecodeAsJSON(
  GradAutomatonWolframOriginal** that,
           const JSONNode* const json);

// Return the Grad of the GradAutomatonWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
GradSquare* _GradAutomatonWolframOriginalGrad(
  const GradAutomatonWolframOriginal* const that);

// Return the GrAFun of the GradAutomatonWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunWolframOriginal* _GradAutomatonWolframOriginalFun(
  const GradAutomatonWolframOriginal* const that);

// Return the GrACellShort at position 'pos' for the
// GradAutomatonWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellShort* _GradAutomatonWolframOriginalCellPos(
  GradAutomatonWolframOriginal* const that,
              const VecShort2D* const pos);

// Return the GrACellShort at index 'iCell' for the
// GradAutomatonWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellShort* _GradAutomatonWolframOriginalCellIndex(
  GradAutomatonWolframOriginal* const that,
                           const long iCell);

// Print the GradAutomatonWolframOriginal 'that' on the FILE 'stream'
void _GradAutomatonWolframOriginalPrintln(
  GradAutomatonWolframOriginal* const that,
                                FILE* stream);

// Save the GradAutomatonWolframOriginal 'that' to the stream 'stream'
// If 'compact' equals true it saves in compact form, else it saves in
// readable form
// Return true if the GradAutomatonWolframOriginal could be saved,
// false else
bool _GradAutomatonWolframOriginalSave(
  const GradAutomatonWolframOriginal* const that,
                                FILE* const stream,
                                 const bool compact);

// Load the GradAutomatonWolfraOriginal 'that' from the stream 'stream'
// If 'that' is not null the memory is first freed
// Return true if the GradAutomatonWolframOriginal could be loaded,
// false else
bool _GradAutomatonWolframOriginalLoad(
  GradAutomatonWolframOriginal** that,
                     FILE* const stream);

// -------------- GradAutomatonNeuraNet

// ================= Define ==================

// ================= Data structure ===================

// GradSquare/GradHexa, GraFunNeuraNet, GrACellFloat
typedef struct GradAutomatonNeuraNet {

  // Parent GradAutomaton
  GradAutomaton gradAutomaton;

} GradAutomatonNeuraNet;

// ================ Functions declaration ====================

// Create a new GradAutomatonNeuraNet with a GradSquare
GradAutomatonNeuraNet* GradAutomatonCreateNeuraNetSquare(
               const long dimStatus,
  const VecShort2D* const dimGrad,
               const bool diagLink,
          NeuraNet* const nn);

// Create a new GradAutomatonNeuraNet with a GradHexa
GradAutomatonNeuraNet* GradAutomatonCreateNeuraNetHexa(
               const long dimStatus,
  const VecShort2D* const dimGrad,
       const GradHexaType gradType,
          NeuraNet* const nn);

// Free the memory used by the GradAutomatonNeuraNet 'that'
void GradAutomatonNeuraNetFree(
  GradAutomatonNeuraNet** that);

// Step the GradAutomatonNeuraNet
void _GradAutomatonNeuraNetStep(GradAutomatonNeuraNet* const that);

// Return the Grad of the GradAutomatonNeuraNet 'that'
#if BUILDMODE != 0
static inline
#endif
Grad* _GradAutomatonNeuraNetGrad(
  const GradAutomatonNeuraNet* const that);

// Return the type of Grad of the GradAutomatonNeuraNet 'that'
#if BUILDMODE != 0
static inline
#endif
GradType GradAutomatonNeuraNetGetGradType(
  GradAutomatonNeuraNet* const that);

// Return the GrAFun of the GradAutomatonNeuraNet 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunNeuraNet* _GradAutomatonNeuraNetFun(
  const GradAutomatonNeuraNet* const that);

// Return the GrACellFloat at position 'pos' for the
// GradAutomatonNeuraNet 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellFloat* _GradAutomatonNeuraNetCellPos(
  GradAutomatonNeuraNet* const that,
       const VecShort2D* const pos);

// Return the GrACellFloat at index 'iCell' for the
// GradAutomatonNeuraNet 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellFloat* _GradAutomatonNeuraNetCellIndex(
  GradAutomatonNeuraNet* const that,
                    const long iCell);

// ================= Polymorphism ==================

#define GradAutomatonSwitchAllStatus(G) _Generic(G, \
  GradAutomaton* : _GradAutomatonSwitchAllStatus, \
  GradAutomatonDummy* : _GradAutomatonSwitchAllStatus, \
  GradAutomatonWolframOriginal* : _GradAutomatonSwitchAllStatus, \
  GradAutomatonNeuraNet* : _GradAutomatonSwitchAllStatus, \
  default: PBErrInvalidPolymorphism)((GradAutomaton*)(G))

#define GradAutomatonStep(G) _Generic(G, \
  GradAutomatonDummy* : _GradAutomatonDummyStep, \
  GradAutomatonWolframOriginal* : _GradAutomatonWolframOriginalStep, \
  GradAutomatonNeuraNet* : _GradAutomatonNeuraNetStep, \
  default: PBErrInvalidPolymorphism)(G)

#define GradAutomatonGrad(G) _Generic(G, \
  GradAutomaton* : _GradAutomatonGrad, \
  const GradAutomaton* : _GradAutomatonGrad, \
  GradAutomatonDummy* : _GradAutomatonDummyGrad, \
  const GradAutomatonDummy* : _GradAutomatonDummyGrad, \
  GradAutomatonWolframOriginal* : _GradAutomatonWolframOriginalGrad, \
  const GradAutomatonWolframOriginal* : \
    _GradAutomatonWolframOriginalGrad, \
  GradAutomatonNeuraNet* : _GradAutomatonNeuraNetGrad, \
  const GradAutomatonNeuraNet* : _GradAutomatonNeuraNetGrad, \
  default: PBErrInvalidPolymorphism)(G)

#define GradAutomatonFun(G) _Generic(G, \
  GradAutomatonDummy* : _GradAutomatonDummyFun, \
  const GradAutomatonDummy* : _GradAutomatonDummyFun, \
  GradAutomatonWolframOriginal* : _GradAutomatonWolframOriginalFun, \
  const GradAutomatonWolframOriginal* : \
    _GradAutomatonWolframOriginalFun, \
  GradAutomatonNeuraNet* : _GradAutomatonNeuraNetFun, \
  const GradAutomatonNeuraNet* : _GradAutomatonNeuraNetFun, \
  default: PBErrInvalidPolymorphism)(G)

#define GradAutomatonCell(G, P) _Generic(G, \
  GradAutomaton* : _Generic(P, \
    VecShort2D*: _GradAutomatonCellPos, \
    const VecShort2D*: _GradAutomatonCellPos, \
    long: _GradAutomatonCellIndex, \
    const long: _GradAutomatonCellIndex, \
    default: PBErrInvalidPolymorphism), \
  GradAutomatonDummy* : _Generic(P, \
    VecShort2D*: _GradAutomatonDummyCellPos, \
    const VecShort2D*: _GradAutomatonDummyCellPos, \
    long: _GradAutomatonDummyCellIndex, \
    const long: _GradAutomatonDummyCellIndex, \
    default: PBErrInvalidPolymorphism), \
  GradAutomatonWolframOriginal* : _Generic(P, \
    VecShort2D*: _GradAutomatonWolframOriginalCellPos, \
    const VecShort2D*: _GradAutomatonWolframOriginalCellPos, \
    long: _GradAutomatonWolframOriginalCellIndex, \
    const long: _GradAutomatonWolframOriginalCellIndex, \
    default: PBErrInvalidPolymorphism), \
  GradAutomatonNeuraNet* : _Generic(P, \
    VecShort2D*: _GradAutomatonNeuraNetCellPos, \
    const VecShort2D*: _GradAutomatonNeuraNetCellPos, \
    long: _GradAutomatonNeuraNetCellIndex, \
    const long: _GradAutomatonNeuraNetCellIndex, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(G, P)

#define GradAutomatonPrintln(G, S) _Generic(G, \
  GradAutomatonWolframOriginal* : \
    _GradAutomatonWolframOriginalPrintln, \
  const GradAutomatonWolframOriginal* :\
    _GradAutomatonWolframOriginalPrintln, \
  default: PBErrInvalidPolymorphism)(G, S)

#define GradAutomatonEncodeAsJSON(G) _Generic(G, \
  GradAutomatonWolframOriginal* : \
    _GradAutomatonWolframOriginalEncodeAsJSON, \
  const GradAutomatonWolframOriginal* :\
    _GradAutomatonWolframOriginalEncodeAsJSON, \
  default: PBErrInvalidPolymorphism)(G)

#define GradAutomatonDecodeAsJSON(G, J) _Generic(G, \
  GradAutomatonWolframOriginal** : \
    _GradAutomatonWolframOriginalDecodeAsJSON, \
  default: PBErrInvalidPolymorphism)(G, J)

#define GradAutomatonSave(G, S, C) _Generic(G, \
  GradAutomatonWolframOriginal* : \
    _GradAutomatonWolframOriginalSave, \
  const GradAutomatonWolframOriginal* :\
    _GradAutomatonWolframOriginalSave, \
  default: PBErrInvalidPolymorphism)(G, S, C)

#define GradAutomatonLoad(G, S) _Generic(G, \
  GradAutomatonWolframOriginal** : \
    _GradAutomatonWolframOriginalLoad, \
  const GradAutomatonWolframOriginal** :\
    _GradAutomatonWolframOriginalLoad, \
  default: PBErrInvalidPolymorphism)(G, S)

// ================ static inliner ====================

#if BUILDMODE != 0
#include "gradautomaton-inline.c"
#endif

#endif
