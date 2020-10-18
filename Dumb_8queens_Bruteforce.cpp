//
//  Name: Rayamajhi,Suyogya
//  CS211 21F Lab3
//  Dumb 8 Queens Program using 1 dimensional Array
//  Idea: We generate all possible configurations of Queens on the board
//  This solution prints all the 92 possible solutions. 
//  In the solutions 'Q'represent Queens and '0' represent empty spaces

#include<iostream>
#include<cmath>
using namespace std;

int count=0;

bool ok(int q[]) // ok function that checks the condition of row and column using nested loops
{
        for (int c = 1; c < 8; c++)
        {
                for(int i = 0; i < c; i++)
                {
                        if (q[i] == q[c] || c-i == abs(q[c]-q[i]))
                        {
                        return false;
                        }
                }
        }
        return true;
}
void print(int q[]) // print function to print all the possible solutions
{
        cout<<"Solution: " << ++count <<endl;
  for (int r = 0; r < 8; r++)
  {
                for (int c = 0; c < 8; c++)
                {
                        if (r == q[c])
                             {
                                cout << " Q ";
                        }
                        else
                        {
                                cout << " 0 ";
                        }
                }
                cout << endl;
        }
}
        int main(){ // main function that uses 8 nested loops for each solutions
        int q[8];
        for(int i0=0;i0<8;i0++)
                for(int i1=0;i1<8;i1++)
                        for(int i2=0;i2<8;i2++)
                                for(int i3=0;i3<8;i3++)
                                        for(int i4=0;i4<8;i4++)
                                                for(int i5=0;i5<8;i5++)
                                                        for(int i6=0;i6<8;i6++)
                                                                for(int i7=0;i7<8;i7++){
                                                                        q[0]=i0;
                                                                        q[1]=i1;
                                                                        q[2]=i2;
                                                                        q[3]=i3;
                                                                        q[4]=i4;
                                                                        q[5]=i5;
                                                                        q[6]=i6;
                                                                        q[7]=i7;
                                                                        if(ok(q))print(q); //calling 'ok' and 'print' functions
                                                                        }
}
                                                                 
