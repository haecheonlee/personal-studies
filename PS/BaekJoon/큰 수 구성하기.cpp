#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string n;
	int k;
	
	cin>>n>>k;
	
	int arr[k];
	for(int i=0; i<k; i++) cin>>arr[i];
	sort(arr, arr+k, greater<int>());
	
	bool check=false, isSkipped=true;
	int idx[9];
	for(int i=0; i<n.size(); i++) idx[i]=-1;

	for(int i=0; i<n.size(); i++) {
		if(!check) {
			int current=n[i]-'0';
			
			for(int j=0; j<k; j++) {
				if(current>=arr[j]) {
					idx[i]=arr[j];
					if(current>arr[j]) check=true;
					isSkipped=false;
					break;
				}
			}
			
			if(isSkipped) {
				check=true;
				continue;
			}
			
			if(idx[i]==-1) {
				// arr[0] - biggest #
				idx[i]=arr[0];
				check=true;

				int index=i-1;
				bool isChanged=false;
				while(1) {
					for(int j=0; j<k; j++) {
						if(idx[index]>arr[j]) {
							idx[index]=arr[j];
							isChanged=true;
							break;
						}	
					}
					
					if(isChanged) break;
					else {
						if(index!=0) {
							idx[index]=arr[0];
							index--;
						} else {
							idx[index]=-1;
							break;
						}
					}
				}
			}
		} else {
			idx[i]=arr[0];
		}
	}
	
	for(int i=0; i<n.size(); i++) {
		if(idx[i]==-1) continue;
		cout<<idx[i];
	}

	return 0;
}

/*
boj.kr/18511

INPUT:
657 3
1 5 7

OUTPUT:
577
*/
