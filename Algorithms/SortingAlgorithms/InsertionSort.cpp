#include "bits/stdc++.h"

using namespace std;

void insertionSort (int a[], int n) {
	for (int i = 1; i < n; ++i) {
		int j = i - 1;
		int key = a[i];
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key; //make room for current key
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
		 insertionSort(a, n);
		 cout << "AFTER\n";
		 for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	 }
}
