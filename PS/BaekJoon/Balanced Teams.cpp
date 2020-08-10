#include <iostream>

using namespace std;
const int MAX=12;

int team[4];
int total[4];
int skill[MAX];
int ans=-1;

void go(int now) {
	if(now==MAX) {
		int mx=-1, mn=1e9;
		for(int i=0; i<4; i++) {
			mx=max(total[i],mx);
			mn=min(total[i],mn);
		}
		
		int diff=abs(mx-mn);
		if(ans==-1 || ans>diff) ans=diff;
		
		return;
	}
	
	for(int i=0; i<4; i++) {
		if(team[i]<3) {
			team[i]++;
			total[i]+=skill[now];
			go(now+1);
			total[i]-=skill[now];
			team[i]--;
		}
	}
}

int main() {
	for(int i=0; i<MAX; i++) cin>>skill[i];
	
	go(0);
	cout<<ans;
	
	return 0;
}
