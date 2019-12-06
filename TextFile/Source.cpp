#include <iostream>
using namespace std;
#include <fstream>
#include <string>

void menu();
void write();
void readLines();
void readData();
void modify();
ofstream myFile; //Text file declaration


void main() {




	menu();
}

void menu() {
	int option = -1;
	while (option != 0) {

		cout << "\n";
		cout << "Menu" << "\n";
		cout << "1. Write to file" << "\n";
		cout << "2. Read file" << "\n";
		cout << "3. Modify file" << "\n";
		cout << "4. " << "\n";
		cout << "5. " << "\n";
		cout << "6. " << "\n";
		cout << "\n";

		cin >> option;
		cin.ignore();

		switch (option)
		{
		case 1:
			write();
			break;
		case 2:
			readData();
			break;

		case 3:
			modify();
			break;

		case 4:

			break;

		case 5:

			break;

		case 6:

			break;
		case 7:

			break;

		default:
			cout << "Opción invalida";
			break;
		}
	}
}

void write() {

	cout << "Please student id \n";
	string id;
	getline(cin, id);

	cout << "Please student name \n";
	string name;
	getline(cin, name);

	string line;
	line = id + " " + name;


	myFile.open("myFile.txt", fstream::app); //Open txt file in append mode
	// fstream::app allows to write to the file without overwritting it

	//Wirte to file
	if (myFile.is_open()) {
		myFile << line << "\n";
	}
	//Close file
	myFile.close();


	cout << "Saved to file! \n";
}


//Method allows to read every line form text file separately
void readLines() {


	ifstream myTxtFile("myFile.txt");// Declaration to read from existing file

	cout << "Text file data: \n";
	string line;
	if (myTxtFile.is_open()) {
		while (getline(myTxtFile, line)) {
			cout << line << "\n";
		}
	}
	else {
		cout << "File not open \n";
	}

}



//Method allows to read specific data from file
void readData() {

	//**********Text file data*******
	int id;
	string name;

	//********************************
	ifstream myTxtFile("myFile.txt");// Declaration to read from existing file

	cout << "Text file data: \n";

	if (myTxtFile.is_open()) {
		while (myTxtFile >> id >> name) {
			//The first word will be saved in id variable, then name variable
			cout << "Id: " << id << " Name: " << name << "\n";
		}
	}
	else {
		cout << "File not open \n";
	}

}


//Method allows to modify specific data from file
void modify() {
	cout << "Enter the id of the desired student \n";
	int desiredId;
	cin >> desiredId;
	cin.ignore();
	cout << "Enter the new name of the desired student \n";
	string newName;
	getline(cin, newName);

	//**********Text file data*******
	int id;
	string name;
	string sid;

	//********************************
	ifstream myTxtFile("myFile.txt");// Declaration to read from existing file: used to get all lines
	string line;
	string allData;
	if (myTxtFile.is_open()) {
		while (getline(myTxtFile, line)) {
			
			//get id
			string word;
			for (auto x : line)
			{
				if (x == ' ')
				{
					id = stoi(word);
					word = "";
					break;
				}
				else
				{
					word = word + x;
				}
			}

			//Check if line is not empry
			if (line != "") {
				//if id matches line should be modified
				if (id == desiredId) {
					cout << "Old data: " << "Id: " << id << " Name: " << name << "\n";
					cout << "Modified data: " << "Id: " << id << " Name: " << newName << "\n";
					string sid = to_string(id);
					allData += sid + " " + newName + "\n";;
				}
				else {

					allData += line + "\n";
				}
			}
		}
	}
	else {
		cout << "File not open \n";
	}

	//re write file with updated data
	myFile.open("myFile.txt"); //Open txt file without append mode
	//Wirte to file
	if (myFile.is_open()) {
		cout << allData << "\n";
		myFile << allData << "\n";
		cout << "Data was modified! \n";
	}
	else {
		cout << "File is not open \n";
	}
	//Close file
	myFile.close();

}


