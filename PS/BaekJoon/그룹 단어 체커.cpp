#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    int N = 0;
    cin>>N;
    
    string str_list[N];
    int count = 0;
    
    for(int i=0; i < N; i++)
    {
        cin>>str_list[i];
    }
    
    for(int index = 0; index < N; index++)
    {
        string str = str_list[index];

        map<char, vector<int>> list;
        
        for(int i=0; i < str.length(); i++)
        {
            list[str[i]].push_back(i);
        }
    
        bool check = true;    
        for(auto x : list) {
            int val = x.second.at(0);
            
            for(auto it = x.second.begin() + 1; it < x.second.end(); it++)
            {
                if(*it - val != 1) {
                    check = false;
                    break;
                } else {
                    val = *it;
                }
            }
        }
        
        if(check) count++;
    }
    cout << count << endl;

    return 0;
}
