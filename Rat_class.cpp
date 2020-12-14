//  Name: Rayamajhi,Suyogya
//  CS211 21F Lab11
//  Rat class Assignment

#include <iostream>
#include <cmath>
using namespace std;

class Rat
{
private:
   int n;
   int d;
   
public: // defining constructors
   
   // default constructor
   Rat()
   {
      n=0;
      d=1;
   }
   
   // 2 parameter constructor
   Rat(int i, int j)
   {
      n=i;
      d=j;
   }
   
   // conversion constructor
   Rat(int i)
   {
      n=i;
      d=1;
   }
   
   //accessor get-set functions
   int getN(){ return n;}
   int getD(){ return d;}
   
   void setN(int i){ n=i;}
   void setD(int i){ d=i;}
   
   //arithmetic operators
   Rat operator+(Rat r)
   {
      Rat t;
      t.n = n * r.d + d * r.n;
      t.d = d * r.d;
      simplify(t);
      return t;
   }
   
   // writing the other operators - * / 
   Rat operator-(Rat r)
   {
      Rat t;
      t.n = n * r.d - d * r.n; //numerator
      t.d = d * r.d; //denominator
      simplify(t);
      return t;
   }
   
   Rat operator*(Rat r)
   {
      Rat t;
      t.n = n * r.n; // multiplication
      t.d = d * r.d;
      simplify(t);
      return t;
   }
   
   Rat operator/(Rat r)
   {
      Rat t;
      t.n = n * r.d;
      t.d = d * r.n;
      simplify(t);
      return t;
   }
   
   
   // Reduce Rat using a function
   // Denominator should be positive
   void simplify(Rat &t) 
    {
        int theGCD = t.gcd(t.getN(), t.getD());
        t.n /= theGCD;
        t.d /= theGCD;
    }
   
   void improperFraction(Rat &t) 
   {
        if (t.getN() > t.getD()) 
        {
            t.n%=t.d;
        }
    }
      
   // Calculate the Highest Common Factor
   int gcd(int n, int d)
   {
      return d == 0 ? n : gcd(d, n%d);
   }

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
}; 

ostream& operator<<(ostream& os, Rat r)
{
   
   if(r.n==r.d)
   	os<<1;
   		   
   else if(r.n%r.d == 0)
    os<<(r.n)/(r.d);  
	
   else if(r.n == 0)
   	os<<0;	 	
   	
   else if(r.n>r.d)
   {
   	int whole;
   	int partial;
   	whole = r.n/r.d;
   	partial = r.n - (whole) * r.d;
   	os<<whole<< " " <<partial << "/" << r.d;
   }	
   
   else
   	os<<r.n<<"/"<<r.d;
      
   return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat it has access to its private sections.
istream& operator>>(istream& is, Rat& r)
{
   is >> r.n >> r.d;
   return is;
}

int main() 
{
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   return 0;
}
