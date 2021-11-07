//
//  twinnedPrimes.h
//  twinnedPrimes
//
//  Created by Quaternion Works on 2021-11-06.
//

#ifndef twinnedPrimes_h
#define twinnedPrimes_h

typedef int (* primesFunc)(int *, int, int);

int twinnedPrimes(int *, int, int dummy);
primesFunc pf01 = twinnedPrimes;

int twinnedPrimesIndices(int *, int, int);
primesFunc pf02 = twinnedPrimesIndices;

int isTwinnedPrime(int *, int, int);
primesFunc pf05 = isTwinnedPrime;

int vectorize(int *, int, int, int *, int);

void twinnedPrimesManager(int * p, int pSize, int target)
{
    std::cout << "Work with twinned primes will now run." << std::endl;
    
    pf01(p + target, pSize - target, 0);
    
    std::cout << "Work with twinned primes has terminated." << std::endl;
}

int twinnedPrimes(int * a, int aSize, int dummy)
{
    // print twinned primes to console
    std::cout << "\tTwinned primes: {  ";
    int p = 0;
    for (int c = 0; c < aSize; c++)
        if (*(a + c) + 2 == *(a + c + 1))
        {
            std::cout << * (a + c) << "  " << * (a + c + 1) << "  ";
            p++;
        }
    std::cout << "}\n";
    std::cout << "Number of twinned primes: " << p << " twins \n";
    
    // print numbers that are between twinned primes to console
    std::cout << "\tNumbers between twinned primes: {  ";
    int q = 0;
    for (int c = 0; c < aSize; c++)
        if (*(a + c) + 2 == *(a + c + 1))
        {
            std::cout << * (a + c) + 1 << "  ";
            q++;
        }
    std::cout << "}\n";
    std::cout << "Number of numbers that are between twinned primes: " << q << "\n";
    
    return q;
}

int twinnedPrimesIndices(int * a, int aSize, int dummy)
{
    // print twinned primes to console
    std::cout << "\tValues n when nth prime is a twinned prime: {  ";
    int p = 0;
    for (int c = 0; c < aSize; c++)
        if (*(a + c) + 2 == *(a + c + 1))
        {
            std::cout << (c + 1) << "  " << (c + 2) << "  ";
            p++;
        }
    std::cout << "}\n";
    std::cout << "Number of twinned primes: " << p << " twins \n";
    
    return p;
}

int isTwinnedPrime(int * a, int aSize, int dummy)
{
    int output = -1;
    const int vSize = aSize;
    float percent = 0;
    
    int d = 0;
    int * t1 = new int [vSize];
    for (int b = 0; b < vSize; b++)
        * (t1 + b) = 0;
    int * t2 = new int [vSize];
    for (int b = 0; b < vSize; b++)
        * (t2 + b) = 0;
    
    for (int c = 0; c < aSize - 1; c++)
        if ((aSize > 1) &&
            (*(a + c) + 2 == *(a + c + 1)))
        {
            std::cout << d + 1 << ":  \t";
            std::cout << vectorize(a, aSize, *(a + c), t1, vSize) << " = \t{   ";
            for (int b = 0; b < vSize; b++)
                std::cout << * (t1 + b) << "  ";
            std::cout << "}\n";
            d++;
            for (int b = 0; b < vSize; b++)
                * (t1 + b) = 0;
            
            std::cout << d + 1 << ":  \t";
            std::cout << vectorize(a, aSize, *(a + c + 1), t2, vSize) << " = \t{   ";
            for (int b = 0; b < vSize; b++)
                std::cout << * (t2 + b) << "  ";
            std::cout << "}\n";
            d++;
            for (int b = 0; b < vSize; b++)
                * (t2 + b) = 0;
        }
    if (aSize > 1)
    {
        output = d;
        if (aSize > 3)
            output = d - 1;
        percent = (float(output) / float(aSize)) * 100;
        std::cout << "Number of twinned primes: " << output << "\n";
        std::cout << "Number of primes: " << aSize << "\n";
        std::cout << "Per cent of primes that twinned: " << percent << " %\n";
    }
        
    delete [] t1;
    t1 = nullptr;
    delete [] t2;
    t2 = nullptr;
    
    return output;
}

#endif /* twinnedPrimes_h */
