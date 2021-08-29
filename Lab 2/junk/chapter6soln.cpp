#include <bits/stdc++.h>
using namespace std;

class timea
{
public:
    int hours, minutes, seconds;
    timea(int h = 0, int m = 0, int s = 0)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    void addfunction(timea a, timea b)
    {
        hours = (a.hours + b.hours) % 12 + (a.minutes + b.minutes) / 60;
        minutes = (a.minutes + b.minutes) % 60 + (a.seconds + b.seconds) / 60;
        seconds = (a.seconds + b.seconds) % 60;
    }
};

int main()
{
    timea t1(10, 5, 30);
    timea t2(2, 4, 16);
    timea t3;
    t3.addfunction(t1, t2);
    t3.display();
    //cout
}
