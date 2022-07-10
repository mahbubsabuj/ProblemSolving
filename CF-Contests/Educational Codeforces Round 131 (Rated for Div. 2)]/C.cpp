#include "bits/stdc++.h"
using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 long long n, m;
		 cin >> n >> m;
		 map<long long, long long> cnt;
		 long long res = 0;
		 for (int i = 1; i <= m; ++i) {
			 long long x;
			 cin >> x;
			 ++cnt[x];
			 res = max(res, cnt[x]);
		 }
		 auto yes = [&] (long long time) {
			long long pending_tasks = 0;
			for (pair<long long, long long> p : cnt) {
				if (p.second > time) {
					pending_tasks += p.second - time;
				} else {
					if (p.second == time) continue;
					pending_tasks -= (time - p.second) / 2;
				}
			} 
			pending_tasks -= ((time / 2) * (n - (long long) cnt.size()));
			return pending_tasks <= 0;
		 };
		 long long l = 1, r = res;
		 while (l <= r) {
			 long long mid = l + (r - l) / 2;
			 if (yes(mid)) {
				 r = mid - 1;
				 res = mid;
			 } else {
				 l = mid + 1;
			 }
		 }
		 cout << res << '\n';
	 }
}
 