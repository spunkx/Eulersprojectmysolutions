#include <stdio.h>

//this is missing the removal of the multiples of 15, something I did not consider

int getLCD(int num1, int num2){
  return num1 * num2;
}

int findSummrkII(int sum, int LIMIT, int countThree, int countFive){
  //remove multiples of 15
  if(countFive < LIMIT){
    findSummrkII(sum+(countFive+countThree), LIMIT, countThree+3, countFive+5);
  }
  else if(countThree != LIMIT-1){
    findSummrkII(sum+countThree, LIMIT, countThree+3, countFive);
  }
  else{
    sum=sum+countThree;
    return sum;
  }

  return sum;
}

int main(void) {
  const int LIMIT = 1000;
  int sum = 0;
  sum = findSummrkII(sum, LIMIT, 0, 0);
  printf("\nFrom second equation %d", sum);

  return 0;
}
