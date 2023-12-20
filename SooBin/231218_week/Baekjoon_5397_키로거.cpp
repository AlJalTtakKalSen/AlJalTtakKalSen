#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <list>

using namespace std;

int main() {
    int T;
    cin >> T;

    string str;
    list<char>::iterator it;
    list<char> password;

    for (int i = 0; i < T; ++i) {
        cin >> str;
        password.clear();
        it = password.begin();

        for (int j = 0; j < str.length(); ++j) {
            if (str[j] == '<') {
                if (it != password.begin()) it--;
            }
            else if (str[j] == '>') {
                if (it != password.end()) it++;
            }
            else if (str[j] == '-') {
                if (it != password.begin()) it = password.erase(--it);
            }
            else {
                it = password.insert(it, str[j]);
                it++;
            }
        }

        for (char x : password) cout << x;
        cout << '\n';
    }
    return 0;
}