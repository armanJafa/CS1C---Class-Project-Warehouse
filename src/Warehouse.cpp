/*************************************************
 * AUTHOR 		: Daniel Phan, Samuel Yeaw,
 * 				  Arman Jafarinia, Jacob McIver
 * STUDENT ID 	: 243390
 * Class Project	: Warehouse Class Project
 * CLASS 		: CS1C
 * SECTION 		: TTh 12:30PM - 4:20PM
 * DUE DATE 		: 3/17/15
 **************************************************/

#include "Warehouse.h"

/*************************************************
 * Default Constructor
 *************************************************/
Warehouse::Warehouse()
{

}

/*************************************************
 * Destructor
 *************************************************/
Warehouse::~Warehouse()
{

}

void Warehouse::LoadMembers(ifstream &inFile)
{
	members.CreateList(inFile);
}

void Warehouse::LoadItems(ifstream &inFile)
{
	inventory.ReadInFile(inFile);
}

/*************************************************
 * PrintSalesReport
 * -----------------------------------------------
 * This member function prints a sales report. It
 * searches for a date and outputs the information
 * associated with that date.
 * -----------------------------------------------
 * PRE-CONDITIONS:
 * 	aDate	: A date to search for
 *
 * POST-CONDITIONS:
 *  <Outputs a report with information associated
 *   with a particular date>
 *************************************************/
void Warehouse::PrintSalesReport(Date aDate) //OBJECTIVE 1
{
	// CONSTANT DECLARATIONS
	const int TITLE = 31;
	const int ITEM = 26;
	const int QUANTITY = 10;
	const int COST = 10;
	const int BUYER = 17;

	// VARIABLE DECLARATIONS
	int index;
	int totalBasic;
	int totalPreferred;
	float totalRevenue;
	bool  noItemsPurchased;
	Basic* aMember;
	Item* itemPtr;
	Date datePtr;

	// VARIABLE INITIALIZATION
	totalBasic = 0;
	totalPreferred = 0;
	totalRevenue = 0;

	// OUTPUT TITLE
	cout << left;
	cout << setprecision(2) << fixed;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* SALES REPORT FOR ";
	aDate.Print();
	cout << " *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	// OUTPUT HEADING
	cout << setw(ITEM + 1) << "ITEM";
	cout << setw(QUANTITY + 1) << "QUANTITY";
	cout << setw(COST + 1) << "COST";
	cout << setw(BUYER) << "BUYER";
	cout << endl;

	cout << setfill('-');
	cout << setw(ITEM) << '-' << ' ';
	cout << setw(QUANTITY) << '-' << ' ';
	cout << setw(COST) << '-' << ' ';
	cout << setw(BUYER) << '-';
	cout << setfill(' ');
	cout << endl;

	// OUTPUT LIST OF ITEMS BOUGHT
	index = 1;
	itemPtr = inventory.GetHead();
	noItemsPurchased = true;

	while (itemPtr != NULL)
	{
		if (index < 10)
		{
			cout << index << ".  ";
		}
		else
		{
			cout << index << ". ";
		}
		cout << setw(ITEM - 3) << itemPtr->GetName();
		cout << setw(QUANTITY + 1) << itemPtr->GetQuantity();
		cout << '$';
		cout << setw(COST) << itemPtr->GetPrice();

		aMember = members.SearchMember(itemPtr->GetBuyerID());
		cout << aMember->GetName();

		totalRevenue += itemPtr->GetPrice() * itemPtr->GetQuantity();

		noItemsPurchased = false;

		itemPtr = itemPtr->GetNextItem();
		cout << endl;
		index++;
	}

	if(noItemsPurchased)
	{
		cout << "<NO ITEMS PURCHASED>\n";
	}

	cout << setfill('-');
	cout << setw(ITEM + QUANTITY + COST + BUYER + 3) << '-';
	cout << endl << endl;

	cout << "TOTAL NUMBER OF MEMBERS\n";
	cout << setw(23) << '-' << endl;
	cout << setfill(' ');
	cout << endl;

	aMember = members.GetHead();
	while (aMember != NULL)
	{
		if (aMember->GetMemberType() == 0)
		{
			totalBasic++;
		}
		else
		{
			totalPreferred++;
		}
		aMember = aMember->GetNext();
	}

	cout << "BASIC:     " << totalBasic << endl;
	cout << "PREFERRED: " << totalPreferred << endl;
	cout << endl;

	cout << "TOTAL REVENUE: $" << totalRevenue << endl;
	cout << endl << endl;

	cout << right;
}
//Output All Members (Non-objective)
void Warehouse::OutputMembers()
{
	Basic *memberPtr;
	//Date datePtr;

	memberPtr = members.GetHead();

	while (memberPtr != NULL)
	{
		cout << "NAME: " << memberPtr->GetName() << endl;
		cout << "ID:   " << memberPtr->GetId() << endl;
		//cout << "Expiration: " << datePtr.GetDay() << endl;
		cout << "Membership   ";
		if (memberPtr->GetMemberType() == 0)
		{
			cout << "BASIC";
		}
		else
		{
			cout << "PREFERRED";
		}
		cout << endl << endl;
		memberPtr = memberPtr->GetNext();
	}

}
//Outputs Entire Item list from Inventory (Non-objective)
void Warehouse::OutputInventory()
{
	Item* itemPtr;
	//Date datePtr;

	itemPtr = inventory.GetHead();

	while (itemPtr != NULL)
	{
		cout << "ITEM NAME: " << itemPtr->GetName() << endl;
		cout << "SHOPPER ID:   " << itemPtr->GetBuyerID() << endl;
		cout << "COST:   " << itemPtr->GetPrice() << endl;
		cout << "QUANTITY:   " << itemPtr->GetQuantity() << endl;

		cout << endl << endl;
		itemPtr = itemPtr->GetNextItem();
	}

}
//OBJECTIVE 2
void Warehouse::PrintMemberPurchaseReport(int search)
{
	// CONSTANT DECLARATIONS
	const int TITLE = 26;
	const int ITEM = 24;
	const int QUANTITY = 10;
	const int COST = 10;

	// VARIABLE DECLARATIONS
	int index;
	int totalPurchases;
	bool noItemsPurchased;
	Item* perPtr;
	Basic *memberPtr;

	// OUTPUT TITLE
	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* MEMBER PURCHASE REPORT *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	// MEMBER INITIALIZATIONS
	memberPtr = members.SearchMember(search);

	cout << "NAME: " << memberPtr->GetName() << endl;
	cout << "ID:   " << memberPtr->GetId() << endl << endl;

	cout << setw(ITEM + 1) << "ITEM";
	cout << setw(QUANTITY + 1) << "QUANTITY";
	cout << setw(COST) << "COST";
	cout << endl;

	cout << setfill('-');
	cout << setw(ITEM) << '-' << ' ';
	cout << setw(QUANTITY) << '-' << ' ';
	cout << setw(COST) << '-';
	cout << setfill(' ');
	cout << endl;

	// Loop for Purchases
	index = 1;
	totalPurchases = 0;
	perPtr = inventory.GetHead();
	noItemsPurchased = true;

	while (perPtr != NULL)
	{
		if (perPtr->GetBuyerID() == memberPtr->GetId())
		{
			if (index < 10)
			{
				cout << index << ".  ";
			}
			else
			{
				cout << index << ". ";
			}
			cout << setw(ITEM - 3) << perPtr->GetName();
			cout << setw(QUANTITY + 1) << perPtr->GetQuantity();
			cout << setw(COST) << perPtr->GetPrice();
			cout << endl;

			totalPurchases++;
			index++;
			noItemsPurchased = false;
		}

		perPtr = perPtr->GetNextItem();
	}

	if (noItemsPurchased)
	{
		cout << "<No items were puchased by this user>\n";
	}

	cout << setfill('-');
	cout << setw(ITEM + QUANTITY + COST) << '-';
	cout << setfill(' ');
	cout << endl << endl;

	cout << "TOTAL PURCHASES: " << totalPurchases;
	cout << endl << endl;

	cout << right;
}

//OBJECTIVE 3
void Warehouse::PrintTotalSalesReport()
{
	Basic *memberPtr;
	Item *itemPtr;
	Date datePtr;
	bool matches;

	memberPtr = members.GetHead();

	while (memberPtr != NULL)
	{
		itemPtr = inventory.GetHead();
		matches = false;
		cout << "   ID # " << memberPtr->GetId() << " PURCHASED:" << endl;
		cout << "----------------------------------" << endl;

		while (itemPtr != NULL)
		{
			if (itemPtr->GetBuyerID() == memberPtr->GetId())
			{
				cout << "ITEM NAME: " << itemPtr->GetName();
				cout << endl;
				matches = true;
			}

			itemPtr = itemPtr->GetNextItem();
		}

		if(!matches)
		{
			cout << "Nothing was Purchased By this User..." << endl;
		}

		memberPtr = memberPtr->GetNext();
		cout << endl;
	}

}
//OBJECTIVE 4
void Warehouse::PrintItemSalesReport(string itemToSearch)
{
	const int TITLE = 21;
	Item *itemPtr = NULL;
	bool itemFound;
	bool stringEmpty;

	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* ITEM SALES REPORT *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	itemPtr = inventory.GetHead();
	itemFound = false;
	stringEmpty = true;

	do	//Error checking
	{
		if(itemToSearch.empty())
		{
			cout << "Please enter an item to search: ";
			getline(cin, itemToSearch);
		}
		else
		{
			stringEmpty = false;
		}
	}while(stringEmpty);

	//Searching for item
	while(itemPtr!=NULL && !itemFound)
	{
		if (itemPtr->GetName() == itemToSearch)
		{
			itemFound = true;
		}
		else
		{
			itemPtr = itemPtr->GetNextItem();
		}
	}

	//IF ITEMPTR == NULL DON'T TRY TO ACCESS MEMBERS
	if(itemPtr != NULL)
	{
	cout << setw(TITLE) << itemPtr->GetName()
		 << " X " << itemPtr->GetQuantity();
	cout << " = $" << (float(itemPtr->GetQuantity()) * (itemPtr->GetPrice()))
		 << endl << endl;
	}
	else
	{
		cout << "No Item called: " << itemToSearch
			 << " found!" << endl << endl;
	}
}

//OBJECTIVE 7
void Warehouse::PrintMemberPaidPerYearReport()
{
	const int TITLE = 29;
	const int MEMBER_TYPE = 11;
	const int MEMBER_NAME = 22;
	const int TOTAL_SPENT = 10;

	struct MemberInfo
	{
		string memberName;
		MemberType type;
	};

	MemberInfo memberArray[11];
	Basic *perPtr;

	perPtr=members.GetHead();

	int i=0;

	    while(perPtr!=NULL)
	    {
	        memberArray[i].memberName =perPtr->GetName();
	        memberArray[i].type = perPtr->GetMemberType();
	        perPtr=perPtr->GetNext();
	        i++;
	    }


	 int j;

	 MemberInfo tmp;
	 for (i = 0; i < 11; i++)
	 {
		 j = i;
		 while (j > 0 && memberArray[j - 1].memberName > memberArray[j].memberName)
		 {
			 tmp = memberArray[j];
			 memberArray[j] = memberArray[j - 1];
			 memberArray[j - 1] = tmp;
			 j--;
		 }//end of while loop

	 }//end of for loop

	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* MEMBER YEARLY AMOUNT PAID *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	cout << setw(MEMBER_TYPE) << "MEMBER TYPE   ";
	cout << setw(MEMBER_NAME) << "MEMBER NAME";
	cout << setw(TOTAL_SPENT) << "   TOTAL SPENT";
	cout << endl;

	cout << setfill('-');
	cout << setw(MEMBER_TYPE) << '-' << "   ";
	cout << setw(MEMBER_NAME) << '-' << "   ";
	cout << setw(TOTAL_SPENT) << '-';
	cout << setfill(' ');
	cout << endl;

	i=0;
	perPtr = members.GetHead();

	while (i < 11)
	{
		if(memberArray[i].type == BASIC)
		{
			cout << setw(MEMBER_TYPE + 3) << "BASIC";
			cout << setw(MEMBER_NAME) << memberArray[i].memberName;
			cout << setw(TOTAL_SPENT) << "   $55.00";
			cout << endl;
		}
		i++;
	}

	cout << endl;

	i=0;
	while (i < 11)
	{
		if(memberArray[i].type == PREFERRED)
		{
			cout << setw(MEMBER_TYPE + 3) << "PREFERRED";
			cout << setw(MEMBER_NAME) << memberArray[i].memberName;
			cout << setw(TOTAL_SPENT) << "   $95.00";
			cout << endl;
		}
		i++;
	}

	cout << endl << right;

}
//OBJECTIVE 8
void Warehouse::PrintAmountDueByMonthReport(Date aDate)
{
	const int TITLE = 29;
	const int MONTH = 11;
	const int MEMBER_NAME = 10;
	const int AMOUNT_DUE = 10;

	Basic *perPtr = members.GetHead();

	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* AMOUNT DUE AT THE END OF MONTH REPORT *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

	cout << setw(MONTH) << "MONTH   ";
	cout << setw(MEMBER_NAME) << "MEMBER NAME  ";
	cout << setw(AMOUNT_DUE) << "AMOUNT DUE";
	cout << endl;

	cout << setfill('-');
	cout << setw(MONTH) << '-' << "   ";
	cout << setw(MEMBER_NAME) << '-' << "   ";
	cout << setw(AMOUNT_DUE) << '-';
	cout << setfill(' ');
	cout << endl;

	while (perPtr != NULL)
	{
		if (aDate.GetMonth() == perPtr->GetExpiration().GetMonth())
		{
			cout << setw(MONTH) << aDate.GetMonth();
			cout << setw(MEMBER_NAME) << perPtr->GetName();
			if (perPtr->GetMemberType() == BASIC)
			{
				cout << setw(AMOUNT_DUE) << "$55.00";

			}
			else
			{
				cout << setw(AMOUNT_DUE) << "$95.00";
			}
			cout << endl;
		}

		perPtr = perPtr->GetNext();
	}

	cout << right;
}

//OBJECTIVE 6
void Warehouse::PrintRebateReport()
{
	Basic *memberPtr;
	Date datePtr;

	cout << "=====================================" << endl << "	Rebate Report"
			<< endl << "=====================================" << endl;
	memberPtr = members.GetHead();
	while (memberPtr != NULL)
	{
		if (memberPtr->GetMemberType() == PREFERRED)
		{
			cout << "ID:   " << memberPtr->GetId() << "	REBATE:" << endl;
			cout << "";
		}
		memberPtr = memberPtr->GetNext();
	}
	cout << endl;
}

void Warehouse::PrintItemsSold()
{
	Item *itemPtr;
	Date datePtr;

	cout << "=====================================" << endl << "	Items Sold"
			<< endl << "=====================================" << endl;
	itemPtr = inventory.GetHead();
	while (itemPtr != NULL)
	{
		cout << "ITEM NAME:   " << itemPtr->GetName();
		cout << "Quantity: " << itemPtr->GetQuantity() << endl;

		itemPtr = itemPtr->GetNextItem();
	}
	cout << endl;
}

void Warehouse::AddMember()
{
	string name;
	int id;
	int day;
	int month;
	int year;
	string memberType;
	Basic* memberPtr;
	Date   aDate;

	cout << "What is the name of the new member? ";
	getline(cin, name);
	cout << endl;

	cout << "What is their id? ";
	cin  >> id;
	cout << endl;

	cout << "What is the date of their expiration?\n";
	cout << "Day:   ";
	cin  >> day;
	cout << endl;

	cout << "Month: ";
	cin  >> month;
	cout << endl;

	cout << "Year:  ";
	cin  >> year;
	cout << endl;

	cout << "What type of member are you adding (Basic/Preferred): ";
	getline(cin, memberType);
	cout << endl;

	memberPtr	= NULL;
	if(memberType == "Basic")
	{
		memberPtr	= new Basic;
	}
	else
	{
		memberPtr 	= new Preferred;
	}

	memberPtr->SetName(name);
	memberPtr->SetId(id);
	aDate.SetDate(day, month, year);
	memberPtr->SetExpiration(aDate);

	members.AddMember(memberPtr);

	cout << memberPtr->GetName() << " has been added.\n\n";


}

void Warehouse::DeleteMember()
{
	Basic* delPtr;
	string name;

	cout << "Which member would you like to delete? ";
	getline(cin, name);
	cout << endl;

	delPtr = members.SearchMember(name);
	members.DeleteMember(delPtr);

	cout << name << " has been deleted\n\n";
}

void Warehouse::PrintMembershipDues()
{
	Basic *memberPtr;
	Date datePtr;

	memberPtr = members.GetHead();

	cout << "=====================================" << endl
			<< "	MEMBERSHIP DUES\n" << endl
			<< "=====================================" << endl;

	while (memberPtr != NULL)
	{
		if (memberPtr->GetMemberType() == PREFERRED)
		{
			cout << "MEMBER TYPE: PREFERRED" << endl;
			cout << "NAME: " << memberPtr->GetName() << endl;
			cout << "MEMBERSHIP DUES: $" << 95.00; // NEED to edit this still
			cout << endl << endl;

		}

		memberPtr = memberPtr->GetNext();
	}

	memberPtr = members.GetHead();

	while (memberPtr != NULL)
	{
		if (memberPtr->GetMemberType() == BASIC)
		{
			cout << "MEMBER TYPE: BASIC" << endl;
			cout << "NAME: " << memberPtr->GetName() << endl;
			cout << "MEMBERSHIP DUES: $" << 55.00; // NEED to edit this still
			cout << endl << endl;

		}
		memberPtr = memberPtr->GetNext();
	}
	cout << endl << endl;
}

//Objective 10
void Warehouse::DetermineBasicToPrefferred()
{
	const int TITLE = 27;

    Basic *memberPtr;
    Item  *itemPtr;
    int numBasic = 0;
    int i = 0;

    struct MemberInfo
    {
    	string name;
    	int id;
    	float totalSpent;
    };

	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* MEMBER ALERT: UPGRADE *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

    memberPtr=members.GetHead();

    //Initialize counter for member array
    while(memberPtr != NULL)
    {
    	if(memberPtr->GetMemberType() == BASIC)
    	{
    		numBasic++;
    	}
    	memberPtr = memberPtr->GetNext();
    }

    MemberInfo memberArray[numBasic];
    memberPtr = members.GetHead();

    //Loading in Basic Member infos to struct
    while(memberPtr != NULL)
    {
    	if(memberPtr->GetMemberType() == BASIC)
		{
			memberArray[i].name = memberPtr->GetName();
			memberArray[i].id = memberPtr->GetId();
			i++;
		}
    	memberPtr = memberPtr->GetNext();
    }

    memberPtr = members.GetHead();
    itemPtr=inventory.GetHead();

    //Load in totalSpent for each unique member
    for(i = 0; i < numBasic; i++)
    {
    	while(itemPtr != NULL)
    	{
    		if(memberArray[i].id == itemPtr->GetBuyerID())
    		{
    			memberArray[i].totalSpent += itemPtr->GetPrice();
    		}
    		itemPtr = itemPtr->GetNextItem();
    	}

    	itemPtr = inventory.GetHead();
    }

    //Output if member should upgrade or not
    for(i = 0; i < numBasic; i++)
    {
		if(memberArray[i].totalSpent > 100.00)
		{
			cout << "Member " << memberArray[i].name << ": Status "
					"-> Upgrade to Preferred" << endl << endl;
		}
    }
}

//Objective 11
void Warehouse::DeterminePreferredToBasic()
{
	const int TITLE = 29;

    Basic *memberPtr;
    Item  *itemPtr;
    int numPref = 0;
    int i = 0;

    struct MemberInfo
    {
    	string name;
    	int id;
    	float totalSpent;
    };

	cout << left;
	cout << setfill('*');
	cout << setw(TITLE) << '*' << endl;
	cout << "* MEMBER ALERT: DOWNGRADE *" << endl;
	cout << setw(TITLE) << '*' << endl;
	cout << setfill(' ');
	cout << endl;

    memberPtr=members.GetHead();

    //Initialize counter for member array
    while(memberPtr != NULL)
    {
    	if(memberPtr->GetMemberType() == PREFERRED)
    	{
    		numPref++;
    	}
    	memberPtr = memberPtr->GetNext();
    }

    MemberInfo memberArray[numPref];
    memberPtr = members.GetHead();

    //Loading in Preferred Member infos to struct
    while(memberPtr != NULL)
    {
    	if(memberPtr->GetMemberType() == PREFERRED)
		{
			memberArray[i].name = memberPtr->GetName();
			memberArray[i].id = memberPtr->GetId();
			i++;
		}
    	memberPtr = memberPtr->GetNext();
    }

    memberPtr = members.GetHead();
    itemPtr=inventory.GetHead();

    //Load in totalSpent for each unique member
    for(i = 0; i < numPref; i++)
    {
    	while(itemPtr != NULL)
    	{
    		if(memberArray[i].id == itemPtr->GetBuyerID())
    		{
    			memberArray[i].totalSpent += itemPtr->GetPrice();
    		}
    		itemPtr = itemPtr->GetNextItem();
    	}

    	itemPtr = inventory.GetHead();
    }

    //Output if member should upgrade or not
    for(i = 0; i < numPref; i++)
    {
		if(memberArray[i].totalSpent <= 100.00)
		{
			cout << "Member " << memberArray[i].name << ": Status "
					"-> Downgrade to Basic" << endl << endl;
		}
    }
}
