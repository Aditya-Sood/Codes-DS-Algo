#include <iostream>
using namespace std;

class Stack
{
    int top;
    int stk[INT_MAX];
    
    public:
    
    Stack() { top = -1; }
    
    void push(int ele)
    {
        if(top >= INT_MAX)
        {
            cout << "Stack Overflow\n";
            return;
        }
        
        top++;
        stk[top] = ele;
    }
    
    int peek()
    {
        return stk[top];
    }
    
    int pop()
    {
        if(top < 0)
        {
            cout << "Empty Stack\n";
            return;
        }
        
        return stk[top--];
    }
    
    int iter()
}

int main() {
	
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int j = 0; j < n; j++)
	        cin >> arr[j];
	        
	    Stack stack = new Stack();
	    
	    stack.push(-1);
	    int lge = -1;
	    for(int k = n-2; k >= 0; k--)
	    {
	        if(arr[k] >= arr[k+1])
	        {
	            if(arr[k] < stack.peek())
	            {
	                stack.push(stack.peek());
	            }
	            
	            else if(arr[k] >= stack.peek())
	            {
	                //Iterate through list of nge, assign -1 if none.
	            }
	        }
	        else if(arr[k] < arr[k+1])
	        {
	            stack.push(arr[k+1]);
	        }
	        
	    }
	    
	}
	
	return 0;
}