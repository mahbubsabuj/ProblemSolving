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
		 int a[n + 1];
		 for (int i = 1; i <= n; ++i) {
			 cin >> a[i];
		 }
		 map<int, vector<int>> idx;
		 for (int i = 1; i <= n; ++i) idx[a[i]].push_back(i);
		 int ans = a[1], l = 1, r = 1, cnt = 1;
		 for (pair<int, vector<int>> p: idx) {
			 //kadane's algorithm
			 int l2 = p.second[0], r2 = p.second[0];
			 int sum = 1;
			 for (int i = 1; i < (int) p.second.size(); ++i) {
				 int diff = p.second[i] - p.second[i - 1] - 1;
				 sum -= diff;
				 ++sum;
				 sum = max(sum, 0);
				 if (sum > 0) {
					 r2 = p.second[i];
					 if (sum > cnt) {
						 l = l2;
						 r = r2;
						 cnt = sum;
						 ans = p.first;
					 }
				 } else {
					 l2 = r2 = p.second[i];
					 sum = 1;
				 }
				 
			 }
			 if (sum > cnt) {
				 l = l2;
				 r = r2;
				 cnt = sum;
				 ans = p.first;
			 }
		 }
		 cout << ans << ' ' << l << ' ' << r << '\n';
	 }
}
