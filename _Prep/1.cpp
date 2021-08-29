#include <bits/stdc++.h>

using namespace std;
class person
{
public:
	person() {}
	person(const person &p1);
};
person::person(const person &p1)
{
	cout << "yeah" << endl;
}

person f1(person p1)
{
	person x(p1);
	person y = x;
	return y;
}
int main()
{
	person a;
	person b = f1(f1(a));
}
