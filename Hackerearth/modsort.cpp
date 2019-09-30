#include <iostream>
using namespace std;
#define endl '\n'

int* temp;

void modSort(int* a, int k, int l, int r) {

        //Modified merge sort using mod values to order each element
        if(r <= l)
                return;

        int mid = (l+r)/2;

        //Return sorted halves
        modSort(a,k,l,mid);
        modSort(a,k,mid+1,r);

        //Merging sorted halves
        int li = l, ri = mid+1, cap = (r-l+1);
        
        int t = 0;

        while(t < cap) {

                if(li == mid+1) {//Left half merged

                        while(t < cap)
                                temp[t++] = a[ri++];
                }

                else if(ri == r+1) {//Right half merged

                        while(t < cap)
                                temp[t++] = a[li++];
                }


                if(a[li]%k <= a[ri]%k) { //Equality for stable sort, as processing left to right and so the li points to the element which came before
                        temp[t++] = a[li++];
                }
                else {
                        temp[t++] = a[ri++];
                }
        }

        for(int i = l; i <= r; i++)
                a[i] = temp[i-l];

}

int main() {

        int n, k;
        cin >> n >> k;

        int a[n];
        temp = (int*) malloc(sizeof(int)*n);
        for(int i = 0; i < n; i++)
                cin >> a[i];

        modSort(a,k,0,n-1);

        for(int val : a)
                cout << val << ' ';

        cout << endl;

        return 0;
}

