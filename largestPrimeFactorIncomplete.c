#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//gcd?
//way to 

//if not get more primes
  //do this until number is not greater than itself divided by two

void createpotentialPrime(int potePrime[2], int val){
  //6 * 1  = +1 or -1;
  //using numberphile multiples of 6 method
  int multipleSix = 0;
  multipleSix = val * 6;
  potePrime[0] = multipleSix - 1;
  potePrime[1] = multipleSix + 1;
}

void checkpotePrime(int oddNumber, int isPrime){
  int singledigPrimes[4] = {3,5,7,9};
  for(int i = 0; i <= sizeof(singledigPrimes)/sizeof(int); i++){
    //check if 3,5,7,9 (quickest check)
    isPrime = singledigPrimes[i] == oddNumber;
    //check if multiple of 3,5,7,9 (quick check)
    if(isPrime != 1){
      isPrime = (oddNumber % singledigPrimes[i]) != 0;
    }
    else{
      break;
    }
  }
}

int primeFactors(long int number, long int **arrFactors){
  //add to array of factors
  if(number % 2 == 0){
    //even
    primeFactors(number/2, arrFactors);
  }

  else if(number % 2 != 0){
    //odd
    int *isPrime[2] = {0,0};

    int digitLength = (sizeof(number) / sizeof(int));
    int *potePrime[2] = {};
    while(isPrime[0] != 0 || isPrime[1] != 0){
      for(int i = 1; i <= digitLength; i++){
        createpotentialPrime(*potePrime, i);
        checkpotePrime(*potePrime[0], *isPrime[0]);
        checkpotePrime(*potePrime[1], *isPrime[1]);
      }
    }

    //if both are prime check that both divise into the number
    int isDivisor = 0;
    while(isDivisor == 0){


    }

  }
  


  return number;
}

int main(void) {
  //dynamic memory allocation for larger numbers
  long int NUMBER = 600851475143;
  int n = sizeof(NUMBER);
  //arr factors is of arbitrary length
  long int** arrFactors = NULL;
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
  if(largestpFactor == 1){
    printf("Number is maybe prime");
  }
  printf("\nlargestpFactor %d", largestpFactor);
  return 0;
}