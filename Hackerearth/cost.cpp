/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
        int num;
        cin >> num;                                                     
                        // Reading input from STDIN
        cout << "Input number is " << num << endl;              // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

// #include <iostream>
// using namespace std;

// int main()
// {
//     short int t;
//     cin >> t;
    
//     while(t > 0)
//     {
//         t--;
        
//         int n;
//         cin >> n;
        
//         int arr[n];
//         for(int i = 0; i < n; i++)
//             cin >> arr[i];
        
//         int count = 0;
            
//         if(arr[0] != -1)
//         {
//             count++;
//             arr[0] = -1;
//         }
//         if(arr[n-1] != +1)
//         {
//             count++;
//             arr[n-1] = +1;
//         }
        
//         int freq[] = {0, 0};
//         for(int i = 1; i < n-1; i++)
//             if(arr[i] == -1)
//                 freq[0]++;
//             else
//                 freq[1]++;
                
//         if(freq[0] == 0 || freq[1] == 0) //If none of other, don't need any changes
//         {
//             cout << count << endl;
//             continue;
//         }
        
//         int type = 0;
//         if(freq[0] <= freq[1])
//             type = -1;
//         else
//             type = +1;
            
        
//         cout << "Freq " << freq[0] << ' ' << freq[1] << endl;
//         cout << "Type " << type << endl;
            
//         if(type < 0) //left end
//         {
//             // cout << "Left end" << endl;
            
//             for(int i = 1; i < n-1; i++)
//             {
//                 if(arr[i] == type && arr[i-1] != type)
//                 {
//                     arr[i] *= -1;
//                     count++;

//                     /*for(int i = 0; i < n; i++)
//                      cout << arr[i] << ' ';
//                      cout << endl;*/
//                 }
//             }
//         }
//         else if(type > 0)
//         {
//             // cout << "Right end" << endl;
            
//             for(int i = n-2; i > 0; i--)
//             {
//                 if(arr[i] == type && arr[i+1] != type)
//                 {
//                     arr[i] *= -1;
//                     count++;

//                     /*for(int i = 0; i < n; i++)
//                      cout << arr[i] << ' ';
//                      cout << endl;*/
//                 }
                
//                 /*for(int i = 0; i < n; i++)
//                     cout << arr[i] << ' ';
//                 cout << endl;*/
//             }
//         }
        
//         cout << count << endl;
        
//         for(int i = 0; i < n; i++)
//             cout << arr[i] << ' ';
//         cout << endl;
//     }
    
//     return 0;
// }

#include <iostream>
#include <climits>
using namespace std;

void in(int* n)
{
        scanf("%i", n);
}

int out(int n)
{
        printf("%i\n", n);
}

int main()
{
        int t;
        in(&t);

        while(t > 0)
        {
                t--;

                int n;
                in(&n);

                int *arr = (int*) malloc(sizeof(int)*n);
                int *costup = (int*) malloc(sizeof(int)*n);      //flipping all to up except first from right to i
                int *costlow = (int*) malloc(sizeof(int)*n); //flipping all to low except last from left to i

                for(int i = 0; i < n; i++)
                        in(arr+i);

                costlow[0] = 0;
                if(arr[0] != -1)
                {
                        arr[0] = -1;
                        costlow[0] = 1;
                }
                costup[n-1] = 0;
                if(arr[n-1] != 1)
                {
                        arr[n-1] = 1;
                        costup[n-1]=1;
                }

                //Calculate costlow
                for(int i = 1; i < n-1; i++)
                {
                        costlow[i] = costlow[i-1];
                        if(arr[i] > 0)
                                costlow[i]++;
                }

                //Calculate costup
                for(int i = n-2; i > 0; i--)
                {
                        costup[i] = costup[i+1];
                        if(arr[i] < 0)
                                costup[i]++;
                }

                int min = INT_MAX;

                //Possible flip point
                for(int i = 1; i < n; i++)
                        if((costlow[i-1] + costup[i]) < min)
                                min = (costlow[i-1] + costup[i]);

                out(min);

                free(arr);
                free(costup);
                free(costlow);  //I'll figure it out. I'll make it.

        }

        return 0;
}

