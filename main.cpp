#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>


using namespace std;

vector<int> set_primes(bool isntPrime[], int size) {
    vector<int> primes;
    for(int i=2;i<size;i++){
        if(!isntPrime[i]){
            primes.push_back(i);
            for(int j=2*i; j<size; j+=i){
                isntPrime[j] = true;
            }
        }
    }
    return primes;
}

bool prime(int factor) {
    for(int i=2; i<=sqrt(factor); i++)
        if(factor % i == 0)
            return false;
    return true;
}

int euler(int n, vector<int>& primes) {
    int res = n;
    for(int i = 0; i<primes.size();i++){
        int p = primes[i];
        if(n % p == 0)
            res = (res/p) * (p-1);
    }
    return res;
}

void update_results(int results[], int size, vector<int>& primes){
    for(int i=0;i<primes.size();i++){
        int p = primes[i];
        results[p] = p-1;
        for(int j=2*p;j<size;j+=p){
            results[j] = (results[j]/p) * (p-1);
        }
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]); //TODO: unnote
//    int n;
//    cout << "enter number\n";
//    cin >> n;
    int res;
    int size = n+1;
    bool isntPrime[1500000] = {0};
    int results[size];
    for(int i=0;i<size;i++){
        results[i] = i;
    }
    vector<int> primes = set_primes(isntPrime, n);
    update_results(results, size, primes);
    for(int i=1; i<size; i++){
        cout << results[i] << " "; //TODO: unnote
    }
//    cout << endl; //TODO: note
    return 0;
}


