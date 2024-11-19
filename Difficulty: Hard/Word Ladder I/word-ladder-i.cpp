//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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

template<class T>
void chmax(T & a, const T & b) { a = max(a, b); }
template<class T>
void chmin(T & a, const T & b) { a = min(a, b); }

void mergeWordArrays(vector<string>& arr, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    
    vector<string> leftSubArray(len1);
    vector<string> rightSubArray(len2);
    
    int idx = 0;
    while(idx < len1) {
        leftSubArray[idx] = arr[left + idx];
        idx++;
    }
    
    idx = 0;
    while(idx < len2) {
        rightSubArray[idx] = arr[mid + 1 + idx];
        idx++;
    }
    
    int i = 0, j = 0, k = left;
    
    while(i < len1 && j < len2) {
        arr[k] = (leftSubArray[i] <= rightSubArray[j]) ? leftSubArray[i++] : rightSubArray[j++];
        k++;
    }
    
    while(i < len1) {
        arr[k] = leftSubArray[i];
        i++;
        k++;
    }
    
    while(j < len2) {
        arr[k] = rightSubArray[j];
        j++;
        k++;
    }
}

void mergeSortWords(vector<string>& arr, int left, int right) {
    right > left ? (void)(mergeSortWords(arr, left, (left + right) / 2), 
                         mergeSortWords(arr, (left + right) / 2 + 1, right),
                         mergeWordArrays(arr, left, (left + right) / 2, right)) : void();
}

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        mergeSortWords(wordList, 0, wordList.size() - 1);
        
        set<string> uniqueWords;
        int wordListSize = wordList.size();
        
        int wordIdx = 0;
        while(wordIdx < wordListSize) {
            uniqueWords.insert(wordList[wordIdx]);
            wordIdx++;
        }
        
        int wordExistsCondition = (uniqueWords.find(targetWord) != uniqueWords.end()) ? 1 : 0;
        if(wordExistsCondition == 0) 
            return 0;
        
        queue<pair<string, int>> transformQueue;
        set<string> visitedWords;
        
        transformQueue.push({startWord, 1});
        visitedWords.insert(startWord);
        
        while(!transformQueue.empty()) {
            string currentWord = transformQueue.front().first;
            int currentLength = transformQueue.front().second;
            transformQueue.pop();
            
            if(currentWord == targetWord)
                return currentLength;
            
            int wordLength = currentWord.length();
            string modifiedWord = currentWord;
            
            int charIdx = 0;
            while(charIdx < wordLength) {
                char originalChar = modifiedWord[charIdx];
                
                char letterChar = 'a';
                while(letterChar <= 'z') {
                    modifiedWord[charIdx] = letterChar;
                    
                    int wordExistsFlag = (uniqueWords.find(modifiedWord) != uniqueWords.end()) ? 1 : 0;
                    int visitedFlag = (visitedWords.find(modifiedWord) == visitedWords.end()) ? 1 : 0;
                    
                    if(wordExistsFlag && visitedFlag) {
                        transformQueue.push({modifiedWord, currentLength + 1});
                        visitedWords.insert(modifiedWord);
                    }
                    
                    letterChar++;
                }
                
                modifiedWord[charIdx] = originalChar;
                charIdx++;
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends