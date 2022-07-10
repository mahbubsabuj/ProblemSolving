#include "bits/stdc++.h"
using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int n;
		 cin >> n;
		 vector<int> res;
		 map<int, int> has;
		 for (int i = 1; i <= n; ++i) {
			 if (has[i]) continue;
			 int x = i;
			 res.push_back(x);
			 has[x] = true;
			 while (x <= n) {
				 x *= 2;
				 if (x > n) break;
				 res.push_back(x);
				 has[x] = true;
			 }
		 }
		 cout << 2 << '\n';
		 for (int i = 0; i < (int) res.size(); ++i) {
			 cout << res[i] << ' ';
		 }
		 cout << '\n';
	 }
}
 