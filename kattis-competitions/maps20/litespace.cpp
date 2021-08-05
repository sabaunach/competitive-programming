#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input; cin >> input;
    stack<int> st;
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == 'S') {
            if (i + 4 < input.size() && input[i + 1] == 'S') {
                bool sign = input[i + 2] == 'T';
                int j = i + 4;
                for (; input[j] != 'N'; j++);
                int res = 0;
                int pow = 1;
                for (size_t k = j - 1; k >= i + 3; k--) {
                    res += (input[k] == 'T')*pow;
                    pow *= 2;
                }
                res *= sign ? -1 : 1;
                st.push(res);
                i = j;
            } else if (i + 2 < input.size() && input[i + 1] == 'N') {
                if (input[i + 2] == 'S') {
                    if (st.empty()) {
                        cout << "Invalid copy operation" << "\n";
                    } else {
                        st.push(st.top());
                    }
                } else if (input[i + 2] == 'T') {
                    if (st.empty()) {
                        cout << "Invalid swap operation" << "\n";
                    } else {
                        int top = st.top(); st.pop();
                        int sop = st.top(); st.pop();
                        st.push(top);
                        st.push(sop);
                    }
                } else if (input[i + 2] == 'N') {
                    if (st.empty()) {
                        cout << "Invalid remove operation" << "\n";
                    } else {
                        st.pop();
                    }
                }
                i += 2;
            }
        } else {
            if (i + 3 < input.size() && input[i + 1] == 'S') {
                if (input[i + 2] == 'S') {
                    if (input[i + 3] == 'S') {
                        if (st.size() < 2) {
                            cout << "Invalid addition operation" << "\n";
                        } else {
                            int top = st.top(); st.pop();
                            int sop = st.top(); st.pop();
                            st.push(top + sop);
                        }
                    } else if (input[i + 3] == 'T') {
                        if (st.size() < 2) {
                            cout << "Invalid subtraction operation" << "\n";
                        } else {
                            int top = st.top(); st.pop();
                            int sop = st.top(); st.pop();
                            st.push(sop - top);
                        }
                    } else if (input[i + 3] == 'N') {
                        if (st.size() < 2) {
                            cout << "Invalid multiplication operation" << "\n";
                        } else {
                            int top = st.top(); st.pop();
                            int sop = st.top(); st.pop();
                            st.push(top * sop);
                        }
                    }
                } else if (input[i + 2] == 'T') {
                    if (st.size() < 2) {
                        cout << "Invalid division operation" << "\n";
                    } else if (st.top() == 0) {
                        cout << "Division by zero" << "\n";
                    } else {
                        int top = st.top(); st.pop();
                        int sop = st.top(); st.pop();
                        st.push(sop / top);
                    }
                }
            } else if (i + 3 < input.size() && input[i + 1] == 'N') {
                if (st.empty()) {
                    cout << "Invalid print operation" << "\n";
                } else {
                    int top = st.top();
                    st.pop();
                    cout << top << "\n";
                }
            }
        i += 3;
        }
    }
}
