#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    stack<char> st1,st2;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != '#'){
            st1.push(s1[i]);
        } else if(!st1.empty() && s1[i] == '#'){
            st1.pop();
        } else if(st1.empty() && s1[i] == '#'){
            st1.push(s1[i]);
        }
    }

    for(int i = 0; i < s2.size(); i++){
        if(s2[i] != '#'){
            st2.push(s2[i]);
        } else if(!st2.empty() && s2[i] == '#'){
            st2.pop();
        } else if(st2.empty() && s2[i] == '#'){
            st2.push(s2[i]);
        }
    }

    if(st1.size() == st2.size()){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}