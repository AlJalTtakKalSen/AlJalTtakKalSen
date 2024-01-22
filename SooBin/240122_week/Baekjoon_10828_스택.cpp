#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
#include<string>
#include<sstream>

#define MAX 9999999

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;

    int N;
    cin >> N;
    string command;
    for (int i = 0; i < N; i++)
    {
        cin >> command;
        if (command == "push")
        {
            int num;
            cin >> num;
            s.push(num);

        }
        else if (command == "pop")
        {
            if (s.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (command == "size")
        {
            cout << s.size() << endl;
        }
        else if (command == "empty")
        {
            if (s.empty()) {
                cout << 1 << endl;
            } 
            else
            {
                cout << 0 << endl;
            }
        }
        else if (command == "top")
        {
            if (s.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << s.top() << endl;
            }
        }
    }

    return 0;
}
