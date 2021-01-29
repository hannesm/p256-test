#include <stdint.h>
#include <stdio.h>

#include "p256_64.c"

#define LIMBS 4

//big endian encoded constants
static uint64_t two[LIMBS] = { 0 , 0 , 0 , 0x02 };
static uint64_t inv_two[LIMBS] = { 0x7fffffff80000000 , 0x8000000000000000 , 0x0000000080000000 , 0x0000000000000000 };

extern void inverse (uint64_t[LIMBS], uint64_t[LIMBS + 1]);

int test () {
  uint64_t inv[LIMBS];
  uint64_t in[LIMBS + 1];
  uint64_t mo[LIMBS];

  fiat_p256_to_montgomery(in, two);
  in[LIMBS] = 0;

  inverse(inv, in);
  fiat_p256_from_montgomery(mo, inv);
  for (int i = 0; i < LIMBS; i++) {
    printf("at %d: inv_two %lx inv %lx mo %lx\n", i, inv_two[i], inv[i], mo[i]);
  }
  return 0;
}
