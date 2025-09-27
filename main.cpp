// main.cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello, Cursor!" << endl;

    vector<int> nums = {1, 2, 3, 4, 5};
    for (const auto &num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}