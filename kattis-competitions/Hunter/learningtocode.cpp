#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int

unordered_map<string, string> vars;

string evaluate(string str) {
    string out = "";
    for (uint i = 0; i < str.size(); ++i) {

        // parse expr
        if (str[i] == '$' && str[i+1] == '{') {
            i += 2; // eat ${
            uint start = i; // for remembering start of substr

            // parse string
            if (str[i] == '"') {
                ++i; ++start; // eat opening "
                for (; str[i] != '"'; ++i);
                out += str.substr(start, i - start);
                continue;
            // parse variable
            } else if (str[i] != '`') {
                for (; str[i] != '}'; ++i);
                string varname = str.substr(start, i - start);
                out += vars[varname];
                continue;
            }

            // otherwise, parse expr (since it wasn't a string or var)
            // nothing changes, we continue *(there used to be a continue here)*
        }
        if (str[i] == '`' || str[i] == '}' || str[i] == '"') // str[i] == '"' to replace the nontrivial continue;
            continue;
        // efficiency note: rather than go character by character,
        // should probably scan ahead to next expr

        uint start = i;
        for (; str[i] != '$' && str[i + 1] != '{'; ++i);
        out += str[i];
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    string in;
    while (cin >> in) {
        if (in == "end.")
            return 0;

        if (in == "var") {
            string varname;
            cin >> varname >> in;
            string val;
            cin.ignore();
            getline(cin, val);
            val = val.substr(0, val.length() - 1); // eat ;
            vars[varname] = evaluate("${" + val + "}"); // make evaluate method easier
            //cerr << val << endl;
            //cerr << vars[varname] << endl;

        } else if (in == "print") {
            string val;
            cin.ignore();
            getline(cin, val);
            val = val.substr(0, val.length() - 1); // eat ;
            //cerr << val << endl;
            string res = evaluate("${" + val + "}") + "\n";
            cout << res;

        }
    }
}
