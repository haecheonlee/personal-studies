#include <iostream>
#include <deque>

using namespace std;

class Location {
public:
	int index;
	int x;
	int y;
	Location(int _index, int _x, int _y) : index{_index}, x{_x}, y{_y} {}
};

int n;
int area[200][200];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
deque<Location> q;
deque<Location> next_q;

void bfs() {
	while(!q.empty()) {
		int current_index=q.front().index;
		int current_x=q.front().x;
		int current_y=q.front().y;
		q.pop_front();
		
		for(int k=0; k<4; k++) {
			int nx=current_x+dx[k];
			int ny=current_y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				if(area[nx][ny]==0) {
					area[nx][ny]=area[current_x][current_y];
					next_q.push_front({current_index,nx,ny});
				}
			}
		}
	}
}

int main() {
	int k,s,x,y;
	cin>>n>>k;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>area[i][j];
			if(area[i][j]!=0) {
				if(!q.empty()) {
					deque<Location> to_copy;
					while(1) {
						Location l = q.back();
						if(l.index>area[i][j]) {
							to_copy.push_front(l);
							q.pop_back();
						} else {
							q.push_back({area[i][j],i,j});
							while(!to_copy.empty()) {
								q.push_back(to_copy.front());
								to_copy.pop_front();
							}
							break;
						}
					}
				} else {
					q.push_front({area[i][j],i,j});
				}
			}
		}
	}
	cin>>s>>x>>y;
	
	for(int i=0; i<s; i++) {
		if(!next_q.empty()) {
			while(!next_q.empty()) {
				q.push_front(next_q.front());
				next_q.pop_front();
			}
		}
		
		bfs();
	}
	
	cout<<area[x-1][y-1];
	
	return 0;
}

/*
boj.kr/18405

INPUT:
3 3
1 0 2
0 0 0
3 0 0
2 3 2

OUTPUT:
3
*/
