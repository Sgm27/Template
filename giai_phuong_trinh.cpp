#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int delta = b * b - 4 * a * c;

    if (delta < 0) {
        cout << "null" << endl;
    }
    else if (delta == 0) {
        int x = -b / (2 * a);
        cout << x << endl;
    }
    else {
        int x1 = (-b + sqrt(delta)) / (2 * a);
        int x2 = (-b - sqrt(delta)) / (2 * a);
        cout << max(x1, x2) << endl << min(x1, x2) << endl;
    }

    return 0;
}