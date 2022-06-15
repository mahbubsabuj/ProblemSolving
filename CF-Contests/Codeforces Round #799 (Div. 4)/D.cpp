#include "bits/stdc++.h"

using namespace std;

int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 string s;
		 int x;
		 cin >> s >> x;
		 set<string> st;
		 auto calculate = [&] (int X, int Y) {
			 string s = "";
			 string t = "";
			 if (X < 10) {
				 s.push_back('0');
			 }
			 if (Y < 10) {
				 t.push_back('0');
			 }
			 s += to_string(X);
			 t += to_string(Y);
			 reverse(t.begin(), t.end());
			 if (s != t) return;
			 st.insert(s + t);
			 return;
		 };
		 int init_hour = (s[0] - '0') * 10 + (s[1] - '0');
		 int init_min = (s[3] - '0') * 10 + (s[4] - '0');
		 for (int i = 1; i <= 60 * 24; ++i) {
			 calculate(init_hour, init_min);
			 int hour_delta = x / 60;
			 int min_delta = x % 60;
			 init_hour += hour_delta;
			 init_min += min_delta;
			 init_hour += init_min / 60;
			 init_min %= 60;
			 init_hour %= 24;
		 }
		 cout << (int) st.size() << '\n';
	 }
}
