// 1759 암호 만들기

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

vector<char> v;
vector<char> password;
int L, C;

void f(int index, int count) {
    if (count == L) {
        int vowel = 0;
        int consonant = 0;
        for (int i = 0; i < password.size(); i++) {
            if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') {
                vowel++;
            }
            else {
                consonant++;
            }

        }
        if (vowel >= 1 && consonant >= 2) {
            for (int i = 0; i < password.size(); i++) {
                cout << password[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = index; i < v.size(); i++) {
        password.push_back(v[i]);
        f(i + 1, count + 1);
        password.pop_back();
    }
    return;
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());

    f(0, 0);

    return 0;
}
