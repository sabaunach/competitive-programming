#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        vector<pair<ii, ii>> segs(n);
        for (int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            segs[i] = {{s, e}, {i, -1}};
        }
        sort(segs.begin(), segs.end());
        vector<int> cj_ends(2, 0);
        bool fail;
        for (auto &seg: segs) {
            int s = seg.first.first, e = seg.first.second;
            fail = true;
            for (size_t i = 0; i < cj_ends.size(); i++) {
                int &end = cj_ends[i];
                if (end <= s)
                    end = 0;
                if (end == 0) {
                    fail = false;
                    end = e;
                    seg.second.second = i;
                    break;
                }
            }
            if (fail)
                break;
        }
        if (fail) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        sort(segs.begin(), segs.end(), [](pair<ii, ii> a, pair<ii, ii> b) {
            return a.second.first < b.second.first;
        });
        for (auto seg: segs) {
            if (seg.second.second == 0)
                cout << "C";
            else
                cout << "J";
        }
        cout << "\n";
    }
}
