#include<bits/stdc++.h>
using namespace std;
class LRUCache{
    public:
        int cap;

        list<pair<int,int>> dll;
        unordered_map<int,list<pair<int,int>>::iterator> mp;

        LRUCache(int capacity){
            cap = capacity;
        }

        int get(int key){
            if(mp.find(key) == mp.end()) return -1;

            auto it = mp[key];
            int val = it->second; 

            dll.erase(it); // dll se delete
            dll.push_front({key,val}); // front me add
            mp[key] = dll.begin(); // map update

            return val;
        }

        void put(int key,int value){

            // key already present h
            if(mp.find(key) != mp.end()){
                auto it = mp[key];
                dll.erase(it);

            }
            // cache full
            else if(dll.size() == cap){
                auto last = dll.back();
                mp.erase(last.first);
                dll.pop_back();
            }
            //insert new aur update it
            dll.push_front({key,value});
            mp[key] = dll.begin();
        }
};

int main(){
    LRUCache cache(4);

    cache.put(2,6);
    cache.put(4,7);
    cache.put(8,11);
    cache.put(7,10);

    cout<<cache.get(2)<<endl;
    cout<<cache.get(8)<<endl;

    cout<<cache.get(7)<<endl;

    cache.put(5,7);
}