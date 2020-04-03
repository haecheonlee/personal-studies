#include <iostream>
#include <vector>

using namespace std;

int a[21][21];
int n,ans=1000000;
bool check[21];

void go(vector<int> list, int index, int size) {
	if(list.size()==size) {
		int diff=0;

		vector<int> list2;
		for(int i=0; i<n; i++) {
			if(check[i]==false) list2.push_back(i);
		}
		
		int t1=0;
		for(int i=0; i<list.size(); i++) {
			for(int j=0; j<list.size(); j++) {
				if(i==j) continue;
				t1+=a[list[i]][list[j]];
			}
		}

		int t2=0;
		for(int i=0; i<list2.size(); i++) {
			for(int j=0; j<list2.size(); j++) {
				if(i==j) continue;
				t2+=a[list2[i]][list2[j]];
			}
		}
		
		ans=min(ans,abs(t1-t2));
		return;
	}
	
	if(index>=n) return;
	list.push_back(index);
	check[index]=true;
	go(list,index+1,size);
	list.pop_back();
	check[index]=false;
	go(list,index+1,size);
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];
	}

	for(int i=0; i<n-1; i++) {
		go(vector<int>(), 0, i+1);
	}

	cout<<ans;
	
	return 0;
}

/*
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
