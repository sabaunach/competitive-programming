#include <bits/stdc++.h>

using namespace std;

int main() {
    bitset<100001> bits;
    int n,m;
    cin >> n >> m;
    vector<int> seq1;
    vector<int> seq2;
    int num;
    int maxn = -1;
    for(int i = 0; i < m; i++){
        cin >> num;
        if(num > maxn){
            maxn = num;
        }
        bits[num] = 1;
        seq1.push_back(num);
    }
    maxn = max(n,maxn);
    if(n == m){
        for(int i : seq1){
            cout << i << endl;
        }
        return 0;
    }
    for(int i = 1; i <= maxn; i++){
        if (!bits[i]) {
            seq2.push_back(i);
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(seq1[cnt1] < seq2[cnt2] && seq1[cnt1] != 0 || seq2[cnt2] == 0){
            cout << seq1[cnt1] << endl;
            cnt1++;
        }else{
            cout << seq2[cnt2] << endl;
            cnt2++;
        }
    }
}
