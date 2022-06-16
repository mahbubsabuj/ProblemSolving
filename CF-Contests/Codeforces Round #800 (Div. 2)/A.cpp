#include "bits/stdc++.h"

using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int a, b;
		 cin >> a >> b;
		 int n = a + b;
		 if (a > b) {
			 for (int i = 1; i <= n; ++i) {
				 if (i % 2 == 0 && b > 0) {
					 cout << '1';
					 --b;
				 } else {
					 cout << '0';
					 --a;
				 }
			 }
		 } else {
			 for (int i = 1; i <= n; ++i) {
				 if (i % 2 == 0 && a > 0) {
					 cout << '0';
					 --a;
				 } else {
					 cout << '1';
					 --b;
				 }
			 }
		 }
		 cout << '\n';
	 }
}
