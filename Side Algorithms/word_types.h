#ifndef WORD_TYPES_H
#define WORD_TYPES_H
#include <stdint.h>

typedef struct 
{
    uint64_t word:8;
} word8;

typedef struct 
{
    uint64_t word:16;
} word16;

typedef struct 
{
    uint64_t word:32;
} word32;

typedef struct 
{
    uint64_t word:48;
} word48;

typedef struct 
{
    uint64_t word:64;
} word64;

#endif