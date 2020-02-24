#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<int> list;
int largest=-1000000001, smallest=1000000001;
bool used[10];
int cnt[4] {0};
vector<char> operators {'+','-','*','/'};

void go(int index, int end) {
	if(index==end) {
		vector<int> copy=nums;
		vector<int> copy_list=list;

		for(int i=0; i<copy_list.size(); i++) {
			if(operators[copy_list[i]]=='*') { 
				copy[i]=copy[i]*copy[i+1];
				copy.erase(copy.begin()+(i+1));
				copy_list.erase(copy_list.begin()+i);
				i--;
				continue;
			}
			
			if(operators[copy_list[i]]=='/') {
				copy[i]=copy[i]/copy[i+1];
				copy.erase(copy.begin()+(i+1));
				copy_list.erase(copy_list.begin()+i);
				i--;
				continue;
			}
		}

		for(int i=0; i<copy_list.size(); i++) {
			if(operators[copy_list[i]]=='+') { 
				copy[i]=copy[i]+copy[i+1];
				copy.erase(copy.begin()+(i+1));
				copy_list.erase(copy_list.begin()+i);
				i--;
				continue;
			}
			
			if(operators[copy_list[i]]=='-') {
				copy[i]=copy[i]-copy[i+1];
				copy.erase(copy.begin()+(i+1));
				copy_list.erase(copy_list.begin()+i);	
				i--;
				continue;
			}
		}
		
		largest=max(largest,copy[0]);
		smallest=min(smallest,copy[0]);
		
		return;
	}
	
	for(int i=0; i<4; i++) {
		if(cnt[i]>0) {
			cnt[i]--;
			list[index]=i;
			go(index+1, end);
			cnt[i]++;
		}
	}
}

int main() {
	int n,a;
	cin>>n;
	
	nums.resize(n);
	list.resize(n-1);
	
	for(int i=0; i<n; i++) cin>>nums[i];
	for(int i=0; i<4; i++) {
		cin>>a;
		while(a--) cnt[i]++;
	}
	
	go(0,n-1);
	
	cout<<largest<<'\n'<<smallest;
	
	return 0;
}

/*
boj.kr/15659

INPUT:
6
1 2 3 4 5 6
2 1 1 1

OUTPUT:
35
-27
*/
