//  Name: Rayamajhi,Suyogya
//  CS211 21F Lab5
//  8 Queens Program using 1 dimensional Array and NO goto
//  Idea: The idea is to backtrack without using the goto but instead use the else-if loop
//  I also tried the numerical form of solution for this

#include <iostream>
#include <cmath>
using namespace std;

// True if queen in column c holds

bool ok(int q[], int c) 
{
   for(int i = 1;i <= c; i ++)
   { 
      if(q[c] == q[i-1] || q[c-i] == q[c]-i || q[c-i] == q[c]+i) //Check if conflict between Queens in columns i and c
         return false;
   }
   return true;
}
void print(int q[]) 
{
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   
   // Print Solution
   
   for(int i = 0; i < 8; i++)
      cout << q[i];

   cout << "\n";
}

int main() 
{
   int q[8]={0};    // Array initialization

   // First row and first column are the base case
   int r = 0, c = 0;

   while (c >= 0)
   {
                 
      c++;          // Next Column move
      if(c > 7)
      {             // Backtracking
         print(q);            
         c--;
         r = q[c];           
      }
      else
         r = -1;

      while (c >= 0) 
      {
         r++;
         q[c] = r;  // Next Row move

         if(r > 7)
         {
            c --;
            r = q[c];        
         }

         else if(ok(q,c))
         {   
            break;
         }                  // If true, reuturn to the beginning of the outer loop

      }
   }
   return 0;
}
