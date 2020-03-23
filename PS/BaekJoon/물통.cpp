#include <iostream>
#include <queue>

using namespace std;

int from[]={0,0,1,1,2,2};
int to[]={1,2,0,2,0,1};
int cap[3];
bool check[201][201];
bool ans[201];

int main() {
	for(int i=0; i<3; i++) cin>>cap[i];

	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	check[0][0]=true;
	ans[cap[2]]=true;
	
	int sum=cap[2];
	while(!q.empty()) {
		int current[3];
		
		current[0]=q.front().first;
		current[1]=q.front().second;
		current[2]=sum-current[0]-current[1];
		q.pop();
		
		for(int k=0; k<6; k++) {
			int next[3]={current[0],current[1],current[2]};
			
			next[to[k]]+=next[from[k]];
			next[from[k]]=0;
			
			if(next[to[k]]>cap[to[k]]) {
				next[from[k]]+=next[to[k]]-cap[to[k]];
				next[to[k]]=cap[to[k]];
			}
			
			if(check[next[0]][next[1]]==false) {
				check[next[0]][next[1]]=true;
				if(next[0]==0) ans[next[2]]=true;
				q.push(make_pair(next[0],next[1]));
			}
		}
	}
	
	for(int i=0; i<=cap[2]; i++) {
		if(ans[i]) cout<<i<<" ";
	}

	return 0;
}

/*
INPUT:
8 9 10

OUTPUT:
1 2 8 9 10
*/
