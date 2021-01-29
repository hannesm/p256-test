#include <stdint.h>
#include <stdio.h>

#include "p256_64.c"

#define LIMBS 4

//encoded constants (reverse ordered limbs, the number 2 is { 2, 0, 0, 0 })
static uint64_t two[LIMBS] = { 0x02 , 0 , 0 , 0 };
static uint64_t inv_two[LIMBS] = { 0x0000000000000000 , 0x0000000080000000 , 0x8000000000000000 , 0x7fffffff80000000 };

extern void inverse (uint64_t[LIMBS], uint64_t[LIMBS + 1]);

int test () {
  uint64_t inv[LIMBS];
  uint64_t in[LIMBS + 1];

  fiat_p256_to_montgomery(in, two);
  in[LIMBS] = 0;

  inverse(inv, in);
  for (int i = 0; i < LIMBS; i++) {
    if (inv_two[i] != inv[i]) {
      printf("FAIL at %d: inv_two %lx inv %lx\n", i, inv_two[i], inv[i]);
      return 1;
    }
  }
  return 0;
}
