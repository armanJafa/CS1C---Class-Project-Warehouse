#include <iostream>
#include <fstream>
#include <limits>
#include "Warehouse.h"
#include "Myheader.h"
using namespace std;


int main()
{
	ifstream 	memberInFile;
	ofstream    memberOutFile;
	ifstream	itemInFile;
	Warehouse	warehouse;
	Date		testDate;
	Basic   testMember;
	MemberList members;
	int choice;
	int idSearch;
	string itemNameSearch;

	itemInFile.open("assets/day1.txt");
	memberInFile.open("assets/warehouse shoppers.txt");

	warehouse.LoadMembers(memberInFile);
	warehouse.LoadItems(itemInFile);
	testDate.SetDate(1, 2, 2015);


	do
	{
		cout << MENU;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << endl << endl;

		switch(choice)
		{
		case 1: 			warehouse.PrintSalesReport(testDate);
							break;

		case 2:				cout << "Enter the Id of the member you would"
									" like to search for: ";
							cin >> idSearch;

							cout << endl << endl;

							warehouse.PrintMemberPurchaseReport(idSearch);
							break;

		case 3:				warehouse.PrintTotalSalesReport();
							break;

		case 4:				cout << "Enter the name of the item you would"
									" like to search for: " << endl << endl;
							getline(cin, itemNameSearch);

							warehouse.PrintItemSalesReport(itemNameSearch);
							break;

		case 5: 			warehouse.PrintItemsSold();
							break;

		case 6: 			warehouse.PrintRebateReport();
							break;

		case 7: 			warehouse.PrintMembershipDues();
							break;

		case 8: 			cout << "NOT DONE";
							break;

		case 9: 			warehouse.OutputMembers();
							break;

		case 10: 			warehouse.OutputInventory();
							break;

		case 11:			warehouse.PrintAmountDueByMonthReport(testDate);
							break;
		case 12:			warehouse.AddMember();
							break;
		case 13:			warehouse.DeleteMember();
							break;

		case 14:			warehouse.PrintMemberPaidPerYearReport();
							break;

		case 15:			warehouse.DetermineBasicToPrefferred();
							break;

		case 16:			warehouse.DeterminePreferredToBasic();
							break;
		default:			break;
		}
	}while(choice != 0);


	memberInFile.close();
	itemInFile.close();

	cout << "\nSaving Changes .... \n\n";

	memberOutFile.open("assets/warehouse shoppers.txt");

	warehouse.SaveChanges(memberOutFile);

	memberOutFile.close();

	cout << "Work has been saved. Thank you for using "
			"Project Awesome.\n";
	cout << "Developed by the  Guardians of the Galaxy\n";
	cout << "Special thanks to Daniel Phan - Scrum Master\n";


	return 0;
}
