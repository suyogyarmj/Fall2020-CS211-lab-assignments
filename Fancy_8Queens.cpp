/  Name: Rayamajhi,Suyogya
//  CS211 21F Lab8
//  Eight Queens with “Fancy Print” Chessboard
//  Idea: I augmented the 1 dimensional no go-to version of 8 Queens with 2 boxes array wq and bq.
//  Rest was done as per the instrucitons provided in the assignment page

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c)
{
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

void print(int q[])
{
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];   // box defined as a char data type i.e. 5x7 2D array
   box bb, wb, *board[8][8]; // bb represents black boards whereas wb represents white boards
                             // Both are 5x7 box type arrays. Board is represented by 8x8 pointer array.


   // Chessboard contains many pointers to the same box. We fill up the wq and bq arrays

   for (i=0; i<5; i++)
      for (j=0; j<7; j++)
      {
         bb[i][j] = ' ';
         wb[i][j] = char(219);
      }

   // bq and wq boxes are created to represent queens in respective black and white positions in the 2D array

   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };

   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

   // We fill the board 2D array with pointers to bb & wb in alt-positions

   for(i=0; i<8; i++)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;

   // Each solution is set up on the chessboard by placing pointers to bq & wq in respective squares
   // Place black Queens on white and white Queens on black squares. To see them in the print

   for(i=0; i<8; i++)
      if((i+q[i])%2 == 0)
         board[q[i]][i] = &bq;
      else
         board[q[i]][i] = &wq;

   cout << "Solution #" << ++solution << ":\n ";

   // upper border print

   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   for (i=0; i<8; i++)          // board row
      for (k=0; k<5; k++)
      {     // box row
         cout << char(179);
         for (j=0; j<8; j++)    // board column
            for (l=0; l<7; l++) // box column

               // board[i][j] is the box pointer in the ith row, jth column of the board.
               // *board[i][j] is the box being pointed to.
               // (*board[i][j])[k][l] is the kth row, lth column of the box.

               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      }

   // Lower border print

   cout << " ";
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}

void next(int q[], int c)
{
   if (c == 8)
      print(q);
   else for (q[c] = 0; q[c] < 8; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main()
{
   int q[8];
   next(q, 0);
   return 0;
}
