#include <iostream>
#include <cmath>

using namespace std;
using pii=pair<int,int>;

double dist(int x1, int x2, int y1, int y2) {
	int x = x1 - x2, y = y1 - y2;
	return sqrt(x * x + y * y);
}

int main() {
	int sx,sy;
	cin>>sx>>sy;
	
	pii a[3];
	for(int i=0; i<3; i++) cin>>a[i].first>>a[i].second;
	
	int ans = 1e9;
	for(int i=0; i<3; i++) {
		double d = 0;
		for(int j=0; j<3; j++) {
			if(i==j) continue;
			for(int k=0; k<3; k++) {
				if(i==k || j==k) continue;
				
				double d =	dist(sx, a[i].first, sy, a[i].second) + 
							dist(a[i].first, a[j].first, a[i].second, a[j].second) + 
							dist(a[j].first, a[k].first, a[j].second, a[k].second);

				ans = min(ans, (int)d);
			}
		}
	}
	cout<<ans;

	return 0;
}
