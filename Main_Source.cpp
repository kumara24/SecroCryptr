#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>
#include "supportFunctions.h"

using namespace std;

int main()
{
	srand(time(0));
	bool again = true;

	while (again) {
		int length;
		int b, count, j = 0, a;
		string word; 
		int matr[1000]; 
		string againResp;

		int key[3][3];
		int inv[3][3] = { 0 }; 

		int ciph[1000] = { 0 };  

		system("CLS");
		cout << "\t\t----------------------------------------------------" << endl;
		cout << endl;
		cout << "\t\t		     SECROCRYPTR                " << endl;
		cout << endl;
		cout << "\t\t     The One Stop Program for Absolute Privacy         " << endl;
		cout << "\t\t        Created and Coded by Avinash Kumar" << endl;
		cout << endl;
		cout << "\t\t----------------------------------------------------\n" << endl;

		string resp;
		bool tryAgain = true;
		while (tryAgain) {
			cout << "\nWould you like to encrypt (1) or decrypt (2): ";
			cin >> resp;
			if (resp == "1" || resp == "2")
				tryAgain = false;
		}

		string filename;
		cout << "\nEnter a filename: ";
		cin >> filename;

		
		if (resp == "1") {
			cin.ignore();
			int determ = 0;
			while (determ != 1) 
			{
				for (int y = 0; y < 3; ++y)
					for (int z = 0; z < 3; ++z)
						key[y][z] = ((rand()) % 100) + 1;

				determ = determinant(key);
			} 

			invert(key, inv); 

			cout << "\nEnter the message you want encrypted:" << endl;
			getline(cin, word);
			length = word.length();

			lettertonum(word, matr, length);

			addFiller(matr, length);

			ofstream outFile;
			outFile.open(filename);

			for (int y = 0; y < 3; ++y)
				for (int z = 0; z < 3; ++z)
					outFile << inv[y][z] << endl; 

			outFile << length << endl;
			matrixmult(key, length, matr, ciph);

			for (int d = 0; d < length; ++d) 
				outFile << ciph[d] << endl;

			outFile.close();
		}


		else if (resp == "2") {
			bool fileError = false;
			ifstream inFile;
			inFile.open(filename);

			if (inFile.fail()) {
				cout << "\nError! File was not found!" << endl;
				fileError = true;
			}
			if (!fileError) {   
				int ciph2[1000] = { 0 };
				int matr2[1000];
				int ikey[3][3]; 
				int y, z;
				for (y = 0; y < 3; ++y)     
					for (z = 0; z < 3; ++z)
						inFile >> ikey[y][z];

				char ans[1000]; 

				inFile >> length;
				for (int b = 0; b < length; ++b)    
					inFile >> matr2[b];

				inFile.close();

				matrixmult(ikey, length, matr2, ciph2);

				numtoletter(ciph2, ans, length); 

				cout << "\nDecrypted Message:\n\n";
				for (int g = 0; g < length; ++g)
					cout << ans[g];

				cout << "\n";
			}
		}

		tryAgain = true;
		while (tryAgain) {
			cout << "\nDo you want to continue (Y/N)? ";
			cin >> againResp;

			if (againResp == "y" || againResp == "Y")
			{
				again = true;
				tryAgain = false;
			}
			else if (againResp == "N" || againResp == "n")
			{
				again = false;
				tryAgain = false;
				cout << "Good bye!!!" << endl;
				cin.ignore();
			}
			else
				tryAgain = true;
		}
	}
}