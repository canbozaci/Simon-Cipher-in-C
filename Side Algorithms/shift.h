#ifndef SHIFT_H
#define SHIFT_H

#include <stdint.h>
#include <stddef.h>
#include "word_types.h"

#define DECLARE_SHIFT(word_length) \
    uint64_t LSHIFT##word_length(word##word_length value, size_t length, size_t shift); \
    uint64_t RSHIFT##word_length(word##word_length value, size_t length, size_t shift);
    
#define LSHIFT(value, word_length, shift) LSHIFT##word_length(value, word_length, shift)
#define RSHIFT(value, word_length, shift) RSHIFT##word_length(value, word_length, shift)
    

#endif 