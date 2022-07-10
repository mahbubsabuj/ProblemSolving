#include "bits/stdc++.h"
using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int one = 0;
		 for (int i = 1; i <= 2; ++i) {
			 for (int j = 1; j <= 2; ++j) {
				 int x;
				 cin >> x;
				 one += (x == 1);
			 }
		 }
		 if (one == 0) {
			 cout << 0 << '\n';
		 } else {
			 cout << (one == 4 ? 2 : 1) << '\n';
		 }
	 }
}
 