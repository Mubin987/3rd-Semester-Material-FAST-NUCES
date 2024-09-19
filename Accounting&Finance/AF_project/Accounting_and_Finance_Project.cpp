#include <bits/stdc++.h>
using namespace std;

void Display()
{
	string line;
	ifstream infile;
	infile.open("Trial_balance.txt");
	int totalDR = 0, totalCR = 0;
	string l2, l3, l4, l5;
	cout << " Account title";
	for (int i = 0; i < 22; i++)
	{
		cout << " ";
	}
	cout << "DR";
	for (int i = 0; i < 17; i++)
	{
		cout << " ";
	}
	cout << "CR" << endl;
	while (getline(infile, line))
	{
		// cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		// cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		stringstream ss(line);
		getline(ss, l2, ',');
		getline(ss, l3, ',');

		cout << l2;

		for (int j = 0; j < 35 - l2.length(); j++)
		{
			cout << " ";
		}

		if (l3 == "DR")
		{

			getline(ss, l4);
			if (l4 != "")
			{
				int bal1 = stoi(l4);
				totalDR += bal1;
				cout << bal1;
			}
			cout << endl;
		}
		else if (l3 == "CR")
		{

			getline(ss, l4);
			if (l4 != "")
			{
				int bal2 = stoi(l4);
				totalCR += bal2;
				for (int j = 0; j < 20; j++)
				{
					cout << " ";
				}
				cout << bal2;
			}
			cout << endl;
		}
	}
	infile.close();
	cout << "Total Ammount";
	for (int j = 0; j < 22; j++)
	{
		cout << " ";
	}
	cout << totalDR;
	for (int j = 0; j < 14; j++)
	{
		cout << " ";
	}
	cout << totalCR << endl;
}
void supplies()
{
	int a, b, c;
	string l1, l2, l3, l4;
	cout << "1.Used." << endl;
	cout << "2.Remainning." << endl;
	cin >> a;
	cout << "Enter ammount: ";
	cin >> b;
	string in;
	ofstream outfile;
	ifstream file;
	outfile.open("temp.txt");
	file.open("Trial_balance.txt");
	while (getline(file, in))
	{
		stringstream ss(in);
		getline(ss, l1, ',');
		getline(ss, l2, ',');
		getline(ss, l3, ',');
		getline(ss, l4);
		if (l1 == "Office Supplies")
		{
			c = stoi(l3);
			if (a == 1)
			{
				outfile << endl
						<< l1 << "," << l2 << "," << c - b << "," << l4;
			}
			else if (a == 2)
			{
				outfile << endl
						<< l1 << "," << l2 << "," << b << "," << l4;
			}
		}
		else if (l1 == "Supplies Expense")
		{
			if (a == 1)
			{
				outfile << endl
						<< l1 << "," << l2 << "," << b << "," << l4;
			}
			else if (a == 2)
			{
				outfile << endl
						<< l1 << "," << l2 << "," << c - b << "," << l4;
			}
		}
		else
		{
			if (l1 == "Cash")
				outfile << in;
			else
				outfile << endl
						<< in;
		}
	}
	outfile.close();
	file.close();
	remove("Trial_balance.txt");
	rename("temp.txt", "Trial_balance.txt");
}
void Depriciation()
{
	int a, b, c;
	string name, cname, ename, l1, l2, l3, l4;
	cout << "Enter Name of entity: ";
	cin >> name;
	cout << "1.Monthly." << endl;
	cout << "2.Annual." << endl;
	cin >> a;
	cout << "Enter ammount: ";
	cin >> b;
	if (a == 2)
		b /= 12;
	cname = "Accumulated Depreciation " + name;
	ename = "Depreciation Expense " + name;
	string in;
	ofstream outfile;
	ifstream file;
	outfile.open("temp.txt");
	file.open("Trial_balance.txt");
	while (getline(file, in))
	{
		stringstream ss(in);
		getline(ss, l1, ',');
		getline(ss, l2, ',');
		getline(ss, l3, ',');
		getline(ss, l4);
		if (l1 == cname)
		{
			if (l3 != "")
			{
				c = stoi(l3);
				outfile << endl
						<< l1 << "," << l2 << "," << c + b << "," << l4;
			}
			else
			{
				outfile << endl
						<< l1 << "," << l2 << "," << b << "," << l4;
			}
		}
		else if (l1 == ename)
		{
			if (l3 != "")
			{
				c = stoi(l3);
				outfile << endl
						<< l1 << "," << l2 << "," << b << "," << l4;
			}
			else
			{
				outfile << endl
						<< l1 << "," << l2 << "," << b << "," << l4;
			}
		}
		else
		{
			if (l1 == "Cash")
				outfile << in;
			else
				outfile << endl
						<< in;
		}
	}
	outfile.close();
	file.close();
	remove("Trial_balance.txt");
	rename("temp.txt", "Trial_balance.txt");
}
void salary()
{
	int a, b, c, d;
	string l1, l2, l3, l4;
	cout << "Enter Total ammount: ";
	cin >> b;
	cout << "Enter number of days in working week: ";
	cin >> a;

	cout << "Enter number of days: ";
	cin >> c;
	string in;
	ofstream outfile;
	ifstream file;
	outfile.open("temp.txt");
	file.open("Trial_balance.txt");
	while (getline(file, in))
	{
		stringstream ss(in);
		getline(ss, l1, ',');
		getline(ss, l2, ',');
		getline(ss, l3, ',');
		getline(ss, l4);
		if (l1 == "Salaries Payable")
		{
			if (l3 != "")
			{
				d = stoi(l3);
				outfile << endl
						<< l1 << "," << l2 << "," << d + ((b / a) * c) << "," << l4;
			}
			else
			{
				outfile << endl
						<< l1 << "," << l2 << "," << ((b / a) * c) << "," << l4;
			}
		}
		else if (l1 == "Salaries Expense")
		{
			if (l3 != "")
			{
				d = stoi(l3);
				outfile << endl
						<< l1 << "," << l2 << "," << d + ((b / a) * c) << "," << l4;
			}
			else
			{
				outfile << endl
						<< l1 << "," << l2 << "," << ((b / a) * c) << "," << l4;
			}
		}
		else
		{
			if (l1 == "Cash")
				outfile << in;
			else
				outfile << endl
						<< in;
		}
	}
	outfile.close();
	file.close();
	remove("Trial_balance.txt");
	rename("temp.txt", "Trial_balance.txt");
}
void service_revenue()
{
	int a;
	cout << "1.Unearned Revenue." << endl;
	cout << "2.Earned but not paid Revenue." << endl;
	cin >> a;
	if (a == 1)
	{
		int b, c;
		string l1, l2, l3, l4;
		cout << "How much revenue has earned: ";
		cin >> b;
		string in;
		ofstream outfile;
		ifstream file;
		outfile.open("temp.txt");
		file.open("Trial_balance.txt");
		while (getline(file, in))
		{
			stringstream ss(in);
			getline(ss, l1, ',');
			getline(ss, l2, ',');
			getline(ss, l3, ',');
			getline(ss, l4);
			if (l1 == "Unearned Revenue")
			{
				if (l3 != "")
				{
					c = stoi(l3);
					outfile << endl
							<< l1 << "," << l2 << "," << c - b << "," << l4;
				}
				else
				{
					outfile << endl
							<< l1 << "," << l2 << "," << b << "," << l4;
				}
			}
			else if (l1 == "Service Revenue")
			{
				if (l3 != "")
				{
					c = stoi(l3);
					outfile << endl
							<< l1 << "," << l2 << "," << b + c << "," << l4;
				}
				else
				{
					outfile << endl
							<< l1 << "," << l2 << "," << b << "," << l4;
				}
			}
			else
			{
				if (l1 == "Cash")
					outfile << in;
				else
					outfile << endl
							<< in;
			}
		}
		outfile.close();
		file.close();
		remove("Trial_balance.txt");
		rename("temp.txt", "Trial_balance.txt");
	}
	else if (a == 2)
	{
		int b, d;
		string l1, l2, l3, l4;
		cout << "How much ammount is unpaid: ";
		cin >> b;
		string in;
		ofstream outfile;
		ifstream file;
		outfile.open("temp.txt");
		file.open("Trial_balance.txt");
		while (getline(file, in))
		{
			stringstream ss(in);
			getline(ss, l1, ',');
			getline(ss, l2, ',');
			getline(ss, l3, ',');
			getline(ss, l4);
			if (l1 == "")
			{
				if (l3 != "Accounts Receivable")
				{
					d = stoi(l3);
					outfile << endl
							<< l1 << "," << l2 << "," << b + d << "," << l4;
				}
				else
				{
					outfile << endl
							<< l1 << "," << l2 << "," << b << "," << l4;
				}
			}
			else if (l1 == "Service Revenue")
			{
				if (l3 != "")
				{
					d = stoi(l3);
					outfile << endl
							<< l1 << "," << l2 << "," << d + b << "," << l4;
				}
				else
				{
					outfile << endl
							<< l1 << "," << l2 << "," << b << "," << l4;
				}
			}
			else
			{
				if (l1 == "Cash")
					outfile << in;
				else
					outfile << endl
							<< in;
			}
		}
		outfile.close();
		file.close();
		remove("Trial_balance.txt");
		rename("temp.txt", "Trial_balance.txt");
	}
}
void insurance()
{
	int a, b, c, d;
	string l1, l2, l3, l4;
	cout << "Enter total period of insurance (in months): ";
	cin >> b;
	cout << "Enter total time has pased (in months): ";
	cin >> c;
	string in;
	ofstream outfile;
	ifstream file;
	outfile.open("temp.txt");
	file.open("Trial_balance.txt");
	while (getline(file, in))
	{
		stringstream ss(in);
		getline(ss, l1, ',');
		getline(ss, l2, ',');
		getline(ss, l3, ',');
		getline(ss, l4);
		if (l1 == "Prepaid Insurance")
		{
			if (l3 != "")
			{
				a = stoi(l3);
				outfile << endl
						<< l1 << "," << l2 << "," << a - ((a / b) * c) << "," << l4;
			}
		}
		else if (l1 == "Insurance Expense")
		{
			if (l3 != "")
			{
				d = stoi(l3);
				outfile << endl
						<< l1 << "," << l2 << "," << d + ((a / b) * c) << "," << l4;
			}
			else
			{
				outfile << endl
						<< l1 << "," << l2 << "," << ((a / b) * c) << "," << l4;
			}
		}
		else
		{
			if (l1 == "Cash")
				outfile << in;
			else
				outfile << endl
						<< in;
		}
	}
	outfile.close();
	file.close();
	remove("Trial_balance.txt");
	rename("temp.txt", "Trial_balance.txt");
}
void rent()
{
	int a, b, c, d;
	string l1, l2, l3, l4;
	cout << "Enter total period of rent (in months): ";
	cin >> b;
	cout << "Enter total time has pased (in months): ";
	cin >> c;
	string in;
	ofstream outfile;
	ifstream file;
	outfile.open("temp.txt");
	file.open("Trial_balance.txt");
	while (getline(file, in))
	{
		stringstream ss(in);
		getline(ss, l1, ',');
		getline(ss, l2, ',');
		getline(ss, l3, ',');
		getline(ss, l4);
		if (l1 == "Prepaid Rent")
		{
			if (l3 != "")
			{
				a = stoi(l3);
				outfile << endl
						<< l1 << "," << l2 << "," << a - ((a / b) * c) << "," << l4;
			}
		}
		else if (l1 == "Rent Expense")
		{
			if (l3 != "")
			{
				d = stoi(l3);
				outfile << endl
						<< l1 << "," << l2 << "," << d + ((a / b) * c) << "," << l4;
			}
			else
			{
				outfile << endl
						<< l1 << "," << l2 << "," << ((a / b) * c) << "," << l4;
			}
		}
		else
		{
			if (l1 == "Cash")
				outfile << in;
			else
				outfile << endl
						<< in;
		}
	}
	outfile.close();
	file.close();
	remove("Trial_balance.txt");
	rename("temp.txt", "Trial_balance.txt");
}
int RevenuesForIncomeStatement()
{
	string line, l2, l3, l4, l5;
	ifstream infile;
	infile.open("Trial_balance.txt");
	int totalRevenues = 0;

	while (!infile.eof())
	{
		getline(infile, line);

		stringstream ss(line);
		getline(ss, l2, ',');
		getline(ss, l3, ',');
		getline(ss, l4, ',');
		getline(ss, l5);
		if (l5 == "Rev")
		{
			cout << "  " << left << setw(38) << l2;
			if (l4 != "")
			{
				int rev = stoi(l4);
				totalRevenues += rev;
				cout << string(8, ' ') << rev;
			}
			cout << endl;
		}
	}
	return totalRevenues;
}

int ExpensesForIncomeStatement()
{
	string line, l2, l3, l4, l5;
	ifstream infile;
	infile.open("Trial_balance.txt");
	int totalExpense = 0;

	while (!infile.eof())
	{
		getline(infile, line);
		stringstream ss(line);
		getline(ss, l2, ',');
		getline(ss, l3, ',');
		getline(ss, l4, ',');
		getline(ss, l5);

		if (l5 == "Exp")
		{
			cout << "  " << left << setw(38) << l2;
			getline(ss, l4);
			if (l4 != "")
			{
				int exp = stoi(l4);
				totalExpense += exp;
				cout << exp;
			}
			cout << endl;
		}
	}

	return totalExpense;
}
int incomeStatement()
{
	int revenues;
	int expenses;
	int net;

	cout << "Revenues:" << endl;
	revenues = RevenuesForIncomeStatement();

	cout << "\nExpenses:" << endl;
	expenses = ExpensesForIncomeStatement();

	cout << left << setw(40) << "    Total Expense" << string(8, ' ') << "(" << expenses << ")" << endl
		 << endl;

	net = revenues - expenses;

	if (net < 0)
		cout << left << setw(40) << "Net Loss: " << string(8, ' ') << "(" << net << ")" << endl;
	else
		cout << left << setw(40) << "Net Income: " << string(8, ' ') << net << endl;

	return net;
}
int RetE_OwnerEq(int beginning)
{
	string line;
	ifstream infile;
	infile.open("Trial_balance.txt");
	string l2, l3, l4;
	int res = 0;
	while (getline(infile, line))
	{
		stringstream ss(line);
		getline(ss, l2, ',');
		getline(ss, l3, ',');
		getline(ss, l4, ',');
		if (l2 == "Dividends" || l2 == "Drawing")
			break;
	}
	if (l2 == "Dividends")
	{

		int d;
		cout << " \t\t\t\tStatement of Retained Earnings" << endl
			 << endl;
		cout << " Beginning retained Earnings + Net Income:";
		for (int j = 0; j < 20; j++)
		{
			cout << " ";
		}
		cout << beginning << endl;

		cout << "Less " << l2;

		for (int j = 0; j < 35 - l2.length(); j++)
		{
			cout << " ";
		}

		if (l4 != "")
		{
			int div = stoi(l4);
			d = div;
			for (int j = 0; j < 20; j++)
			{
				cout << " ";
			}
			cout << "(" << d << ")" << endl;
		}
		int ret_earnings = beginning - d;
		res = ret_earnings;
		cout << " Ending retained Earnings:";
		for (int j = 0; j < 35; j++)
		{
			cout << " ";
		}
		cout << ret_earnings << endl;
	}
	else if (l2 == "Drawing")
	{
		int capital;
		cout << " \t\t\t\tStatement of Owner's Equity" << endl
			 << endl;
		cout << " Beginning Owner's Equity + Net Income:";
		for (int j = 0; j < 20; j++)
		{
			cout << " ";
		}
		cout << beginning << endl;

		if (l4 != "")
		{
			int cap = stoi(l4);
			capital = cap;
		}
		int owner_eq = beginning - capital;
		res = owner_eq;
		cout << "Less Drawing ";
		for (int j = 0; j < 40; j++)
		{
			cout << " ";
		}
		cout << "(" << capital << ")" << endl;
		cout << endl;
		cout << " Ending Owner's Equity:";
		for (int j = 0; j < 35; j++)
		{
			cout << " ";
		}
		cout << owner_eq << endl;
	}
	return res;
}
void balancesheet(int val)
{
	int total = 0, liabilities = 0, owners = 0;
	string l1, l2, temp, l4, line;
	int l3 = 0;

	ifstream filein;
	filein.open("Trial_balance.txt", ios::in);
	cout << "\t\t\t\tAssets" << endl
		 << endl;
	while (getline(filein, line))
	{
		stringstream ss(line);
		getline(ss, l1, ',');
		getline(ss, l2, ',');
		getline(ss, temp, ',');
		getline(ss, l4);
		l3 = stoi(temp);
		if (l4 == "Ast")
		{
			cout << l1;
			for (int j = 0; j < 45 - l1.length(); j++)
			{
				cout << " ";
			}
			stringstream s1(l1);
			getline(s1, temp, ' ');
			if (temp == "Accumulated")
			{
				total -= l3;
				cout << "(" << l3 << ")" << endl;
			}
			else
			{
				total += l3;
				cout << l3 << endl;
			}
		}
	}
	filein.close();
	cout << endl;
	cout << "Total Assets ";
	for (int j = 0; j < 33; j++)
	{
		cout << " ";
	}
	cout << total << endl
		 << endl;

	filein.open("Trial_balance.txt", ios::in);
	cout << "\t\t\t\tLiabilities" << endl
		 << endl;
	while (getline(filein, line))
	{
		stringstream ss(line);
		getline(ss, l1, ',');
		getline(ss, l2, ',');
		getline(ss, temp, ',');
		getline(ss, l4);
		l3 = stoi(temp);
		if (l4 == "Lib")
		{
			cout << l1;
			for (int j = 0; j < 45 - l1.length(); j++)
			{
				cout << " ";
			}
			liabilities += l3;
			cout << l3 << endl;
		}
	}
	filein.close();
	cout << endl;
	cout << "Total Liabilities";
	for (int j = 0; j < 28; j++)
	{
		cout << " ";
	}
	cout << liabilities << endl
		 << endl;

	filein.open("Trial_balance.txt", ios::in);
	cout << "\t\t\t\tStockholders' Equity" << endl
		 << endl;
	bool is_ret = false;
	while (getline(filein, line))
	{
		stringstream ss(line);
		getline(ss, l1, ',');
		getline(ss, l2, ',');
		getline(ss, temp, ',');
		getline(ss, l4);
		l3 = stoi(temp);
		if (l1 == "Dividends")
			is_ret = true;
		if (l4 == "Equ")
		{
			cout << l1;
			for (int j = 0; j < 45 - l1.length(); j++)
			{
				cout << " ";
			}
			owners += l3;
			cout << l3 << endl;
		}
	}
	if (is_ret)
	{
		l1 = "Retained Earnings";
		cout << l1;
		owners += val;
		for (int j = 0; j < 45 - l1.length(); j++)
		{
			cout << " ";
		}
		cout << val << endl;
	}
	else
	{
		l1 = "Owners Equity";
		cout << l1;
		owners += val;
		for (int j = 0; j < 45 - l1.length(); j++)
		{
			cout << " ";
		}
		cout << val << endl;
	}
	filein.close();
	cout << endl;
	cout << "Total Stockholders' Equity";
	for (int j = 0; j < 19; j++)
	{
		cout << " ";
	}
	cout << owners << endl
		 << endl;

	cout << "Total Liabilities + Stockholders' Equity";
	for (int j = 0; j < 5; j++)
	{
		cout << " ";
	}
	cout << owners + liabilities << endl
		 << endl;
}
void options()
{
	int c;
	cout << "1.Supplies." << endl;
	cout << "2.Depriciation." << endl;
	cout << "3.Salary." << endl;
	cout << "4.Service Revenue." << endl;
	cout << "5.Insurance." << endl;
	cout << "6.Rent." << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		supplies();
		break;
	case 2:
		Depriciation();
		break;
	case 3:
		salary();
		break;
	case 4:
		service_revenue();
		break;
	case 5:
		insurance();
		break;
	case 6:
		rent();
		break;
	}
}
int main()
{
	cout << " \t\t\t\tUnadjusted Trial Balance" << endl
		 << endl;
	Display();
	cout << endl;
	cout << "Press Enter to Continue." << endl;
	getchar();
	while (1)
	{
		system("CLS");
		int n;
		cout << "1.Add New Entry." << endl;
		cout << "2.Print Adjusted Trial Balance and Financial Statements." << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			options();
			break;
		case 2:
			cout << " \t\t\t\tadjusted Trial Balance" << endl
				 << endl;
			Display();
			cout << endl
				 << endl;
			cout << " \t\t\t\tIncome Statement" << endl
				 << endl;
			int a = incomeStatement();
			cout << endl
				 << endl;
			int b = RetE_OwnerEq(a);
			cout << endl
				 << endl;
			cout << " \t\t\t\tBalance Sheet" << endl
				 << endl;
			balancesheet(b);
			cout << endl;
			return 0;
		}
	}
}
