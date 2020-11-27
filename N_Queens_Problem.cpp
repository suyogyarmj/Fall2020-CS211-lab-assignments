//  Name: Rayamajhi,Suyogya
//  CS211 21F Lab10
//  The n queens problem

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   for(int i = 1;i <= c; i ++)
   {
      if(q[c] == q[i-1] || q[c-i] == q[c]-i || q[c-i] == q[c]+i) //Check the conflict between the queens in columns i & c
         return false;
   }
   return true;
}

// "nqueens" function returns the number of solutions for given board size
int nqueens(int n)
{
   int* q = new int[n]; // Dynamic array declaration of size n with first element initialized to 0
   q[0] = 0;
   
   // Using backtracking to find the solutions (similar to 1D 8 Queens)
   int r = 0, c = 0, solutions = 0;

   while (c >= 0)
   {
       c++; // Moving to the next column
       if(c > n)
        {   // If you pass the last column, call the print function and backtrack
            solutions ++;
            c--;
            r = q[c]; // Else move to one before the first row
        }
       else
           r = -1;

    while (c >= 0)
    {
        r++;
        q[c] = r;  // Move to the next row

        if(r > n)
         {
            c --;
            r = q[c]; // If end of the column is passed we backtrack
         }

        else if(ok(q,c))
        {
            break;
        }
    }
   }
   
   // Delete the dynamically allocated array to prevent memory leak
        delete [] q;
        
   // Return the number of solutions
        return solutions;
}

int main()
{
   int n = 8;
   for (int i = 0; i < n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i+1 << " queens problem.\n";
   return 0;
}
