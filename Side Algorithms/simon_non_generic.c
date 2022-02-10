#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <inttypes.h>

#include "nm.h"
#include "shift.h"

void simon128x128(uint64_t k[], uint64_t pt0, uint64_t pt1, uint64_t *ct0, uint64_t *ct1)
{
    uint64_t z[5]= {0x3E8958737D12B0E6, 0X23BE4C2D477C985A, 0X2BDC0D262847E5B3, 0X36EB19781229CD0F, 0x3479AD88170CA4EF};
    uint64_t y = pt0;
    uint64_t x = pt1;
    uint64_t temp = 0;
    int i; 
    int value = 0;
    int z_new = 0;
    int m = 2;
    int n = 64;  
    int T;
    uint64_t z_generic;
    simon_generic(n, m, &T,&z_generic);
    for (int i=m; i<T+2; i++){
        temp = x;
        x = (y ^ ((lshift(x, n, 1)) & (lshift(x, n, 8)))) ^ (lshift(x, n, 2)) ^ k[(i -m) % 2];
        y = temp;
        value = (i -m) % 62;
        z_new = (z[2] >> (61 - value)) & 0x1;
        temp = rshift(k[(i-1) % 2],n, 3);
        temp = temp ^ rshift(temp, n, 1);
        k[i % 2] = ~k[(i-m) % 2] ^ temp ^ z_new ^ 0x3;
    }
*ct0 = y;
*ct1 = x;
}

int main(){
    uint64_t k2[2] = { 0x0706050403020100, 0x0f0e0d0c0b0a0908};
    printf ("Key :        0%llx       0%llx\n",k2[1], k2[0]);
    uint64_t pt1_0 = 0x6c6c657661727420;
    uint64_t pt1_1 = 0x6373656420737265;
    uint64_t ct0, ct1;
    simon128x128(k2, pt1_0, pt1_1, &ct0, &ct1);
    printf ("Plaintext:   %llx       %llx\n", pt1_0, pt1_1);
    printf ("Ciphertext:  %llx       %llx\n", ct1, ct0);    
}
