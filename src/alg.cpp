// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i * i <= value; i += 2) {
      if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0; 
  uint64_t num = 1;   
  while (count < n) {
    num++;
      if (checkPrime(num)) {
          count++;
      }
  }
    return num;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t num = value;
    while (true) {
        num++;
        if (checkPrime(num)) {
            break;
        }
    }
    return num; 
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0; 
  uint64_t i = 2;
   while (i < hbound) { 
      if (checkPrime(i)) { 
          sum += i;
        }
        i++;
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    uint64_t lastPrime = 0;
    uint64_t i = lbound;
    while (i < hbound) {
        if (checkPrime(i)) {
            if (lastPrime > 0) {
                if (i - lastPrime == 2) {
                    count++;
                }
            }
            lastPrime = i;
        }
        i++;
    }
    return count
}
