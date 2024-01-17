
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<stack>

#define MAX 9999999

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int *array = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    sort(array, array + N);

    int M;
    cin >> M;
    int temp;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        if (binary_search(array, array + N, temp))
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }
   
    delete[] array;

    return 0;
}
