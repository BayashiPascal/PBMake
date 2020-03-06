// ============ PBCEXTENSION.H ================

#ifndef PBCEXTENSION_H
#define PBCEXTENSION_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// ================= Define ==================

// Return the number of arguments of a variadic function given
// the type 'Type' of these arguments
#define __VA_NB_ARGS__(Type, ...) \
  (sizeof((Type[]){__VA_ARGS__})/sizeof(Type))

// Macro to swap two variables
#define swap(a, b) do {char c[sizeof(a)]; memcpy(c, &a, sizeof(a)); \
    a = b; memcpy(&b, c, sizeof(a));} while(0)

// Macros used to perform graphic rendering of text in the
// console
// cf https://en.wikipedia.org/wiki/ANSI_escape_code
// Example of use:
//  char* hello = "Hello\n";
//  SGRString(
//    SGR_SlowBlink(
//    SGR_Underline(
//    SGR_Bold(
//    SGR_ColorFG(255, 0, 0, 
//    SGR_ColorBG(0, 0, 255, hello))))));
#define SGRString(...) \
  (_SGRString(__VA_NB_ARGS__(char*, __VA_ARGS__), __VA_ARGS__))
#define SGR_Bold(str) "\033[1m",str,"\033[0m"
#define SGR_Underline(str) "\033[4m",str,"\033[0m"
#define SGR_SlowBlink(str) "\033[5m",str,"\033[0m"
#define SGR_ColorFG(r, g, b, str) "\033[38;2;" #r ";" #g ";" #b "m",str,"\033[39m"
#define SGR_ColorBG(r, g, b, str) "\033[48;2;" #r ";" #g ";" #b "m",str,"\033[49m"

// ================= Functions declaration ==================

// Functions used to perform graphic rendering of text in the
// console
// To be used through the macro SGRString
// Return a new string which must be freed by the caller, or
// NULL if we couldn't allocate memory for the result string
char* _SGRString(int nbStr, ...);

#endif
