#include <stdio.h>
#include <stdlib.h>

extern int test (void);

int main () {
  if (test () != 0) {
    printf("FAIL\n");
    exit(1);
  }
  exit(0);
}
