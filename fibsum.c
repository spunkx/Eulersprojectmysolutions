#include <stdio.h>

int generateFib(int acc, int LIMIT, int sum){
  if(LIMIT != 0){
    if(acc % 2 == 0){
      sum = sum + acc;
    }
    generateFib(acc+acc, LIMIT-1, sum);
  }
  sum = sum + acc;
  return sum;
}

int main(void) {
  int LIMIT = 4000000;
  int sum = 0;
  sum = generateFib(1, LIMIT, 0);
  printf("\nFib Sequence even sum%d", sum);
  return 0;
}