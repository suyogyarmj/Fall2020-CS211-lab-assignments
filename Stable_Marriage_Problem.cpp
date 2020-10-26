//  Name: Rayamajhi,Suyogya
//  CS211 21F Lab7
//  Stable Marriage Using Backtracking
//  Definition: The Stable Marriage Problem states that given N men and N women, 
//  where each person has ranked all members of the opposite sex in order of preference, 
//  marry the men and women together such that there are no two people of opposite sex 
//  who would both rather have each other than their current partners. 
//  If there are no such people, all the marriages are “stable”

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) 
{
    //Preference arrays
    static int mp[3][3] = { {0,2,1},  // Preferences for Man#0
                            {0,2,1},  // Preferences for Man#1
                            {1,2,0}   
                          }; // Preferences for Man#2
    
    static int wp[3][3] = { {2,1,0},  // Preferences for Woman#0
                            {0,1,2},  // Preferences for Woman#1
                            {2,0,1}
                          }; // Preferences for Woman#2

    for(int i = 0; i < c; i++)
    { //Check if Woman 'i' has been asssigned to a Man
        if(q[i] == q[c])
            return false;
    }

    for(int i = 0; i < c; i++)
    { //Check men's preferences i.e. If Man 'i' likes Woman 'c' OR if Man 'i' likes Woman 'i'
        if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) 
            return false;
    }

    for(int i = 0; i < c; i++)
    {
        if(wp[q[i]][c] < wp[q[i]][i] && mp[c][q[i]] < mp[c][q[c]])
            return false;
    }

return true;
}

void print(int q[]) 
{
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}

void next(int q[], int c) 
{
   if (c == 3)
      print(q);
   else for (q[c] = 0; q[c] < 3; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() 
{
   int q[3];
   next(q, 0);
   return 0;
}
