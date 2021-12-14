#include <iostream>
#include <string>

using namespace std;

int month[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
    int x, y;
    cin >> x >> y;
    int days = 0;
    for (int i = 0; i < x - 1; i++)
    {
        days += month[i];
    }
    days += y;
    cout << day[days % 7];
    return 0;
}