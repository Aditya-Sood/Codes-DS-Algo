/* https://www.geeksforgeeks.org/sudoku-backtracking-7/ */
#include <iostream>
using namespace std;

int grid[9][9];

bool check(int a, int b)
{
    for(int i = 0; i < 9; i++) //Check col
    {
        if(i == a)  continue;
        
        if(grid[a][b] == grid[i][b])
            return false;
    }
    
    for(int i = 0; i < 9; i++) //Check row
    {
        if(i == b)  continue;
        
        if(grid[a][b] == grid[a][i])
            return false;
    }
    
    int sr = (a/3)*3, sc = (b/3)*3;
    
    for(int i = sr; i < sr+3; i++)
        for(int j = sc; j < sc+3; j++)
        {
            if(i == a && j == b) continue;
            
            if(grid[a][b] == grid[i][j])
                return false;
        }
        
    return true;
}

bool assign(int a, int b)
{
    if(a == 8 && b == 8) //last cell
        return true;
    
    if(b == 8)
    {
        a++;
        b = 0;
    }
    else
    {
        b++;
    }
    
    while(a != 8 && b != 8)
    {
        if(grid[a][b] == 0) break;
        
        if(b < 8)   b++;
        
        else if(b == 8 && a < 8)
        {
            a++; b = 0;
        }
    }
    
    if(grid[a][b] != 0)
        return true;
        
    for(int i = 1; i < 10; i++)
    {
        grid[a][b] = i;
        
        if(check(a, b))
        {
            if(assign(a, b))
                return true;
                
            else
            {
                grid[a][b] = 0;
                continue;
            }
        }
        else
        {
            grid[a][b] = 0;
            continue;   
        }
    }
    
    return false;
}

int main() {
    
    int t;
    cin >> t;
    
    for(; t > 0; t--)
    {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                cin >> grid[i][j];
                
        cout << assign(0, 0) << endl;
                
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                cout << grid[i][j] << " ";
        
        cout << endl;
        
    }
    
	//code
	return 0;
}

/*
3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0
3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9 
3 1 6 5 7 8 4 2 9 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0
*/