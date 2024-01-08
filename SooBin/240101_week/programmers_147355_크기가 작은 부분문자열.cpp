#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i = 0; i < t.size() - p.size() + 1; i++){
        string temp = "";
        for(int j = 0; j < p.size(); j++){
            temp += t[i+j];
        }
        if(temp  <= p) answer++;
        temp = "";
    }
    return answer;
}