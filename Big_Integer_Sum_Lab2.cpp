//
//  Name: Rayamajhi,Suyogya
//  CS211 21F Lab2
//  Adding BIG Integers Upto 100 digits each
//  Idea: We reverse both strings and kept adding digits one by one from the 0th
//  index using the loop until the end of smaller string, sum % 10 is attached to
//  the end of result and the carryover is tracked by sum / 10. Result is reversed
//  to counter the previous reversal

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

string add(string a, string b){
    if (a.length() > b.length()) // we need to make sure 'b' is larger in length
        swap(a,b);
    
    string emp = ""; // empty string declaration for result storage
    
    int n1 = a.length(); // calculating length of both strings
    int n2 = b.length();
    
    reverse(a.begin(), b.end()); //both strings are reversed
    reverse(b.begin(), a.end());
    
    int carry = 0;
    
    for (int i=0; i<n1; i++){ // computing sum of current digits and the carryover
        
        int sum = ((a[i] - '0') + (b[i] - '0') + carry);
        emp.push_back(sum % 10 + '0');
        
        carry = sum / 10; // carry is calculated for the next step
    }
    
    for ( int i=n1; i<n2; i++){ // remaining digits for larger number is added
        int sum  = ((b[i]-'0') + carry);
        emp.push_back(sum%10 +'0');
        carry = sum/10;
    }
    
    if (carry) // adding remaining carry
        emp.push_back(carry + '0');
    
    reverse(emp.begin(), emp.end()); // resultant string is reversed
    
    return emp;
}

int main() {
    string x, y;
        cout << "Enter the first number: "; // asking for input
        cin >> x;
        cout << "\n";
        cout << "Enter the second number: ";
        cin >> y;
        cout << "\n";
    if ((x != "done") && (x.length() < 101) && (y.length() < 101)) { // setting up criterias
        string answer = add(x,y); // function call
        cout << add(x,y) <<"\n"; // result 1
    }
    else{
        cout <<"Invalid input size ( > 100) OR user terminated (done)" <<"\n"; // result 2
        
        return 0;
    }
}

