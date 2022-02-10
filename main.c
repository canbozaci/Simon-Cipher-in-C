#include <stdio.h>
#include <stdint.h>

#include "nm.h"
#include "shift.h"
int n;
int m;

void simon_generic(uint64_t k[], uint64_t pt0, uint64_t pt1, uint64_t *ct0, uint64_t *ct1)
{
    uint64_t y = pt0;
    uint64_t x = pt1;
    uint64_t temp = 0; 
    int value = 0;
    int z_new = 0;
    int T;
    uint64_t c; // c = (2^n) - 4
    uint64_t z_generic; // z[] to be chosen
    simon_parameters(n, m, &T,&z_generic,&c); // T (round), z_generic and c produced here, those are related to n and m.
    for (int i=m; i<T+m; i++){
        temp = x;
        x = (y ^ ((lshift(x, n, 1)) & (lshift(x, n, 8)))) ^ (lshift(x, n, 2)) ^ k[(i -m) % m]; // %m due to generic code
        y = temp;
        value = (i -m) % 62; 
        z_new = (z_generic >> (value)) & 1;
        temp = rshift(k[(i-1) % m],n, 3);
        if (m==4){
          temp = temp ^ k[(i-3) % m];
        }
        temp = temp ^ rshift(temp, n, 1);
        k[i % m] = k[(i-m) % m] ^ temp ^ z_new ^ c;
    }
*ct0 = y;
*ct1 = x;
}


int main(){
   //         Cipher
   /* n =64;
    m =4;
    uint64_t k2[] = {0x0706050403020100, 0x0f0e0d0c0b0a0908, 0x1716151413121110, 0x1f1e1d1c1b1a1918};  // key
    uint64_t pt1_0 = 0x6d69732061207369; // plaintext LSB n bit
    uint64_t pt1_1 = 0x74206e69206d6f6f; // plaintext MSB n bit
    uint64_t ct0, ct1; 
    simon_generic(k2, pt1_0, pt1_1, &ct0, &ct1); 
    printf("Plaintext:   %llx       %llx\n", pt1_0, pt1_1);
    printf("Ciphertext:  %llx       %llx\n", ct1, ct0); */

    // Random Number Generator Using Simon Cipher
    n =64;
    m =2;
    uint64_t stream[312];
    uint64_t k2[] = {0x0f0e0d0c0b0a0908, 0x0706050403020100};
    uint64_t pt1_1 = 0x6c6c657661727420;
    uint64_t pt1_0 = 0x6373656420737265;
    uint64_t ct1_0;
    uint64_t ct1_1;

    simon_generic(k2,pt1_0,pt1_1,&ct1_0,&ct1_1);
    stream[0] = ct1_0 ^ pt1_0;
    stream[1] = ct1_1 ^ pt1_1;
    printf("%llx      ve      %llx\n", stream[0], stream [1]);
    for(int i = 0; i<39;i = i+2){
        simon_generic(k2,stream[i],stream[i+1],&ct1_0,&ct1_1);
        stream[i+3] = ct1_1 ^ stream[i+1];
        stream[i+2] = ct1_0 ^ stream[i];
        printf("%llx      ve      %llx\n", stream[i+2], stream [i+3]);
    }
}