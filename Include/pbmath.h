// ============ PBMATH.H ================

#ifndef PBMATH_H
#define PBMATH_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "pberr.h"
#include "pbjson.h"

// ================= Define ==================

#define PBMATH_EPSILON 0.00001
#define PBMATH_TWOPI 6.283185307
#define PBMATH_TWOPI_DIV_360 0.01745329252
#define PBMATH_PI 3.141592654
#define PBMATH_HALFPI 1.570796327
#define PBMATH_QUARTERPI 0.7853981634
#define PBMATH_SQRTTWO 1.414213562
#define PBMATH_SQRTONEHALF 0.707106781
#ifndef MAX
  #define MAX(a,b) ((a)>(b)?(a):(b))
#endif
#ifndef MIN
  #define MIN(a,b) ((a)<(b)?(a):(b))
#endif
#define ISEQUALF(a,b) (fabs((a)-(b))<PBMATH_EPSILON)
#define SHORT(a) ((short)(round(a)))
#define INT(a) ((int)(round(a)))
#define rnd() (float)(rand())/(float)(RAND_MAX)

// -------------- VecLong

// ================= Data structure ===================

// Vector of long values
typedef struct VecLong {
  // Dimension
  long _dim;
  // Values
  long _val[0];
} VecLong;

typedef struct VecLong2D {
  // Dimension
  long _dim;
  // Values
  long _val[2];
} VecLong2D;

typedef struct VecLong3D {
  // Dimension
  long _dim;
  // Values
  long _val[3];
} VecLong3D;

typedef struct VecLong4D {
  // Dimension
  long _dim;
  // Values
  long _val[4];
} VecLong4D;

// ================ Functions declaration ====================

// Create a new VecLong of dimension 'dim'
// Values are initalized to 0.0
VecLong* VecLongCreate(const long dim);

// Static constructors for VecLong
#if BUILDMODE != 0
static inline
#endif 
VecLong2D VecLongCreateStatic2D();
#if BUILDMODE != 0
static inline
#endif 
VecLong3D VecLongCreateStatic3D();
#if BUILDMODE != 0
static inline
#endif 
VecLong4D VecLongCreateStatic4D();

// Clone the VecLong
// Return NULL if we couldn't clone the VecLong
VecLong* _VecLongClone(const VecLong* const that);

// Function which return the JSON encoding of 'that' 
JSONNode* _VecLongEncodeAsJSON(const VecLong* const that);

// Function which decode from JSON encoding 'json' to 'that'
bool _VecLongDecodeAsJSON(VecLong** that, const JSONNode* const json);

// Load the VecLong from the stream
// If the VecLong is already allocated, it is freed before loading
// Return true in case of success, else false
bool _VecLongLoad(VecLong** that, FILE* const stream);

// Save the VecLong to the stream
// If 'compact' equals true it saves in compact form, else it saves in 
// readable form
// Return true in case of success, else false
bool _VecLongSave(const VecLong* const that, 
  FILE* const stream, const bool compact);

// Free the memory used by a VecLong
// Do nothing if arguments are invalid
void _VecLongFree(VecLong** that);

// Print the VecLong on 'stream'
void _VecLongPrint(const VecLong* const that, 
  FILE* const stream);

// Return the i-th value of the VecLong
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGet(const VecLong* const that, const long i);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGet2D(const VecLong2D* const that, const long i);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGet3D(const VecLong3D* const that, const long i);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGet4D(const VecLong4D* const that, const long i);

// Set the i-th value of the VecLong to v
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSet(VecLong* const that, const long i, const long v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSet2D(VecLong2D* const that, const long i, const long v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSet3D(VecLong3D* const that, const long i, const long v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSet4D(VecLong4D* const that, const long i, const long v);

// Set the i-th value of the VecLong to v plus its current value
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSetAdd(VecLong* const that, const long i, const long v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSetAdd2D(VecLong2D* const that, const long i, const long v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSetAdd3D(VecLong3D* const that, const long i, const long v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSetAdd4D(VecLong4D* const that, const long i, const long v);

// Return the dimension of the VecLong
// Return 0 if arguments are invalid
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGetDim(const VecLong* const that);

// Return the Hamiltonian distance between the VecLong 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongHamiltonDist(const VecLong* const that, const VecLong* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongHamiltonDist2D(const VecLong2D* const that, const VecLong2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongHamiltonDist3D(const VecLong3D* const that, const VecLong3D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongHamiltonDist4D(const VecLong4D* const that, const VecLong4D* const tho);

// Return true if the VecLong 'that' is equal to 'tho', else false
#if BUILDMODE != 0 
static inline 
#endif 
bool _VecLongIsEqual(const VecLong* const that, 
  const VecLong* const tho);

// Copy the values of 'w' in 'that' (must have same dimensions)
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongCopy(VecLong* const that, const VecLong* const w);

// Return the dot product of 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongDotProd(const VecLong* const that, 
  const VecLong* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongDotProd2D(const VecLong2D* const that, 
  const VecLong2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongDotProd3D(const VecLong3D* const that, 
  const VecLong3D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongDotProd4D(const VecLong4D* const that, 
  const VecLong4D* const tho);

// Set all values of the vector 'that' to 0
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongSetNull(VecLong* const that);

// Step the values of the vector incrementally by 1 from 0
// in the following order (for example) : 
// (0,0,0)->(0,0,1)->(0,0,2)->(0,1,0)->(0,1,1)->...
// The upper limit for each value is given by 'bound' (val[i] < dim[i])
// Return false if all values of 'that' have reached their upper limit 
// (in which case 'that''s values are all set back to 0)
// Return true else
bool _VecLongStep(VecLong* const that, const VecLong* const bound);

// Step the values of the vector incrementally by 1 from 0
// in the following order (for example) : 
// (0,0,0)->(1,0,0)->(2,0,0)->(0,1,0)->(1,1,0)->...
// The upper limit for each value is given by 'bound' (val[i] < dim[i])
// Return false if all values of 'that' have reached their upper limit 
// (in which case 'that''s values are all set back to 0)
// Return true else
bool _VecLongPStep(VecLong* const that, const VecLong* const bound);

// Step the values of the vector incrementally by 1
// in the following order (for example) : 
// (0,0,0)->(0,0,1)->(0,0,2)->(0,1,0)->(0,1,1)->...
// The lower limit for each value is given by 'from' (val[i] >= from[i])
// The upper limit for each value is given by 'to' (val[i] < to[i])
// 'that' must be initialised to 'from' before the first call of this
// function
// Return false if all values of 'that' have reached their upper limit 
// (in which case 'that''s values are all set back to from)
// Return true else
bool _VecLongShiftStep(VecLong* const that, 
  const VecLong* const from, const VecLong* const to);

// Step the values of the vector incrementally by delta from 0
// in the following order (for example) : 
// (0,0,0)->(0,0,1)->(0,0,2)->(0,1,0)->(0,1,1)->...
// The upper limit for each value is given by 'bound' (val[i] <= dim[i])
// Return false after all values of 'that' have reached their upper 
// limit (in which case 'that''s values are all set back to 0)
// Return true else
bool _VecLongStepDelta(VecLong* const that, 
  const VecLong* const bound, const VecLong* const delta);

// Step the values of the vector incrementally by delta from 0
// in the following order (for example) : 
// (0,0,0)->(1,0,0)->(2,0,0)->(0,1,0)->(1,1,0)->...
// The upper limit for each value is given by 'bound' (val[i] <= dim[i])
// Return false after all values of 'that' have reached their upper 
// limit (in which case 'that''s values are all set back to 0)
// Return true else
bool _VecLongPStepDelta(VecLong* const that, 
  const VecLong* const bound, const VecLong* const delta);

// Calculate (that * a + tho * b) and store the result in 'that'
// 'tho' can be null, in which case it is consider to be the null vector
// If 'tho' is not null it must be of same dimension as 'that'
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongOp(VecLong* const that, const long a, 
  const VecLong* const tho, const long b);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongOp2D(VecLong2D* const that, const long a, 
  const VecLong2D* const tho, const long b);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongOp3D(VecLong3D* const that, const long a, 
  const VecLong3D* const tho, const long b);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongOp4D(VecLong4D* const that, const long a, 
  const VecLong4D* const tho, const long b);

// Return a VecLong equal to (that * a + tho * b)
// Return NULL if arguments are invalid
// 'tho' can be null, in which case it is consider to be the null vector
// If 'tho' is not null it must be of same dimension as 'that'
#if BUILDMODE != 0 
static inline 
#endif 
VecLong* _VecLongGetOp(const VecLong* const that, const long a, 
  const VecLong* const tho, const long b);
#if BUILDMODE != 0 
static inline 
#endif 
VecLong2D _VecLongGetOp2D(const VecLong2D* const that, const long a, 
  const VecLong2D* const tho, const long b);
#if BUILDMODE != 0 
static inline 
#endif 
VecLong3D _VecLongGetOp3D(const VecLong3D* const that, const long a, 
  const VecLong3D* const tho, const long b);
#if BUILDMODE != 0 
static inline 
#endif 
VecLong4D _VecLongGetOp4D(const VecLong4D* const that, const long a, 
  const VecLong4D* const tho, const long b);

// Calculate the Hadamard product of that by tho and store the 
// result in 'that'
// 'tho' and 'that' must be of same dimension
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongHadamardProd(VecLong* const that, 
  const VecLong* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongHadamardProd2D(VecLong2D* const that, 
  const VecLong2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongHadamardProd3D(VecLong3D* const that, 
  const VecLong3D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecLongHadamardProd4D(VecLong4D* const that, 
  const VecLong4D* const tho);

// Return a VecLong equal to the hadamard product of 'that' and 'tho'
// Return NULL if arguments are invalid
// 'tho' and 'that' must be of same dimension
#if BUILDMODE != 0 
static inline 
#endif 
VecLong* _VecLongGetHadamardProd(const VecLong* const that, 
  const VecLong* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecLong2D _VecLongGetHadamardProd2D(const VecLong2D* const that, 
  const VecLong2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecLong3D _VecLongGetHadamardProd3D(const VecLong3D* const that, 
  const VecLong3D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecLong4D _VecLongGetHadamardProd4D(const VecLong4D* const that, 
  const VecLong4D* const tho);

// Get the max value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGetMaxVal(const VecLong* const that);

// Get the min value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGetMinVal(const VecLong* const that);

// Get the max value (in absolute value) in components of the 
// vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGetMaxValAbs(const VecLong* const that);

// Get the min value (in absolute value) in components of the 
// vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGetMinValAbs(const VecLong* const that);

// Get the index of the max value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecLongGetIMaxVal(const VecLong* const that);

// -------------- VecShort

// ================= Data structure ===================

// Vector of short values
typedef struct VecShort {
  // Dimension
  long _dim;
  // Values
  short _val[0];
} VecShort;

typedef struct VecShort2D {
  // Dimension
  long _dim;
  // Values
  short _val[2];
} VecShort2D;

typedef struct VecShort3D {
  // Dimension
  long _dim;
  // Values
  short _val[3];
} VecShort3D;

typedef struct VecShort4D {
  // Dimension
  long _dim;
  // Values
  short _val[4];
} VecShort4D;

// ================ Functions declaration ====================

// Create a new VecShort of dimension 'dim'
// Values are initalized to 0.0
VecShort* VecShortCreate(const long dim);

// Static constructors for VecShort
#if BUILDMODE != 0
static inline
#endif 
VecShort2D VecShortCreateStatic2D();
#if BUILDMODE != 0
static inline
#endif 
VecShort3D VecShortCreateStatic3D();
#if BUILDMODE != 0
static inline
#endif 
VecShort4D VecShortCreateStatic4D();

// Clone the VecShort
// Return NULL if we couldn't clone the VecShort
VecShort* _VecShortClone(const VecShort* const that);

// Function which return the JSON encoding of 'that' 
JSONNode* _VecShortEncodeAsJSON(const VecShort* const that);

// Function which decode from JSON encoding 'json' to 'that'
bool _VecShortDecodeAsJSON(VecShort** that, const JSONNode* const json);

// Load the VecShort from the stream
// If the VecShort is already allocated, it is freed before loading
// Return true in case of success, else false
bool _VecShortLoad(VecShort** that, FILE* const stream);

// Save the VecShort to the stream
// If 'compact' equals true it saves in compact form, else it saves in 
// readable form
// Return true in case of success, else false
bool _VecShortSave(const VecShort* const that, 
  FILE* const stream, const bool compact);

// Free the memory used by a VecShort
// Do nothing if arguments are invalid
void _VecShortFree(VecShort** that);

// Print the VecShort on 'stream'
void _VecShortPrint(const VecShort* const that, 
  FILE* const stream);

// Return the i-th value of the VecShort
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortGet(const VecShort* const that, const long i);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortGet2D(const VecShort2D* const that, const long i);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortGet3D(const VecShort3D* const that, const long i);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortGet4D(const VecShort4D* const that, const long i);

// Set the i-th value of the VecShort to v
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSet(VecShort* const that, const long i, const short v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSet2D(VecShort2D* const that, const long i, const short v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSet3D(VecShort3D* const that, const long i, const short v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSet4D(VecShort4D* const that, const long i, const short v);

// Set the i-th value of the VecShort to v plus its current value
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSetAdd(VecShort* const that, const long i, const short v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSetAdd2D(VecShort2D* const that, const long i, const short v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSetAdd3D(VecShort3D* const that, const long i, const short v);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSetAdd4D(VecShort4D* const that, const long i, const short v);

// Return the dimension of the VecShort
// Return 0 if arguments are invalid
#if BUILDMODE != 0 
static inline 
#endif 
long _VecShortGetDim(const VecShort* const that);

// Return the Hamiltonian distance between the VecShort 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortHamiltonDist(const VecShort* const that, const VecShort* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortHamiltonDist2D(const VecShort2D* const that, const VecShort2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortHamiltonDist3D(const VecShort3D* const that, const VecShort3D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortHamiltonDist4D(const VecShort4D* const that, const VecShort4D* const tho);

// Return true if the VecShort 'that' is equal to 'tho', else false
#if BUILDMODE != 0 
static inline 
#endif 
bool _VecShortIsEqual(const VecShort* const that, 
  const VecShort* const tho);

// Copy the values of 'w' in 'that' (must have same dimensions)
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortCopy(VecShort* const that, const VecShort* const w);

// Return the dot product of 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortDotProd(const VecShort* const that, 
  const VecShort* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortDotProd2D(const VecShort2D* const that, 
  const VecShort2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortDotProd3D(const VecShort3D* const that, 
  const VecShort3D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortDotProd4D(const VecShort4D* const that, 
  const VecShort4D* const tho);

// Set all values of the vector 'that' to 0
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortSetNull(VecShort* const that);

// Step the values of the vector incrementally by 1 from 0
// in the following order (for example) : 
// (0,0,0)->(0,0,1)->(0,0,2)->(0,1,0)->(0,1,1)->...
// The upper limit for each value is given by 'bound' (val[i] < dim[i])
// Return false if all values of 'that' have reached their upper limit 
// (in which case 'that''s values are all set back to 0)
// Return true else
bool _VecShortStep(VecShort* const that, const VecShort* const bound);

// Step the values of the vector incrementally by 1 from 0
// in the following order (for example) : 
// (0,0,0)->(1,0,0)->(2,0,0)->(0,1,0)->(1,1,0)->...
// The upper limit for each value is given by 'bound' (val[i] < dim[i])
// Return false if all values of 'that' have reached their upper limit 
// (in which case 'that''s values are all set back to 0)
// Return true else
bool _VecShortPStep(VecShort* const that, const VecShort* const bound);

// Step the values of the vector incrementally by 1
// in the following order (for example) : 
// (0,0,0)->(0,0,1)->(0,0,2)->(0,1,0)->(0,1,1)->...
// The lower limit for each value is given by 'from' (val[i] >= from[i])
// The upper limit for each value is given by 'to' (val[i] < to[i])
// 'that' must be initialised to 'from' before the first call of this
// function
// Return false if all values of 'that' have reached their upper limit 
// (in which case 'that''s values are all set back to from)
// Return true else
bool _VecShortShiftStep(VecShort* const that, 
  const VecShort* const from, const VecShort* const to);

// Step the values of the vector incrementally by delta from 0
// in the following order (for example) : 
// (0,0,0)->(0,0,1)->(0,0,2)->(0,1,0)->(0,1,1)->...
// The upper limit for each value is given by 'bound' (val[i] <= dim[i])
// Return false after all values of 'that' have reached their upper 
// limit (in which case 'that''s values are all set back to 0)
// Return true else
bool _VecShortStepDelta(VecShort* const that, 
  const VecShort* const bound, const VecShort* const delta);

// Step the values of the vector incrementally by delta from 0
// in the following order (for example) : 
// (0,0,0)->(1,0,0)->(2,0,0)->(0,1,0)->(1,1,0)->...
// The upper limit for each value is given by 'bound' (val[i] <= dim[i])
// Return false after all values of 'that' have reached their upper 
// limit (in which case 'that''s values are all set back to 0)
// Return true else
bool _VecShortPStepDelta(VecShort* const that, 
  const VecShort* const bound, const VecShort* const delta);

// Calculate (that * a + tho * b) and store the result in 'that'
// 'tho' can be null, in which case it is consider to be the null vector
// If 'tho' is not null it must be of same dimension as 'that'
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortOp(VecShort* const that, const short a, 
  const VecShort* const tho, const short b);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortOp2D(VecShort2D* const that, const short a, 
  const VecShort2D* const tho, const short b);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortOp3D(VecShort3D* const that, const short a, 
  const VecShort3D* const tho, const short b);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortOp4D(VecShort4D* const that, const short a, 
  const VecShort4D* const tho, const short b);

// Return a VecShort equal to (that * a + tho * b)
// Return NULL if arguments are invalid
// 'tho' can be null, in which case it is consider to be the null vector
// If 'tho' is not null it must be of same dimension as 'that'
#if BUILDMODE != 0 
static inline 
#endif 
VecShort* _VecShortGetOp(const VecShort* const that, const short a, 
  const VecShort* const tho, const short b);
#if BUILDMODE != 0 
static inline 
#endif 
VecShort2D _VecShortGetOp2D(const VecShort2D* const that, const short a, 
  const VecShort2D* const tho, const short b);
#if BUILDMODE != 0 
static inline 
#endif 
VecShort3D _VecShortGetOp3D(const VecShort3D* const that, const short a, 
  const VecShort3D* const tho, const short b);
#if BUILDMODE != 0 
static inline 
#endif 
VecShort4D _VecShortGetOp4D(const VecShort4D* const that, const short a, 
  const VecShort4D* const tho, const short b);

// Calculate the Hadamard product of that by tho and store the 
// result in 'that'
// 'tho' and 'that' must be of same dimension
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortHadamardProd(VecShort* const that, 
  const VecShort* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortHadamardProd2D(VecShort2D* const that, 
  const VecShort2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortHadamardProd3D(VecShort3D* const that, 
  const VecShort3D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecShortHadamardProd4D(VecShort4D* const that, 
  const VecShort4D* const tho);

// Return a VecShort equal to the hadamard product of 'that' and 'tho'
// Return NULL if arguments are invalid
// 'tho' and 'that' must be of same dimension
#if BUILDMODE != 0 
static inline 
#endif 
VecShort* _VecShortGetHadamardProd(const VecShort* const that, 
  const VecShort* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecShort2D _VecShortGetHadamardProd2D(const VecShort2D* const that, 
  const VecShort2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecShort3D _VecShortGetHadamardProd3D(const VecShort3D* const that, 
  const VecShort3D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecShort4D _VecShortGetHadamardProd4D(const VecShort4D* const that, 
  const VecShort4D* const tho);

// Get the max value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortGetMaxVal(const VecShort* const that);

// Get the min value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortGetMinVal(const VecShort* const that);

// Get the max value (in absolute value) in components of the 
// vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortGetMaxValAbs(const VecShort* const that);

// Get the min value (in absolute value) in components of the 
// vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
short _VecShortGetMinValAbs(const VecShort* const that);

// Get the index of the max value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecShortGetIMaxVal(const VecShort* const that);

// -------------- VecFloat

// ================= Data structure ===================

// Vector of float values
typedef struct VecFloat {
  // Dimension
  long _dim;
  // Values
  float _val[0];
} VecFloat;

typedef struct VecFloat2D {
  // Dimension
  long _dim;
  // Values
  float _val[2];
} VecFloat2D;

typedef struct VecFloat3D {
  // Dimension
  long _dim;
  // Values
  float _val[3];
} VecFloat3D;

// ================ Functions declaration ====================

// Create a new VecFloat of dimension 'dim'
// Values are initalized to 0.0
VecFloat* VecFloatCreate(const long dim);

// Static constructors for VecFloat
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat2D VecFloatCreateStatic2D();
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat3D VecFloatCreateStatic3D();

// Clone the VecFloat
VecFloat* _VecFloatClone(const VecFloat* const that);

// Function which return the JSON encoding of 'that' 
JSONNode* _VecFloatEncodeAsJSON(const VecFloat* const that);

// Function which decode from JSON encoding 'json' to 'that'
bool _VecFloatDecodeAsJSON(VecFloat** that, const JSONNode* const json);

// Load the VecFloat from the stream
// If the VecFloat is already allocated, it is freed before loading
// Return true in case of success, else false
bool _VecFloatLoad(VecFloat** that, FILE* const stream);

// Save the VecFloat to the stream
// If 'compact' equals true it saves in compact form, else it saves in 
// readable form
// Return true in case of success, else false
bool _VecFloatSave(const VecFloat* const that, 
  FILE* const stream, const bool compact);

// Free the memory used by a VecFloat
// Do nothing if arguments are invalid
void _VecFloatFree(VecFloat** that);

// Print the VecFloat on 'stream' with 'prec' digit precision
// Do nothing if arguments are invalid
void VecFloatPrint(const VecFloat* const that, FILE* const stream, 
  const unsigned int prec);
static inline void _VecFloatPrintDef(const VecFloat* const that, 
  FILE* const stream) {
  VecFloatPrint(that, stream, 3);
}

// Return the 'i'-th value of the VecFloat
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatGet(const VecFloat* const that, const long i);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatGet2D(const VecFloat2D* const that, const long i);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatGet3D(const VecFloat3D* const that, const long i);

// Set the 'i'-th value of the VecFloat to 'v'
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatSet(VecFloat* const that, const long i, const float v);
#if BUILDMODE != 0
static inline
#endif 
void _VecFloatSet2D(VecFloat2D* const that, const long i, const float v);
#if BUILDMODE != 0
static inline
#endif 
void _VecFloatSet3D(VecFloat3D* const that, const long i, const float v);

// Set the 'i'-th value of the VecFloat to 'v' plus its current value
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatSetAdd(VecFloat* const that, const long i, const float v);
#if BUILDMODE != 0
static inline
#endif 
void _VecFloatSetAdd2D(VecFloat2D* const that, const long i, 
  const float v);
#if BUILDMODE != 0
static inline
#endif 
void _VecFloatSetAdd3D(VecFloat3D* const that, const long i, 
  const float v);

// Set all values of the vector 'that' to 0
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatSetNull(VecFloat* const that);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatSetNull2D(VecFloat2D* const that);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatSetNull3D(VecFloat3D* const that);

// Return the dimension of the VecFloat
// Return 0 if arguments are invalid
#if BUILDMODE != 0 
static inline 
#endif 
long _VecFloatGetDim(const VecFloat* const that);

// Return a new VecFloat as a copy of the VecFloat 'that' with 
// dimension changed to 'dim'
// if it is extended, the values of new components are 0.0
// If it is shrinked, values are discarded from the end of the vector
VecFloat* _VecFloatGetNewDim(const VecFloat* const that, const long dim); 

// Copy the values of 'w' in 'that' (must have same dimensions)
// Do nothing if arguments are invalid
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatCopy(VecFloat* const that, const VecFloat* const w);

// Return the norm of the VecFloat
// Return 0.0 if arguments are invalid
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatNorm(const VecFloat* const that);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatNorm2D(const VecFloat2D* const that);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatNorm3D(const VecFloat3D* const that);

// Normalise the VecFloat
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatNormalise(VecFloat* const that);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatNormalise2D(VecFloat2D* const that);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatNormalise3D(VecFloat3D* const that);

// Return the distance between the VecFloat 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatDist(const VecFloat* const that, 
  const VecFloat* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatDist2D(const VecFloat2D* const that, 
  const VecFloat2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatDist3D(const VecFloat3D* const that, 
  const VecFloat3D* const tho);

// Return the Hamiltonian distance between the VecFloat 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatHamiltonDist(const VecFloat* const that, 
  const VecFloat* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatHamiltonDist2D(const VecFloat2D* const that, 
  const VecFloat2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatHamiltonDist3D(const VecFloat3D* const that, 
  const VecFloat3D* const tho);

// Return the Pixel distance between the VecFloat 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatPixelDist(const VecFloat* const that, 
  const VecFloat* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatPixelDist2D(const VecFloat2D* const that, 
  const VecFloat2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatPixelDist3D(const VecFloat3D* const that, 
  const VecFloat3D* const tho);

// Return true if the VecFloat 'that' is equal to 'tho', else false
#if BUILDMODE != 0 
static inline 
#endif 
bool _VecFloatIsEqual(const VecFloat* const that, 
  const VecFloat* const tho);

// Calculate (that * a) and store the result in 'that'
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatScale(VecFloat* const that, const float a);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatScale2D(VecFloat2D* const that, const float a);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatScale3D(VecFloat3D* const that, const float a);

// Return a VecFloat equal to (that * a)
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat* _VecFloatGetScale(const VecFloat* const that, const float a);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat2D _VecFloatGetScale2D(const VecFloat2D* const that, 
  const float a);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat3D _VecFloatGetScale3D(const VecFloat3D* const that, 
  const float a);

// Calculate (that * a + tho * b) and store the result in 'that'
// 'tho' can be null, in which case it is consider to be the null vector
// If 'tho' is not null it must be of same dimension as 'that'
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatOp(VecFloat* const that, const float a, 
  const VecFloat* const tho, const float b);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatOp2D(VecFloat2D* const that, const float a, 
  const VecFloat2D* const tho, const float b);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatOp3D(VecFloat3D* const that, const float a, 
  const VecFloat3D* const tho, const float b);

// Return a VecFloat equal to (that * a + tho * b)
// Return NULL if arguments are invalid
// 'tho' can be null, in which case it is consider to be the null vector
// If 'tho' is not null it must be of same dimension as 'that'
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat* _VecFloatGetOp(const VecFloat* const that, const float a, 
  const VecFloat* const tho, const float b);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat2D _VecFloatGetOp2D(const VecFloat2D* const that, const float a, 
  const VecFloat2D* const tho, const float b);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat3D _VecFloatGetOp3D(const VecFloat3D* const that, const float a, 
  const VecFloat3D* const tho, const float b);

// Calculate the Hadamard product of that by tho and store the 
// result in 'that'
// 'tho' and 'that' must be of same dimension
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatHadamardProd(VecFloat* const that, 
  const VecFloat* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatHadamardProd2D(VecFloat2D* const that, 
  const VecFloat2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatHadamardProd3D(VecFloat3D* const that, 
  const VecFloat3D* const tho);

// Return a VecFloat equal to the hadamard product of 'that' and 'tho'
// Return NULL if arguments are invalid
// 'tho' and 'that' must be of same dimension
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat* _VecFloatGetHadamardProd(const VecFloat* const that, 
  const VecFloat* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat2D _VecFloatGetHadamardProd2D(const VecFloat2D* const that, 
  const VecFloat2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat3D _VecFloatGetHadamardProd3D(const VecFloat3D* const that, 
  const VecFloat3D* const tho);

// Rotate CCW 'that' by 'theta' radians and store the result in 'that'
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatRot2D(VecFloat2D* const that, const float theta);

// Return a VecFloat2D equal to 'that' rotated CCW by 'theta' radians
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat2D _VecFloatGetRot2D(const VecFloat2D* const that, 
  const float theta);

// Rotate right-hand 'that' by 'theta' radians around 'axis' and 
// store the result in 'that'
// 'axis' must be normalized
// https://en.wikipedia.org/wiki/Rotation_matrix
#if BUILDMODE != 0 
static inline 
#endif 
void _VecFloatRotAxis(VecFloat3D* const that, 
  const VecFloat3D* const axis, const float theta);

// Return a VecFloat3D equal to 'that' rotated right-hand by 'theta' 
// radians around 'axis'
// 'axis' must be normalized
// https://en.wikipedia.org/wiki/Rotation_matrix
VecFloat3D _VecFloatGetRotAxis(const VecFloat3D* const that, 
  const VecFloat3D* const axis, const float theta);

// Rotate right-hand 'that' by 'theta' radians around X and 
// store the result in 'that'
#if BUILDMODE != 0
static inline
#endif 
void _VecFloatRotX(VecFloat3D* const that, const float theta);

// Rotate right-hand 'that' by 'theta' radians around Y and 
// store the result in 'that'
#if BUILDMODE != 0
static inline
#endif 
void _VecFloatRotY(VecFloat3D* const that, const float theta);

// Rotate right-hand 'that' by 'theta' radians around Z and 
// store the result in 'that'
#if BUILDMODE != 0
static inline
#endif 
void _VecFloatRotZ(VecFloat3D* const that, const float theta);

// Return a VecFloat3D equal to 'that' rotated right-hand by 'theta' 
// radians around X
VecFloat3D _VecFloatGetRotX(const VecFloat3D* const that, 
  const float theta);

// Return a VecFloat3D equal to 'that' rotated right-hand by 'theta' 
// radians around Y
VecFloat3D _VecFloatGetRotY(const VecFloat3D* const that, 
  const float theta);

// Return a VecFloat3D equal to 'that' rotated right-hand by 'theta' 
// radians around Z
VecFloat3D _VecFloatGetRotZ(const VecFloat3D* const that, 
  const float theta);

// Return the dot product of 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatDotProd(const VecFloat* const that, 
  const VecFloat* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatDotProd2D(const VecFloat2D* const that, 
  const VecFloat2D* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatDotProd3D(const VecFloat3D* const that, 
  const VecFloat3D* const tho);

// Return the cross product of 'that' and 'tho'
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat* _VecFloatGetCrossProd(const VecFloat* const that, 
  const VecFloat* const tho);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat3D _VecFloatGetCrossProd3D(const VecFloat3D* const that, 
  const VecFloat3D* const tho);

// Return the angle of the rotation making 'that' colinear to 'tho'
// 'that' and 'tho' must be normalised
// Return a value in [-PI,PI]
float _VecFloatAngleTo2D(const VecFloat2D* const that, 
  const VecFloat2D* const tho);

// Return the conversion of VecFloat 'that' to a VecShort using round()
#if BUILDMODE != 0 
static inline 
#endif 
VecShort* VecFloatToShort(const VecFloat* const that);
#if BUILDMODE != 0 
static inline 
#endif 
VecShort2D VecFloatToShort2D(const VecFloat2D* const that);
#if BUILDMODE != 0 
static inline 
#endif 
VecShort3D VecFloatToShort3D(const VecFloat3D* const that);

// Return the conversion of VecShort 'that' to a VecFloat
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat* VecShortToFloat(const VecShort* const that);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat2D VecShortToFloat2D(const VecShort2D* const that);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat3D VecShortToFloat3D(const VecShort3D* const that);

// Return the conversion of VecLong 'that' to a VecFloat
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat* VecLongToFloat(const VecLong* const that);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat2D VecLongToFloat2D(const VecLong2D* const that);
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat3D VecLongToFloat3D(const VecLong3D* const that);

// Get the max value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatGetMaxVal(const VecFloat* const that);

// Get the min value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatGetMinVal(const VecFloat* const that);

// Get the max value (in absolute value) in components of the 
// vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatGetMaxValAbs(const VecFloat* const that);

// Get the min value (in absolute value) in components of the 
// vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
float _VecFloatGetMinValAbs(const VecFloat* const that);

// Step the values of the vector incrementally by delta from 0
// in the following order (for example) : 
// (0.,0.,0.)->(0.,0.,1.)->(0.,0.,2.)->(0.,1.,0.)->(0.,1.,1.)->...
// The upper limit for each value is given by 'bound' (val[i] <= dim[i])
// Return false after all values of 'that' have reached their upper 
// limit (in which case 'that''s values are all set back to 0.)
// Return true else
bool _VecFloatStepDelta(VecFloat* const that, 
  const VecFloat* const bound, const VecFloat* const delta);

// Step the values of the vector incrementally by delta
// in the following order (for example) : 
// (0.,0.,0.)->(0.,0.,1.)->(0.,0.,2.)->(0.,1.,0.)->(0.,1.,1.)->...
// The lower limit for each value is given by 'from' (val[i] >= from[i])
// The upper limit for each value is given by 'to' (val[i] <= to[i])
// 'that' must be initialised to 'from' before the first call of this
// function
// Return false after all values of 'that' have reached their upper 
// limit (in which case 'that''s values are all set back to from)
// Return true else
bool _VecFloatShiftStepDelta(VecFloat* const that, 
  const VecFloat* const from, const VecFloat* const to, 
  const VecFloat* const delta);

// Get the index of the max value in components of the vector 'that'
#if BUILDMODE != 0 
static inline 
#endif 
long _VecFloatGetIMaxVal(const VecFloat* const that);

// Return a set of two vectors containing the bounds of the vectors in 
// the GSet 'that'
// The set must have at least one element
// The returned set is ordered as follow: (boundMin, boundMax)
GSetVecFloat _GSetVecFloatGetBounds(const GSetVecFloat* const that);

// -------------- MatFloat

// ================= Data structure ===================

// Vector of float values
typedef struct MatFloat {
  // Dimension (nbCol, nbLine)
  const VecShort2D _dim;
  // Values (memorized by lines)
  float _val[0];
} MatFloat;

// Simple pod to hold the result of a QR decomposition
typedef struct QRDecomp {
  MatFloat* _Q;
  MatFloat* _R;
} QRDecomp;

// ================ Functions declaration ====================

// Free memory used by the QRDecomp 'that'
#if BUILDMODE != 0 
static inline 
#endif 
void QRDecompFreeStatic(QRDecomp* const that);

// Create a new MatFloat of dimension 'dim' (nbCol, nbLine)
// Values are initalized to 0.0
MatFloat* MatFloatCreate(const VecShort2D* const dim);

// Set the MatFloat to the identity matrix
// The matrix must be a square matrix
#if BUILDMODE != 0 
static inline 
#endif 
void _MatFloatSetIdentity(MatFloat* const that);

// Clone the MatFloat
MatFloat* _MatFloatClone(const MatFloat* const that);

// Copy the values of 'w' in 'that' (must have same dimensions)
#if BUILDMODE != 0 
static inline 
#endif 
void _MatFloatCopy(MatFloat* const that, const MatFloat* const tho);

// Function which return the JSON encoding of 'that' 
JSONNode* _MatFloatEncodeAsJSON(MatFloat* const that);

// Function which decode from JSON encoding 'json' to 'that'
bool _MatFloatDecodeAsJSON(MatFloat** that, JSONNode* json);

// Load the MatFloat from the stream
// If the MatFloat is already allocated, it is freed before loading
// Return true upon success, else false
bool _MatFloatLoad(MatFloat** that, FILE* stream);

// Save the MatFloat to the stream
// If 'compact' equals true it saves in compact form, else it saves in 
// readable form
// Return true upon success, else false
bool _MatFloatSave(MatFloat* const that, FILE* stream, bool compact);

// Free the memory used by a MatFloat
// Do nothing if arguments are invalid
void _MatFloatFree(MatFloat** that);

// Print the MatFloat on 'stream' with 'prec' digit precision
// Do nothing if arguments are invalid
void MatFloatPrintln(MatFloat* const that, FILE* stream, unsigned int prec);
static inline void _MatFloatPrintlnDef(MatFloat* const that, FILE* stream) {
  MatFloatPrintln(that, stream, 3);
}

// Return the value at index (col, line) of the MatFloat
// Index starts at 0, index in matrix = line * nbCol + col
#if BUILDMODE != 0 
static inline 
#endif 
float _MatFloatGet(const MatFloat* const that, 
  VecShort2D* index);

// Set the value at index (col, line) of the MatFloat to 'v'
// Index starts at 0, index in matrix = line * nbCol + col
#if BUILDMODE != 0 
static inline 
#endif 
void _MatFloatSet(MatFloat* const that, VecShort2D* index, float v);

// Return the dimension of the MatFloat
#if BUILDMODE != 0 
static inline 
#endif 
const VecShort2D* _MatFloatDim(const MatFloat* const that);

// Return a VecShort2D containing the dimension of the MatFloat
#if BUILDMODE != 0 
static inline 
#endif 
VecShort2D _MatFloatGetDim(const MatFloat* const that);

// Return the number of rows of the MatFloat 'that'
#if BUILDMODE != 0 
static inline 
#endif 
short _MatFloatGetNbRow(const MatFloat* const that);

// Return the number of columns of the MatFloat 'that'
#if BUILDMODE != 0 
static inline 
#endif 
short _MatFloatGetNbCol(const MatFloat* const that);

// Return the inverse matrix of 'that'
// The matrix must be a square matrix
MatFloat* _MatFloatGetInv(MatFloat* const that);

// Return the product of matrix 'that' and vector 'v'
// Number of columns of 'that' must equal dimension of 'v'
VecFloat* _MatFloatGetProdVecFloat(MatFloat* const that, VecFloat* v);

// Return the product of vector 'v' and transpose of vector 'w'
MatFloat* _MatFloatGetProdVecVecTransposeFloat(
  const VecFloat* const v, 
  const VecFloat* const w);

// Return the product of matrix 'that' by matrix 'tho'
// Number of columns of 'that' must equal number of line of 'tho'
MatFloat* _MatFloatGetProdMatFloat(MatFloat* const that, MatFloat* tho);

// Return the addition of matrix 'that' with matrix 'tho'
// 'that' and 'tho' must have same dimensions
#if BUILDMODE != 0 
static inline 
#endif 
MatFloat* _MatFloatGetAdd(MatFloat* const that, MatFloat* tho);

// Add matrix 'that' with matrix 'tho' and store the result in 'that'
// 'that' and 'tho' must have same dimensions
#if BUILDMODE != 0 
static inline 
#endif 
void _MatFloatAdd(MatFloat* const that, MatFloat* tho);

// Multiply the matrix 'that' by 'a'
#if BUILDMODE != 0 
static inline 
#endif 
void _MatFloatScale(MatFloat* const that, const float a);

// Return true if 'that' is equal to 'tho', false else
bool _MatFloatIsEqual(MatFloat* const that, MatFloat* tho);

// Calculate the Eigen values and vectors of the MatFloat 'that'
// Return a set of VecFloat. The first VecFloat of the set contains 
// the Eigen values, with values sorted from biggest to 
// smallest (in absolute value). The following VecFloat are the 
// respectiev Eigen vectors
// 'that' must be a 2D square matrix
// TODO: should be improved with the Hessenberg QR method
// https://www.math.kth.se/na/SF2524/matber15/qrmethod.pdf
// http://madrury.github.io/jekyll/update/statistics/2017/10/04/qr-algorithm.html
GSetVecFloat _MatFloatGetEigenValues(const MatFloat* const that);

// Calculate the QR decomposition of the MatFloat 'that' using the 
// Householder algorithm
// Return NULL if the MatFloat couldn't be decomposed
// http://www.seas.ucla.edu/~vandenbe/133A/lectures/qr.pdf
QRDecomp _MatFloatGetQR(const MatFloat* const that);

// Calculate the transposed of the MatFloat 'that'
MatFloat* _MatFloatGetTranspose(const MatFloat* const that);

// -------------- Gauss

// ================= Define ==================

// ================= Data structure ===================

// Should be vector of float values
typedef struct Gauss {
  // Mean
  float _mean;
  // Sigma
  float _sigma;
} Gauss;

// ================ Functions declaration ====================

// Create a new Gauss of mean 'mean' and sigma 'sigma'
// Return NULL if we couldn't create the Gauss
Gauss* GaussCreate(const float mean, const float sigma);
Gauss GaussCreateStatic(const float mean, const float sigma);

// Free the memory used by a Gauss
// Do nothing if arguments are invalid
void GaussFree(Gauss** that);

// Return the value of the Gauss 'that' at 'x'
#if BUILDMODE != 0 
static inline 
#endif 
float GaussGet(const Gauss* const that, const float x);

// Return a random value according to the Gauss 'that'
// random() must have been called before calling this function
#if BUILDMODE != 0 
static inline 
#endif 
float GaussRnd(Gauss* const that);

// -------------- Smoother

// ================= Define ==================

// ================= Data structure ===================

// ================ Functions declaration ====================

// Return the order 1 smooth value of 'x'
// if x < 0.0 return 0.0
// if x > 1.0 return 1.0
#if BUILDMODE != 0 
static inline 
#endif 
float SmoothStep(const float x);

// Return the order 2 smooth value of 'x'
// if x < 0.0 return 0.0
// if x > 1.0 return 1.0
#if BUILDMODE != 0 
static inline 
#endif 
float SmootherStep(const float x);

// -------------- Conversion functions

// ================ Functions declaration ====================

// Convert radians to degrees
static inline float ConvRad2Deg(const float rad) {
  return rad / PBMATH_TWOPI_DIV_360;
}

// Convert degrees to radians
static inline float ConvDeg2Rad(const float deg) {
  return PBMATH_TWOPI_DIV_360 * deg;
}

// -------------- SysLinEq

// ================= Data structure ===================

// Linear system of equalities
typedef struct SysLinEq {
  // Matrix
  MatFloat* _M;
  // Inverse of the matrix
  MatFloat* _Minv;
  // Vector
  VecFloat* _V;
} SysLinEq;

// ================ Functions declaration ====================

// Create a new SysLinEq with matrix 'm' and vector 'v'
// The dimension of 'v' must be equal to the number of column of 'm'
// If 'v' is null the vector null is used instead
// The matrix 'm' must be a square matrix
// Return NULL if we couldn't create the SysLinEq
SysLinEq* _SLECreate(const MatFloat* const m, const VecFloat* const v);

// Free the memory used by the SysLinEq
// Do nothing if arguments are invalid
void SysLinEqFree(SysLinEq** that);

// Clone the SysLinEq 'that'
// Return NULL if we couldn't clone the SysLinEq
SysLinEq* SysLinEqClone(const SysLinEq* const that);

// Solve the SysLinEq _M.x = _V
// Return the solution vector, or null if there is no solution or the 
// arguments are invalid
#if BUILDMODE != 0 
static inline 
#endif 
VecFloat* SysLinEqSolve(const SysLinEq* const that);

// Set the matrix of the SysLinEq to a clone of 'm'
// Do nothing if arguments are invalid
#if BUILDMODE != 0 
static inline 
#endif 
void SysLinEqSetM(SysLinEq* const that, const MatFloat* const m);

// Set the vector of the SysLinEq to a clone of 'v'
// Do nothing if arguments are invalid
#if BUILDMODE != 0 
static inline 
#endif 
void _SLESetV(SysLinEq* const that, const VecFloat* const v);

// -------------- Usefull basic functions

// ================ Functions declaration ====================

// Return x^y when x and y are int
// to avoid numerical imprecision from (pow(double,double)
// From https://stackoverflow.com/questions/29787310/
// does-pow-work-for-int-data-type-in-c
#if BUILDMODE != 0 
static inline 
#endif 
int powi(const int base, const int exp);

// Compute a^n, faster than std::pow for n<~100
static inline float fastpow(const float a, const int n) {
  double ret = 1.0;
  double b = a;
  for (int i = n; i--;) ret *= b;
  return (float)ret;
}

// Compute a^2
static inline float fsquare(const float a) {
  return a * a;
}

// Compute the 'iElem'-th element of the 'base'-ary version of the 
// Thue-Morse sequence
// 'iElem' >= 0
// 'base' >= 2
long ThueMorseSeqGetNthElem(long iElem, long base);

// Compute the area of a triangle knowing its 3 sides length 'a', 'b', 'c'
// using the Hero's formula
double GetAreaTriangleHero(
  const double a,
  const double b,
  const double c);

// ================= Polymorphism ==================

#define VecClone(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatClone, \
  VecShort*: _VecShortClone, \
  VecLong*: _VecLongClone, \
  const VecFloat*: _VecFloatClone, \
  const VecShort*: _VecShortClone, \
  const VecLong*: _VecLongClone, \
  default: PBErrInvalidPolymorphism)(Vec)

#define VecEncodeAsJSON(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatEncodeAsJSON, \
  VecShort*: _VecShortEncodeAsJSON, \
  VecLong*: _VecLongEncodeAsJSON, \
  const VecFloat*: _VecFloatEncodeAsJSON, \
  const VecShort*: _VecShortEncodeAsJSON, \
  const VecLong*: _VecLongEncodeAsJSON, \
  default: PBErrInvalidPolymorphism)(Vec)

#define VecDecodeAsJSON(VecRef, Json) _Generic(VecRef, \
  VecFloat**: _VecFloatDecodeAsJSON, \
  VecShort**: _VecShortDecodeAsJSON, \
  VecLong**: _VecLongDecodeAsJSON, \
  default: PBErrInvalidPolymorphism)(VecRef, Json)

#define VecLoad(VecRef, Stream) _Generic(VecRef, \
  VecFloat**: _VecFloatLoad, \
  VecShort**: _VecShortLoad, \
  VecLong**: _VecLongLoad, \
  default: PBErrInvalidPolymorphism)(VecRef, Stream)

#define VecSave(Vec, Stream, Compact) _Generic(Vec, \
  VecFloat*: _VecFloatSave, \
  VecFloat2D*: _VecFloatSave, \
  VecFloat3D*: _VecFloatSave, \
  VecShort*: _VecShortSave, \
  VecShort2D*: _VecShortSave, \
  VecShort3D*: _VecShortSave, \
  VecShort4D*: _VecShortSave, \
  VecLong*: _VecLongSave, \
  VecLong2D*: _VecLongSave, \
  VecLong3D*: _VecLongSave, \
  VecLong4D*: _VecLongSave, \
  const VecFloat*: _VecFloatSave, \
  const VecFloat2D*: _VecFloatSave, \
  const VecFloat3D*: _VecFloatSave, \
  const VecShort*: _VecShortSave, \
  const VecShort2D*: _VecShortSave, \
  const VecShort3D*: _VecShortSave, \
  const VecShort4D*: _VecShortSave, \
  const VecLong*: _VecLongSave, \
  const VecLong2D*: _VecLongSave, \
  const VecLong3D*: _VecLongSave, \
  const VecLong4D*: _VecLongSave, \
  default: PBErrInvalidPolymorphism)( \
    _Generic(Vec,  \
      VecFloat2D*: (const VecFloat*)(Vec), \
      VecFloat3D*: (const VecFloat*)(Vec), \
      VecShort2D*: (const VecShort*)(Vec), \
      VecShort3D*: (const VecShort*)(Vec), \
      VecShort4D*: (const VecShort*)(Vec), \
      VecLong2D*: (const VecLong*)(Vec), \
      VecLong3D*: (const VecLong*)(Vec), \
      VecLong4D*: (const VecLong*)(Vec), \
      const VecFloat2D*: (const VecFloat*)(Vec), \
      const VecFloat3D*: (const VecFloat*)(Vec), \
      const VecShort2D*: (const VecShort*)(Vec), \
      const VecShort3D*: (const VecShort*)(Vec), \
      const VecShort4D*: (const VecShort*)(Vec), \
      const VecLong2D*: (const VecLong*)(Vec), \
      const VecLong3D*: (const VecLong*)(Vec), \
      const VecLong4D*: (const VecLong*)(Vec), \
      default: Vec),  \
    Stream, Compact)

#define VecFree(VecRef) _Generic(VecRef, \
  VecFloat**: _VecFloatFree, \
  VecShort**: _VecShortFree, \
  VecLong**: _VecLongFree, \
  default: PBErrInvalidPolymorphism)(VecRef)

#define VecPrint(Vec, Stream) _Generic(Vec, \
  VecFloat*: _VecFloatPrintDef, \
  VecFloat2D*: _VecFloatPrintDef, \
  VecFloat3D*: _VecFloatPrintDef, \
  VecShort*: _VecShortPrint, \
  VecShort2D*: _VecShortPrint, \
  VecShort3D*: _VecShortPrint, \
  VecShort4D*: _VecShortPrint, \
  VecLong*: _VecLongPrint, \
  VecLong2D*: _VecLongPrint, \
  VecLong3D*: _VecLongPrint, \
  VecLong4D*: _VecLongPrint, \
  const VecFloat*: _VecFloatPrintDef, \
  const VecFloat2D*: _VecFloatPrintDef, \
  const VecFloat3D*: _VecFloatPrintDef, \
  const VecShort*: _VecShortPrint, \
  const VecShort2D*: _VecShortPrint, \
  const VecShort3D*: _VecShortPrint, \
  const VecShort4D*: _VecShortPrint, \
  const VecLong*: _VecLongPrint, \
  const VecLong2D*: _VecLongPrint, \
  const VecLong3D*: _VecLongPrint, \
  const VecLong4D*: _VecLongPrint, \
  default: PBErrInvalidPolymorphism)( \
    _Generic(Vec,  \
      VecFloat2D*: (const VecFloat*)(Vec), \
      VecFloat3D*: (const VecFloat*)(Vec), \
      VecShort2D*: (const VecShort*)(Vec), \
      VecShort3D*: (const VecShort*)(Vec), \
      VecShort4D*: (const VecShort*)(Vec), \
      VecLong2D*: (const VecLong*)(Vec), \
      VecLong3D*: (const VecLong*)(Vec), \
      VecLong4D*: (const VecLong*)(Vec), \
      const VecFloat2D*: (const VecFloat*)(Vec), \
      const VecFloat3D*: (const VecFloat*)(Vec), \
      const VecShort2D*: (const VecShort*)(Vec), \
      const VecShort3D*: (const VecShort*)(Vec), \
      const VecShort4D*: (const VecShort*)(Vec), \
      const VecLong2D*: (const VecLong*)(Vec), \
      const VecLong3D*: (const VecLong*)(Vec), \
      const VecLong4D*: (const VecLong*)(Vec), \
      default: Vec),  \
    Stream)

#define VecPrintln(V, S) do {VecPrint(V, S); fprintf(S, "\n");} while(0)

#define VecGet(Vec, Index) _Generic(Vec, \
  VecFloat*: _VecFloatGet, \
  VecFloat2D*: _VecFloatGet2D, \
  VecFloat3D*: _VecFloatGet3D, \
  VecShort*: _VecShortGet, \
  VecShort2D*: _VecShortGet2D, \
  VecShort3D*: _VecShortGet3D, \
  VecShort4D*: _VecShortGet4D, \
  VecLong*: _VecLongGet, \
  VecLong2D*: _VecLongGet2D, \
  VecLong3D*: _VecLongGet3D, \
  VecLong4D*: _VecLongGet4D, \
  const VecFloat*: _VecFloatGet, \
  const VecFloat2D*: _VecFloatGet2D, \
  const VecFloat3D*: _VecFloatGet3D, \
  const VecShort*: _VecShortGet, \
  const VecShort2D*: _VecShortGet2D, \
  const VecShort3D*: _VecShortGet3D, \
  const VecShort4D*: _VecShortGet4D, \
  const VecLong*: _VecLongGet, \
  const VecLong2D*: _VecLongGet2D, \
  const VecLong3D*: _VecLongGet3D, \
  const VecLong4D*: _VecLongGet4D, \
  default: PBErrInvalidPolymorphism)(Vec, Index)

#define VecSet(Vec, Index, Val) _Generic(Vec, \
  VecFloat*: _VecFloatSet, \
  VecFloat2D*: _VecFloatSet2D, \
  VecFloat3D*: _VecFloatSet3D, \
  VecShort*: _VecShortSet, \
  VecShort2D*: _VecShortSet2D, \
  VecShort3D*: _VecShortSet3D, \
  VecShort4D*: _VecShortSet4D, \
  VecLong*: _VecLongSet, \
  VecLong2D*: _VecLongSet2D, \
  VecLong3D*: _VecLongSet3D, \
  VecLong4D*: _VecLongSet4D, \
  default: PBErrInvalidPolymorphism)(Vec, Index, Val)

#define VecSetAdd(Vec, Index, Val) _Generic(Vec, \
  VecFloat*: _VecFloatSetAdd, \
  VecFloat2D*: _VecFloatSetAdd2D, \
  VecFloat3D*: _VecFloatSetAdd3D, \
  VecShort*: _VecShortSetAdd, \
  VecShort2D*: _VecShortSetAdd2D, \
  VecShort3D*: _VecShortSetAdd3D, \
  VecShort4D*: _VecShortSetAdd4D, \
  VecLong*: _VecLongSetAdd, \
  VecLong2D*: _VecLongSetAdd2D, \
  VecLong3D*: _VecLongSetAdd3D, \
  VecLong4D*: _VecLongSetAdd4D, \
  default: PBErrInvalidPolymorphism)(Vec, Index, Val)

#define VecSetNull(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatSetNull, \
  VecFloat2D*: _VecFloatSetNull, \
  VecFloat3D*: _VecFloatSetNull, \
  VecShort*: _VecShortSetNull, \
  VecShort2D*: _VecShortSetNull, \
  VecShort3D*: _VecShortSetNull, \
  VecShort4D*: _VecShortSetNull, \
  VecLong*: _VecLongSetNull, \
  VecLong2D*: _VecLongSetNull, \
  VecLong3D*: _VecLongSetNull, \
  VecLong4D*: _VecLongSetNull, \
  default: PBErrInvalidPolymorphism)( \
    _Generic(Vec,  \
      VecFloat2D*: (VecFloat*)(Vec), \
      VecFloat3D*: (VecFloat*)(Vec), \
      VecShort2D*: (VecShort*)(Vec), \
      VecShort3D*: (VecShort*)(Vec), \
      VecShort4D*: (VecShort*)(Vec), \
      VecLong2D*: (VecLong*)(Vec), \
      VecLong3D*: (VecLong*)(Vec), \
      VecLong4D*: (VecLong*)(Vec), \
      default: Vec))

#define VecCopy(VecDest, VecSrc) _Generic(VecDest, \
  VecFloat*: _Generic(VecSrc, \
    VecFloat*: _VecFloatCopy, \
    VecFloat2D*: _VecFloatCopy, \
    VecFloat3D*: _VecFloatCopy, \
    const VecFloat*: _VecFloatCopy, \
    const VecFloat2D*: _VecFloatCopy, \
    const VecFloat3D*: _VecFloatCopy, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecSrc, \
    VecFloat*: _VecFloatCopy, \
    VecFloat2D*: _VecFloatCopy, \
    const VecFloat*: _VecFloatCopy, \
    const VecFloat2D*: _VecFloatCopy, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecSrc, \
    VecFloat*: _VecFloatCopy, \
    VecFloat3D*: _VecFloatCopy, \
    const VecFloat*: _VecFloatCopy, \
    const VecFloat3D*: _VecFloatCopy, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecSrc, \
    VecShort*: _VecShortCopy, \
    VecShort2D*: _VecShortCopy, \
    VecShort3D*: _VecShortCopy, \
    VecShort4D*: _VecShortCopy, \
    const VecShort*: _VecShortCopy, \
    const VecShort2D*: _VecShortCopy, \
    const VecShort3D*: _VecShortCopy, \
    const VecShort4D*: _VecShortCopy, \
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecSrc, \
    VecShort*: _VecShortCopy, \
    VecShort2D*: _VecShortCopy, \
    const VecShort*: _VecShortCopy, \
    const VecShort2D*: _VecShortCopy, \
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecSrc, \
    VecShort*: _VecShortCopy, \
    VecShort3D*: _VecShortCopy, \
    const VecShort*: _VecShortCopy, \
    const VecShort3D*: _VecShortCopy, \
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecSrc, \
    VecShort*: _VecShortCopy, \
    VecShort4D*: _VecShortCopy, \
    const VecShort*: _VecShortCopy, \
    const VecShort4D*: _VecShortCopy, \
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecSrc, \
    VecLong*: _VecLongCopy, \
    VecLong2D*: _VecLongCopy, \
    VecLong3D*: _VecLongCopy, \
    VecLong4D*: _VecLongCopy, \
    const VecLong*: _VecLongCopy, \
    const VecLong2D*: _VecLongCopy, \
    const VecLong3D*: _VecLongCopy, \
    const VecLong4D*: _VecLongCopy, \
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecSrc, \
    VecLong*: _VecLongCopy, \
    VecLong2D*: _VecLongCopy, \
    const VecLong*: _VecLongCopy, \
    const VecLong2D*: _VecLongCopy, \
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecSrc, \
    VecLong*: _VecLongCopy, \
    VecLong3D*: _VecLongCopy, \
    const VecLong*: _VecLongCopy, \
    const VecLong3D*: _VecLongCopy, \
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecSrc, \
    VecLong*: _VecLongCopy, \
    VecLong4D*: _VecLongCopy, \
    const VecLong*: _VecLongCopy, \
    const VecLong4D*: _VecLongCopy, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)( \
    _Generic(VecDest,  \
      VecFloat2D*: (VecFloat*)(VecDest), \
      VecFloat3D*: (VecFloat*)(VecDest), \
      VecShort2D*: (VecShort*)(VecDest), \
      VecShort3D*: (VecShort*)(VecDest), \
      VecShort4D*: (VecShort*)(VecDest), \
      VecLong2D*: (VecLong*)(VecDest), \
      VecLong3D*: (VecLong*)(VecDest), \
      VecLong4D*: (VecLong*)(VecDest), \
      default: VecDest),  \
    _Generic(VecSrc,  \
      VecFloat2D*: (const VecFloat*)(VecSrc), \
      VecFloat3D*: (const VecFloat*)(VecSrc), \
      VecShort2D*: (const VecShort*)(VecSrc), \
      VecShort3D*: (const VecShort*)(VecSrc), \
      VecShort4D*: (const VecShort*)(VecSrc), \
      VecLong2D*: (const VecLong*)(VecSrc), \
      VecLong3D*: (const VecLong*)(VecSrc), \
      VecLong4D*: (const VecLong*)(VecSrc), \
      const VecFloat2D*: (const VecFloat*)(VecSrc), \
      const VecFloat3D*: (const VecFloat*)(VecSrc), \
      const VecShort2D*: (const VecShort*)(VecSrc), \
      const VecShort3D*: (const VecShort*)(VecSrc), \
      const VecShort4D*: (const VecShort*)(VecSrc), \
      const VecLong2D*: (const VecLong*)(VecSrc), \
      const VecLong3D*: (const VecLong*)(VecSrc), \
      const VecLong4D*: (const VecLong*)(VecSrc), \
      default: VecSrc))

#define VecGetDim(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatGetDim, \
  VecFloat2D*: _VecFloatGetDim, \
  VecFloat3D*: _VecFloatGetDim, \
  VecShort*: _VecShortGetDim, \
  VecShort2D*: _VecShortGetDim, \
  VecShort3D*: _VecShortGetDim, \
  VecShort4D*: _VecShortGetDim, \
  VecLong*: _VecLongGetDim, \
  VecLong2D*: _VecLongGetDim, \
  VecLong3D*: _VecLongGetDim, \
  VecLong4D*: _VecLongGetDim, \
  const VecFloat*: _VecFloatGetDim, \
  const VecFloat2D*: _VecFloatGetDim, \
  const VecFloat3D*: _VecFloatGetDim, \
  const VecShort*: _VecShortGetDim, \
  const VecShort2D*: _VecShortGetDim, \
  const VecShort3D*: _VecShortGetDim, \
  const VecShort4D*: _VecShortGetDim, \
  const VecLong*: _VecLongGetDim, \
  const VecLong2D*: _VecLongGetDim, \
  const VecLong3D*: _VecLongGetDim, \
  const VecLong4D*: _VecLongGetDim, \
  default: PBErrInvalidPolymorphism)( \
    _Generic(Vec, \
      VecFloat*: (const VecFloat*)(Vec), \
      VecFloat2D*: (const VecFloat*)(Vec), \
      VecFloat3D*: (const VecFloat*)(Vec), \
      VecShort*: (const VecShort*)(Vec), \
      VecShort2D*: (const VecShort*)(Vec), \
      VecShort3D*: (const VecShort*)(Vec), \
      VecShort4D*: (const VecShort*)(Vec), \
      VecLong*: (const VecLong*)(Vec), \
      VecLong2D*: (const VecLong*)(Vec), \
      VecLong3D*: (const VecLong*)(Vec), \
      VecLong4D*: (const VecLong*)(Vec), \
      const VecFloat2D*: (const VecFloat*)(Vec), \
      const VecFloat3D*: (const VecFloat*)(Vec), \
      const VecShort2D*: (const VecShort*)(Vec), \
      const VecShort3D*: (const VecShort*)(Vec), \
      const VecShort4D*: (const VecShort*)(Vec), \
      const VecLong2D*: (const VecLong*)(Vec), \
      const VecLong3D*: (const VecLong*)(Vec), \
      const VecLong4D*: (const VecLong*)(Vec), \
      default: Vec))

#define VecGetNewDim(Vec, Dim) _Generic(Vec, \
  VecFloat*: _VecFloatGetNewDim, \
  const VecFloat*: _VecFloatGetNewDim, \
  default: PBErrInvalidPolymorphism)( \
    _Generic(Vec, \
      VecFloat*: Vec, \
      const VecFloat*: Vec, \
      default: Vec), Dim)

#define VecNorm(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatNorm, \
  VecFloat2D*: _VecFloatNorm2D, \
  VecFloat3D*: _VecFloatNorm3D, \
  const VecFloat*: _VecFloatNorm, \
  const VecFloat2D*: _VecFloatNorm2D, \
  const VecFloat3D*: _VecFloatNorm3D, \
  default: PBErrInvalidPolymorphism)(Vec)

#define VecNormalise(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatNormalise, \
  VecFloat2D*: _VecFloatNormalise2D, \
  VecFloat3D*: _VecFloatNormalise3D, \
  default: PBErrInvalidPolymorphism)(Vec)

#define VecDist(VecA, VecB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatDist, \
    const VecFloat*: _VecFloatDist, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatDist2D, \
    const VecFloat2D*: _VecFloatDist2D, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatDist3D, \
    const VecFloat3D*: _VecFloatDist3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecB, \
    VecShort*: _VecShortHamiltonDist,\
    const VecShort*: _VecShortHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortHamiltonDist2D,\
    const VecShort2D*: _VecShortHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortHamiltonDist3D,\
    const VecShort3D*: _VecShortHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortHamiltonDist4D,\
    const VecShort4D*: _VecShortHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecB, \
    VecLong*: _VecLongHamiltonDist,\
    const VecLong*: _VecLongHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongHamiltonDist2D,\
    const VecLong2D*: _VecLongHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongHamiltonDist3D,\
    const VecLong3D*: _VecLongHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongHamiltonDist4D,\
    const VecLong4D*: _VecLongHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  const VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatDist, \
    const VecFloat*: _VecFloatDist, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatDist2D, \
    const VecFloat2D*: _VecFloatDist2D, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatDist3D, \
    const VecFloat3D*: _VecFloatDist3D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort*: _Generic(VecB, \
    VecShort*: _VecShortHamiltonDist,\
    const VecShort*: _VecShortHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  const VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortHamiltonDist2D,\
    const VecShort2D*: _VecShortHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  const VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortHamiltonDist3D,\
    const VecShort3D*: _VecShortHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  const VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortHamiltonDist4D,\
    const VecShort4D*: _VecShortHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong*: _Generic(VecB, \
    VecLong*: _VecLongHamiltonDist,\
    const VecLong*: _VecLongHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  const VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongHamiltonDist2D,\
    const VecLong2D*: _VecLongHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongHamiltonDist3D,\
    const VecLong3D*: _VecLongHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongHamiltonDist4D,\
    const VecLong4D*: _VecLongHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(VecA, VecB)

#define VecHamiltonDist(VecA, VecB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatHamiltonDist, \
    const VecFloat*: _VecFloatHamiltonDist, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatHamiltonDist2D, \
    const VecFloat2D*: _VecFloatHamiltonDist2D, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatHamiltonDist3D, \
    const VecFloat3D*: _VecFloatHamiltonDist3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecB, \
    VecShort*: _VecShortHamiltonDist,\
    const VecShort*: _VecShortHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortHamiltonDist2D,\
    const VecShort2D*: _VecShortHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortHamiltonDist3D,\
    const VecShort3D*: _VecShortHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortHamiltonDist4D,\
    const VecShort4D*: _VecShortHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecB, \
    VecLong*: _VecLongHamiltonDist,\
    const VecLong*: _VecLongHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongHamiltonDist2D,\
    const VecLong2D*: _VecLongHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongHamiltonDist3D,\
    const VecLong3D*: _VecLongHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongHamiltonDist4D,\
    const VecLong4D*: _VecLongHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  const VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatHamiltonDist, \
    const VecFloat*: _VecFloatHamiltonDist, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatHamiltonDist2D, \
    const VecFloat2D*: _VecFloatHamiltonDist2D, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatHamiltonDist3D, \
    const VecFloat3D*: _VecFloatHamiltonDist3D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort*: _Generic(VecB, \
    VecShort*: _VecShortHamiltonDist,\
    const VecShort*: _VecShortHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  const VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortHamiltonDist2D,\
    const VecShort2D*: _VecShortHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  const VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortHamiltonDist3D,\
    const VecShort3D*: _VecShortHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  const VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortHamiltonDist4D,\
    const VecShort4D*: _VecShortHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong*: _Generic(VecB, \
    VecLong*: _VecLongHamiltonDist,\
    const VecLong*: _VecLongHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  const VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongHamiltonDist2D,\
    const VecLong2D*: _VecLongHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongHamiltonDist3D,\
    const VecLong3D*: _VecLongHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongHamiltonDist4D,\
    const VecLong4D*: _VecLongHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(VecA, VecB)

#define VecPixelDist(VecA, VecB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatPixelDist, \
    const VecFloat*: _VecFloatPixelDist, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatPixelDist2D, \
    const VecFloat2D*: _VecFloatPixelDist2D, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatPixelDist3D, \
    const VecFloat3D*: _VecFloatPixelDist3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecB, \
    VecShort*: _VecShortHamiltonDist,\
    const VecShort*: _VecShortHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortHamiltonDist2D,\
    const VecShort2D*: _VecShortHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortHamiltonDist3D,\
    const VecShort3D*: _VecShortHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortHamiltonDist4D,\
    const VecShort4D*: _VecShortHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecB, \
    VecLong*: _VecLongHamiltonDist,\
    const VecLong*: _VecLongHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongHamiltonDist2D,\
    const VecLong2D*: _VecLongHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongHamiltonDist3D,\
    const VecLong3D*: _VecLongHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongHamiltonDist4D,\
    const VecLong4D*: _VecLongHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  const VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatPixelDist, \
    const VecFloat*: _VecFloatPixelDist, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatPixelDist2D, \
    const VecFloat2D*: _VecFloatPixelDist2D, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatPixelDist3D, \
    const VecFloat3D*: _VecFloatPixelDist3D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort*: _Generic(VecB, \
    VecShort*: _VecShortHamiltonDist,\
    const VecShort*: _VecShortHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  const VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortHamiltonDist2D,\
    const VecShort2D*: _VecShortHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  const VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortHamiltonDist3D,\
    const VecShort3D*: _VecShortHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  const VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortHamiltonDist4D,\
    const VecShort4D*: _VecShortHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong*: _Generic(VecB, \
    VecLong*: _VecLongHamiltonDist,\
    const VecLong*: _VecLongHamiltonDist,\
    default: PBErrInvalidPolymorphism), \
  const VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongHamiltonDist2D,\
    const VecLong2D*: _VecLongHamiltonDist2D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongHamiltonDist3D,\
    const VecLong3D*: _VecLongHamiltonDist3D,\
    default: PBErrInvalidPolymorphism), \
  const VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongHamiltonDist4D,\
    const VecLong4D*: _VecLongHamiltonDist4D,\
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(VecA, VecB)

#define VecIsEqual(VecA, VecB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatIsEqual, \
    VecFloat2D*: _VecFloatIsEqual, \
    VecFloat3D*: _VecFloatIsEqual, \
    const VecFloat*: _VecFloatIsEqual, \
    const VecFloat2D*: _VecFloatIsEqual, \
    const VecFloat3D*: _VecFloatIsEqual, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat*: _VecFloatIsEqual, \
    VecFloat2D*: _VecFloatIsEqual, \
    const VecFloat*: _VecFloatIsEqual, \
    const VecFloat2D*: _VecFloatIsEqual, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat*: _VecFloatIsEqual, \
    VecFloat3D*: _VecFloatIsEqual, \
    const VecFloat*: _VecFloatIsEqual, \
    const VecFloat3D*: _VecFloatIsEqual, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecB, \
    VecShort*: _VecShortIsEqual,\
    VecShort2D*: _VecShortIsEqual,\
    VecShort3D*: _VecShortIsEqual,\
    VecShort4D*: _VecShortIsEqual,\
    const VecShort*: _VecShortIsEqual,\
    const VecShort2D*: _VecShortIsEqual,\
    const VecShort3D*: _VecShortIsEqual,\
    const VecShort4D*: _VecShortIsEqual,\
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecB, \
    VecShort*: _VecShortIsEqual,\
    VecShort2D*: _VecShortIsEqual,\
    const VecShort*: _VecShortIsEqual,\
    const VecShort2D*: _VecShortIsEqual,\
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecB, \
    VecShort*: _VecShortIsEqual,\
    VecShort3D*: _VecShortIsEqual,\
    const VecShort*: _VecShortIsEqual,\
    const VecShort3D*: _VecShortIsEqual,\
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecB, \
    VecShort*: _VecShortIsEqual,\
    VecShort4D*: _VecShortIsEqual,\
    const VecShort*: _VecShortIsEqual,\
    const VecShort4D*: _VecShortIsEqual,\
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecB, \
    VecLong*: _VecLongIsEqual,\
    VecLong2D*: _VecLongIsEqual,\
    VecLong3D*: _VecLongIsEqual,\
    VecLong4D*: _VecLongIsEqual,\
    const VecLong*: _VecLongIsEqual,\
    const VecLong2D*: _VecLongIsEqual,\
    const VecLong3D*: _VecLongIsEqual,\
    const VecLong4D*: _VecLongIsEqual,\
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecB, \
    VecLong*: _VecLongIsEqual,\
    VecLong2D*: _VecLongIsEqual,\
    const VecLong*: _VecLongIsEqual,\
    const VecLong2D*: _VecLongIsEqual,\
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecB, \
    VecLong*: _VecLongIsEqual,\
    VecLong3D*: _VecLongIsEqual,\
    const VecLong*: _VecLongIsEqual,\
    const VecLong3D*: _VecLongIsEqual,\
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecB, \
    VecLong*: _VecLongIsEqual,\
    VecLong4D*: _VecLongIsEqual,\
    const VecLong*: _VecLongIsEqual,\
    const VecLong4D*: _VecLongIsEqual,\
    default: PBErrInvalidPolymorphism), \
  const VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatIsEqual, \
    VecFloat2D*: _VecFloatIsEqual, \
    VecFloat3D*: _VecFloatIsEqual, \
    const VecFloat*: _VecFloatIsEqual, \
    const VecFloat2D*: _VecFloatIsEqual, \
    const VecFloat3D*: _VecFloatIsEqual, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat2D*: _Generic(VecB, \
    VecFloat*: _VecFloatIsEqual, \
    VecFloat2D*: _VecFloatIsEqual, \
    const VecFloat*: _VecFloatIsEqual, \
    const VecFloat2D*: _VecFloatIsEqual, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat3D*: _Generic(VecB, \
    VecFloat*: _VecFloatIsEqual, \
    VecFloat3D*: _VecFloatIsEqual, \
    const VecFloat*: _VecFloatIsEqual, \
    const VecFloat3D*: _VecFloatIsEqual, \
    default: PBErrInvalidPolymorphism), \
  const VecShort*: _Generic(VecB, \
    VecShort*: _VecShortIsEqual,\
    VecShort2D*: _VecShortIsEqual,\
    VecShort3D*: _VecShortIsEqual,\
    VecShort4D*: _VecShortIsEqual,\
    const VecShort*: _VecShortIsEqual,\
    const VecShort2D*: _VecShortIsEqual,\
    const VecShort3D*: _VecShortIsEqual,\
    const VecShort4D*: _VecShortIsEqual,\
    default: PBErrInvalidPolymorphism), \
  const VecShort2D*: _Generic(VecB, \
    VecShort*: _VecShortIsEqual,\
    VecShort2D*: _VecShortIsEqual,\
    const VecShort*: _VecShortIsEqual,\
    const VecShort2D*: _VecShortIsEqual,\
    default: PBErrInvalidPolymorphism), \
  const VecShort3D*: _Generic(VecB, \
    VecShort*: _VecShortIsEqual,\
    VecShort3D*: _VecShortIsEqual,\
    const VecShort*: _VecShortIsEqual,\
    const VecShort3D*: _VecShortIsEqual,\
    default: PBErrInvalidPolymorphism), \
  const VecShort4D*: _Generic(VecB, \
    VecShort*: _VecShortIsEqual,\
    VecShort4D*: _VecShortIsEqual,\
    const VecShort*: _VecShortIsEqual,\
    const VecShort4D*: _VecShortIsEqual,\
    default: PBErrInvalidPolymorphism), \
  const VecLong*: _Generic(VecB, \
    VecLong*: _VecLongIsEqual,\
    VecLong2D*: _VecLongIsEqual,\
    VecLong3D*: _VecLongIsEqual,\
    VecLong4D*: _VecLongIsEqual,\
    const VecLong*: _VecLongIsEqual,\
    const VecLong2D*: _VecLongIsEqual,\
    const VecLong3D*: _VecLongIsEqual,\
    const VecLong4D*: _VecLongIsEqual,\
    default: PBErrInvalidPolymorphism), \
  const VecLong2D*: _Generic(VecB, \
    VecLong*: _VecLongIsEqual,\
    VecLong2D*: _VecLongIsEqual,\
    const VecLong*: _VecLongIsEqual,\
    const VecLong2D*: _VecLongIsEqual,\
    default: PBErrInvalidPolymorphism), \
  const VecLong3D*: _Generic(VecB, \
    VecLong*: _VecLongIsEqual,\
    VecLong3D*: _VecLongIsEqual,\
    const VecLong*: _VecLongIsEqual,\
    const VecLong3D*: _VecLongIsEqual,\
    default: PBErrInvalidPolymorphism), \
  const VecLong4D*: _Generic(VecB, \
    VecLong*: _VecLongIsEqual,\
    VecLong4D*: _VecLongIsEqual,\
    const VecLong*: _VecLongIsEqual,\
    const VecLong4D*: _VecLongIsEqual,\
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)( \
    _Generic(VecA,  \
      VecFloat2D*: (const VecFloat*)(VecA), \
      VecFloat3D*: (const VecFloat*)(VecA), \
      VecShort2D*: (const VecShort*)(VecA), \
      VecShort3D*: (const VecShort*)(VecA), \
      VecShort4D*: (const VecShort*)(VecA), \
      VecLong2D*: (const VecLong*)(VecA), \
      VecLong3D*: (const VecLong*)(VecA), \
      VecLong4D*: (const VecLong*)(VecA), \
      const VecFloat2D*: (const VecFloat*)(VecA), \
      const VecFloat3D*: (const VecFloat*)(VecA), \
      const VecShort2D*: (const VecShort*)(VecA), \
      const VecShort3D*: (const VecShort*)(VecA), \
      const VecShort4D*: (const VecShort*)(VecA), \
      const VecLong2D*: (const VecLong*)(VecA), \
      const VecLong3D*: (const VecLong*)(VecA), \
      const VecLong4D*: (const VecLong*)(VecA), \
      default: VecA),  \
    _Generic(VecB,  \
      VecFloat2D*: (const VecFloat*)(VecB), \
      VecFloat3D*: (const VecFloat*)(VecB), \
      VecShort2D*: (const VecShort*)(VecB), \
      VecShort3D*: (const VecShort*)(VecB), \
      VecShort4D*: (const VecShort*)(VecB), \
      VecLong2D*: (const VecLong*)(VecB), \
      VecLong3D*: (const VecLong*)(VecB), \
      VecLong4D*: (const VecLong*)(VecB), \
      const VecFloat2D*: (const VecFloat*)(VecB), \
      const VecFloat3D*: (const VecFloat*)(VecB), \
      const VecShort2D*: (const VecShort*)(VecB), \
      const VecShort3D*: (const VecShort*)(VecB), \
      const VecShort4D*: (const VecShort*)(VecB), \
      const VecLong2D*: (const VecLong*)(VecB), \
      const VecLong3D*: (const VecLong*)(VecB), \
      const VecLong4D*: (const VecLong*)(VecB), \
      default: VecB))

#define VecOp(VecA, CoeffA, VecB, CoeffB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatOp, \
    const VecFloat*: _VecFloatOp, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatOp2D, \
    const VecFloat2D*: _VecFloatOp2D, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatOp3D, \
    const VecFloat3D*: _VecFloatOp3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecB, \
    VecShort*: _VecShortOp, \
    const VecShort*: _VecShortOp, \
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortOp2D, \
    const VecShort2D*: _VecShortOp2D, \
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortOp3D, \
    const VecShort3D*: _VecShortOp3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortOp4D, \
    const VecShort4D*: _VecShortOp4D, \
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecB, \
    VecLong*: _VecLongOp, \
    const VecLong*: _VecLongOp, \
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongOp2D, \
    const VecLong2D*: _VecLongOp2D, \
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongOp3D, \
    const VecLong3D*: _VecLongOp3D, \
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongOp4D, \
    const VecLong4D*: _VecLongOp4D, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(VecA, CoeffA, VecB, CoeffB)

#define VecGetOp(VecA, CoeffA, VecB, CoeffB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatGetOp, \
    const VecFloat*: _VecFloatGetOp, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatGetOp2D, \
    const VecFloat2D*: _VecFloatGetOp2D, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatGetOp3D, \
    const VecFloat3D*: _VecFloatGetOp3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecB, \
    VecShort*: _VecShortGetOp, \
    const VecShort*: _VecShortGetOp, \
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortGetOp2D, \
    const VecShort2D*: _VecShortGetOp2D, \
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortGetOp3D, \
    const VecShort3D*: _VecShortGetOp3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortGetOp4D, \
    const VecShort4D*: _VecShortGetOp4D, \
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecB, \
    VecLong*: _VecLongGetOp, \
    const VecLong*: _VecLongGetOp, \
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongGetOp2D, \
    const VecLong2D*: _VecLongGetOp2D, \
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongGetOp3D, \
    const VecLong3D*: _VecLongGetOp3D, \
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongGetOp4D, \
    const VecLong4D*: _VecLongGetOp4D, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatGetOp, \
    const VecFloat*: _VecFloatGetOp, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatGetOp2D, \
    const VecFloat2D*: _VecFloatGetOp2D, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatGetOp3D, \
    const VecFloat3D*: _VecFloatGetOp3D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort*: _Generic(VecB, \
    VecShort*: _VecShortGetOp, \
    const VecShort*: _VecShortGetOp, \
    default: PBErrInvalidPolymorphism), \
  const VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortGetOp2D, \
    const VecShort2D*: _VecShortGetOp2D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortGetOp3D, \
    const VecShort3D*: _VecShortGetOp3D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortGetOp4D, \
    const VecShort4D*: _VecShortGetOp4D, \
    default: PBErrInvalidPolymorphism), \
  const VecLong*: _Generic(VecB, \
    VecLong*: _VecLongGetOp, \
    const VecLong*: _VecLongGetOp, \
    default: PBErrInvalidPolymorphism), \
  const VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongGetOp2D, \
    const VecLong2D*: _VecLongGetOp2D, \
    default: PBErrInvalidPolymorphism), \
  const VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongGetOp3D, \
    const VecLong3D*: _VecLongGetOp3D, \
    default: PBErrInvalidPolymorphism), \
  const VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongGetOp4D, \
    const VecLong4D*: _VecLongGetOp4D, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(VecA, CoeffA, VecB, CoeffB)

#define VecHadamardProd(VecA, VecB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatHadamardProd, \
    const VecFloat*: _VecFloatHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatHadamardProd2D, \
    const VecFloat2D*: _VecFloatHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatHadamardProd3D, \
    const VecFloat3D*: _VecFloatHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecB, \
    VecShort*: _VecShortHadamardProd, \
    const VecShort*: _VecShortHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortHadamardProd2D, \
    const VecShort2D*: _VecShortHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortHadamardProd3D, \
    const VecShort3D*: _VecShortHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortHadamardProd4D, \
    const VecShort4D*: _VecShortHadamardProd4D, \
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecB, \
    VecLong*: _VecLongHadamardProd, \
    const VecLong*: _VecLongHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongHadamardProd2D, \
    const VecLong2D*: _VecLongHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongHadamardProd3D, \
    const VecLong3D*: _VecLongHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongHadamardProd4D, \
    const VecLong4D*: _VecLongHadamardProd4D, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(VecA, VecB)

#define VecGetHadamardProd(VecA, VecB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatGetHadamardProd, \
    const VecFloat*: _VecFloatGetHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatGetHadamardProd2D, \
    const VecFloat2D*: _VecFloatGetHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatGetHadamardProd3D, \
    const VecFloat3D*: _VecFloatGetHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort*: _Generic(VecB, \
    VecShort*: _VecShortGetHadamardProd, \
    const VecShort*: _VecShortGetHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortGetHadamardProd2D, \
    const VecShort2D*: _VecShortGetHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortGetHadamardProd3D, \
    const VecShort3D*: _VecShortGetHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortGetHadamardProd4D, \
    const VecShort4D*: _VecShortGetHadamardProd4D, \
    default: PBErrInvalidPolymorphism), \
  VecLong*: _Generic(VecB, \
    VecLong*: _VecLongGetHadamardProd, \
    const VecLong*: _VecLongGetHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongGetHadamardProd2D, \
    const VecLong2D*: _VecLongGetHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongGetHadamardProd3D, \
    const VecLong3D*: _VecLongGetHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongGetHadamardProd4D, \
    const VecLong4D*: _VecLongGetHadamardProd4D, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat*: _Generic(VecB, \
    VecFloat*: _VecFloatGetHadamardProd, \
    const VecFloat*: _VecFloatGetHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat2D*: _Generic(VecB, \
    VecFloat2D*: _VecFloatGetHadamardProd2D, \
    const VecFloat2D*: _VecFloatGetHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat3D*: _Generic(VecB, \
    VecFloat3D*: _VecFloatGetHadamardProd3D, \
    const VecFloat3D*: _VecFloatGetHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort*: _Generic(VecB, \
    VecShort*: _VecShortGetHadamardProd, \
    const VecShort*: _VecShortGetHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  const VecShort2D*: _Generic(VecB, \
    VecShort2D*: _VecShortGetHadamardProd2D, \
    const VecShort2D*: _VecShortGetHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort3D*: _Generic(VecB, \
    VecShort3D*: _VecShortGetHadamardProd3D, \
    const VecShort3D*: _VecShortGetHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  const VecShort4D*: _Generic(VecB, \
    VecShort4D*: _VecShortGetHadamardProd4D, \
    const VecShort4D*: _VecShortGetHadamardProd4D, \
    default: PBErrInvalidPolymorphism), \
  const VecLong*: _Generic(VecB, \
    VecLong*: _VecLongGetHadamardProd, \
    const VecLong*: _VecLongGetHadamardProd, \
    default: PBErrInvalidPolymorphism), \
  const VecLong2D*: _Generic(VecB, \
    VecLong2D*: _VecLongGetHadamardProd2D, \
    const VecLong2D*: _VecLongGetHadamardProd2D, \
    default: PBErrInvalidPolymorphism), \
  const VecLong3D*: _Generic(VecB, \
    VecLong3D*: _VecLongGetHadamardProd3D, \
    const VecLong3D*: _VecLongGetHadamardProd3D, \
    default: PBErrInvalidPolymorphism), \
  const VecLong4D*: _Generic(VecB, \
    VecLong4D*: _VecLongGetHadamardProd4D, \
    const VecLong4D*: _VecLongGetHadamardProd4D, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(VecA, VecB)

#define VecScale(Vec, Scale) _Generic(Vec, \
  VecFloat*: _VecFloatScale, \
  VecFloat2D*: _VecFloatScale2D, \
  VecFloat3D*: _VecFloatScale3D, \
  default: PBErrInvalidPolymorphism)(Vec, Scale)

#define VecGetScale(Vec, Scale) _Generic(Vec, \
  VecFloat*: _VecFloatGetScale, \
  const VecFloat*: _VecFloatGetScale, \
  VecFloat2D*: _VecFloatGetScale2D, \
  const VecFloat2D*: _VecFloatGetScale2D, \
  VecFloat3D*: _VecFloatGetScale3D, \
  const VecFloat3D*: _VecFloatGetScale3D, \
  default: PBErrInvalidPolymorphism)(Vec, Scale)

#define VecRot(Vec, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatRot2D, \
  VecFloat2D*: _VecFloatRot2D, \
  default: PBErrInvalidPolymorphism)((VecFloat2D*)(Vec), Theta)

#define VecGetRot(Vec, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatGetRot2D, \
  const VecFloat*: _VecFloatGetRot2D, \
  VecFloat2D*: _VecFloatGetRot2D, \
  const VecFloat2D*: _VecFloatGetRot2D, \
  default: PBErrInvalidPolymorphism)((const VecFloat2D*)(Vec), Theta)

#define VecRotAxis(Vec, Axis, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatRotAxis, \
  VecFloat3D*: _VecFloatRotAxis, \
  default: PBErrInvalidPolymorphism)((VecFloat3D*)(Vec), \
    (VecFloat3D*)(Axis), Theta)

#define VecGetRotAxis(Vec, Axis, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatGetRotAxis, \
  const VecFloat*: _VecFloatGetRotAxis, \
  VecFloat3D*: _VecFloatGetRotAxis, \
  const VecFloat3D*: _VecFloatGetRotAxis, \
  default: PBErrInvalidPolymorphism)((const VecFloat3D*)(Vec), \
    (const VecFloat3D*)(Axis), Theta)

#define VecRotX(Vec, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatRotX, \
  VecFloat3D*: _VecFloatRotX, \
  default: PBErrInvalidPolymorphism)((VecFloat3D*)(Vec), Theta)

#define VecGetRotX(Vec, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatGetRotX, \
  const VecFloat*: _VecFloatGetRotX, \
  VecFloat3D*: _VecFloatGetRotX, \
  const VecFloat3D*: _VecFloatGetRotX, \
  default: PBErrInvalidPolymorphism)((const VecFloat3D*)(Vec), Theta)

#define VecRotY(Vec, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatRotY, \
  VecFloat3D*: _VecFloatRotY, \
  default: PBErrInvalidPolymorphism)((VecFloat3D*)(Vec), Theta)

#define VecGetRotY(Vec, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatGetRotY, \
  const VecFloat*: _VecFloatGetRotY, \
  VecFloat3D*: _VecFloatGetRotY, \
  const VecFloat3D*: _VecFloatGetRotY, \
  default: PBErrInvalidPolymorphism)((const VecFloat3D*)(Vec), Theta)

#define VecRotZ(Vec, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatRotZ, \
  VecFloat3D*: _VecFloatRotZ, \
  default: PBErrInvalidPolymorphism)((VecFloat3D*)(Vec), Theta)

#define VecGetRotZ(Vec, Theta) _Generic(Vec, \
  VecFloat*: _VecFloatGetRotZ, \
  const VecFloat*: _VecFloatGetRotZ, \
  VecFloat3D*: _VecFloatGetRotZ, \
  const VecFloat3D*: _VecFloatGetRotZ, \
  default: PBErrInvalidPolymorphism)((const VecFloat3D*)(Vec), Theta)

#define VecDotProd(VecA, VecB) _Generic(VecA, \
  VecShort*: _VecShortDotProd,\
  const VecShort*: _VecShortDotProd,\
  VecShort2D*: _VecShortDotProd2D,\
  const VecShort2D*: _VecShortDotProd2D,\
  VecShort3D*: _VecShortDotProd3D,\
  const VecShort3D*: _VecShortDotProd3D,\
  VecShort4D*: _VecShortDotProd4D,\
  const VecShort4D*: _VecShortDotProd4D,\
  VecLong*: _VecLongDotProd,\
  const VecLong*: _VecLongDotProd,\
  VecLong2D*: _VecLongDotProd2D,\
  const VecLong2D*: _VecLongDotProd2D,\
  VecLong3D*: _VecLongDotProd3D,\
  const VecLong3D*: _VecLongDotProd3D,\
  VecLong4D*: _VecLongDotProd4D,\
  const VecLong4D*: _VecLongDotProd4D,\
  VecFloat*: _VecFloatDotProd, \
  const VecFloat*: _VecFloatDotProd, \
  VecFloat2D*: _VecFloatDotProd2D, \
  const VecFloat2D*: _VecFloatDotProd2D, \
  VecFloat3D*: _VecFloatDotProd3D, \
  const VecFloat3D*: _VecFloatDotProd3D, \
  default: PBErrInvalidPolymorphism) (VecA, VecB) \

#define VecCrossProd(VecA, VecB) _Generic(VecA, \
  VecFloat*: _VecFloatGetCrossProd, \
  const VecFloat*: _VecFloatGetCrossProd, \
  VecFloat3D*: _VecFloatGetCrossProd3D, \
  const VecFloat3D*: _VecFloatGetCrossProd3D, \
  default: PBErrInvalidPolymorphism) (VecA, VecB) \

#define VecAngleTo(VecFrom, VecTo) _Generic(VecFrom, \
  VecFloat*: _VecFloatAngleTo2D, \
  const VecFloat*: _VecFloatAngleTo2D, \
  VecFloat2D*: _VecFloatAngleTo2D, \
  const VecFloat2D*: _VecFloatAngleTo2D, \
  default: PBErrInvalidPolymorphism)((const VecFloat2D*)(VecFrom), \
    (const VecFloat2D*)(VecTo))

#define VecStep(Vec, VecBound) _Generic(Vec, \
  VecShort*: _VecShortStep, \
  VecShort2D*: _VecShortStep, \
  VecShort3D*: _VecShortStep, \
  VecShort4D*: _VecShortStep, \
  VecLong*: _VecLongStep, \
  VecLong2D*: _VecLongStep, \
  VecLong3D*: _VecLongStep, \
  VecLong4D*: _VecLongStep, \
  default: PBErrInvalidPolymorphism)(_Generic(Vec, \
    VecShort*: (VecShort*)(Vec), \
    VecShort2D*: (VecShort*)(Vec), \
    VecShort3D*: (VecShort*)(Vec), \
    VecShort4D*: (VecShort*)(Vec), \
    VecLong*: (VecLong*)(Vec), \
    VecLong2D*: (VecLong*)(Vec), \
    VecLong3D*: (VecLong*)(Vec), \
    VecLong4D*: (VecLong*)(Vec)), _Generic(VecBound, \
    VecShort*: (const VecShort*)(VecBound), \
    VecShort2D*: (const VecShort*)(VecBound), \
    VecShort3D*: (const VecShort*)(VecBound), \
    VecShort4D*: (const VecShort*)(VecBound), \
    const VecShort*: (const VecShort*)(VecBound), \
    const VecShort2D*: (const VecShort*)(VecBound), \
    const VecShort3D*: (const VecShort*)(VecBound), \
    const VecShort4D*: (const VecShort*)(VecBound), \
    VecLong*: (const VecLong*)(VecBound), \
    VecLong2D*: (const VecLong*)(VecBound), \
    VecLong3D*: (const VecLong*)(VecBound), \
    VecLong4D*: (const VecLong*)(VecBound), \
    const VecLong*: (const VecLong*)(VecBound), \
    const VecLong2D*: (const VecLong*)(VecBound), \
    const VecLong3D*: (const VecLong*)(VecBound), \
    const VecLong4D*: (const VecLong*)(VecBound)))

#define VecPStep(Vec, VecBound) _Generic(Vec, \
  VecShort*: _VecShortPStep, \
  VecShort2D*: _VecShortPStep, \
  VecShort3D*: _VecShortPStep, \
  VecShort4D*: _VecShortPStep, \
  VecLong*: _VecLongPStep, \
  VecLong2D*: _VecLongPStep, \
  VecLong3D*: _VecLongPStep, \
  VecLong4D*: _VecLongPStep, \
  default: PBErrInvalidPolymorphism)(_Generic(Vec, \
    VecShort*: (VecShort*)(Vec), \
    VecShort2D*: (VecShort*)(Vec), \
    VecShort3D*: (VecShort*)(Vec), \
    VecShort4D*: (VecShort*)(Vec), \
    VecLong*: (VecLong*)(Vec), \
    VecLong2D*: (VecLong*)(Vec), \
    VecLong3D*: (VecLong*)(Vec), \
    VecLong4D*: (VecLong*)(Vec)), _Generic(VecBound, \
    VecShort*: (const VecShort*)(VecBound), \
    VecShort2D*: (const VecShort*)(VecBound), \
    VecShort3D*: (const VecShort*)(VecBound), \
    VecShort4D*: (const VecShort*)(VecBound), \
    const VecShort*: (const VecShort*)(VecBound), \
    const VecShort2D*: (const VecShort*)(VecBound), \
    const VecShort3D*: (const VecShort*)(VecBound), \
    const VecShort4D*: (const VecShort*)(VecBound), \
    VecLong*: (const VecLong*)(VecBound), \
    VecLong2D*: (const VecLong*)(VecBound), \
    VecLong3D*: (const VecLong*)(VecBound), \
    VecLong4D*: (const VecLong*)(VecBound), \
    const VecLong*: (const VecLong*)(VecBound), \
    const VecLong2D*: (const VecLong*)(VecBound), \
    const VecLong3D*: (const VecLong*)(VecBound), \
    const VecLong4D*: (const VecLong*)(VecBound)))

#define VecShiftStep(Vec, VecFrom, VecTo) _Generic(Vec, \
  VecShort*: _VecShortShiftStep, \
  VecShort2D*: _VecShortShiftStep, \
  VecShort3D*: _VecShortShiftStep, \
  VecShort4D*: _VecShortShiftStep, \
  VecLong*: _VecLongShiftStep, \
  VecLong2D*: _VecLongShiftStep, \
  VecLong3D*: _VecLongShiftStep, \
  VecLong4D*: _VecLongShiftStep, \
  default: PBErrInvalidPolymorphism)(_Generic(Vec, \
    VecShort*: (VecShort*)(Vec), \
    VecShort2D*: (VecShort*)(Vec), \
    VecShort3D*: (VecShort*)(Vec), \
    VecShort4D*: (VecShort*)(Vec), \
    VecLong*: (VecLong*)(Vec), \
    VecLong2D*: (VecLong*)(Vec), \
    VecLong3D*: (VecLong*)(Vec), \
    VecLong4D*: (VecLong*)(Vec)), _Generic(VecFrom, \
    VecShort*: (const VecShort*)(VecFrom), \
    VecShort2D*: (const VecShort*)(VecFrom), \
    VecShort3D*: (const VecShort*)(VecFrom), \
    VecShort4D*: (const VecShort*)(VecFrom), \
    const VecShort*: (const VecShort*)(VecFrom), \
    const VecShort2D*: (const VecShort*)(VecFrom), \
    const VecShort3D*: (const VecShort*)(VecFrom), \
    const VecShort4D*: (const VecShort*)(VecFrom), \
    VecLong*: (const VecLong*)(VecFrom), \
    VecLong2D*: (const VecLong*)(VecFrom), \
    VecLong3D*: (const VecLong*)(VecFrom), \
    VecLong4D*: (const VecLong*)(VecFrom), \
    const VecLong*: (const VecLong*)(VecFrom), \
    const VecLong2D*: (const VecLong*)(VecFrom), \
    const VecLong3D*: (const VecLong*)(VecFrom), \
    const VecLong4D*: (const VecLong*)(VecFrom)), _Generic(VecTo, \
    VecShort*: (const VecShort*)(VecTo), \
    VecShort2D*: (const VecShort*)(VecTo), \
    VecShort3D*: (const VecShort*)(VecTo), \
    VecShort4D*: (const VecShort*)(VecTo), \
    const VecShort*: (const VecShort*)(VecTo), \
    const VecShort2D*: (const VecShort*)(VecTo), \
    const VecShort3D*: (const VecShort*)(VecTo), \
    const VecShort4D*: (const VecShort*)(VecTo), \
    VecLong*: (const VecLong*)(VecTo), \
    VecLong2D*: (const VecLong*)(VecTo), \
    VecLong3D*: (const VecLong*)(VecTo), \
    VecLong4D*: (const VecLong*)(VecTo), \
    const VecLong*: (const VecLong*)(VecTo), \
    const VecLong2D*: (const VecLong*)(VecTo), \
    const VecLong3D*: (const VecLong*)(VecTo), \
    const VecLong4D*: (const VecLong*)(VecTo)))

#define VecPStepDelta(Vec, VecBound, VecDelta) _Generic(Vec, \
  VecShort*: _VecShortPStepDelta, \
  VecShort2D*: _VecShortPStepDelta, \
  VecShort3D*: _VecShortPStepDelta, \
  VecShort4D*: _VecShortPStepDelta, \
  VecLong*: _VecLongPStepDelta, \
  VecLong2D*: _VecLongPStepDelta, \
  VecLong3D*: _VecLongPStepDelta, \
  VecLong4D*: _VecLongPStepDelta, \
  default: PBErrInvalidPolymorphism)(_Generic(Vec, \
    VecShort*: (VecShort*)(Vec), \
    VecShort2D*: (VecShort*)(Vec), \
    VecShort3D*: (VecShort*)(Vec), \
    VecShort4D*: (VecShort*)(Vec), \
    VecLong*: (VecLong*)(Vec), \
    VecLong2D*: (VecLong*)(Vec), \
    VecLong3D*: (VecLong*)(Vec), \
    VecLong4D*: (VecLong*)(Vec)), _Generic(VecBound, \
    VecShort*: (const VecShort*)(VecBound), \
    VecShort2D*: (const VecShort*)(VecBound), \
    VecShort3D*: (const VecShort*)(VecBound), \
    VecShort4D*: (const VecShort*)(VecBound), \
    const VecShort*: (const VecShort*)(VecBound), \
    const VecShort2D*: (const VecShort*)(VecBound), \
    const VecShort3D*: (const VecShort*)(VecBound), \
    const VecShort4D*: (const VecShort*)(VecBound), \
    VecLong*: (const VecLong*)(VecBound), \
    VecLong2D*: (const VecLong*)(VecBound), \
    VecLong3D*: (const VecLong*)(VecBound), \
    VecLong4D*: (const VecLong*)(VecBound), \
    const VecLong*: (const VecLong*)(VecBound), \
    const VecLong2D*: (const VecLong*)(VecBound), \
    const VecLong3D*: (const VecLong*)(VecBound), \
    const VecLong4D*: (const VecLong*)(VecBound)), _Generic(VecDelta, \
    VecShort*: (const VecShort*)(VecDelta), \
    VecShort2D*: (const VecShort*)(VecDelta), \
    VecShort3D*: (const VecShort*)(VecDelta), \
    VecShort4D*: (const VecShort*)(VecDelta), \
    const VecShort*: (const VecShort*)(VecDelta), \
    const VecShort2D*: (const VecShort*)(VecDelta), \
    const VecShort3D*: (const VecShort*)(VecDelta), \
    const VecShort4D*: (const VecShort*)(VecDelta), \
    VecLong*: (const VecLong*)(VecDelta), \
    VecLong2D*: (const VecLong*)(VecDelta), \
    VecLong3D*: (const VecLong*)(VecDelta), \
    VecLong4D*: (const VecLong*)(VecDelta), \
    const VecLong*: (const VecLong*)(VecDelta), \
    const VecLong2D*: (const VecLong*)(VecDelta), \
    const VecLong3D*: (const VecLong*)(VecDelta), \
    const VecLong4D*: (const VecLong*)(VecDelta)))

#define VecGetMaxVal(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatGetMaxVal, \
  const VecFloat*: _VecFloatGetMaxVal, \
  VecFloat2D*: _VecFloatGetMaxVal, \
  const VecFloat2D*: _VecFloatGetMaxVal, \
  VecFloat3D*: _VecFloatGetMaxVal, \
  const VecFloat3D*: _VecFloatGetMaxVal, \
  VecShort*: _VecShortGetMaxVal, \
  const VecShort*: _VecShortGetMaxVal, \
  VecShort2D*: _VecShortGetMaxVal, \
  const VecShort2D*: _VecShortGetMaxVal, \
  VecShort3D*: _VecShortGetMaxVal, \
  const VecShort3D*: _VecShortGetMaxVal, \
  VecShort4D*: _VecShortGetMaxVal, \
  const VecShort4D*: _VecShortGetMaxVal, \
  VecLong*: _VecLongGetMaxVal, \
  const VecLong*: _VecLongGetMaxVal, \
  VecLong2D*: _VecLongGetMaxVal, \
  const VecLong2D*: _VecLongGetMaxVal, \
  VecLong3D*: _VecLongGetMaxVal, \
  const VecLong3D*: _VecLongGetMaxVal, \
  VecLong4D*: _VecLongGetMaxVal, \
  const VecLong4D*: _VecLongGetMaxVal, \
  default: PBErrInvalidPolymorphism) (_Generic(Vec, \
    VecFloat2D*: (const VecFloat*)(Vec), \
    const VecFloat2D*: (const VecFloat*)(Vec), \
    VecFloat3D*: (const VecFloat*)(Vec), \
    const VecFloat3D*: (const VecFloat*)(Vec), \
    VecShort2D*: (const VecShort*)(Vec), \
    const VecShort2D*: (const VecShort*)(Vec), \
    VecShort3D*: (const VecShort*)(Vec), \
    const VecShort3D*: (const VecShort*)(Vec), \
    VecShort4D*: (const VecShort*)(Vec), \
    const VecShort4D*: (const VecShort*)(Vec), \
    VecLong2D*: (const VecLong*)(Vec), \
    const VecLong2D*: (const VecLong*)(Vec), \
    VecLong3D*: (const VecLong*)(Vec), \
    const VecLong3D*: (const VecLong*)(Vec), \
    VecLong4D*: (const VecLong*)(Vec), \
    const VecLong4D*: (const VecLong*)(Vec), \
    default: Vec))

#define VecGetMinVal(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatGetMinVal, \
  const VecFloat*: _VecFloatGetMinVal, \
  VecFloat2D*: _VecFloatGetMinVal, \
  const VecFloat2D*: _VecFloatGetMinVal, \
  VecFloat3D*: _VecFloatGetMinVal, \
  const VecFloat3D*: _VecFloatGetMinVal, \
  VecShort*: _VecShortGetMinVal, \
  const VecShort*: _VecShortGetMinVal, \
  VecShort2D*: _VecShortGetMinVal, \
  const VecShort2D*: _VecShortGetMinVal, \
  VecShort3D*: _VecShortGetMinVal, \
  const VecShort3D*: _VecShortGetMinVal, \
  VecShort4D*: _VecShortGetMinVal, \
  const VecShort4D*: _VecShortGetMinVal, \
  VecLong*: _VecLongGetMinVal, \
  const VecLong*: _VecLongGetMinVal, \
  VecLong2D*: _VecLongGetMinVal, \
  const VecLong2D*: _VecLongGetMinVal, \
  VecLong3D*: _VecLongGetMinVal, \
  const VecLong3D*: _VecLongGetMinVal, \
  VecLong4D*: _VecLongGetMinVal, \
  const VecLong4D*: _VecLongGetMinVal, \
  default: PBErrInvalidPolymorphism) (_Generic(Vec, \
    VecFloat2D*: (const VecFloat*)(Vec), \
    const VecFloat2D*: (const VecFloat*)(Vec), \
    VecFloat3D*: (const VecFloat*)(Vec), \
    const VecFloat3D*: (const VecFloat*)(Vec), \
    VecShort2D*: (const VecShort*)(Vec), \
    const VecShort2D*: (const VecShort*)(Vec), \
    VecShort3D*: (const VecShort*)(Vec), \
    const VecShort3D*: (const VecShort*)(Vec), \
    VecShort4D*: (const VecShort*)(Vec), \
    const VecShort4D*: (const VecShort*)(Vec), \
    VecLong2D*: (const VecLong*)(Vec), \
    const VecLong2D*: (const VecLong*)(Vec), \
    VecLong3D*: (const VecLong*)(Vec), \
    const VecLong3D*: (const VecLong*)(Vec), \
    VecLong4D*: (const VecLong*)(Vec), \
    const VecLong4D*: (const VecLong*)(Vec), \
    default: Vec))

#define VecGetMaxValAbs(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatGetMaxValAbs, \
  const VecFloat*: _VecFloatGetMaxValAbs, \
  VecFloat2D*: _VecFloatGetMaxValAbs, \
  const VecFloat2D*: _VecFloatGetMaxValAbs, \
  VecFloat3D*: _VecFloatGetMaxValAbs, \
  const VecFloat3D*: _VecFloatGetMaxValAbs, \
  VecShort*: _VecShortGetMaxValAbs, \
  const VecShort*: _VecShortGetMaxValAbs, \
  VecShort2D*: _VecShortGetMaxValAbs, \
  const VecShort2D*: _VecShortGetMaxValAbs, \
  VecShort3D*: _VecShortGetMaxValAbs, \
  const VecShort3D*: _VecShortGetMaxValAbs, \
  VecShort4D*: _VecShortGetMaxValAbs, \
  const VecShort4D*: _VecShortGetMaxValAbs, \
  VecLong*: _VecLongGetMaxValAbs, \
  const VecLong*: _VecLongGetMaxValAbs, \
  VecLong2D*: _VecLongGetMaxValAbs, \
  const VecLong2D*: _VecLongGetMaxValAbs, \
  VecLong3D*: _VecLongGetMaxValAbs, \
  const VecLong3D*: _VecLongGetMaxValAbs, \
  VecLong4D*: _VecLongGetMaxValAbs, \
  const VecLong4D*: _VecLongGetMaxValAbs, \
  default: PBErrInvalidPolymorphism) (_Generic(Vec, \
    VecFloat2D*: (const VecFloat*)(Vec), \
    const VecFloat2D*: (const VecFloat*)(Vec), \
    VecFloat3D*: (const VecFloat*)(Vec), \
    const VecFloat3D*: (const VecFloat*)(Vec), \
    VecShort2D*: (const VecShort*)(Vec), \
    const VecShort2D*: (const VecShort*)(Vec), \
    VecShort3D*: (const VecShort*)(Vec), \
    const VecShort3D*: (const VecShort*)(Vec), \
    VecShort4D*: (const VecShort*)(Vec), \
    const VecShort4D*: (const VecShort*)(Vec), \
    VecLong2D*: (const VecLong*)(Vec), \
    const VecLong2D*: (const VecLong*)(Vec), \
    VecLong3D*: (const VecLong*)(Vec), \
    const VecLong3D*: (const VecLong*)(Vec), \
    VecLong4D*: (const VecLong*)(Vec), \
    const VecLong4D*: (const VecLong*)(Vec), \
    default: Vec))

#define VecGetMinValAbs(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatGetMinValAbs, \
  const VecFloat*: _VecFloatGetMinValAbs, \
  VecFloat2D*: _VecFloatGetMinValAbs, \
  const VecFloat2D*: _VecFloatGetMinValAbs, \
  VecFloat3D*: _VecFloatGetMinValAbs, \
  const VecFloat3D*: _VecFloatGetMinValAbs, \
  VecShort*: _VecShortGetMinValAbs, \
  const VecShort*: _VecShortGetMinValAbs, \
  VecShort2D*: _VecShortGetMinValAbs, \
  const VecShort2D*: _VecShortGetMinValAbs, \
  VecShort3D*: _VecShortGetMinValAbs, \
  const VecShort3D*: _VecShortGetMinValAbs, \
  VecShort4D*: _VecShortGetMinValAbs, \
  const VecShort4D*: _VecShortGetMinValAbs, \
  VecLong*: _VecLongGetMinValAbs, \
  const VecLong*: _VecLongGetMinValAbs, \
  VecLong2D*: _VecLongGetMinValAbs, \
  const VecLong2D*: _VecLongGetMinValAbs, \
  VecLong3D*: _VecLongGetMinValAbs, \
  const VecLong3D*: _VecLongGetMinValAbs, \
  VecLong4D*: _VecLongGetMinValAbs, \
  const VecLong4D*: _VecLongGetMinValAbs, \
  default: PBErrInvalidPolymorphism) (_Generic(Vec, \
    VecFloat2D*: (const VecFloat*)(Vec), \
    const VecFloat2D*: (const VecFloat*)(Vec), \
    VecFloat3D*: (const VecFloat*)(Vec), \
    const VecFloat3D*: (const VecFloat*)(Vec), \
    VecShort2D*: (const VecShort*)(Vec), \
    const VecShort2D*: (const VecShort*)(Vec), \
    VecShort3D*: (const VecShort*)(Vec), \
    const VecShort3D*: (const VecShort*)(Vec), \
    VecShort4D*: (const VecShort*)(Vec), \
    const VecShort4D*: (const VecShort*)(Vec), \
    VecLong2D*: (const VecLong*)(Vec), \
    const VecLong2D*: (const VecLong*)(Vec), \
    VecLong3D*: (const VecLong*)(Vec), \
    const VecLong3D*: (const VecLong*)(Vec), \
    VecLong4D*: (const VecLong*)(Vec), \
    const VecLong4D*: (const VecLong*)(Vec), \
    default: Vec))

#define VecStepDelta(Vec, VecBound, Delta) _Generic(Vec, \
  VecFloat*: _VecFloatStepDelta, \
  VecFloat2D*: _VecFloatStepDelta, \
  VecFloat3D*: _VecFloatStepDelta, \
  VecShort*: _VecShortStepDelta, \
  VecShort2D*: _VecShortStepDelta, \
  VecShort3D*: _VecShortStepDelta, \
  VecShort4D*: _VecShortStepDelta, \
  VecLong*: _VecLongStepDelta, \
  VecLong2D*: _VecLongStepDelta, \
  VecLong3D*: _VecLongStepDelta, \
  VecLong4D*: _VecLongStepDelta, \
  default: PBErrInvalidPolymorphism)(_Generic(Vec, \
    VecFloat*: Vec, \
    VecFloat2D*: (VecFloat*)(Vec), \
    VecFloat3D*: (VecFloat*)(Vec), \
    VecShort*: Vec, \
    VecShort2D*: (VecShort*)(Vec), \
    VecShort3D*: (VecShort*)(Vec), \
    VecShort4D*: (VecShort*)(Vec), \
    VecLong*: Vec, \
    VecLong2D*: (VecLong*)(Vec), \
    VecLong3D*: (VecLong*)(Vec), \
    VecLong4D*: (VecLong*)(Vec)), _Generic(Vec, \
    VecFloat*: VecBound, \
    VecFloat2D*: (VecFloat*)(VecBound), \
    VecFloat3D*: (VecFloat*)(VecBound), \
    VecShort*: VecBound, \
    VecShort2D*: (VecShort*)(VecBound), \
    VecShort3D*: (VecShort*)(VecBound), \
    VecShort4D*: (VecShort*)(VecBound), \
    VecLong*: VecBound, \
    VecLong2D*: (VecLong*)(VecBound), \
    VecLong3D*: (VecLong*)(VecBound), \
    VecLong4D*: (VecLong*)(VecBound)), _Generic(Vec, \
    VecFloat*: Delta, \
    VecFloat2D*: (VecFloat*)(Delta), \
    VecFloat3D*: (VecFloat*)(Delta), \
    VecShort*: Delta, \
    VecShort2D*: (VecShort*)(Delta), \
    VecShort3D*: (VecShort*)(Delta), \
    VecShort4D*: (VecShort*)(Delta), \
    VecLong*: Delta, \
    VecLong2D*: (VecLong*)(Delta), \
    VecLong3D*: (VecLong*)(Delta), \
    VecLong4D*: (VecLong*)(Delta)))  

#define VecShiftStepDelta(Vec, VecFrom, VecTo, Delta) _Generic(Vec, \
  VecFloat*: _VecFloatShiftStepDelta, \
  VecFloat2D*: _VecFloatShiftStepDelta, \
  VecFloat3D*: _VecFloatShiftStepDelta, \
  default: PBErrInvalidPolymorphism)((VecFloat*)(Vec), \
    (VecFloat*)(VecFrom), (VecFloat*)(VecTo), (VecFloat*)(Delta))

#define VecGetIMaxVal(Vec) _Generic(Vec, \
  VecFloat*: _VecFloatGetIMaxVal, \
  const VecFloat*: _VecFloatGetIMaxVal, \
  VecFloat2D*: _VecFloatGetIMaxVal, \
  const VecFloat2D*: _VecFloatGetIMaxVal, \
  VecFloat3D*: _VecFloatGetIMaxVal, \
  const VecFloat3D*: _VecFloatGetIMaxVal, \
  VecShort*: _VecShortGetIMaxVal, \
  const VecShort*: _VecShortGetIMaxVal, \
  VecShort2D*: _VecShortGetIMaxVal, \
  const VecShort2D*: _VecShortGetIMaxVal, \
  VecShort3D*: _VecShortGetIMaxVal, \
  const VecShort3D*: _VecShortGetIMaxVal, \
  VecShort4D*: _VecShortGetIMaxVal, \
  const VecShort4D*: _VecShortGetIMaxVal, \
  VecLong*: _VecLongGetIMaxVal, \
  const VecLong*: _VecLongGetIMaxVal, \
  VecLong2D*: _VecLongGetIMaxVal, \
  const VecLong2D*: _VecLongGetIMaxVal, \
  VecLong3D*: _VecLongGetIMaxVal, \
  const VecLong3D*: _VecLongGetIMaxVal, \
  VecLong4D*: _VecLongGetIMaxVal, \
  const VecLong4D*: _VecLongGetIMaxVal, \
  default: PBErrInvalidPolymorphism) (_Generic(Vec, \
    VecFloat2D*: (const VecFloat*)(Vec), \
    const VecFloat2D*: (const VecFloat*)(Vec), \
    VecFloat3D*: (const VecFloat*)(Vec), \
    const VecFloat3D*: (const VecFloat*)(Vec), \
    VecShort2D*: (const VecShort*)(Vec), \
    const VecShort2D*: (const VecShort*)(Vec), \
    VecShort3D*: (const VecShort*)(Vec), \
    const VecShort3D*: (const VecShort*)(Vec), \
    VecShort4D*: (const VecShort*)(Vec), \
    const VecShort4D*: (const VecShort*)(Vec), \
    VecLong2D*: (const VecLong*)(Vec), \
    const VecLong2D*: (const VecLong*)(Vec), \
    VecLong3D*: (const VecLong*)(Vec), \
    const VecLong3D*: (const VecLong*)(Vec), \
    VecLong4D*: (const VecLong*)(Vec), \
    const VecLong4D*: (const VecLong*)(Vec), \
    default: Vec))

#define MatClone(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatClone, \
  const MatFloat*: _MatFloatClone, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatEncodeAsJSON(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatEncodeAsJSON, \
  const MatFloat*: _MatFloatEncodeAsJSON, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatDecodeAsJSON(MatRef, Json) _Generic(MatRef, \
  MatFloat**: _MatFloatDecodeAsJSON, \
  default: PBErrInvalidPolymorphism)(MatRef, Json)

#define MatLoad(MatRef, Stream) _Generic(MatRef, \
  MatFloat**: _MatFloatLoad, \
  default: PBErrInvalidPolymorphism)(MatRef, Stream)

#define MatSave(Mat, Stream, Compact) _Generic(Mat, \
  MatFloat*: _MatFloatSave, \
  const MatFloat*: _MatFloatSave, \
  default: PBErrInvalidPolymorphism)(Mat, Stream, Compact)

#define MatFree(MatRef) _Generic(MatRef, \
  MatFloat**: _MatFloatFree, \
  default: PBErrInvalidPolymorphism)(MatRef)

#define MatPrintln(Mat, Stream) _Generic(Mat, \
  MatFloat*: _MatFloatPrintlnDef, \
  const MatFloat*: _MatFloatPrintlnDef, \
  default: PBErrInvalidPolymorphism)(Mat, Stream)

#define MatGet(Mat, VecIndex) _Generic(Mat, \
  MatFloat*: _MatFloatGet, \
  const MatFloat*: _MatFloatGet, \
  default: PBErrInvalidPolymorphism)(Mat, VecIndex)

#define MatSet(Mat, VecIndex, Val) _Generic(Mat, \
  MatFloat*: _MatFloatSet, \
  default: PBErrInvalidPolymorphism)(Mat, VecIndex, Val)

#define MatCopy(MatDest, MatSrc) _Generic(MatDest, \
  MatFloat*: _Generic (MatSrc, \
    MatFloat*: _MatFloatCopy, \
    const MatFloat*: _MatFloatCopy, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(MatDest, MatSrc)

#define MatDim(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatDim, \
  const MatFloat*: _MatFloatDim, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatGetDim(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatGetDim, \
  const MatFloat*: _MatFloatGetDim, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatGetEigenValues(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatGetEigenValues, \
  const MatFloat*: _MatFloatGetEigenValues, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatGetQR(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatGetQR, \
  const MatFloat*: _MatFloatGetQR, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatGetInv(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatGetInv, \
  const MatFloat*: _MatFloatGetInv, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatGetTranspose(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatGetTranspose, \
  const MatFloat*: _MatFloatGetTranspose, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatGetNbRow(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatGetNbRow, \
  const MatFloat*: _MatFloatGetNbRow, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatGetNbCol(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatGetNbCol, \
  const MatFloat*: _MatFloatGetNbCol, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatGetProdMat(MatA, MatB) _Generic(MatA, \
  MatFloat*: _Generic(MatB, \
    MatFloat*: _MatFloatGetProdMatFloat, \
    const MatFloat*: _MatFloatGetProdMatFloat, \
    default: PBErrInvalidPolymorphism), \
  const MatFloat*: _Generic(MatB, \
    MatFloat*: _MatFloatGetProdMatFloat, \
    const MatFloat*: _MatFloatGetProdMatFloat, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(MatA, MatB)

#define MatGetProdVec(Mat, Vec) _Generic(Mat, \
  MatFloat*: _Generic(Vec, \
    VecFloat*: _MatFloatGetProdVecFloat, \
    const VecFloat*: _MatFloatGetProdVecFloat, \
    VecFloat2D*: _MatFloatGetProdVecFloat, \
    const VecFloat2D*: _MatFloatGetProdVecFloat, \
    VecFloat3D*: _MatFloatGetProdVecFloat, \
    const VecFloat3D*: _MatFloatGetProdVecFloat, \
    default: PBErrInvalidPolymorphism), \
  const MatFloat*: _Generic(Vec, \
    VecFloat*: _MatFloatGetProdVecFloat, \
    const VecFloat*: _MatFloatGetProdVecFloat, \
    VecFloat2D*: _MatFloatGetProdVecFloat, \
    const VecFloat2D*: _MatFloatGetProdVecFloat, \
    VecFloat3D*: _MatFloatGetProdVecFloat, \
    const VecFloat3D*: _MatFloatGetProdVecFloat, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(Mat, (VecFloat*)(Vec))

#define MatGetProdVecVecTranspose(VecA, VecB) _Generic(VecA, \
  VecFloat*: _Generic(VecB, \
    VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat*: _Generic(VecB, \
    VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    default: PBErrInvalidPolymorphism), \
  VecFloat2D*: _Generic(VecB, \
    VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat2D*: _Generic(VecB, \
    VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    default: PBErrInvalidPolymorphism), \
  VecFloat3D*: _Generic(VecB, \
    VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    default: PBErrInvalidPolymorphism), \
  const VecFloat3D*: _Generic(VecB, \
    VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat2D*: _MatFloatGetProdVecVecTransposeFloat, \
    VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    const VecFloat3D*: _MatFloatGetProdVecVecTransposeFloat, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)((VecFloat*)(VecA), \
    (VecFloat*)(VecB))

#define MatAdd(MatA, MatB) _Generic(MatA, \
  MatFloat*: _Generic(MatB, \
    MatFloat*: _MatFloatAdd, \
    const MatFloat*: _MatFloatAdd, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(MatA, MatB)

#define MatScale(MatA, A) _Generic(MatA, \
  MatFloat*: _MatFloatScale, \
  const MatFloat*: _MatFloatScale, \
  default: PBErrInvalidPolymorphism)(MatA, A)

#define MatGetAdd(MatA, MatB) _Generic(MatA, \
  MatFloat*: _Generic(MatB, \
    MatFloat*: _MatFloatGetAdd, \
    const MatFloat*: _MatFloatGetAdd, \
    default: PBErrInvalidPolymorphism), \
  const MatFloat*: _Generic(MatB, \
    MatFloat*: _MatFloatGetAdd, \
    const MatFloat*: _MatFloatGetAdd, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(MatA, MatB)

#define MatSetIdentity(Mat) _Generic(Mat, \
  MatFloat*: _MatFloatSetIdentity, \
  default: PBErrInvalidPolymorphism)(Mat)

#define MatIsEqual(MatA, MatB) _Generic(MatA, \
  MatFloat*: _Generic(MatB, \
    MatFloat*: _MatFloatIsEqual, \
    const MatFloat*: _MatFloatIsEqual, \
    default: PBErrInvalidPolymorphism), \
  const MatFloat*: _Generic(MatB, \
    MatFloat*: _MatFloatIsEqual, \
    const MatFloat*: _MatFloatIsEqual, \
    default: PBErrInvalidPolymorphism), \
  default: PBErrInvalidPolymorphism)(MatA, MatB)

#define SysLinEqCreate(Mat, Vec) _Generic(Vec, \
  VecFloat*: _SLECreate, \
  const VecFloat*: _SLECreate, \
  VecFloat2D*: _SLECreate, \
  const VecFloat2D*: _SLECreate, \
  VecFloat3D*: _SLECreate, \
  const VecFloat3D*: _SLECreate, \
  default: PBErrInvalidPolymorphism)(Mat, (VecFloat*)(Vec))

#define SysLinEqSetV(Sys, Vec) _Generic(Vec, \
  VecFloat*: _SLESetV, \
  const VecFloat*: _SLESetV, \
  VecFloat2D*: _SLESetV, \
  const VecFloat2D*: _SLESetV, \
  VecFloat3D*: _SLESetV, \
  const VecFloat3D*: _SLESetV, \
  default: PBErrInvalidPolymorphism)(Sys, (VecFloat*)(Vec))

// ================ static inliner ====================

#if BUILDMODE != 0
#include "pbmath-inline.c"
#endif


#endif
