#include <iostream>

using namespace std;

int n;
int lost[20];
int happy[20];
int ans=0;

void go(int index, int sum, int health) {
	if(health<=0) return;
	ans=max(ans, sum);
	if(index==n) return;
	
	go(index+1, sum+happy[index], health-lost[index]);
	go(index+1, sum, health);
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) cin>>lost[i];
	for(int i=0; i<n; i++) cin>>happy[i];
	
	go(0,0,100);
	cout<<ans;
	
	return 0;
}
