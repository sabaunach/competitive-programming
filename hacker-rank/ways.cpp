#include <bits/stdc++.h>

/*
   given an integer TOTAL and an integer k,
   compute the number of ways to sum to TOTAL using integers 1-k
   ex. 8 2
   11111111
   1111112
   111122
   11222
   2222
   5 ways.
 */

using namespace std;

/*
 * Complete the 'ways' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER total
 *  2. INTEGER k
 */

int ways(int total, int k) {
	cerr << total << " ";
	cerr << k;
	vector<int> s_mprev(total + 1, 1);
	vector<int> s_m(total + 1);
	int m = 1;
	while (++m <= k) {
		int i = 0;
		for (; i < m; i++) {
			s_m[i] = s_mprev[i];
		}
		for (; i <= total; i++) {
			s_m[i] = (s_mprev[i] + s_m[i - m]) % 1000000007;
		}
		s_mprev = s_m;
	}
	return s_mprev[total];
}
