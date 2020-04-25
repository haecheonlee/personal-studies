#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int a[n];
	bool check[n] {false};
	
	for(int i=0; i<n; i++) cin>>a[i];
	
	int cnt=0,index=0;
	while(1) {
		cout<<index+1<<" ";
		cnt+=1;
		check[index]=true;
		
		if(cnt>=n) break;
		
		int move=a[index];
		if(move>0) {
			int selected=0;
			while(selected<move) {
				index++;
				if(index>=n) index=0;
				if(check[index]==false) selected++;
			}
		} else {
			int selected=0;
			while(selected>move) {
				index--;
				if(index<0) index=n-1;
				if(check[index]==false) selected--;
			}
		}
	}
	
	return 0;
}

/*
INPUT:
5
3 2 1 -3 -1

OUTPUT:
1 4 5 3 2
*/
