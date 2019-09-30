// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int w;
    TrieNode** next;
    
    TrieNode() : w(-1), next((TrieNode**) malloc(sizeof(TrieNode*)*26))  {
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string s, int w) {
    TrieNode* curr = root;
    for(int i = 0; i < s.length(); i++) {
        if(curr->next[s[i]-'a'] == NULL) {
            curr->next[s[i]-'a'] = new TrieNode();
        }
        
        curr = curr->next[s[i]-'a'];
        
        if(w > curr->w) {
            curr->w = w;
        }
    }
}

int bestMatch(TrieNode* root, string p) {
    // int best = -1;
    TrieNode* curr = root;
    for(int i = 0; i < p.length(); i++) {
        if(curr->next[p[i]-'a'] != NULL) {
            curr = curr->next[p[i]-'a'];
        } else {
            return -1;
        }
    }
    
    return curr->w;
}

int main() {
    
    TrieNode* root = new TrieNode();
    
    int n, q;
    cin >> n >> q;
    
    string s;
    int w;
    for(int i = 0; i < n; i++) {
        cin >> s >> w;
        insert(root, s, w);
    }
        
        
    for(int i = 0; i < q; i++) {
        cin >> s;
        cout << bestMatch(root, s) << endl;
    }
    
    return 0;
}

