#include <stdint.h>

uint64_t rshift(uint64_t l, int n, int shift){
  l = (l >> shift) | (l << (n- shift));
  uint64_t tem = 0;
  for (int i = 0; i<n;i++){
    tem = tem << 1;
    tem = tem | 1;
  }
  l = l & (tem); 
  return l;
}
uint64_t lshift(uint64_t l, int n, int shift){
  l = (l << shift) | (l >> (n- shift));
  uint64_t tem = 0;
  for (int i = 0; i<n;i++){
    tem = tem << 1;
    tem = tem | 1;
  }
  l = l & (tem); 
  return l;
}