#include <iostream>

using namespace std;

int H, Y;
int ans;

void invest(int money, int y) {
	if(y == Y) {
		ans = max(ans, money);
		return;
	}
	
	if(y + 1 <= Y) {
		double x = money * 1.05;
		invest((int)x, y + 1);
	}
	
	if(y + 3 <= Y) {
		double x = money * 1.20;
		invest((int)x, y + 3);
	}
	
	if(y + 5 <= Y) {
		double x = money * 1.35;
		invest((int)x, y + 5);
	}
}

int main() {
	cin >> H >> Y;
	
	ans = H;
	invest(H, 0);
	
	cout << ans << '\n';
	
	return 0;
}
