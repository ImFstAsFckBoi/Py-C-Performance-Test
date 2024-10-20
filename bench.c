#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recurse_fibbonaci(int n) {
  if (n < 2) {
    return n;
  } else {
    return recurse_fibbonaci(n - 1) + recurse_fibbonaci(n - 2);
  }
}

int iter_fibbonaci(int n) {
  uint64_t a = 0;
  uint64_t b = 1;
  uint64_t c = 0;

  for (int i = 0; i < n - 1; ++i) {
    c = a + b;
    a = b;
    b = c;
  }

  return c;
}

int prime_sieve(int n) {
  bool *A = malloc(n * sizeof(bool));
  memset(A, true, n * sizeof(bool));
  int sqrt_n = (int)floor(sqrt((int)n));

  for (int i = 2; i <= sqrt_n; ++i) {
    if (A[i]) {
      for (int j = i * i; j < n; j += i) {
        A[j] = false;
      }
    }
  }

  int sum = 0;
  for (int i = 2; i < n; ++i) {
    sum += A[i];
  }

  free(A);
  return sum;
}

void *run_test(void *_) {
  recurse_fibbonaci(40);
  return NULL;
}

#define N 8
void run() {
  for (int i = 0; i < N; ++i) {
    run_test(NULL);
    printf("%d/%d\r", i + 1, N);
    fflush(stdout);
  }
  printf("\n");
}

void run_threaded() {
  pthread_t ts[N] = {};

  for (int i = 0; i < N; ++i) {
    pthread_create(&ts[i], NULL, run_test, NULL);
  }

  for (int i = 0; i < N; ++i) {
    pthread_join(ts[i], NULL);
    printf("%d/%d\r", i + 1, N);
    fflush(stdout);
  }

  printf("\n");
}
