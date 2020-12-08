#include <iostream>

using namespace std;

int nextHour(int hour) {
	hour++;
	return (hour == 24 ? 0 : hour);
}

bool is_night(int hour) {
	if(hour >= 22 || hour <= 2) return true;
	return false;
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		string s;
		int d;
		cin >> s >> d;
		
		int H = ((s[0] - '0') * 10) + (s[1] - '0');
		int M = ((s[3] - '0') * 10) + (s[4] - '0');
		int time = (H * 60 + M);

		int ans = 0;
		while(d > 0) {
			if(is_night(H) && d > 300) {
				int hd = ((H >= 22) ? (H - 22) : (24 + H) - 22);
				d -= (600 - (hd * 60 + M));
				H = 8, M = 0;
				
				ans += 5000;
			} else {
				H = nextHour(H);
				d -= 60;
				
				ans += 1000;
			}
		}
		
		cout << ans << '\n';
	}

	return 0;
}
