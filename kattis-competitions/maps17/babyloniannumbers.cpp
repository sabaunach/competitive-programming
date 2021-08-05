#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n; cin >> n;
    string line;
    while (cin >> line) {
        vector<int> digits;
        n = 0;
        for (size_t i = 0; i < line.size(); i++) {
            if (line[i] == ',')
                n++;
        }
        ull power = pow(60, n);
        size_t st = 0;
        ull sum = 0;
        size_t i = 0;
        do {
            if (line[i] == ',' || i == line.size()) {
                if (i - st == 0)
                    n = 0;
                else
                    n = stoi(line.substr(st, i - st));
                sum += n*power;
                power /= 60;
                st = i + 1;
            }
            i++;
        } while (i <= line.size());
        cout << sum << endl;
    }
}
