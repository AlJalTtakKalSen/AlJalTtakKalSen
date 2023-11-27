#include <bits/stdc++.h>
using namespace std;

// 문자열을 소문자로 바꿔주는 함수
string to_lower(string s) {
    string lower_str = "";
    for(char c: s) {
        lower_str += tolower(c);
    };
    return lower_str;
};

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> cache_vector;
    string cache_hit_city = "";
    
    string hit_city = "", lowercase_str = "";
    // 벡터 기준 맨 뒤가 최신, 앞이 이전
    for(string city: cities) {
        lowercase_str = to_lower(city);
        
            auto it = find(cache_vector.begin(), cache_vector.end(), lowercase_str);
        
        // 만약 캐시에 저장되어 있는 도시 중에 하나일 경우 벡터에서 제거 후 다시 push
        if(it != cache_vector.end() && cacheSize > 0) {
            cache_vector.erase(it);
            cache_vector.push_back(lowercase_str);
            answer++;
        } else {
                answer += 5;
                if(cacheSize > 0 ) {
                    if(cache_vector.size() >= cacheSize && !cache_vector.empty())
                    cache_vector.erase(cache_vector.begin());
            
                    cache_vector.push_back(lowercase_str);
                }

            };
    };
    
    return answer;
}