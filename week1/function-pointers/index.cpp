#include <stdio.h>

void f(int **p) {
  **p = 7;
}

int main() {
  int var = 10;
  int *p = &var;

  f(&p);
  printf("%d", var);
  return 0;
}