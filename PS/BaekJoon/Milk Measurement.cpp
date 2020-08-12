#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;
using tpl=tuple<int,string,int>;

string cows[] = {"Bessie", "Elsie", "Mildred"};
map<string,int> list;

int main() {
	for(int i=0; i<3; i++) list[cows[i]]=7;
	
	int N;
	cin>>N;

	vector<tpl> a;
	for(int i=0; i<N; i++) {
		int day,amount;
		string name;
		
		cin>>day>>name>>amount;
		a.push_back({day,name,amount});
	}
	sort(a.begin(), a.end());
	
	int ans=0;
	int current_display=7;	//	0: Bessie, 1: Elsie, 2: Mildred, 3: B&E, 
	for(int i=0; i<N; i++) {
		int day,amount;
		string name;
		
		tie(day,name,amount)=a[i];
		list[name]+=amount;
		
		int highest=0, display=0;
		for(int i=0; i<3; i++) {
			if(list[cows[i]]>highest) {
				highest=list[cows[i]];
				display=(1<<i);
			} else if(list[cows[i]]==highest) {
				display+=(1<<i);
			}
		}
		
		if(display!=current_display) {
			current_display=display;
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
