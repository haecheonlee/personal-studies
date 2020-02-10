#include <iostream>

using namespace std;

int n;
int arr[20][20];
int list_selected[20];
int list_unselected[20];
int last_index;
bool check[20];
int smallest=1001;

void go(int index, int start) {
	if(index==last_index) {
		int team_start=0;
		int team_link=0;
		
		int idx=0;
		for(int i=0; i<n; i++) {
			if(!check[i]) list_unselected[idx++]=i;
		}
		
		for(int i=0; i<index; i++) {
			for(int j=i+1; j<index; j++) {
				team_start+=arr[list_selected[i]][list_selected[j]]+arr[list_selected[j]][list_selected[i]];
				team_link+=arr[list_unselected[i]][list_unselected[j]]+arr[list_unselected[j]][list_unselected[i]];
			}
		}
		
		smallest=min(smallest, abs(team_start-team_link));
		
		return;
	}
	
	for(int i=start; i<n; i++) {
		if(check[i]) continue;
		check[i]=true;
		list_selected[index]=i;
		go(index+1,i+1);
		check[i]=false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;
	last_index=n/2;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>arr[i][j];
	}
	
	check[0]=true;
	list_selected[0]=0;
	go(1,1);
	
	cout<<smallest;
	
	return 0;
}

/*
boj.kr/14889

INPUT:
8
0 5 4 5 4 5 4 5
4 0 5 1 2 3 4 5
9 8 0 1 2 3 1 2
9 9 9 0 9 9 9 9
1 1 1 1 0 1 1 1
8 7 6 5 4 0 3 2
9 1 9 1 9 1 0 9
6 5 4 3 2 1 9 0

OUTPUT:
1
*/
