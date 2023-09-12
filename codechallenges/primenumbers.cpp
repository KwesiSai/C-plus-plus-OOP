#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;

    if (num == 2)
        return true;

    if (num % 2 == 0)
        return false;

    for (int i = 2; i <=num/2 ; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main() {
    cout << "Prime numbers between 0 and 10 are: ";

    for (int i = 0; i <= 10; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
