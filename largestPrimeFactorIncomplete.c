#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//gcd?
//way to 

//if not get more primes
  //do this until number is not greater than itself divided by two

void createpotentialPrime(int *potePrime, int val){
  //6 * 1  = +1 or -1;
  //using numberphile multiples of 6 method
  int multipleSix = 0;
  multipleSix = val * 6;
  potePrime[0] = multipleSix - 1;
  potePrime[1] = multipleSix + 1;
}

void checkpotePrime(int *oddNumber, int *isPrime){
  int singledigPrimes[4] = {3,5,7,9};
  //sizeof(singledigPrimes)/sizeof(int)
  for(int i = 0; i != sizeof(singledigPrimes)/sizeof(int); i++){
    //check if 3,5,7,9 (quickest check)\
    *isPrime = singledigPrimes[i] == *(oddNumber);
    //check if multiple of 3,5,7,9 (quick check)
    if(isPrime != 1){
      *isPrime = (*oddNumber % singledigPrimes[i]) != 0;
    }
    else{
      break;
    }
  }
}

void checkFactor(int *poteFactor, int *isprimeFact, long int number){
  *(isprimeFact) = number % *(poteFactor) == 0;
}

long int primeFactors(long int number, long int **arrFactors){
  //add to array of factors
  if(number % 2 == 0){
    //even
    primeFactors(number/2, arrFactors);
  }
  else if(number % 2 != 0){
    //odd
    int isPrime[2] = {0,0};

    long int digitLength = 71;
    //(sizeof(number) / sizeof(int))
    int potePrime[2] = {0,0};

    int isprimeFact[2] = {0,0};
    printf("digit length %d\n", digitLength);
    while(isprimeFact[0] != 1 || isprimeFact[1] != 1){
      //smallest prime factor at the moment
      //for a large prime factor, we need to keep going until it is
      //at least less than equal to half the number
      for(int i = 1; i <= digitLength; i++){
        createpotentialPrime(potePrime, i);
        //verify if they are prime or not
        checkpotePrime(&potePrime[0], &isPrime[0]);
        checkpotePrime(&potePrime[1], &isPrime[1]);

        printf("Prime? %d is %d\n", potePrime[0], isPrime[0]);
        printf("Prime? %d is %d\n", potePrime[1], isPrime[1]);

        if(isPrime[0] == 1){
          checkFactor(&potePrime[0], &isprimeFact[0], number);
          //printf("Prime Fact? %d is %d\n", potePrime[0], isprimeFact[0]);
        }
        else if(isPrime[1] == 1){
          checkFactor(&potePrime[1], &isprimeFact[1], number);
          //printf("Prime Fact? %d is %d\n", potePrime[1], isprimeFact[1]);
          break;
        }
      }
    }


    //check divisor and if not, keep going
  
    /*printf("Prime? %d is%d\nPrime? %d is%d", potePrime[0], isPrime[0], potePrime[1], isPrime[1]);*/

  }

  return number;
}

int main(void) {
  //dynamic memory allocation for larger numbers
  long int NUMBER = 600851475143;
  unsigned long int n = sizeof(NUMBER);
  //arr factors is of arbitrary length
  long int** arrFactors = NULL;
  if((arrFactors = malloc(n)) != NULL){
    for(unsigned long int i=0;i<n;i++){
      *(arrFactors+1) = 0;
    }
  }
  else{
    printf("Malloc Failed");
    exit(0);
  }
  long int largestpFactor = primeFactors(NUMBER, arrFactors);
  printf("\nlargestpFactor %ld", largestpFactor);
  return 0;
}
