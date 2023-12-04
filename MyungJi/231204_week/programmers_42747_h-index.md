# 일반 풀이
```c++
#include <bits/stdc++.h>

using namespace std;
int indexH;
int solution(vector<int> citations) {
    int answer = 0;
    //1. 정렬
    sort(citations.begin(), citations.end());
    //2. 최대 논문수 세기
    for (int h=0;h<citations[citations.size()-1];h++){
        int cnt=0;
        for(int c:citations){
            if(c>=h) cnt++;
        }
        if(cnt>=h){
            indexH = h;    
        }
        else break;
        
    }
    return indexH;
}
```

# 잘 알려진 풀이(인덱스 사용)
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] < i + 1) {
            return i;
        }
    }

    return citations.size();
}
```
