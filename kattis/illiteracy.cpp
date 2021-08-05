#include <bits/stdc++.h>

using namespace std;

unordered_set<string> visited;
vector<string> sequences;
vector<string> newsequences;

void rotate(char &c) {
    c += 1;
    if (c == 71)
        c = 65;
}

string click(const string oldseq, const int x) {
    string seq = oldseq;
    switch(seq[x]) {
        case 'A':   if (x > 0) rotate(seq[x - 1]);
                    if (x < 7) rotate(seq[x + 1]);
                    break;
        case 'B':   if (x > 0 && x < 7) seq[x + 1] = seq[x - 1];
                    break;
        case 'C':   rotate(seq[7 - x]);
                    break;
        case 'D':   if (x > 0 && x < 7) {
                        if (x <= 3) {
                            for (int i = x - 1; i >= 0; i--)
                                rotate(seq[i]);
                        }
                        else
                            for (int i = x + 1; i <= 7; i++)
                                rotate(seq[i]);
                        }
                    break;
        case 'E':   if (x > 0 && x < 7) {
                        if (x <= 3) {
                            rotate(seq[0]);
                            rotate(seq[2 * x]);
                        }
                        else {
                            rotate(seq[x - (7 - x)]);
                            rotate(seq[7]);
                        }
                    }
                    break;
        case 'F':   if ((x + 1) % 2 == 0)
                        rotate(seq[(x + 1) / 2 - 1]);
                    else
                        rotate(seq[(x + 1 + 9) / 2 - 1]);
                    break;
    }
    return seq;
}

int main() {
    string begin_in, target_in;
    cin >> begin_in >> target_in;
    //cout << "answer: " << click(click(begin_in, 3), 5) << endl;
    sequences.push_back(begin_in);
    visited.insert(begin_in);
    string newseq;
    int iteration = 0;
    if (target_in == begin_in) {
        cout << 0;
        return 0;
    }
    while (sequences.size() > 0) { // if this goes to 0, no solution found
        iteration++;
        for (auto seq: sequences) {
            for (int x = 0; x <= 7; x++) {
                newseq = click(seq, x);
                //cerr << seq << ": click " << x << " on " << iteration << ": " << newseq << endl;
                if (newseq == target_in) {
                    cout << iteration;
                    return 0;
                }
                if (visited.find(newseq) == visited.end()) {
                    visited.insert(newseq);
                    newsequences.push_back(newseq);
                }
            }
        }
        vector<string> newv = newsequences;
        sequences = newv;
        newsequences.clear();
    }
    cout << "No solution found!";
}
