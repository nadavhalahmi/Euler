#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

bool prime(ull num) {
    for(ull i=2; i<=sqrt(num);i++)
        if(num%i == 0)
            return false;
    return true;
}

ull euler(ull n) {
    ull res = n;
    for(ull i=2; i<=n; i++){
        if(n%i == 0 && prime(i))
            res = (res/i) * (i-1);
    }
    return res;
}

int main(int argc, char *argv[]) {
//    ull n = atoi(argv[1]); //TODO: unnote
    ull n;
    cout << "enter number\n";
    cin >> n;
    ull res;
    for(ull i=1; i<=n; i++){
        res = euler(i);
//        cout << res << " "; //TODO: unnote
    }
    cout << endl; //TODO: note
    return 0;
}
