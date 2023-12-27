#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> num;        
string s1, s2;
vector<int> split(const string& input) {
    vector<int> ret;
    stringstream ss(input.substr(1, input.length() - 2)); // 대괄호 제거
    string token;

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            ret.push_back(stoi(token));
        }
    }
    return ret;
}
int main(){
    cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
    // 1. 입력받기
    cin >> t;
    while(t--){
        // 초기화
        num.clear();
        int lp=0;
        cin >> s1 >> n >> s2;
        // 입력값 처리
        num = split(s2);
        int rp = n-1;
        bool reverse = false;
        // 2. 작업 수행
        for(int i=0;i<s1.length();i++){
            if (lp>rp+1) {
                break;
            }
            if (s1[i]=='R'){
                reverse = !reverse;
            } 
            else if(s1[i]=='D'){
                if(reverse){
                    rp--;
                } else lp++;
            }
        }
        if(lp>rp+1){
            cout << "error" << "\n";
        } 
        else{
            // 정답 출력
            cout << "[";
            if (lp==rp+1);
            else if(reverse){
                for (int i=rp;i>lp;i--) cout << num[i] << ",";
                cout << num[lp];
            }
            else{
                for (int i=lp;i<rp;i++) cout << num[i] << ",";
                cout << num[rp];
            } 
            cout << "]\n";
        }
    }
}