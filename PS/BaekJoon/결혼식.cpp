#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int>> list;
    set<int> my_friend;
    set<int> friends_friend;
    
    int n, m, a, b;
    cin>>n>>m;
    
    for(int i=0; i<m; i++) {
        cin>>a>>b;
        
        list.push_back(make_pair(a, b));
    }
    
    for(int i=0; i<list.size(); i++) {
        if(list[i].first == 1) my_friend.insert(list[i].second);
        else if(list[i].second == 1) my_friend.insert(list[i].first);
    }
    
    for(int i=0; i<list.size(); i++) {
        if(my_friend.find(list[i].first) != my_friend.end() && my_friend.find(list[i].second) == my_friend.end()) {
            if(list[i].second != 1) friends_friend.insert(list[i].second);
        } else if(my_friend.find(list[i].second) != my_friend.end() && my_friend.find(list[i].first) == my_friend.end()) {
            if(list[i].first != 1) friends_friend.insert(list[i].first);
        }
    }
    
    int total = my_friend.size() + friends_friend.size();
    cout<<total<<endl;

    return 0;
}

/*
boj.kr/5567

INPUT:
6
5
1 2
1 3
3 4
2 3
4 5

OUTPUT:
3
*/
