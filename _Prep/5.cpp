#include <iostream>
#include <string>
using namespace std;

//prototype
string operator-(string, const string &);

int main()
{
    string a = "Alvee chodu";
    string b = "chodu";
    cout << a - b << endl;
}

string operator-(string firstOp, const string &secondOp)
{
    //test if the firstOp contains the secondOp
    if (firstOp.find(secondOp) != string::npos)
    {
        //erase the secondOp of the firstOp
        firstOp.erase(firstOp.find(secondOp), secondOp.length());
    }
    return firstOp;
}

//Output: "llo World"
