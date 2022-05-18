#include "bits/stdc++.h"

using namespace std;

void bubbleSort (int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		bool swapped = false;
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
			//than the array is already sorted we should break the loop
		}
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
		 bubbleSort(a, n);
		 cout << "AFTER\n";
		 for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	 }
}
