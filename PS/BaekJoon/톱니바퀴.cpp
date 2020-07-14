#include <iostream>

#define SIZE 4
#define LEN 8
#define LEFT 0
#define RIGHT 1

using namespace std;

string a[SIZE];

void cw(int index) {
	int last=a[index][LEN-1];
	for(int i=LEN-1; i>0; i--) a[index][i]=a[index][i-1];
	a[index][0]=last;
}

void ccw(int index) {
	int first=a[index][0];
	for(int i=0; i<LEN; i++) a[index][i]=a[index][i+1];
	a[index][LEN-1]=first;
}

void transform(int index, int rotation) {
	if(rotation==1) cw(index);
	else ccw(index);
}

inline int opposite(int dir) {
	if(dir==1) return -1;
	else return 1;
}

bool check(char current, int next_index, int prev, int dir) {
	if(next_index==prev) return false;
	if(dir==LEFT) {
		// left
		if(current==a[next_index][2]) return false;
		else return true;
	} else {
		// right
		if(current==a[next_index][6]) return false;
		else return true;
	}
}

void go(int index, int prev, int rotation) {
	char L=a[index][6];	// current_index
	char R=a[index][2];	// current index 
	
	// rotate based on rotation
	transform(index, rotation);

	if(index==0) {
		if(check(R, index+1, prev, RIGHT)) 
			go(index+1,index,opposite(rotation));
	} else if((index+1)==SIZE) {
		if(check(L, index-1, prev, LEFT)) 
			go(index-1, index, opposite(rotation));
	} else {
		if(check(L, index-1, prev, LEFT)) 
			go(index-1, index, opposite(rotation));
		
		if(check(R, index+1, prev, RIGHT))
			go(index+1, index, opposite(rotation));
	}
}

int main() {
	for(int i=0; i<SIZE; i++) cin>>a[i];
	
	int K;
	cin>>K;

	while(K--) {
		int index,rotation;
		cin>>index>>rotation;
		index-=1;

		go(index,-1,rotation);
	}
	
	int ans=0;
	for(int i=0; i<SIZE; i++) {
		// if postion of 12 (south) is S(=1)
		if(a[i][0]=='1') ans+=(1<<i);
	}
	cout<<ans;
	
	return 0;
}
