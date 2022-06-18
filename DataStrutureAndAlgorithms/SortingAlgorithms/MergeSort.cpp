#include "bits/stdc++.h"

using namespace std;

void merge (int a[], int l, int mid, int r) {
	int n = mid - l + 1;
	int m = r - mid;
	int left[n], right[m];
	for (int i = 0; i < n; ++i) {
		left[i] = a[l + i];
	}
	for (int i = 0; i < m; ++i) {
		right[i] = a[mid + i + 1];
	}
	int idx = l; //from idx = l to r
	l = 0, r = 0;
	while (l < n && r < m) {
		if (left[l] < right[r]) {
			a[idx++] = left[l++];
		} else {
			a[idx++] = right[r++];
		}
	}
	while (l < n) {
		a[idx++] = left[l++];
	}
	while (r < m) {
		a[idx++] = right[r++];
	}
}

void mergeSort (int a[], int l, int r) {
	if (l >= r) return;
	int mid = l + (r - l) / 2;
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
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
		 mergeSort(a, 0, n - 1);
		 cout << "AFTER\n";
		 for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	 }
}
