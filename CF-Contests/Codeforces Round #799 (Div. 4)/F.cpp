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
		 vector<int> a(n);
		 for (int i = 0; i < n; ++i) cin >> a[i];
		 int cnt[10];
		 fill(cnt, cnt + 10, 0);
		 for (int i = 0; i < n; ++i) ++cnt[a[i] % 10];
		 auto can = [&] (int x, int y, int z) {
			 return (x + y + z) % 10 == 3;
		 };
		 bool yes = false;
		 for (int i = 0; i <= 9; ++i) {
			 for (int j = 0; j <= 9; ++j) {
				 for (int k = 0; k <= 9; ++k) {
					 --cnt[i];
					 --cnt[j];
					 --cnt[k];
					 if (cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0) {
						 yes |= can(i, j, k);
					 }
					 ++cnt[i];
					 ++cnt[j];
					 ++cnt[k];
				 }
			 }
		 }
		 cout << (yes ? "YES\n" : "NO\n");
	 }
}
