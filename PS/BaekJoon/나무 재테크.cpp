#include <iostream>
#include <queue>
#include <deque>
#include <tuple>

using namespace std;
using tpl=tuple<int,int,int>;
using pi=pair<int,int>;

int N,M,K;
queue<tpl> dead;
deque<tpl> tree;
queue<pi> breed;
int area[11][11];
int A[11][11];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

void spring() {
	deque<tpl> next_tree;
	
	while(!tree.empty()) {
		int x,y,age;
		tie(x,y,age)=tree.front();
		tree.pop_front();
		
		if(area[x][y]-age>=0) {
			area[x][y]-=age;
			next_tree.push_back(make_tuple(x,y,age+1));
			if((age+1)%5==0) breed.push(make_pair(x,y));
		}
		else {
			dead.push(make_tuple(x,y,age));
		}
	}
	
	tree.swap(next_tree);
}

void summer() {
	while(!dead.empty()) {
		int x,y,age;
		tie(x,y,age)=dead.front();
		dead.pop();
		
		area[x][y]+=(int)age/2;
	}
}

void fall() {
	while(!breed.empty()) {
		int x,y;
		tie(x,y)=breed.front();
		breed.pop();
		
		for(int k=0; k<8; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(1<=nx && nx<=N && 1<=ny && ny<=N) {
				tree.push_front(make_tuple(nx,ny,1));
			}
		}
	}
}

void winter() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) area[i][j]+=A[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M>>K;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin>>A[i][j];
			area[i][j]=5;
		}
	}
	
	// position of tree
	while(M--) {
		int x,y,age;
		cin>>x>>y>>age;
		tree.push_front(make_tuple(x,y,age));
	}
	
	// year starts
	while(K--) {
		spring();
		summer();
		fall();
		winter();
	}

	cout<<tree.size();

	return 0;
}
