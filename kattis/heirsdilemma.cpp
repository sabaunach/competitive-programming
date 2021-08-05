#include <bits/stdc++.h>

using namespace std;

int main() {
    int min, max;
    cin >> min >> max;
    int count = 0;
    for (int i = min; i <= max; i++) {
        vector<int> digits(6);
        for (int j = 0; j < 6; j++) {
            digits[j] = (int)(i / pow(10, 5-j) ) % 10;
        }
        bool divisible = true, norepeats = true;
        // check no repeats
        for (int j = 0; norepeats && j < 6; j++) {
            for (int k = j + 1; norepeats && k < 6; k++)
                if (digits[k] == digits[j])
                    norepeats = false;
        }
        if (!norepeats) {
            //cout << "repeats in " << i << endl;
            continue;
        }
        // check divisibility and no zeros
        for (int j = 0; divisible && j < 6; j++) {
            if (digits[j] == 0 || i % digits[j] != 0) {
                divisible = false;
            }
        }
        if (!divisible) {
            //cout << "indivisibility in " << i << endl;
            continue;
        }
        count++;
    }
    cout << count;
    return 0;
}
