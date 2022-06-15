#include "bits/stdc++.h"

using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int n, s;
		 cin >> n >> s;
		 int a[n + 1];
		 for (int i = 1; i <= n; ++i) cin >> a[i];
		 int pref[n + 1] = {0};
		 int suf[n + 1] = {0};
		 for (int i = 1; i <= n; ++i) pref[i] += pref[i - 1] + a[i];
		 suf[n] = a[n];
		 for (int i = n - 1; i >= 1; --i) suf[i] += suf[i + 1] + a[i];
		 if (pref[n] < s) {
			 cout << -1 << '\n';
			 continue;
		 }
		 map<int, int> idx;
		 for (int i = n; i >= 1; --i) {
			 idx[suf[i]] = max(idx[suf[i]], i);
		 }
		 int sum = pref[n];
		 int res = INT_MAX;
		 for (int i = 0; i < n; ++i) {
			 int pref_now = pref[i];
			 int sum_now = sum - pref_now - s;
			 if (sum_now == 0) {
				 res = min(res, i);
			 }
			 if (idx.find(sum_now) != idx.end()) {
				 res = min(res, i + n - idx[sum_now] + 1);
			 }
		 }
		 cout << res << '\n';
	 }
}
