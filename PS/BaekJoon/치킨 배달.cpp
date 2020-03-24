#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PI;

int n,m,x;
int path[101][101];
vector<PI> house;
vector<PI> store;
int ans=1000000000;

void go(int index, vector<int> list) {
	if(list.size()==m) {
		int distance=0;
		
		for(int i=0; i<house.size(); i++) {
			int shortest=path[i][list[0]];
			for(int &idx : list) {
				shortest=min(shortest,path[i][idx]);
			}
			distance+=shortest;
		}

		if(ans>distance) ans=distance;
		return;
	}
	
	if(index>=store.size()) return;
	list.push_back(index);
	go(index+1,list);
	list.pop_back();
	go(index+1,list);
}

int main() {
	cin>>n>>m;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>x;
			
			if(x==1) house.push_back(make_pair(i,j));
			else if(x==2) store.push_back(make_pair(i,j));
		}	
	}
	
	for(int i=0; i<house.size(); i++) {
		PI current_house=house[i];
		
		for(int j=0; j<store.size(); j++) {
			PI current_store=store[j];
			path[i][j]=abs(current_house.first-current_store.first)+abs(current_house.second-current_store.second);
		}
	}
	
	go(0,vector<int>());
	cout<<ans;
	
	return 0;
}

/*
INPUT:
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2

OUTPUT:
10
*/
