/* reference: https://jaejin89.tistory.com/41 */

#include <iostream>

using namespace std;
const int N=6;

int t1[]={0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int t2[]={1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
int win[N];
int draw[N];
int lose[N];
bool ans;

void go(int match) {
	if(ans) return;
	
	if(match==15) {
		ans=true;
		return;
	}
	
	int r1=t1[match];
	int r2=t2[match];
	
	if(win[r1] && lose[r2]) {
		win[r1]--; lose[r2]--;
		go(match+1);
		win[r1]++; lose[r2]++;
	}
	
	if(lose[r1] && win[r2]) {
		lose[r1]--; win[r2]--;
		go(match+1);
		lose[r1]++; win[r2]++;
	}
	
	if(draw[r1] && draw[r2]) {
		draw[r1]--; draw[r2]--;
		go(match+1);
		draw[r1]++; draw[r2]++;
	}
}

int main() {
	for(int i=0; i<4; i++) {
		ans=false;
		
		int tw, td, tl;
		tw=tl=td=0;
		
		for(int i=0; i<N; i++) {
			cin>>win[i]>>draw[i]>>lose[i];
			
			tw+=win[i];
			td+=draw[i];
			tl+=lose[i];
		}
		
		if(tw+td+tl==30) go(0);
		cout<<ans<<" ";
	}

	return 0;
}
