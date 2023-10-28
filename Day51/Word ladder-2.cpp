#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> sequences;
        queue<vector<string>> q;
        q.push({beginWord});

        int level = 0;

        while (!q.empty()) {
            int currentLevelSize = q.size();
            unordered_set<string> usedLevel;

            for (int i = 0; i < currentLevelSize; i++) {
                vector<string> path = q.front();
                q.pop();

                string currentWord = path.back();

                for (int j = 0; j < currentWord.size(); j++) {
                    string originalWord = currentWord;

                    for (char c = 'a'; c <= 'z'; c++) {
                        currentWord[j] = c;

                        if (wordSet.count(currentWord) > 0) {
                            path.push_back(currentWord);
                            usedLevel.insert(currentWord);

                            if (currentWord == endWord) {
                                sequences.push_back(path);
                            } else {
                                q.push(path);
                            }

                            path.pop_back();
                        }
                    }

                    currentWord = originalWord;
                }
            }

            for (const string& word : usedLevel) {
                wordSet.erase(word);
            }

            level++;
            if (!sequences.empty()) {
                break;  // We found the shortest sequences
            }
        }

        return sequences;
    }
};

int main() {
    Solution solution;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = solution.findSequences(beginWord, endWord, wordList);

    for (const vector<string>& seq : result) {
        for (const string& word : seq) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
