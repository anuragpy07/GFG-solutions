//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional> 
#include <unordered_map>
using namespace std;  
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl; 
#define REP(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<=(b);i++) 
#define FORD(i,a,b) for(int i=(a);i>=(b);i--) 
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; } 
 
const int INF = 1<<29; 
typedef long long ll; 
 
inline int two(int n) { return 1 << n; } 
inline int test(int n, int b) { return (n>>b)&1; } 
inline void set_bit(int & n, int b) { n |= two(b); } 
inline void unset_bit(int & n, int b) { n &= ~two(b); } 
inline int last_bit(int n) { return n & (-n); } 
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; } 
 
template<class T> void chmax(T & a, const T & b) { a = max(a, b); } 
template<class T> void chmin(T & a, const T & b) { a = min(a, b); } 

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache_list;
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;

public:
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
        return cache_map.find(key) != cache_map.end() ? 
            (moveToFront(key), cache_map[key]->second) : -1;
    }
    
    void set(int key, int value) {
        while(cache_map.find(key) != cache_map.end()) {
            cache_list.erase(cache_map[key]);
            cache_map.erase(key);
        }
        
        while(cache_list.size() >= capacity) {
            cache_map.erase(cache_list.back().first);
            cache_list.pop_back();
        }
        
        cache_list.push_front({key, value});
        cache_map[key] = cache_list.begin();
    }
    
private:
    void moveToFront(int key) {
        pair<int, int> node = *cache_map[key];
        cache_list.erase(cache_map[key]);
        cache_list.push_front(node);
        cache_map[key] = cache_list.begin();
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends