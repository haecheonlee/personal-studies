#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pictures[1001]{0};
int main() {
	int n,t, pic;
	cin>>n>>t;
	
	vector<int> gallery;
	for(int i=0; i<t; i++) {
		cin>>pic;
		if(find(gallery.begin(), gallery.end(), pic)!=gallery.end()) {
			pictures[pic]+=1;
		} else {
			if(gallery.size()==n) {
				int selected_pic=gallery[0], selected_idx=0;
				for(int i=1; i<gallery.size(); i++) {
					if(pictures[gallery[i]]<pictures[selected_pic]) {
						selected_pic=gallery[i];
						selected_idx=i;
					}
				}
				
				pictures[selected_pic]=0;
				gallery.erase(gallery.begin()+selected_idx);
			}
			
			gallery.push_back(pic);
			pictures[pic]+=1;
		}
	}
	
	sort(gallery.begin(), gallery.end());
	for(int i=0; i<gallery.size(); i++) cout<<gallery[i]<<" ";
	
	return 0;
}

/*
boj.kr/1713

INPUT:
3
9
2 1 4 3 5 6 2 7 2

OUTPUT:
2 6 7
*/
