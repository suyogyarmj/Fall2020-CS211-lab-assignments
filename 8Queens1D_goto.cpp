//  Name: Rayamajhi,Suyogya
//  CS211 21F Lab4
//  8 Queens Program using 1 dimensional Array and goto
//  Idea: The idea is to place queens one by one in different columns, starting from the leftmost column. 
//  When we place a queen in a column, we check for clashes with already placed queens. 
//  In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. 
//  If we do not find such a row due to clashes then we backtrack and return false.

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	int q[8] ; // 1D array declaration
	int  c = 0; // Initializing Column Number
	q[0] = 0; // Placing Queens in the First Row/Column

nextCol: // Label for performing Operation from the next column
   c++;
   
   if (c > 7)
      goto print;

   q[c] = -1;

nextRow: // Label for performing Operation from the next row
   q[c]++;

   if (q[c] > 7)
      goto backtrack;

   for(int i=0;i<c;i++)
   { // Row & Diagonal Test
    	if ((q[c] == q[i])||((c - i) == (abs(q[c] - q[i])))){
         goto nextRow;
     	}
 	}

	goto nextCol;

backtrack: // Performing Backtrack
	c--;

	if (c < 0){
		return 0;
    }
	goto nextRow;

print: // Printing all the outputs
   cout <<""<< endl;
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
   
   // Printing the 2D Array 
    for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
	   		if(q[y] != x){
          		cout << 0 << " ";
			}
			else
			{
				cout << 1 << " ";
			}
  	 	}
   	cout <<""<< endl;
	}
   goto backtrack; // Goto backtrack again once the solution is printed
}
