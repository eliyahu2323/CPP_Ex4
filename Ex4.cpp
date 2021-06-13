

#include <iostream>
#include<string.h>
#include <string>
using namespace std;
bool is_peak(int  a[][5], int rows, int cols, int i, int j);
bool beforEqAfter(string str);
string diff(string a, string b);

int main()
{
	int menu;
	bool flag = true; //boolean variable for loop
	while (flag) {
		cout << "Menu:" << endl;
		cout << "Press:" << endl;
		cout << "0 for exit" << endl;
		cout << "1 for is peak" << endl;
		cout << "2 before equal to after" << endl;
		cout << "3 string different" << endl;
		cout << "Enter your choice:";
		cin >> menu; //get your choice from user

		switch (menu) {

		case 0: {//if menu == 0 you want exit
			cout << "Thank you for using the program" << endl;
			flag = false;
			break;
		}
		case 1: {
			int a[][5] = { {10,1,4,16,26},{5,12,5,14,12},{6,2,8,3,25},{12,4,5,12,10},{8,6,5,22,18} };
			int result = is_peak(a, 5, 5, 0, 3);//return 1 if true else false
			if ( result== 1) {
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
			break;
		}
		case 2: {
			string str;
			cout << "please enter string: ";
			cin >> str;
			if (beforEqAfter(str) == 0) {
				cout << "false\n";
			}
			else {
				cout << "true\n";

			}
		}
		case 3: {
			string str1;//string 1
			string str2;//string 2
			cout << "please enter string 1: ";
			cin >> str1;
			cout << "please enter string 2: ";
			cin >> str2;
			string stringReturn = diff(str1, str2);//save the letters do not appear
			if (stringReturn.empty() == true) {
				cout << "All the members of string a are in string b." << endl;
			}
			else{
			cout <<"The latters that do not appear are: "<<stringReturn<<endl;
		    }
		}
		}
	}

}


bool is_peak(int  a[][5], int rows, int cols, int i, int j) {
	//Loops that pass through all the neighbors of the given organ
	for (int m = i - 1; m <= i + 1; m++) {
		for (int n = j - 1; n <= j + 1; n++) {
			//A condition that checks that they do not exceed the limits of an array
			if (m >= 0 && m < rows && n >= 0 && n < cols) {
				//When you reach our organ we skip it
				if (m == i && n == j) {
					continue;
				}
				if (a[m][n] >= a[i][j]){//cheack if a[i][j]<=Neighbor if yes return false
					return false;
				}
			}
		}
	}
	return true;
}
		

bool beforEqAfter(string str) {
	int  index = str.find('.',1);//save where index contain point 
	//cout << index;
	string left = str.substr(0, index);//save left string
	string right = str.substr(index + 1, str.length());//save right string
	//cout << left.length() << "    " << right.length() << endl;
	//cheack if size left and right same
	if (right.length()==left.length()) {
		for (int i = 0; i < right.length(); i++) {//loop cheack if the string left and right same
			if (right[i]!= left[i]) {	
				return false;
			}
        }
		return true;
	}
	return false;
}

string diff(string a, string b) { 
	string retu ="";//string ezer for save the different leters
	for (size_t i = 0; i < a.length(); i++) {
		//check if the letter contain in b
		if (b.find(a[i]) == -1) {
			retu += a[i];
		}
	}
	return retu;



}
