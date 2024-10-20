#include <iostream>
#include <string>
using namespace std;

bool check_number(string s) {
    int count_4 = 0, count_7 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '4') count_4++;
        else if (s[i] == '7') count_7++;
        else return false;
    }
    return count_4 == count_7;
}

int main() {
	freopen("thu.inp","r",stdin);
    string n;
    cin >> n;
    int num = stoi(n);
    while (!check_number(to_string(++num)));
    cout << num << endl;
    return 0;
}
