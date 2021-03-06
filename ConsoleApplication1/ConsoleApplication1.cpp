
#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const char lookUpTable[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
string baseconverter(int, int);

string baseconverter(int base_in, int convertee)
{
	string res;
	do {

		int basetableindex = convertee % base_in;
		res = lookUpTable[basetableindex];

		convertee /= base_in;
		if (convertee == 0)
			return(res);
		else
			res.append(baseconverter(base_in, convertee));
		return(res);

	} while (convertee != 0);


}

int main()
{

	int base_in;
	int convertee;
	int n = 0;
	while (n == 0) {
		cout << "Select a base between 1-61 \n";
		cin >> base_in;

		cout << "Pick a number less than 2147483647\n";
		cin >> convertee;


		string final = baseconverter(base_in, convertee);
		std::reverse(final.begin(), final.end());
		cout << "Converted number: " << final << endl;
		cout << "do you want to convert another number? 0=y 1=n \n";
		cin >> n;
	}
	return 0;
}

