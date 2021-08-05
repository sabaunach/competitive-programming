#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
const size_t N = 10000,
             INF = numeric_limits<size_t>::max(),
             MOD = 1000000000 + 7;

unordered_map<char, size_t> t[N];
string s[N];
size_t p[N], nn, tv, ia, ib;
size_t ind[N];

void RTreeInsert(string str, int index) {
    str += '$'; tv = 0; ia = 0;
    node:
    if (!t[tv][str[ia]]) {
        t[tv][str[ia]] = nn; p[nn] = tv; s[nn] = str.substr(ia, str.length() - ia);
        ind[nn] = index;
        nn++; return;
    }
    tv = t[tv][str[ia]]; ia++; ib = 1;
    for (; ia < str.length(); ia++, ib++) {
        if (ib == s[tv].length()) goto node;
        if (str[ia] != s[tv][ib]) {
            t[nn][s[tv][ib]] = tv; t[nn][str[ia]] = nn + 1; p[nn] = p[tv];
            s[nn] = s[tv].substr(0, ib); t[p[nn]][s[tv][0]] = nn;
            p[tv] = nn; s[tv] = s[tv].substr(ib, s[tv].length() - ib);
            p[nn+1] = nn; s[nn+1] = str.substr(ia, str.length() - ia);
            ind[nn+1] = index;
            nn += 2; return;
        }
    }
}

void RTreeInit() {
    nn = 1;
    fill(s, s+N, "");
    fill(p, p+N, INF);
    fill(ind, ind+N, INF);
    for (auto &m: t) m.clear();
}

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


int n, k;
ull picks[N];
void initPicks() {
    picks[k] = 1;
    picks[k-1] = n-k+1;
    for (int i = k-2; i >= 0; i--)
        picks[i] = (picks[i+1]*(n-i)) % MOD;
}

vector<string> dict;
void initDict() {
    for (int i = 0; i < n; i++) {
        string in; cin >> in;
        dict.push_back(in);
    }
    sort(dict.begin(), dict.end());
}

int main() {
    cin >> n >> k;
    initPicks();
    initDict();
    // initialize fenwick tree
    FenwickTree fTree(vector<int>(n, 1));

    // initialize radix tree
    RTreeInit();
    for (size_t i = 0; i < dict.size(); i++)
        RTreeInsert(dict[i], i);

    string target; cin >> target;
    int cnt = 1, node = t[0][target[0]];
    size_t ib = 1;
    ull res = 1;
    for (size_t ia = 0; ia < target.size(); ia++, ib++) {
        if (ind[node] == INF)
            if (ib < s[node].size())
                continue;
        ib = 0; // will incr to 1 on next iteration
        if (ind[node] == INF) {
            node = t[node][target[ia+1]];
            continue;
        }

        ull index = ind[node];
        ull nBelow = fTree.sum(index - 1);
        fTree.add(index, -1);
        ull pick = picks[cnt];
        res += (nBelow*pick) % MOD;
        res %= MOD;
        cnt++;
        ia += s[node].size() - 2;
        node = t[0][target[ia+1]];
    }

    cout << res;
}
