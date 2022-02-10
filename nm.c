#include <stdint.h>
#include <inttypes.h>
int simon_parameters(int n, int m, int *T, uint64_t *z_generic, uint64_t *c){
  //uint64_t z[5]= {0x3E8958737D12B0E6, 0X23BE4C2D477C985A, 0X2BDC0D262847E5B3, 0X36EB19781229CD0F, 0x3479AD88170CA4EF};
  uint64_t z[5] = {0b0001100111000011010100100010111110110011100001101010010001011111,
                        0b0001011010000110010011111011100010101101000011001001111101110001,
                        0b0011001101101001111110001000010100011001001011000000111011110101,
                        0b0011110000101100111001010001001000000111101001100011010111011011,
                        0b0011110111001001010011000011101000000100011011010110011110001011};
  if(n==16){
    *c = 0xFFFC;
    if (m==4){
      *z_generic =  z[0];
      *T = 32;
    }
  }
  else if(n==24){
    *c = 0xFFFFFC;
    if (m==3){
      *z_generic =  z[0];
      *T = 36;
    }
    else if (m==4){
      *z_generic =  z[1];
      *T = 36;
    }
  }
  else if(n==32){
    *c = 0xFFFFFFFC;
    if (m==3){
      *z_generic =  z[2];
      *T = 42;
    }
    else if (m==4){
      *z_generic =  z[3];
      *T = 44;
    }
  }
  else if(n==48){
    *c = 0xFFFFFFFFFFFC;
    if (m==2){
      *z_generic =  z[2];
      *T = 52;
    }
    else if (m==3){
      *z_generic =  z[3];
      *T = 54;
    }
  }
  else if(n==64){
    *c = 0xFFFFFFFFFFFFFFFC;
    if (m==2){
      *z_generic =  z[2];
      *T = 68;
    }
    else if (m==3){
      *z_generic =  z[3];
      *T = 69;
    }
    else if (m==4){
      *z_generic =  z[4];
      *T = 72;
    }
  }
}

