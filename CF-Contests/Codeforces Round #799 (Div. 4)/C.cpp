#include "bits/stdc++.h"

using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int n = 8, m = 8;
		 vector<string> grid(n);
		 for (int i = 0; i < n; ++i) {
			 cin >> grid[i];
		 }
		 auto yes = [&] (int i, int j, int dx, int dy) {
			 if ((i == 0 && j == 0) || (i == n - 1 && j == m - 1) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0)) return false;
			 while (i >= 0 && j >= 0 && i < n && j < m) {
				 if (grid[i][j] != '#') return false;
				 i += dx;
				 j += dy;
			 }
			 return true;
		 };
		 int res_x, res_y;
		 for (int i = 0; i < n; ++i) {
			 for (int j = 0; j < m; ++j) {
				 int x = i, y = j;
				 if (yes(x, y, -1, +1) && yes(x, y, -1, -1) && yes(x, y, +1, +1) && yes(x, y, +1, -1)) {
					 res_x = x, res_y = y;
					 break;
				 }
			 }
		 }
		 cout << res_x + 1 << ' ' << res_y + 1 << '\n';
	 }
}
