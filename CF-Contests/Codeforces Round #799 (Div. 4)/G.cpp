#include "bits/stdc++.h"

using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int n, k;
		 cin >> n >> k;
		 double a[n + 1];
		 for (int i = 1; i <= n; ++i) cin >> a[i];
		 double logs[n + 1];
		 for (int i = 1; i <= n; ++i) {
			 logs[i] = log2(a[i]);
		 }
		 int cnt = 0;
		 int res = 0;
		 for (int i = 1; i <= n; ++i) logs[i] += i - 1;
		 logs[0] = 0;
		 for (int i = 1; i <= n; ++i) {
			 if (logs[i] > logs[i - 1]) {
				 ++cnt;
			 } else {
				 res += max(0, cnt - k);
				 cnt = 1;
			 }
		 }
		 res += max(0, cnt - k);
		 cout << res << '\n';
	 }
}
