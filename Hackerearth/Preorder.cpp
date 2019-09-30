#include <bits/stdc++.h>
using namespace std;

void getPreorder(string &preord, vector<int> &start, vector<int> &last, vector<int> &val, vector<list<int>> &adj, int i) {
    preord.append(val[i]);
    start[i] = preord.size()-1;

    for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
        getPreorder(preord, last, val, adj, *it);
    }

    last[i] = preord.size()-1;
}

long long int getK(string &preord, vector<int> &start, vector<int> &last, int k) {
    long long int total = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = start[i]+1; j < last[i]; j++) {
            for(int l = j+1; l <= last[i]; l++) {
                if(preord[start[i]] + preord[j] + preord[l] >= k)
                    total++;
            }
        }
    }

    return total;
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> val(n+1);
    vector<list<int>> adj(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for(int i = 1, t; i <= n-1; i++) {
        cin >> t;
        adj[t].push_back(i+1);
    }

    vector<int> start(n+1);
    vector<int> last(n+1);
    string preord = "";
    getPreorder(preord, start, last, val, adj, 1);

    cout << getK(preord, start, last, k);

    return 0;
}

