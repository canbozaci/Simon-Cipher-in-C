#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <inttypes.h>
 // **Left and Right Shift**
uint64_t rshift(uint64_t l, int n, int shift){
  l = (l >> shift) | (l << (n- shift));
  return l;
}
uint64_t lshift(uint64_t l, int n, int shift){
  l = (l << shift) | (l >> (n- shift));
  return l;
}
// **

// **Crypting**
void cipher(uint64_t k[], uint64_t pt0, uint64_t pt1, uint64_t *ct0, uint64_t *ct1)
{
    uint64_t y = pt0;
    uint64_t x = pt1;
    uint64_t temp = 0;
    const int n = 64;
    const int T = 5;
    for (int i=0; i<T; i++){
        temp = x;
        x = (y ^ ((lshift(x, n, 1)) & (lshift(x, n, 8)))) ^ (lshift(x, n, 2)) ^ k[i];
        y = temp;
    }
*ct0 = y;
*ct1 = x;
}
// **

// Key Generation
int main()
{
    const int m = 2;
    const int n = 64;
    int i;
    const int T = 5;
    int value = 0;
    int z_new = 0;
    uint64_t k[] = {0x0000000000000001, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001}; 
    uint64_t temp = 0;
    uint64_t z[5]= {0x3E8958737D12B0E6, 0X23BE4C2D477C985A, 0X2BDC0D262847EB3, 0X36EB19781229CD0F, 0x3479AD88170CA4EF};
    for (i =m; i < T + m;i++){
      value = (i -m) % 62;
      z_new = (z[2] >> (61 - value)) & 0x1;
      temp = rshift(k[i-1],n, 3);
      printf("%#llx\n",temp);
      temp = temp ^ rshift(temp, n, 1);
      printf("%#llx\n",temp);
      k[i] = ~k[i-m] ^ temp ^ z_new ^ 0x3;  
    }
    printf("%d", k[i]);
    
}

