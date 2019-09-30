/* https://leetcode.com/problems/custom-sort-string/ */

class Solution {
public:
    string customSortString(string s, string t) {
        
        int tn = t.size();
        if(tn == 1) return t;
        
        int sn = s.size();
        
        vector<int> count(26, 0);
        
        for(char c : t)
        {
            count[c - 'a']++;
        }
        
        string res = "";
        
        for(int i = 0; i<sn; i++)
        {
            int k = count[s[i] - 'a'];
            
            for(int j = 1; j<=k; j++)
                res += s[i];
            
            count[s[i] - 'a'] -= k;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(count[i] != 0)
            {
                int k = count[i];
                char c = i + 'a';
                
                for(int j = 1; j<=k; j++)
                    res += c;
                
                count[i] = 0;
            }
        }
        
        return res;
    }
};

/*
class Solution {
public:
    string customSortString(string s, string t) {
        
        int sn = s.size();
        int tn = t.size();
        
        if(tn == 1) return t;
        
        int count[sn];
        for(int i = 0; i<sn; i++)
            count[i] = 0;
        
        string res = "";
        
        //Reduces complexity of locating character in the string S
        map<char,int> charLoc;
        
        for(int i = 0; i<sn; i++)
        {
            charLoc.insert(make_pair(s[i], i));
        }
        
        for(int i = 0; i < tn; i++)
        {
            auto itr = charLoc.find(t[i]);
            
            if(itr != charLoc.end())
            {
                count[itr->second]++;
            }
            else
                res += t[i];
        }
        
        for(int i = 0; i < sn; i++)
        {
            int k = count[i];
            if(k != 0)
            {
                for(int j = 1; j <= k; j++)
                    res += s[i];
            }
        }
        
        return res;
    }
};
*/

/*
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool compar(int a, int b)
{
    return (a<b);
}
    
string customSortString(string s, string t)
{    
    int n = t.length();
    if(n == 1)
        return t;
    
    map<char, int> charInt;
    map<int, char> intChar;
    
    
    for(int i = 0; i < s.length(); i++)
    {
        charInt.insert(make_pair(s[i], i));
        intChar.insert(make_pair(i, s[i]));
    }
    
    int tInt[n], len = 0;
    string res = "";
    
    for(int i = 0; i < n; i++)
    {
        auto itr = charInt.find(t[i]);
        
        if(itr != charInt.end())
        {
            cout << "Found " << t[i] << endl;
            tInt[len++] = itr->second;
        }
        else
        {
            cout << "Miss " << t[i] << endl;
            res += t[i];
        }
    }           
    
    cout << "\n###\n" << endl;

    sort(tInt, tInt+len, compar);

    cout << "Sorted order: ";
    for(int i = 0; i < len; i++)
    {
        auto itr = intChar.find(tInt[i]);
        cout << itr->second << " ";
    }
    cout << endl;
    
    for(int i = 0; i < len; i++)
    {
        auto itr = intChar.find(tInt[i]);
        
        if(itr != intChar.end())
        {
            cout << "Add " << itr->second << endl;
            res += itr->second;
        }
    }
    
    return res;
}

int main()
{
    string a, b;
    //cin >> a >> b;

    a = "qwert";
    b = "qwertktkprkekwvq";

    cout << customSortString(a, b) << endl;

    return 0;
}
*/