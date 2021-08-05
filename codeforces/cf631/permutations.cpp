#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (cin >> n) {
        vector<int> list;
        map<int, vector<int>> occur;
        int lastL1 = -1, firstL2 = 1000000;
        for (int i = 0; i < n; i++) {
            int in; cin >> in;
            list.push_back(in);
            auto find = occur.find(in);
            if (find == occur.end()) {
                occur.insert({in, vector<int>{i}});
            } else {
                if ((find->second).size() == 2) {
                    lastL1 = firstL2 = 0;
                    break;
                } else {
                    (find->second).push_back(i);
                    firstL2 = min(firstL2, i);
                    lastL1 = max(lastL1, (find->second)[0]);
                }
            }
        }
        cout << firstL2 - lastL1 << "\n";
        for (int i = lastL1 + 1; i <= firstL2; i++) {
            cout << i << " " << list.size() - i << "\n";
        }
    }
}
