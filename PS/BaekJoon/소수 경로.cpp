#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int d[10001];
bool c[10001]; 

int change(int num, int index, int digit) {
	if(index==0 && digit==0) return -1;
	
	string s=to_string(num);
	s[index]=digit+'0';
	
	return stoi(s);
}

int main() {
	bool primes[10001] {true};
	
	for(int i=2; i<=10000; i++) {
		if(primes[i]==false) {
			for(int j=i*i; j<=10000; j+=i) primes[j]=true;
		}
	}
	
	for(int i=0; i<=10000; i++) primes[i]=!primes[i];
	
	int t;
	cin>>t;
	
	while(t--) {
		int start,end;
		cin>>start>>end;
		
		// reset
		memset(c,false,sizeof(c));
		memset(d,0,sizeof(d));
		
		queue<int> q;
		q.push(start);
		
		d[start]=0;
		c[start]=true;
		
		while(!q.empty()) {
			int now=q.front();
			q.pop();
			
			for(int i=0; i<4; i++) {
				for(int j=0; j<=9; j++) {
					int next=change(now,i,j);
					if(next==-1) continue;
					
					if(primes[next] && c[next]==false) {
						d[next]=d[now]+1;
						c[next]=true;
						q.push(next);
					}
				}
			}
		}
		
		if(c[end]) cout<<d[end]<<endl;
		else cout<<"Impossible"<<endl;
	}
	
	return 0;
}

/*
INPUT:
3
1033 8179
1373 8017
1033 1033

OUTPUT:
6
7
0
*/
