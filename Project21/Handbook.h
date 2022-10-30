#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Book
{
	string company;
	string name;
	int number;
	string address;
	string type;
	static int count;
public:
	Book()
	{
		company = name = address = type = "";
		number = 0;
	}
	Book(const char* c, const char* n, int num, const char* a, const char* t)
	{
		company = c;
		name = n;
		number = num;
		address = a;
		type = t;
		count++;
		Save();
	}
	void Init()
	{
		cout << "Company: ";
		cin >> company;
		cout << "Name: ";
		cin >> name;
		cout << "Number: ";
		cin >> number;
		cout << "Address: ";
		cin >> address;
		cout << "Type: ";
		cin >> type;
		count++;
		Save();
	}
	void Save()
	{
		ofstream out;
		out.open("Book.txt", ios::app);
		out << "\n" << count << "\n" << "Company: " << company
			<< "\n" << "Name: " << name << "\n" << "Number: "
			<< number << "\n" << "Address: " << address
			<< "\n" << "Type: " << type << "\n";
		out.close();
	}
};

int Book::count = 0;
