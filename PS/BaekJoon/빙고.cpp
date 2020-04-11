#include <iostream>
#include <unordered_map>

using namespace std;

int a[5][5];
bool check[5][5];

int count() {
	int cnt, lines=0;
	
	for(int i=0; i<5; i++) {
		for(cnt=0; cnt<5; cnt++) 
			if(check[i][cnt]==false) break;
		
		if(cnt==5) lines++;
		
		for(cnt=0; cnt<5; cnt++) 
			if(check[cnt][i]==false) break;
		
		if(cnt==5) lines++;
	}
	
	for(cnt=0; cnt<5; cnt++) 
		if(check[cnt][cnt]==false) break;
	if(cnt==5) lines++;
	
	for(cnt=0; cnt<5; cnt++)
		if(check[4-cnt][cnt]==false) break;
	if(cnt==5) lines++;
	
	return lines;	
}

int main() {
	int n=5;

	unordered_map<int,pair<int,int>> um;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) { 
			cin>>a[i][j];
			
			um[a[i][j]]=make_pair(i,j);
			check[i][j]=false;
		}
	}
	
	int v,bingo=0;
	for(int i=0; i<n*n; i++) {
		cin>>v;
		
		int x=um[v].first;
		int y=um[v].second;
		check[x][y]=true;
		
		if(count()>=3) {
			cout<<i+1;
			break;
		}
	}

	return 0;
}

/*
INPUT:
11 12 2 24 10
16 1 13 3 25
6 20 5 21 17
19 4 8 14 9
22 15 7 23 18
5 10 7 16 2
4 22 8 17 13
3 18 1 6 25
12 19 23 14 21
11 24 9 20 15

OUTPUT:
15
*/
