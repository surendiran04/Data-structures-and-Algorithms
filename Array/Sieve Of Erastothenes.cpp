#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) { //n*log(logn)
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {  //for i=2 marks all the multiples of 2 after 2*2=4 as false similarly for all the rest works
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}
