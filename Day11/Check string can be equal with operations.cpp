#include <bits/stdc++.h>
using namespace std;

bool checkStrings(string s1, string s2) {
        int n = s1.size();
        if(s1 == s2) return true;
        string str1;
        string str2;
        string str3;
        string str4;
        
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                str1.push_back(s1[i]);
                str2.push_back(s2[i]);
            }
            else{
                str3.push_back(s1[i]);
                str4.push_back(s2[i]);
            }
        }
        sort(begin(str1), end(str1));
        sort(begin(str2), end(str2));
        sort(begin(str3), end(str3));
        sort(begin(str4), end(str4));
        
        if(str1 == str2 and str3 == str4){
            return true;
        }
        
        return false;
        
    } 

int main()
{
    string s1 = "abcdba", s2 = "cabdab";
    
    bool ans = checkStrings(s1, s2);
    if(ans){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}
