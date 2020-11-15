#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <immintrin.h>
#include <nmmintrin.h>
#include <stdio.h>

using namespace std;

inline vector<int> set_primes(vector<bool>& isntPrime) {
    vector<int> primes;
    for(int i=2;i<isntPrime.size();i++){
        if(!isntPrime[i]){
            primes.push_back(i);
            for(int j=2*i; j<isntPrime.size(); j+=i){
                isntPrime[j] = true;
            }
        }
    }
    return primes;
}

inline void update_results(int results[], int size, vector<int>& primes){
    for(int i=0;i<primes.size();i++){
        int p = primes[i];
        results[p] = p-1;
        for(int j=2*p;j<size;j+=p){
            __builtin_prefetch (&results[j+3*p], 1, 0);
            results[j] = (results[j]/p) * (p-1);
        }
    }
}

 #define pc(x) putchar_unlocked(x);
    inline void writeInt (int N)
    {
        pc(' ');
        (N >= 1000000) && pc(N/1000000 + '0');
        (N >= 100000) && pc(N/100000%10 + '0');
        (N >= 10000) && pc(N/10000%10 + '0');
        (N >= 1000) && pc(N/1000%10 + '0');
        (N >= 100) && pc(N/100%10 + '0');
        (N >= 10) && pc(N/10%10 + '0');
        pc(N%10 + '0');   
    }
    
    

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int size = n+1;
    vector<bool> isntPrime(size, false);
    int results[size];
    vector<int> primes;
    int i;
    for(i=0;i<=size-8;i+=8){
        __m256i values = _mm256_setr_epi32(i, i+1, i+2, i+3, i+4, i+5, i+6, i+7);
        _mm256_storeu_si256((__m256i*) &results[i], values);
        //results[i] = i;
        //results[i+1] = i+1;
        //results[i+2] = i+2;
        //results[i+3] = i+3;
        //results[i+4] = i+4;
        //results[i+5] = i+5;
        //results[i+6] = i+6;
        //results[i+7] = i+7;
    }
    for(;i<size;i++)
      results[i] = i;
    primes = set_primes(isntPrime);
    update_results(results, size, primes);
    pc('1');
    for(i=2; i<=size-8; i+=8){
        //__builtin_prefetch (&results[i+16], 0, 0);
        writeInt(results[i]);
        writeInt(results[i+1]);
        writeInt(results[i+2]);
        writeInt(results[i+3]);
        writeInt(results[i+4]);
        writeInt(results[i+5]);
        writeInt(results[i+6]);
        writeInt(results[i+7]);
    }
    for(;i<size;i++)
      writeInt(results[i]);
    return 0;
}


