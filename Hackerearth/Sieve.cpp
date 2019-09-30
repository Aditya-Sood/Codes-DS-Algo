#include <iostream>
using namespace std;

int main()
{
        int n;
        cin >> n;
        bool* prime = (bool*) malloc(sizeof(bool)*n);

        for(int i = 0; i < n; i++)
                prime[i] = true;        //initially all set to prime

        for(int i = 2; i*i < n; i++)
                for(int j = i; j*i < n; j++) //j=i because product with lower numbers already covered previously (when i={the lower number itself})
                        prime[i*j] = false;


        for(int i = 2; i < n; i++)
                if(prime[i])
                        cout << i << '\n';

}

