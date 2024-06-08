#ifdef __clang_version__
// Clang (we are parsing header files as bridging header)
#define __nonnull _Nonnull
#define __nullable _Nullable
#else
// GCC
#define __nonnull 
#define __nullable 
#endif

#include <stddef.h>
#include <stdint.h>

extern char * __nullable __brkval;
extern char * __nullable __malloc_heap_start;
extern char * __nullable __malloc_heap_end;
extern size_t __malloc_margin;

static inline uint16_t __heap_top__(void) { return (uint16_t)__brkval; }
static inline uint16_t __heap_start__(void) { return (uint16_t)__malloc_heap_start; }
static inline uint16_t __heap_end__(void) { return (uint16_t)__malloc_heap_end; }

void _setMallocDebugHandler(void (* __nullable handler)(void * __nonnull buffer));
