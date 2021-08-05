#include <bits/stdc++.h>

using namespace std;

bool query(int pos) {
    cout << pos + 1 << endl;
    flush(cout);
    bool res;
    cin >> res;
    return res;
}

vector<bool> data;

void reverse() {
    for (size_t i = 0; i < data.size()/2; i++) {
        bool save = data[i];
        data[i] = data[data.size() - i - 1];
        data[data.size() - i - 1] = save;
    }
}

void flip() {
    for (size_t i = 0; i < data.size(); i++) {
        data[i] = !data[i];
    }
}

int main() {
    // assuming b always even and flucs always happen on 1st, 11th, ...
    int tc, b;
    cin >> tc >> b;
    for (int t = 1; t <= tc; t++) {
        int numQueries = 0;
        data = vector<bool>(b);
        vector<int> sameBits; // location of bit pairs that are equal
        vector<int> diffBits; // location of bit pairs that are different
        for (int q = 0; q < b/2; q++) {
            if (numQueries % 10 == 0) {
                if (sameBits.size() > 0 && diffBits.size() > 0) {
                    // watch these bits
                    int q1 = sameBits[0], q2 = diffBits[0];
                    bool s_old = data[q1], d_old = data[q2];
                    bool s_new = query(q1), d_new = query(q2);
                    numQueries += 2;
                    if (s_new != s_old) {
                        if (d_new != d_old) {
                            flip();
                        } else {
                            flip(); reverse();
                        }
                    } else if (d_new != d_old) {
                        reverse();
                    } // otherwise, nothing
                } else if (sameBits.size() > 0) {
                    // watch these bits
                    int qs = sameBits[0];
                    bool s_old = data[qs];
                    bool s_new = query(qs);
                    query(qs); // prefer to keep # queries even, so we waste one
                    numQueries += 2;
                    if (s_old != s_new)
                        flip();
                } else if (diffBits.size() > 0) {
                    // watch these bits
                    int qd = diffBits[0];
                    bool d_old = data[qd];
                    bool d_new = query(qd);
                    query(qd); // prefer to keep # queries even, so we waste one
                    numQueries += 2;
                    if (d_old != d_new)
                        flip();
                }
            }
            // get more information
            data[q] = query(q);
            data[b - q - 1] = query(b - q - 1);
            numQueries += 2;
            if (data[q] == data[b - q - 1])
                sameBits.push_back(q);
            else
                diffBits.push_back(q);
        }
        for (bool b: data) {
            cout << b;
        }
        cout << endl;
        flush(cout); // every time we output data
        char res; cin >> res;
        assert(res == 'Y');
    }
}
