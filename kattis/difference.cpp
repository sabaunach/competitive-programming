#include <bits/stdc++.h>

using namespace std;

    bitset<200000000> appeared;
    vector<int> sequence;

int main() {
    int aprev, acurr, m, n = 1;
    cin >> aprev >> m;
    sequence.push_back(aprev);
    appeared.reset();
    appeared[aprev] = 1;
    if (aprev == m) {
        cout << n;
        return 0;
    }
    int smallestint = 1;
    while (n <= 10000) {
        n++;
        while (appeared[smallestint])
            smallestint++;
        //cerr << aprev << " + " <<smallestint << " = " << (aprev + smallestint);
        acurr = aprev + smallestint;
        if (acurr == m) {
            cout << n;
            return 0;
        }
        appeared[acurr] = 1;
        for (int i: sequence) {
            int diff = acurr - i;
            if (diff == m) {
                cout << n;
                return 0;
            }
            appeared[diff] = 1;
        }
        aprev = acurr;
        sequence.push_back(aprev);
        //cerr << endl;
    }
    cout << "Not found!";
}
