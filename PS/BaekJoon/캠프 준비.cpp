#include <iostream>
#include <vector>

using namespace std;

int n,l,r,x;
int a[20];
int ans=0;
vector<int> list;

void go(int index) {
	if(index==n) {
		if(list.size()<2) return;
		int sum=0,hard=-1,easy=-1;
		for(int i=0; i<list.size(); i++) {
			int current=a[list[i]];
			
			sum+=current;
			if(hard==-1 || hard<current) hard=current;
			if(easy==-1 || easy>current) easy=current;
		}
		
		if((sum<=r && sum>=l) && (hard-easy)>=x) ans++;
		return;
	}
	
	if(index>=n) return;
	list.push_back(index);
	go(index+1);
	list.pop_back();
	go(index+1);
}

int main() {
	cin>>n>>l>>r>>x;
	for(int i=0; i<n; i++) cin>>a[i];
	
	go(0);
	cout<<ans;

	return 0;
}

/*
INPUT:
5 25 35 10
10 10 20 10 20

OUTPUT:
6
*/
