#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
	string str;
	cin >> str;

	bool answer = true;

	int numP = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			numP++;
			continue; 
		}
		else {
			if (numP >= 2 && str[i + 1] == 'P') {
				numP--;
				i++;
			}
			else {
				answer = false;
			}
		}	
	}
	if (numP != 1) {
		answer = false;
	}

	if (answer) {
		cout << "PPAP";
	}
	else {
		cout << "NP";
	}

	return 0;
}