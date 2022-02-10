#include "shift.h"

#define DEFINE_SHIFT(word_length) \
    uint64_t LSHIFT##word_length(word##word_length value, size_t length, size_t shift) \
    { \
        return (value.word << shift ) | (value.word >> (length - shift)); \
    } \
      \
    uint64_t RSHIFT##word_length(word##word_length value, size_t length, size_t shift) \
    { \
        return (value.word >> shift ) | (value.word << (length - shift)); \
    }

DEFINE_SHIFT(8);
DEFINE_SHIFT(16);
DEFINE_SHIFT(32);
DEFINE_SHIFT(48);
DEFINE_SHIFT(64);
