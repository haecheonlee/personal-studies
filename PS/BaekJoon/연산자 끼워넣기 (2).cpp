#include <iostream>

using namespace std;

int largest=-1000000001, smallest=1000000001;
int nums[11];
int list[44];
int cnt[4] {0};

void go(int index, int end) {
	if(index==end) {
		int sum=0;
		for(int i=0; i<end; i++) {
			if(list[i]==0) sum=((i>0)?sum+nums[i+1]:nums[i]+nums[i+1]);
			else if(list[i]==1) sum=((i>0)?sum-nums[i+1]:nums[i]-nums[i+1]);
			else if(list[i]==2) sum=((i>0)?sum*nums[i+1]:nums[i]*nums[i+1]);
			else if(list[i]==3) sum=((i>0)?sum/nums[i+1]:nums[i]/nums[i+1]);
		}
		
		largest=max(largest,sum);
		smallest=min(smallest,sum);
		
		return;
	}
	
	for(int i=0; i<4; i++) {
		if(cnt[i]>0) {
			cnt[i]--;
			list[index]=i;
			go(index+1,end);
			cnt[i]++;
		}
	}
}

int main() {
	int n,a;
	cin>>n;
	
	for(int i=0; i<n; i++) cin>>nums[i];
	for(int i=0; i<4; i++) {
		cin>>a;
		while(a--) cnt[i]++;
	}
	
	go(0,n-1);
	
	cout<<largest<<'\n'<<smallest;
	return 0;
}

/*
boj.kr/15658

INPUT:
6
1 2 3 4 5 6
3 2 1 1

OUTPUT:
72
-48
*/
