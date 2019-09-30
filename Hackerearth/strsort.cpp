#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

bool comp(char a, char b) {
        return (a > b);
}

int main() {

        int t;
        cin >> t;

        string ip;
        int m,n;
        while(t > 0) {
                t--;

                cin >> ip >> m >> n;

                /*for(int i = m+1; i <= n; i++) {
                        int j = i-1, val = ip[i];
                        while(j >= m && ip[j] < val) {
                                ip[j+1] = ip[j];
                                j--;
                        }

                        ip[j+1] = val;
                }*/

                sort(&ip[0]+m, &ip[0]+n+1, comp);

                cout << ip << endl;
        }

        return 0;
}

