//
//  Name: Rayamajhi,Suyogya
//  CS211 21F Lab3
//  Dumb 8 Queens Program using 1 dimensional Array
//  Idea: We generate all possible configurations of Queens on the board
//  This solution prints all the 92 possible solutions

#include <cmath>
#include <iostream>
using namespace std;

bool ok(int b[8][8])
{
    
    int i, r, c; // Initializing variables
    
    for(c=0; c<8; c++)
    {
        r=0;
        while(b[r][c]!=1) // Finding the first Queen in the problem
        r++; 
        for(i=0;i<c;i++)
        {// Row test: This loop checks if there are other Queens in the row
            if(b[r][i]==1) 
            return false;
        }
        
        for(i=1;((r-i)>=0 && (c-i)>=0);i++)
        {// UP-Diagonal test: This loop checks if there are other Queens in the UP-diagonal
            if(b[r-i][c-i]==1) return false;
        }
        
        for(i=1;((r+i)<8 && (c-i)>=0);i++)
        {// Down-Diagonal test: This loop checks if there are other Queens in the DOWN-diagonal
            if(b[r+i][c-i]==1) return false;
        }
    }
    return true;// If none of these loops/tests return false, we return true which means a solution had been found
};

void print(int b[8][8], int z)
{// Method to print out the double array
    
    cout<< z <<endl;
    
    for(int i=0;i<8;i++)
        {// Column loop
        for(int j =0;j<8;j++)
        {
            // Row loop
            cout << b[i][j];
        }
        cout << endl;
    }
    cout<< "done" <<endl;
};

int main()
{
    int board[8][8]={0};
    int count = 0; // 'count' variable keeps track of the loop iteration and hence the respective solution number
    for(int i0 = 0; i0 <8; i0 ++)
        for(int i1 = 0; i1 <8; i1 ++)
            for(int i2 = 0; i2 <8; i2 ++)
                for(int i3 = 0; i3 <8; i3 ++)
                    for(int i4 = 0; i4 <8; i4 ++)
                        for(int i5 = 0; i5 <8; i5 ++)
                            for(int i6 = 0; i6 <8; i6 ++)
                                for(int i7 = 0; i7 <8; i7 ++)
                                {
                                    board[i0][0]=1;
                                    board[i1][1]=1;
                                    board[i2][2]=1;
                                    board[i3][3]=1;
                                    board[i4][4]=1;
                                    board[i5][5]=1;
                                    board[i6][6]=1;
                                    board[i7][7]=1;
                                    // We use the loop iteration to setup the array board structure
                                    
                                    // If the array structure obtained is conflict free we print the board and the respective structure
                                    
                                    if(ok(board))
                                    {
                                        print(board, ++count); // printing the solution board
                                    }
                                    
                                    for(int g=0;g<8;g++)
                                    {
                                        // Two loops to reset the board for each iteration
                                        
                                        for(int h = 0;h < 8; h++)
                                        {
                                            board[g][h] = 0;
                                        }
                                    }
                                }
    return 0;
}

