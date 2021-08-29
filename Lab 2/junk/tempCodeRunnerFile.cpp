#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> stack1;
    int cars;
    cin >> cars;
    int array[cars];
    for (int i = 0; i < cars; i++)
    {

        cin >> array[i];
    }
    int passable = 1, i = 0;
    while (i < cars)
    {
        if (array[i] == passable) //car found in the main road
        {
            i++;
            passable++;
        }
        else if (stack1.empty() == 0)
        {
            if (stack1.top() == passable)
            {
                stack1.pop();
                passable++;
            }
            else if (stack1.top() < array[i])
            {
                cout << "NO1" << endl;
                return 0;
            }
            else if (stack1.top() > array[i])
            {
                stack1.push(array[i]);
                i++;
            }
        }
        else
        {
            stack1.push(array[i]);
            i++;
        }
    }
    cout << "YES" << endl;
}