#include <stdint.h>
#include <inttypes.h>
#include "nm.h"
#include "shift.h"

// ------------------------------------
// Key Generation
// ------------------------------------

int main()
{
    int m = 2;
    int n = 64;
    int T;
    uint64_t z_generic;
    uint64_t c;
    simon_parameters(n,m,&T, &z_generic, &c);
    int i;
    int value = 0;
    int z_new = 0;
    uint64_t k[] = {0x0000000000000001, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001}; 
    uint64_t temp = 0;
    uint64_t z[5]= {0x3E8958737D12B0E6, 0X23BE4C2D477C985A, 0X2BDC0D262847EB3, 0X36EB19781229CD0F, 0x3479AD88170CA4EF};
    for (i =m; i < T + m;i++){
        value = (i -m) % 62;
        z_new = (z_generic >> (61 - value)) & 0x1; 
        temp = rshift(k[(i-1) % m],n, 3);
        if (m==4){
          temp = temp ^ k[i-3];
        }
        temp = temp ^ rshift(temp, n, 1);
        k[i % m] = ~k[(i-m) % m] ^ temp ^ z_new ^ 0x3;
    }
}