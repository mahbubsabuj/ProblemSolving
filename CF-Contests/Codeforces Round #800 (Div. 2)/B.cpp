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
		 string s;
		 cin >> n >> s;
		 stack<int> idx;
		 long long res = 1;
		 idx.push(0);
		 for (int i = 1; i < n; ++i) {
			 int current_idx = i;
			 while (!idx.empty()) {
				 int top = idx.top();
				 //~ cout << s[top] << ' ' << s[i] << '\n';
				 if (s[top] != s[i]) {
					 current_idx = top;
					 s[top] = s[i];
					 idx.pop();
				 } else {
					 break;
				 }
			 }
			 //~ cout << s << ' ' << (int) idx.size() << '\n';
			 if (idx.empty()) {
				 current_idx = 0;
				 idx.push(0);
			 }
			 if(current_idx == i) {
				 idx.push(current_idx);
			 }
			 //~ cout << current_idx << ' ' << i << '\n';
			 res += (i - current_idx + 1);
		 }
		 cout << res << '\n';
	 }
}

//~ 1001

//~ 1 = yes
//~ 10 = yes
//~ 100 = no
//~ 1001 = yes
//~ 0 = yes
//~ 00 = no
//~ 001 = yes
//~ 0 = yes
//~ 01 = yes
//~ 1 = yes


//~ 001 = 
//~ res = 1
//~ {1}
//~ 12345
//~ 10001



//~ 1 = 1
//~ 10 = 1
//~ 100 = 0
//~ 1000 = 0
//~ 10001 = 1
//~ 0 = 1
//~ 00 = 0
//~ 000 = 0
//~ 0001 = 1
//~ 0 = 1
//~ 00 = 0
//~ 001 = 1
//~ 0 = 1
//~ 01 = 1
//~ 1 = 1



