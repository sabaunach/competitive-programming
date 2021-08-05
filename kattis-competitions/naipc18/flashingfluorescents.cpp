#include <bits/stdc++.h>

using namespace std;

const int N = 16 + 1;
#define bs bitset<2*N>

int main() {
    bs start;
    start.reset();
    char in;
    int n = 0;
    for (; cin >> in; n++)
        start[n] = (in == '0' ? 0 : 1);

    unordered_set<bs> visited = {start};
    vector<bs> curr;
    vector<bs> next = {start};
    int iter = 0, j;
    // check if it is our target state
    for (j = 0; j < n && start[j]; j++);
    if (j == n) {
        cout << 0;
        return 0;
    }
    while (!next.empty()) {
        iter++;
        curr = next;
        next.clear();
        for (bs currState: curr) {
            // simulate moving one timestep with no click
            bs nsNoClicks = currState;
            for (int i = N; i < N+n; i++) {
                if(currState[i]) {
                    nsNoClicks[i - N].flip();
                    nsNoClicks[i] = 0;
                    if (i < N+n - 1)
                        nsNoClicks[i + 1] = 1;
                }
            }
            // check if it is our target state
            for (j = 0; j < n && nsNoClicks[j]; j++);
            if (j == n) {
                cout << iter;
                return 0;
            }
            if (visited.find(nsNoClicks) == visited.end()) {
                visited.insert(nsNoClicks);
                next.push_back(nsNoClicks);
            }
            // simulate possible clicks that could've happened before nsNoClicks
            for (int i = n - 1; i >= 0; i--) {
                bs ns = nsNoClicks;
                if (currState[i + N] && i < n - 1) {
                    ns[i +  N + 1] = 0;
                }
                else {
                    ns[i + N + 1] = 1;
                }
                ns[i].flip();
                // check if it is our target state
                for (j = 0; j < n && ns[j]; j++);
                if (j == n) {
                    cout << iter;
                    return 0;
                }
                if (visited.find(ns) == visited.end()) {
                    visited.insert(ns);
                    next.push_back(ns);
                }
            }
        }
    }
}
