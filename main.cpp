#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

const int max_size = 10;
int total_bookings = 0, total_arrivals = 5, total_departures = 5;

// Structures

struct flights
{
  string airline;
  string flight_number;
  int total_seats;
  char is_available;
};

struct arrivals
{
  string airline;
  string flight_number;
  string arrival_time;
  string arrival_city;
  bool is_arrived;
};

struct departures
{
  string airline;
  string flight_number;
  string departure_time;
  string departure_city;
  bool is_departed;
};

struct bookings
{
  string name;
  string fromCity;
  string toCity;
  string departDate;
  char ticketType;
  string flightNumber;
};

// Structures

class Admin
{
protected:
  flights flight_info[max_size];
  arrivals arrival_info[max_size] = {
      {"British Airways", "BA1234", "6:00", "Delhi", false},
      {"Virgin", "BA1235", "12:00", "Islamabad", true},
      {"Turkish Airways", "BA1236", "8:00", "Lahore", false},
      {"British Airways", "BA1237", "6:00", "Doha", true},
      {"British Airways", "BA1238", "7:00", "San Jose", true},
  };
  departures departure_info[max_size] = {
      {"British Airways", "BA1234", "4:00", "California", false},
      {"Virgin", "BA1235", "7:00", "Vienna", true},
      {"Turkish Airways", "BA1236", "2:00", "Karachi", false},
      {"British Airways", "BA1237", "5:00", "Manchester", true},
      {"British Airways", "BA1238", "9:00", "San Jose", true},
  };
  bookings bookingsDetail[max_size];

public:
  Admin()
  {
    for (int i = 0; i < max_size; i++)
    {
      flight_info[i].airline = "";
      flight_info[i].flight_number = "";
      flight_info[i].total_seats = 0;
      flight_info[i].is_available = ' ';

      arrival_info[i].airline = "";
      arrival_info[i].flight_number = "";
      arrival_info[i].arrival_time = "";
      arrival_info[i].arrival_city = "";
      arrival_info[i].is_arrived = false;

      departure_info[i].airline = "";
      departure_info[i].flight_number = "";
      departure_info[i].departure_time = "";
      departure_info[i].departure_city = "";
      departure_info[i].is_departed = false;

      bookingsDetail[i].name = "";
      bookingsDetail[i].fromCity = "";
      bookingsDetail[i].toCity = "";
      bookingsDetail[i].departDate = "";
      bookingsDetail[i].ticketType = ' ';
      bookingsDetail[i].flightNumber = "";
    }
  }

  void add_flight()
  {
    int how_many_flights;
    cout << "How many flights do you want to add? ";
    cin >> how_many_flights;
    for (int i = 0; i < how_many_flights; i++)
    {
      cout << "Enter airline: ";
      cin.ignore();
      getline(cin, flight_info[i].airline);
      cout << "Enter flight number: ";
      cin >> flight_info[i].flight_number;
      cout << "Enter total seats: ";
      cin >> flight_info[i].total_seats;
      cout << "Enter availability: (y|n)";
      cin >> flight_info[i].is_available;
    }
  }

  void add_arrivals()
  {
    char choice;
    cout << "Enter airline: ";
    cin.ignore();
    getline(cin, arrival_info[total_arrivals - 1].airline);
    cout << "Enter flight number: ";
    cin >> arrival_info[total_arrivals - 1].flight_number;
    cout << "Enter arrival time: ";
    cin >> arrival_info[total_arrivals - 1].arrival_time;
    cout << "Enter arrival city: ";
    cin >> arrival_info[total_arrivals - 1].arrival_city;
    cout << "Enter arrival status: (y|n)";
    cin >> choice;
    (choice == 'y') ? arrival_info[total_arrivals - 1].is_arrived = true : arrival_info[total_arrivals - 1].is_arrived = false;
    total_arrivals++;
    cout << "Arrival added successfully!" << endl;
  }

  void add_departures()
  {
    char choice;
    cout << "Enter airline: ";
    cin.ignore();
    getline(cin, departure_info[total_departures - 1].airline);
    cout << "Enter flight number: ";
    cin >> departure_info[total_departures - 1].flight_number;
    cout << "Enter departure time: ";
    cin >> departure_info[total_departures - 1].departure_time;
    cout << "Enter departure city: ";
    cin >> departure_info[total_departures - 1].departure_city;
    cout << "Enter departure status: (y|n)";
    cin >> choice;
    (choice == 'y') ? departure_info[total_departures - 1].is_departed = true : departure_info[total_departures - 1].is_departed = false;
    total_departures++;
    cout << "Departure added successfully!" << endl;
  }

  void showAllFlights()
  {
    for (int i = 0; i < max_size; i++)
    {
      cout << "Flight Number " << i + 1 << " " << endl;
      cout << "====================================" << endl;
      cout << "Airline: " << flight_info[i].airline << endl;
      cout << "Flight number: " << flight_info[i].flight_number << endl;
      cout << "Total seats: " << flight_info[i].total_seats << endl;
      cout << "Availability: " << (flight_info[i].is_available == 'y' ? "Yes" : "No") << endl;
      cout << "====================================" << endl;
      cout << endl;
    }
  }

  void showAllBookings()
  {
    for (int i = 0; i < max_size; i++)
    {
      cout << "Booking Number " << i + 1 << " " << endl;
      cout << "====================================" << endl;
      cout << "Name: " << bookingsDetail[i].name << endl;
      cout << "From: " << bookingsDetail[i].fromCity << endl;
      cout << "To: " << bookingsDetail[i].toCity << endl;
      cout << "Departure Date: " << bookingsDetail[i].departDate << endl;
      if (bookingsDetail[i].ticketType == 'E')
        cout << "Ticket Type: Economy" << endl;
      else if (bookingsDetail[i].ticketType == 'B')
        cout << "Ticket Type: Business" << endl;
      cout << "====================================" << endl;
      cout << endl;
    }
  }

  void searchBooking()
  {
    string name;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    for (int i = 0; i < max_size; i++)
    {
      if (bookingsDetail[i].name == name)
      {
        cout << "Booking Number " << i + 1 << " " << endl;
        cout << "====================================" << endl;
        cout << "Name: " << bookingsDetail[i].name << endl;
        cout << "From: " << bookingsDetail[i].fromCity << endl;
        cout << "To: " << bookingsDetail[i].toCity << endl;
        cout << "Departure Date: " << bookingsDetail[i].departDate << endl;
        if (bookingsDetail[i].ticketType == 'E')
          cout << "Ticket Type: Economy" << endl;
        else if (bookingsDetail[i].ticketType == 'B')
          cout << "Ticket Type: Business" << endl;
        cout << "====================================" << endl;
        cout << endl;
      }
    }
  }

  void searchFlight()
  {
    string flight_number;
    cout << "Enter flight number: ";
    cin.ignore();
    getline(cin, flight_number);
    for (int i = 0; i < max_size; i++)
    {
      if (flight_info[i].flight_number == flight_number)
      {
        cout << "Flight Number " << i + 1 << " " << endl;
        cout << "====================================" << endl;
        cout << "Airline: " << flight_info[i].airline << endl;
        cout << "Flight number: " << flight_info[i].flight_number << endl;
        cout << "Total seats: " << flight_info[i].total_seats << endl;
        cout << "Availability: " << flight_info[i].is_available << endl;
        cout << "====================================" << endl;
        cout << endl;
      }
    }
  }

  ~Admin()
  {
    cout << "Admin class destructor called" << endl;
  }
};

class Customer : public Admin
{

public:
  void showDepartures()
  {
    for (int i = 0; i < max_size; i++)
    {
      cout << "Flight Number " << i + 1 << " " << endl;
      cout << "====================================" << endl;
      cout << "Airline: " << departure_info[i].airline << endl;
      cout << "Flight number: " << departure_info[i].flight_number << endl;
      cout << "Departure time: " << departure_info[i].departure_time << endl;
      cout << "Departure city: " << departure_info[i].departure_city << endl;
      cout << "Departure status: " << ((departure_info[i].is_departed == true) ? "Departed" : "Cancelled") << endl;
      cout << "====================================" << endl;
      cout << endl;
    }
  }

  void showArrivals()
  {
    for (int i = 0; i < max_size; i++)
    {
      cout << "Flight Number " << i + 1 << " " << endl;
      cout << "====================================" << endl;
      cout << "Airline: " << arrival_info[i].airline << endl;
      cout << "Flight number: " << arrival_info[i].flight_number << endl;
      cout << "Arrival time: " << arrival_info[i].arrival_time << endl;
      cout << "Arrival city: " << arrival_info[i].arrival_city << endl;
      cout << "Arrival status: " << ((arrival_info[i].is_arrived == true) ? "Arrived" : "Cancelled") << endl;
      cout << "====================================" << endl;
      cout << endl;
    }
  }

  void bookTicket()
  {
    string name;
    string fromCity;
    string toCity;
    string departDate;
    char ticketType;
    int select_flight;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter from city: ";
    getline(cin, fromCity);
    cout << "Enter to city: ";
    getline(cin, toCity);
    cout << "Enter departure date: ";
    getline(cin, departDate);
    cout << "Enter ticket type: (E|B)";
    cin >> ticketType;

    showAllFlights();
    cout << "Select Flight: " << endl;
    cin >> select_flight;
    if (select_flight > max_size)
    {
      cout << "Flight Does not exist" << endl;
      return;
    }
    if (flight_info[select_flight - 1].is_available == false)
    {
      cout << "Flight is not available" << endl;
      return;
    }

    bookingsDetail[total_bookings].name = name;
    bookingsDetail[total_bookings].fromCity = fromCity;
    bookingsDetail[total_bookings].toCity = toCity;
    bookingsDetail[total_bookings].departDate = departDate;
    bookingsDetail[total_bookings].ticketType = ticketType;
    bookingsDetail[total_bookings].flightNumber = flight_info[select_flight - 1].flight_number;
  }

  ~Customer()
  {
    cout << "Customer class destructor called" << endl;
  }
};

void showMenuType(bool isAdmin)
/*
This function is used to show the different menus for admin and user.
*/
{
  if (!isAdmin)
  {
    cout << endl;
    cout << "Press 1 to show arrivals" << endl;
    cout << "Press 2 to show departures" << endl;
    cout << "Press 3 to book a flight" << endl;
    cout << "Press 4 to print flight info" << endl;
    cout << "Press 0 to switch to Admin" << endl;
    cout << "Press 10 to exit" << endl;
    cout << endl;
  }
  else
  {
    cout << endl;
    cout << "Press 1 to add a flight" << endl;
    cout << "Press 2 to show all flights" << endl;
    cout << "Press 3 to show all bookings" << endl;
    cout << "Press 5 to search a booking" << endl;
    cout << "Press 6 to search a flight" << endl;
    cout << "Press 7 to add departure" << endl;
    cout << "Press 8 to add arrival" << endl;
    cout << "Press 0 to switch to Customer" << endl;
    cout << "Press 10 to exit" << endl;
    cout << endl;
  }
}

void validateAdmin(string &line, string &adminPassword, string &enteredPassword, ifstream &inFile, bool &isAdmin)
{

  while (getline(inFile, line))
  {
    adminPassword = line.substr(line.find("=") + 1, line.length());
  }

  if (enteredPassword == adminPassword)
  {
    cout << "Login Successfull" << endl;
    isAdmin = true;
  }
  else
  {
    cout << "Login Failed" << endl;
    isAdmin = false;
  }
}

int main()
{
  system("color 09");
  Admin airport;
  Customer customer;
  int choice, choice2;

  // These vars are used for admin validation
  bool isAdmin = false;
  string line, adminPassword, enteredPassword;
  ifstream inFile;
  inFile.open("airport.txt");

  cout << "Press 1 to login as admin" << endl;
  cout << "Press 2 to login as user" << endl;
  cin >> choice2;

  if (choice2 == 1)
  {
    cout << "Enter password: ";
    cin >> enteredPassword;
    validateAdmin(line, adminPassword, enteredPassword, inFile, isAdmin);
  }
  inFile.close();

  do
  {
    showMenuType(isAdmin);
    cin >> choice;

    if (isAdmin)
    {
      switch (choice)
      {
      case 1:
        airport.add_flight();
        break;

      case 2:
        airport.showAllFlights();
        break;

      case 3:
        airport.showAllBookings();
        break;

      case 7:
        airport.add_departures();
        break;

      case 8:
        airport.add_arrivals();
        break;

      case 0:
        isAdmin = false;
        system("cls");
        break;

      case 10:
        break;

      default:
        cout << "Invalid choice" << endl;
        break;
      }
    }
    else
    {
      switch (choice)
      {
      case 1:
        customer.showArrivals();
        break;

      case 2:
        customer.showDepartures();
        break;

      case 3:
        customer.bookTicket();
        break;

      case 10:
        break;

      case 0:
        isAdmin = true;
        system("cls");
        break;
      default:
        cout << "Invalid choice" << endl;
        break;
      }
    }

  } while (choice != 10);

  system("pause");
  return 0;
}
