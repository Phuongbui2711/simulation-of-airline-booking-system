/************************************************
//                HEADER FILE
************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/************************************************
//     FUNCTIONS AND CLASSES PROTOTYPES
************************************************/

void mainMenu();
void subMenu();
void another();
class Registration;
class Booking;

/***************************************************************
//		  		 DEFINE REGISTRATION CLASS
// This class is used to register customers personal information
***************************************************************/

class Registration
{
	public:
		static string ID;
		static string name;
		static string gender;
		static string age;
		static string phone;
		static string address;
		char line[100];
		
		void getInfo ()
		{
			cout << "REGISTRATION HERE" << endl;
			
			cout << "Enter your ID: ";
			cin >> ID;
			
			cout << "Enter your name: ";
			cin >> name;
			
			cout << "Enter your gender (M for Male or F for Female): ";
			cin >> gender;
			
			cout << "Enter your age: ";
			cin >> age;
			
			cout << "Enter your phone number: ";
			cin >> phone;
			
			cout << "Enter your address: ";
			cin >> address;
			
			cout << "--------------------------------------------" << endl;
			cout << endl;
		}
};

/*********************************************
//		  DEFINE BOOKING CLASS
// This class is used to book flights
*********************************************/

class Booking
{
	public:
		int choice1;
		int choice2;
		int choice3;
		
		string destination;
		double price;
		string flight;
		string time;
		
		char back;
		
		void Reservation ();
		void Domestic ();
		void International ();
};

// Declare some global variables from Registration class

string Registration::ID;
string Registration::name;
string Registration::gender;
string Registration::age;
string Registration::phone;
string Registration::address;

/*************************************************************
//		  		 DEFINE Ticket CLASS
// This class is used to store and display booking information
*************************************************************/

class Ticket : public Registration
{
	public:
		static void ticket(string destination, string flight, double price, string time);
		void showTicket();
};

// Store customers and flights information

void Ticket::ticket(string destination, string flight, double price, string time)
{
	ofstream outf("Info.txt");
	{
		outf << "VIETNAM AIRLINES" << endl;
		outf << "THIS IS YOUR TICKET DETAILS" << endl;
		
		outf << "ID: " << Registration::ID << endl;
		outf << "Name: " << Registration::name << endl;
		outf << "Gender: " << Registration::gender << endl;
		outf << "Age: " << Registration::age << endl;
		outf << "Phone: " << Registration::phone << endl;
		outf << "Address: " << Registration::address << endl;
		
		outf << "Destination: " << destination << endl;
		outf << "Flight: " << flight << endl;
		outf << "Price: " << price << endl;
		outf << "Departure time: " << time << endl;
	}
	outf.close();
}

// Display customers and flights information

void Ticket::showTicket()
{
	ifstream ifs("Info.txt");
	{
		if (!ifs)
		{
			cout << "Error!" << endl;
		}
		while (!ifs.eof())
		{
			ifs.getline(line, 100);
			cout << line << endl;
		}
	}
	ifs.close();
}

/*************************************************
// Define reservation function from booking class
// This function is the menu for booking flights
*************************************************/

void Booking::Reservation()
{
	cout << "\t\t\t\t\t" << "VIETNAM AIRLINES" << endl << endl;
	
	cout << "1. BOOK DOMESTIC FLIGHT" << endl;
	cout << "2. BOOK INTERNATIONAL FLIGHT" << endl;
	cout << "3. BACK TO MAIN" << " (*Press this if you want to change your registered information)" << endl;
	
	cout << "Please enter your choice: ";
	cin >> choice1;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	
	switch (choice1)
	{
		case 1:
			Booking::Domestic();
			break;
			
		case 2:
			Booking::International();
			break;
			
		case 3:
			mainMenu();
			break;
			
		default:
			cout << "Invalid input! Please try again!" << endl;
			Booking::Reservation();
			break;
	}	
}

/*************************************************
// Define Domestic function from booking class
// This function is used to book domestic flights
*************************************************/

void Booking::Domestic()
{
	cout << "\t\t\t\t\t" <<"VIETNAM AIRLINES" << endl << endl;
	
	string Flights[] = {"HO CHI MINH CITY", "DA NANG", "NHA TRANG", "HUE", "DA LAT"};
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". FLIGHT TO " << Flights[i] << endl;
	}
	
	cout << "Please enter your choice: ";
	cin >> choice2;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	
	switch(choice2)
	{
		case 1:
			destination = "HO CHI MINH CITY";
			
			cout << "1. SGN 604" << endl;
			cout << "2022-06-23 12:30 2hrs10mins 60$" << endl;
			
			cout << "2. SGN 278" << endl;
			cout << "2022-06-24 13:40 2hrs10mins 63$" << endl;
			
			cout << "3. SGN 647" << endl;
			cout << "2022-06-25 14:55 2hrs45mins 55$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 60.0;
				flight = "SGN 604";
				time = "2022-06-23 12:30";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight SGN 604" << endl;
			}
			else if (choice3 == 2)
			{
				price = 63.0;
				flight = "SGN 278";
				time = "2022-06-24 13:40";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight SGN 278" << endl;
			}
			else if (choice3 == 3)
			{
				price = 55.0;
				flight = "SGN 647";
				time = "2022-06-25 14:55";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight SGN 647" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl;
				cout << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
			
		case 2:
			destination = "DA NANG";
			
			cout << "1. DAD 1763" << endl;
			cout << "2022-06-23 9:30 1hrs20mins 75$" << endl;
			
			cout << "2. DAD 2873" << endl;
			cout << "2022-06-24 11:15 1hrs20mins 76$" << endl;
			
			cout << "3. DAD 2892" << endl;
			cout << "2022-06-25 13:45 1hrs25mins 73$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 75.0;
				flight = "DAD 1763";
				time = "2022-06-23 9:30";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight DAD 1763" << endl;
			}
			else if (choice3 == 2)
			{
				price = 76.0;
				flight = "DAD 2873";
				time = "2022-06-24 11:15";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight DAD 2873" << endl;
			}
			else if (choice3 == 3)
			{
				price = 73.0;
				flight = "DAD 2892";
				time = "2022-06-25 13:45";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight DAD 2892" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl;
				cout << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
			
		case 3:
			destination = "NHA TRANG";
			
			cout << "1. CXR 578" << endl;
			cout << "2022-06-19 6:30 2hrs 100$" << endl;
			
			cout << "2. CXR 579" << endl;
			cout << "2022-06-20 9:30 2hrs 102$" << endl;
			
			cout << "3. CXR 573" << endl;
			cout << "2022-06-21 12:45 2hrs 101$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 100.0;
				flight = "CXR 578";
				time = "2022-06-19 6:30";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight CXR 578" << endl;
			}
			else if (choice3 == 2)
			{
				price = 102.0;
				flight = "CXR 579";
				time = "2022-06-20 9:30";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight CXR 579" << endl;
			}
			else if (choice3 == 3)
			{
				price = 101.0;
				flight = "CXR 573";
				time = "2022-06-21 12:45";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight CXR 573" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl;
				cout << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
			
		case 4:
			destination = "HUE";
			
			cout << "1. HUI 235" << endl;
			cout << "2022-06-24 8:30 1hrs15mins 77$" << endl;
			
			cout << "2. HUI 236" << endl;
			cout << "2022-06-25 7:30 1hrs15mins 77$" << endl;
			
			cout << "3. HUI 239" << endl;
			cout << "2022-06-26 15:45 1hrs15mins 77$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 77.0;
				flight = "HUI 235";
				time = "2022-06-24 8:30";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight HUI 235" << endl;
			}
			else if (choice3 == 2)
			{
				price = 77.0;
				flight = "HUI 236";
				time = "2022-06-25 7:30";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight HUI 236" << endl;
			}
			else if (choice3 == 3)
			{
				price = 77.0;
				flight = "HUI 239";
				time = "2022-06-26 15:45";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight HUI 239" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl;
				cout << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
		
		case 5:
			destination = "DA LAT";
			
			cout << "1. DLI 1873" << endl;
			cout << "2022-06-26 20:30 1hrs55mins 97$" << endl;
			
			cout << "2. DLI 1836" << endl;
			cout << "2022-06-27 15:00 2hrs00mins 95$" << endl;
			
			cout << "3. DLI 1837" << endl;
			cout << "2022-06-28 12:15 1hrs50mins 100$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 97.0;
				flight = "DLI 1873";
				time = "2022-06-26 20:30";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight DLI 1873" << endl;
			}
			else if (choice3 == 2)
			{
				price = 95.0;
				flight = "DLI 1836";
				time = "2022-06-27 15:00";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight DLI 1836" << endl;
			}
			else if (choice3 == 3)
			{
				price = 100.0;
				flight = "DLI 1837";
				time = "2022-06-28 12:15";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight DLI 1837" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl;
				cout << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
		default:
			cout << "Invalid input! Please try again!" << endl;
			cout << endl;
			Booking::Domestic();
			break;
	}
}

/******************************************************
// Define Domestic function from booking class
// This function is used to book international flights
******************************************************/

void Booking::International()
{
	cout << "\t\t\t\t\t" << "VIETNAM AIRLINES" << endl;
	
	string Flights[] = {"BARCELONA", "LOS ANGELES", "SEOUL", "SHANGHAI", "SINGAPORE"};
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". FLIGHT TO " << Flights[i] << endl;
	}
	
	cout << "Please enter your choice: ";
	cin >> choice2;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	
	switch(choice2)
	{
		case 1:
			destination = "BARCELONA";
			cout << "1. BCN 27604" << endl;
			cout << "2022-07-01 19:30 16hrs45mins 1986$" << endl;
			
			cout << "2. BCN 37992" << endl;
			cout << "2022-07-09 00:25 18hrs 1768$" << endl;
			
			cout << "3. BCN 39280" << endl;
			cout << "2022-07-16 10:40 20hrs50mins 1607$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 1986.0;
				flight = "BCN 27604";
				time = "2022-07-01 19:30";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight BCN 27604" << endl;
			}
			else if (choice3 == 2)
			{
				price = 1768.0;
				flight = "BCN 37992";
				time = "2022-07-09 00:25";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight BCN 37992" << endl;
			}
			else if (choice3 == 3)
			{
				price = 1607.0;
				flight = "BCN 39280";
				time = "2022-07-16 10:40";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight BCN 39280" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
			
		case 2:
			destination = "LOS ANGELES";
			cout << "1. LAX 38929" << endl;
			cout << "2022-06-21 23:35 25hrs25mins 1203$" << endl;
			
			cout << "2. LAX 68927" << endl;
			cout << "2022-07-02 10:55 21hrs20mins 1304$" << endl;
			
			cout << "3. LAX 27910" << endl;
			cout << "2022-07-14 12:45 19hrs30mins 1444$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 1203.0;
				flight = "LAX 38929";
				time = "2022-06-21 23:35";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight LAX 38929" << endl;
			}
			else if (choice3 == 2)
			{
				price = 1304.0;
				flight = "LAX 68927";
				time = "2022-07-02 10:55";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight LAX 68927" << endl;
			}
			else if (choice3 == 3)
			{
				price = 1444.0;
				flight = "LAX 27910";
				time = "2022-07-14 12:45";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight LAX 27910" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
			
		case 3:
			destination = "SEOUL";
			cout << "1. ICN 37928" << endl;
			cout << "2022-06-16 1:40 4hrs30mins 372$" << endl;
			
			cout << "2. ICN 37922" << endl;
			cout << "2022-06-24 11:05 4hrs35mins 375$" << endl;
			
			cout << "3. ICN 38298" << endl;
			cout << "2022-06-30 10:05 4hrs35mins 375$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 372.0;
				flight = "ICN 37928";
				time = "2022-06-16 1:40";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight ICN 37928" << endl;
			}
			else if (choice3 == 2)
			{
				price = 375.0;
				flight = "ICN 37922";
				time = "2022-06-24 11:05";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight ICN 37922" << endl;
			}
			else if (choice3 == 3)
			{
				price = 375.0;
				flight = "ICN 38298";
				time = "2022-06-30 10:05";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight ICN 38298" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
			
		case 4:
			destination = "SHANG HAI";
			cout << "1. PVG 73892" << endl;
			cout << "2022-06-20 11:35 7hrs25mins 417$" << endl;
			
			cout << "2. PVG 93793" << endl;
			cout << "2022-06-28 12:05 6hrs55mins 421$" << endl;
			
			cout << "3. PVG 47289" << endl;
			cout << "2022-07-04 13:15 6hrs55mins 422$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 417.0;
				flight = "PVG 73892";
				time = "2022-06-20 11:35";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight PVG 73892" << endl;
			}
			else if (choice3 == 2)
			{
				price = 421.0;
				flight = "PVG 93793";
				time = "2022-06-28 12:05";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight PVG 93793" << endl;
			}
			else if (choice3 == 3)
			{
				price = 422.0;
				flight = "PVG 47289";
				time = "2022-07-04 13:15";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight PVG 47289" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
		
		case 5:
			destination = "SINGAPORE";
			cout << "1. SIN 20238" << endl;
			cout << "2022-06-25 13:10 3hrs20mins 149$" << endl;
			
			cout << "2. SIN 82091" << endl;
			cout << "2022-06-27 14:00 3hrs35mins 146$" << endl;
			
			cout << "3. SIN 29180" << endl;
			cout << "2022-06-29 10:55 3hrs20mins 150$" << endl;
			
			cout << "Please enter your choice: ";
			cin >> choice3;
			cout << endl;
			
			if (choice3 == 1)
			{
				price = 149.0;
				flight = "SIN 20238";
				time = "2022-06-25 13:10";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight SIN 20238" << endl;
			}
			else if (choice3 == 2)
			{
				price = 146.0;
				flight = "SIN 82091";
				time = "2022-06-27 14:00";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight SIN 82091" << endl;
			}
			else if (choice3 == 3)
			{
				price = 150.0;
				flight = "SIN 29180";
				time = "2022-06-29 10:55";
				Ticket::ticket(destination, flight, price, time);
				cout << "You have successfully booked the flight SIN 29180" << endl;
			}
			else
			{
				cout << "Invalid input! Please enter again!" << endl << endl;
				Booking::Domestic();
			}
			
			subMenu();
			
			break;
			
		default:
			cout << "Invalid input! Please try again!" << endl << endl;
			Booking::International();
			break;		
	}
}

/************************************************************************
// 					DEFINE MAIN MENU FUNCTION
// This function is the first page of the booking process
// This is where customers will go through to register their information
************************************************************************/

void mainMenu ()
{
	int choice;
	cout << "\t\t\t\t" << "WELCOME TO VIETNAM AIRLINES" << endl << endl;
	cout << "\t\t" << "THIS IS NOI BAI AIRPORT FLIGHT RESERVATION SYSTEM" << endl;
	cout << "WHERE YOU CAN BOOK FLIGHTS FROM NOI BAI (HA NOI) TO MANY PLACES IN VIETNAM AND AROUND THE WORLD" << endl << endl;
	cout << "MAIN" << endl;
	cout << "1. CUSTOMER REGISTRATION" << endl;
	cout << "2. EXIT" << endl;
	
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	
	Registration regis;
	Booking booking;
	
	switch (choice)
	{
		case 1:
			regis.getInfo();
			booking.Reservation();
			break;
		case 2:
			cout << "Thank you for your interest!" << endl;
			cout << "See you again!" << endl;
			break;
		default:
			cout << "Invalid input! Please enter again!" << endl << endl;
			mainMenu();
			break;
	}	
}

/********************************************************************************
// 						DEFINE SUB MENU FUNCTION
// This function is the page after users book their flights
// This is where customers will go through to print ticket or change information
********************************************************************************/

void subMenu()
{
	int choice;
	cout << "--------------------------------------------" << endl;
	cout << endl << "You have successfully booked a ticket. Now, you can press" << endl << endl;
	cout << "1. PRINT YOUR TICKET" << endl;
	cout << "2. BACK TO PREVIOUS PAGE" << " (*Press this if you want to change your booked flight)" << endl;
	cout << "3. BACK TO MAIN" << " (*Press this if you want to change your registered information and booked flight)"<< endl;
	
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	
	Ticket ticket;
	Booking booking;
	
	switch (choice)
	{
		case 1:
			ticket.showTicket();
			cout << "PAYMENT: ";
			cout << "Please go to the nearest Vietnam Airlines representative office within 7 days to pay for your ticket." << endl;
			cout << "If you fail to complete your payment on time, your booked ticket will be automatically cancelled." << endl;
			cout << "--------------------------------------------" << endl;
			cout << endl;
			another();
			break;
		case 2:
			booking.Reservation();
			break;
		case 3:
			mainMenu();
			break;
		default:
			cout << "Invalid input! Please enter again!" << endl;
			subMenu();
			break;
	}
}

/********************************************************************
// 						DEFINE ANOTHER FUNCTION
// This function is the page after printing ticket
// This is where customers can choose to book another flight or exit
********************************************************************/

void another()
{
	int choice;
	cout << "1. BOOK ANOTHER TICKET" << endl;
	cout << "2. EXIT" << endl;
	
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	
	switch (choice)
	{
		case 1:
			mainMenu();
			break;
		case 2:
			cout << "Thank you for your interest!" << endl;
			cout << "See you again!" << endl;
			break;
		default:
			cout << "Invalid input! Please enter again!" << endl << endl;
			another();
			break;
	}
}

/**********************************************
//		  	DEFINE MANAGEMENT CLASS
// This class is used to start booking process
**********************************************/

class Management
{
	public:
		Management ()
		{
			mainMenu ();
		}
};

/**********************************************
//		  		 MAIN FUNCTION
**********************************************/

int main ()
{
	Management m;
	return 0;
}