//
//  primes.h
//  CMPT2300Oct2021
//
//  Created by Quaternion Works on 2021-10-28.
//

#ifndef primes_h
#define primes_h

#include "twinnedPrimes.h"

bool isPrime (int);

void primesManager(int, int);

int getPrime(int * a, int, int);
primesFunc pf03 = getPrime;

int lookupPrime(int *, int, int);
primesFunc pf04 = lookupPrime;

int vectorize(int *, int, int, int *, int);

void run()
{
    int numberOfPrimes;
    int begin;
    std::cout << "Work with primes will now run." << std::endl;
    std::cout << "How many primes would you like to generate?" << std::endl;
    std::cin >> numberOfPrimes;
    std::cout << "Enter lowest value, e.g. 2, from which to begin search for twinned primes:" << std::endl;
    std::cin >> begin;
    primesManager(numberOfPrimes, begin);
    std::cout << "Work with primes has terminated." << std::endl;
}

void primesManager(int size, int begin)
{
    // make primes array
    int * primes = new int [size];
    int * vector = new int [size];
    * primes = 2;
    int c = 3, d = 1;
    while (d < size)
    {
        if (isPrime(c))
        {
            * (primes + d) = c;
            d++;
        }
        c++;
        c++;
    }
    
    // print primes to console
    std::cout << "Primes: {  ";
    for (int c = 0; c < size; c++)
        std::cout << * (primes + c) << "  ";
    std::cout << "}\n";
    /*
    // make vectors for primes of interest and print to console
    for (int c = 0; c < size/2; c++)
    {
        std::cout << (c + 1) << ".  Prime: " << * (primes + c) << " - Vector form: {  ";
        vectorize(primes, size, * (primes + c), vector, size);
        for (int c = 0; c < size; c++)
            std::cout << * (vector + c) << "  ";
    std::cout << "}\n";
    }*/
    
    // work with twinned primes
    int start = -1;
    while (start < 0)
    {
        start = pf04(primes, size, begin);
        begin++;
    }
    twinnedPrimesManager(primes, size, start);
    
    // deallocate memory
    delete [] primes;
    primes = nullptr;
    delete [] vector;
    vector = nullptr;
}

bool isPrime(int n)
{
    int c = 2;
    if ((n == 1) || (n < 1))
        return false;
    if (n == 2)
        return true;
    while (c*c < n)
    {
        if (n % c == 0)
            return false;
        c++;
    }
    return true;
}

int getPrime(int * a, int aSize, int key)
{
    int value = * (a + key - 1);
    std::cout << "\t\tPrime number no. " << key << " is ";
    std::cout << value << ".\n";
    return value;
}

int lookupPrime(int * a, int aSize, int value)
{
    int index = -1;
    
    for (int c = 0; c < aSize; c++)
        if (* (a + c) == value)
            index = c;
    
    if (index < 0)
    {
        std::cout << "\t\tValue ";
        std::cout << value << " is not prime.\n";
    } else {
        std::cout << "\t\tValue ";
        std::cout << value << " found.\n";
        std::cout << "\t\tPrime number no. " << index << " is ";
        std::cout << value << ".\n";
    }
    
    return index;
}

int vectorize(int * p, int pSize, int value, int * a, int aSize)
{
    int result = -1;
    int index = 0;
    int check = 1;
    int factor = 1;
    int decliningValue = value;
    for (int c = 0; c < aSize; c++)
    {
        while ((decliningValue % (*(p + c)) == 0) &&
               (decliningValue > 1))
        {
            decliningValue /= (*(p + c));
            index++;
        }
        *(a + c) = index;
        index = 0;
    }
    for (int d = 0; d < aSize; d++)
    {
        for (int e = 0; e < (*(a + d)); e++)
            factor *= *(p + d);
        check *= factor;
        factor = 1;
    }
    if (check == value)
        result = value;
    return result;
}

#endif /* primes_h */
