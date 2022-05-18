#include "bits/stdc++.h"

using namespace std;

void selectionSort (int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int min_idx = i;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		swap(a[min_idx], a[i]);
	}
}

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T = 1;
	 //~ cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int n = rand() % 30 + 1; // making sure that array will contain atleast 1 random number
		 int a[n];
		 for (int i = 0; i < n; ++i) {
			 a[i] = rand() % 200;
		 }
		 cout << "BEFORE\n";
		 for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		 cout << '\n';
		 selectionSort(a, n);
		 cout << "AFTER\n";
		 for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	 }
}
