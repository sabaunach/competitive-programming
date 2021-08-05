#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #"  << t << ": ";
        int depth = 0;
        string input;
        cin >> input;
        for (size_t i = 0; i < input.size(); i++) {
            int n = input[i] - '0';
            for (; n > depth; depth++)
                cout << "(";
            for (; n < depth; depth--)
                cout << ")";
            cout << n;
        }
        for (; depth > 0; depth--)
            cout << ")";
        cout << "\n";
    }
}
