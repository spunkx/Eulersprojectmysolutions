#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

//https://en.wikipedia.org/wiki/Prime_number
//Find factors
//1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51,
//number mod big number equals 0, is a factor, else is not?
//recursive call for a number that is not prime to check factors?
//sieve of Eratosthenes, I was on the right track
//the pattern is that there are only certain ones digits that make up prime numbers
//use a binary operation to check "ones" digit..
//still a lot of divisons

//check if even or odd, if even divide by two
//check if multiple of three,blah and blah if is odd
//check odd divsors if not a multiple of three or then sums of its digits is not a multiple of three? 
//finish when number squared is greater than the prime
//interesting idea https://www.youtube.com/watch?v=ZMkIiFs35HQ
int primeFactors(int64_t number, int **arrFactors){
  int testFactors[4] = {3,5,7,9};
  if(number % 2 == 0){
    primeFactors(number/2, arrFactors);
  }
  else if(number % 2 != 0){
    for(unsigned int test = 0; test < (sizeof(testFactors)/sizeof(int)); test++){
      //get a number that successfully divides into the odd number
      if(number % testFactors[test] == 0){
        primeFactors(number/testFactors[test], arrFactors);
      }
      else{
        return number;
      }
    }
  }
  return number;
}

int main(void) {
  //dynamic memory allocation for larger numbers
  int64_t NUMBER = 600851475143;
  int n = sizeof(NUMBER);
  int32_t** arrFactors = NULL;
  if((arrFactors = malloc(n)) != NULL){
    for(int i=0;i<n;i++){
      *(arrFactors+1) = 0;
    }
  }
  else{
    printf("Malloc Failed");
    exit(0);
  }
  int largestpFactor = primeFactors(NUMBER, arrFactors);
  printf("\nlargestpFactor %d", largestpFactor);
  return 0;
}