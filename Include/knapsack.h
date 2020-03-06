// ============ KNAPSACK.H ================

#ifndef KNAPSACK_H
#define KNAPSACK_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "pberr.h"
#include "gset.h"

// ---- KnapSackPod

// ================= Data structure ===================

typedef struct KnapSackPod {
  // ID
  int _id;
  // Cost
  int _cost;
  // Value
  int _val;
} KnapSackPod;

// ================ Functions declaration ====================

// Create a new KnapSackPod with id 'id', cost 'cost' and value 'val'
KnapSackPod* KnapSackPodCreate(const int id, const int cost, 
  const int val);

// Free the memory used by the KnapSackPod 'that'
void KnapSackPodFree(KnapSackPod** that);

// Get the id of the KnapSackPod 'that'
#if BUILDMODE != 0
static inline
#endif 
int KSPGetId(const KnapSackPod* const that);

// Get the cost of the KnapSackPod 'that'
#if BUILDMODE != 0
static inline
#endif 
int KSPGetCost(const KnapSackPod* const that);

// Get the value of the KnapSackPod 'that'
#if BUILDMODE != 0
static inline
#endif 
int KSPGetValue(const KnapSackPod* const that);

// Set the cost of the KnapSackPod 'that' to 'cost'
#if BUILDMODE != 0
static inline
#endif 
void KSPSetCost(KnapSackPod* const that, const int cost);

// Set the value of the KnapSackPod 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif 
void KSPSetValue(KnapSackPod* const that, const int val);

// ---- 0-1 KnapSack

// ================= Data structure ===================

typedef struct KnapSack {
  // Budget
  int _budget;
  // GSet of selectable KnapSackPod
  GSetKnapSackPod _pods;
  // GSet of selected KnapSackPod
  GSetKnapSackPod _sel;
} KnapSack;

// ================ Functions declaration ====================

// Create a new KnapSack with the budget 'budget'
KnapSack* KnapSackCreate(const int budget);

// Free the memory used by the KnapSack 'that'
// The two GSetKnapSackPod are flushed but it's the responsibility 
// of the user to free each KnapSackPod 
void KnapSackFree(KnapSack** that);

// Get the budget of the KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
int KSGetBudget(const KnapSack* const that);

// Set the budget of the KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
void KSSetBudget(KnapSack* const that, const int budget);

// Get the GSet of selectable KnapSackPod of the KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
GSetKnapSackPod* KSPods(const KnapSack* const that);

// Select the best pods of the KnapSack 'that'
// https://en.wikipedia.org/wiki/Knapsack_problem 
void KSSelect(const KnapSack* const that);

// Get the GSet of selected KnapSackPod of the KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
GSetKnapSackPod* KSSelectedPods(const KnapSack* const that);

// Get the 'iPod'-th KnapSackPod of selectable pods of the 
// KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
const KnapSackPod* KSGetPod(const KnapSack* const that, const int iPod);

// Get the number of selectable pods of the KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
int KSGetNbPod(const KnapSack* const that);

// Get the 'iPod'-th KnapSackPod of selected pods of the 
// KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
const KnapSackPod* KSGetSelectedPod(const KnapSack* const that, 
  const int iPod);

// Get the number of selected pods of the KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
int KSGetNbSelectedPod(const KnapSack* const that);

// Get the cost of the KnapSack 'that' for currently selected pods
int KSGetCost(const KnapSack* const that);

// Get the value of the KnapSack 'that' for currently selected pods
int KSGetValue(const KnapSack* const that);

// Add a new KnapSackPod with cost 'cost' and value 'val' to the 
// KnapSack 'that'
#if BUILDMODE != 0
static inline
#endif 
void KSAdd(KnapSack* const that, const int cost, const int val);

// ================ static inliner ====================

#if BUILDMODE != 0
#include "knapsack-inline.c"
#endif


#endif
