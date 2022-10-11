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

// use our AVR library one instead for defined semantics
__swift_int32_t _longRandom();

// ISR compatible variable access, see AVR headers for details.
// _Bool _readSharedGlobalBool(_Bool test);
// __swift_uint8_t _readSharedGlobalUInt8(__swift_uint8_t test);
// __swift_int8_t _readSharedGlobalInt8(__swift_int8_t test);
// __swift_uint16_t _readSharedGlobalUInt16(__swift_uint16_t test);
// __swift_int16_t _readSharedGlobalInt16(__swift_int16_t test);
// __swift_uint32_t _readSharedGlobalUInt32(__swift_uint32_t test);
// __swift_int32_t _readSharedGlobalInt32(__swift_int32_t test);
// __swift_uint64_t _readSharedGlobalUInt64(__swift_uint64_t test);
// __swift_int64_t _readSharedGlobalInt64(__swift_int64_t test);
// float _readSharedGlobalFloat(float test);

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

// access callback for missing runtime function
void set_runtime_handler_callback(void (* handler)());

#endif

#endif // SWIFT_AVR_H
