#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;
bool check[100001] {false};
int result=-1;

void go(int current, int prime, int count) {
	if(current==prime) {
		if(result==-1 || result>count) result=count;
		return;
	}
	
	if(current/3>prime/3) go(current/3, prime, count+1);
	if(current/2>prime/2) go(current/2, prime, count+1);
	go(prime, prime, count+abs(current-prime));
}

int main() {
	
	for(int i=2; i<=100000; i++) {
		if(check[i]==false) {
			for(int j=i+i; j<=100000; j+=i) check[j]=true;
		}
	}
	
	int t;
	cin>>t;
	
	while(t--) {
		int n,a,b;
		cin>>n>>a>>b;
		
		list.clear();
		for(int i=a; i<=b; i++) {
			if(check[i]==false) list.push_back(i);
		}
		
		if(list.empty()) cout<<-1<<'\n';
		else if(find(list.begin(), list.end(), n)!=list.end()) cout<<0<<'\n';
		else {
			int mn=-1;
			
			for(auto &prime : list) {
				int diff=prime-n;
				int cnt=0;
				
				if(diff>0) {
					cnt=diff;
				}
				else {
					result=-1;
					go(n,prime,0);
					cnt=result;
				}
				
				if(mn==-1 || mn>cnt) mn=cnt;
			}
			
			cout<<mn<<'\n';
		}
	}
	
	return 0;
}
