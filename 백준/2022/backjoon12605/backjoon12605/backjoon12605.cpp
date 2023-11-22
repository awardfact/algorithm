#include <string>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	vector<string> word;

	string tmp;
	string wordTmp;
	cin >> n;
	
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, tmp);
		word.push_back(tmp);
	}

	for (int i = 0; i != word.size(); i++) {

		tmp = "";
		wordTmp = "";
		for (int j = 0; j != word[i].length(); j++) {
			if (word[i].at(j) == ' ') {

				tmp = wordTmp + " " + tmp;
				wordTmp = "";
			}
			else {
				wordTmp += word[i].at(j);
			}

		}

		tmp = wordTmp + " " + tmp;
		cout << "Case #" << i + 1 << ": " << tmp << "\n";



	}


	return 0;
}


