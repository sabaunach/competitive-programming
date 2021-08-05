#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull tc;
    cin >> tc;
    for (ull t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        size_t n; cin >> n;
        vector<unordered_set<int>> rows(n);
        vector<unordered_set<int>> cols(n);
        ull trace = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                ull in; cin >> in;
                if (i == j)
                    trace += in;
                rows[i].insert(in);
                cols[j].insert(in);
            }
        }
        cout << trace << " ";
        ull cnt = 0;
        for (auto s: rows)
            if (s.size() != n)
                cnt++;
        cout << cnt << " ";
        cnt = 0;
        for (auto s: cols)
            if (s.size() != n)
                cnt++;
        cout << cnt << "\n";
    }
}
