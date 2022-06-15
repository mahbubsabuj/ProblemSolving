#include "bits/stdc++.h"

using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int cnt = 0;
		 int x;
		 cin >> x;
		 for (int i = 0; i < 3; ++i) {
			 int y;
			 cin >> y;
			 if (y > x) ++cnt;
		 }
		 cout << cnt << '\n';
	 }
}
