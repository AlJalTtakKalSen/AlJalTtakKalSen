#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string number[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string tempAnswer = "";
    string tempString = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] > 47 && s[i] < 58)
        {
            tempAnswer += s[i];
        }
        else 
        {
            tempString += s[i];
        }
        for(int j = 0; j < 10; j++)
        {
            if(number[j].compare(tempString) == 0)
            {
                tempAnswer += to_string(j);
                tempString = "";
            }
        }
    }
    
    answer = stoi(tempAnswer);
    
    return answer;
}