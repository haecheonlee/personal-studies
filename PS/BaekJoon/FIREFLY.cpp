#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N,H;
	cin>>N>>H;
	
	vector<int> bottom(N/2), top(N/2);
	for(int i=0; i<N; i++) cin>>bottom[i]>>top[i];
	
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());
	
	int obs=1e9, cnt=1;
	for(int i=1; i<=H; i++) {
		int obstacles=bottom.size()-(lower_bound(bottom.begin(), bottom.end(), i)-bottom.begin());
		obstacles+=top.size()-(upper_bound(top.begin(), top.end(), H-i)-top.begin());
		
		if(obs==obstacles) {
			cnt++;
		}
		else if(obs>obstacles){
			obs=obstacles;
			cnt=1;
		}
	}
	cout<<obs<<" "<<cnt;
	
	return 0;
}
