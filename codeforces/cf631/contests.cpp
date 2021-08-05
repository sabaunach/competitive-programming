#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    while (cin >> n >> x) {
        bitset<201> places;
        for (int i = 0; i < n; i++) {
            int in; cin >> in;
            places[in] = 1;
        }
        int i = 1;
        for (; true; i++) {
            if (!places[i]) {
                if (x == 0) {
                    i--;
                    break;
                }
                places[i] = 1;
                x--;
            }
        }
        cout << i << endl;
    }
}
