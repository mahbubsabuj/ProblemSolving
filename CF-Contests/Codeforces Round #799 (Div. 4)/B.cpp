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
		 map<int, int> cnt;
		 for (int i = 0; i < n; ++i) {
			 int x;
			 cin >> x;
			 ++cnt[x];
		 }
		 int res = (int) cnt.size();
		 int removed = 0;
		 for (pair<int, int> p : cnt) {
			 removed += p.second - 1;
		 }
		 if (removed % 2 != 0) {
			 --res;
		 }
		 cout << res << '\n';
	 }
}
