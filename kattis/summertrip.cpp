#include <bits/stdc++.h>

using namespace std;

int total;
string s;

void delve(int index) {
	set<char> uniques;
	for (unsigned int i = index + 1; i < s.size(); i++) {
		if (s[i] == s[index]) {
			//cerr << "  " << index << " = " << i << " : breaking" << endl;
			break;
		}
		uniques.insert(s[i-1]);
		if (uniques.find(s[i]) == uniques.end()) {
			//cerr << "  incr" << endl;
			total++;
		}
	}
}


int main() {
	cin >> s;
	for (unsigned int i = 0; i < s.size(); i++) {
		delve(i);
	}
	cout << total;
}
