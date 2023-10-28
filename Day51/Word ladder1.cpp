#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char it = 'a'; it <= 'z'; it++){
                    word[i] = it;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;
    
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int steps = solution.ladderLength(beginWord, endWord, wordList);
    
    if (steps > 0) {
        cout << "Shortest transformation sequence length: " << steps << endl;
    } else {
        cout << "No transformation sequence found." << endl;
    }

    return 0;
}
