//===--- AVR.h - Wrapper for symbols linked from the AVR module ----*- C -*-===//
//
// This source file is part of Swift for Arduino
//
// Copyright (c) 2020 Carl Peto
// Strictly limited, not for reproduction or copying, use only as explicitly
// allowed within the Swift for Arduino IDE.
//
//===----------------------------------------------------------------------===//
//
//  A wrapper around AVR library functions.
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_AVR_H
#define SWIFT_AVR_H

#include "SwiftStddef.h"
#include "Visibility.h"
#include "SwiftStdint.h"
#include "interrupt_helper.h"
#include "debug_malloc.h"

// use our AVR library one instead for defined semantics
__swift_int32_t _longRandom();

#ifdef AVR_LIBC_DEFINED

#ifdef __clang_version__
// Clang (we are parsing header files as bridging header)
#define __nonnull _Nonnull
#define __nullable _Nullable
#else
// GCC
#define __nonnull 
#define __nullable 
#endif

// PGM direct access
// workaround until the swift compiler supports address space 1 or similar
const unsigned char _byteFromProgmem(const unsigned char * __nonnull address);
const unsigned int _intFromProgmem(const unsigned char * __nonnull address);
const unsigned long _dwordFromProgmem(const unsigned char * __nonnull address);
const float _floatFromProgmem(const unsigned char * __nonnull address);

// access callback for missing runtime function (unit test stub only, other runtime stubs has no effect)
// void set_runtime_handler_callback(_Bool (* __nonnull handler)(const char *));
// void clear_runtime_handler_callback();

#endif

#endif // SWIFT_AVR_H
