#include<bits/stdc++.h>
using namespace std;

class Person {
private:
    string name;
    int age;
    string country;

public:
    string passport;

    void inputDetails() {
        cout << "Enter Name:";
        getchar();
        getline(cin,name);
        cout << "Enter Age:";
        cin >> age;
        cout << "Enter Passport:";
        cin >> passport;
        cout << "Enter Country:";
        cin >> country;
    }

    void showDetails() const {
        cout << "Person Name:" << name << endl;
        cout << "Person Age:" << age << endl;
        cout << "Passport:" << passport << endl;
        cout << "Country Name:" << country << endl;
    }
    string getPassport(){
    return passport;
    }
    string getName(){
    return name;
    }
    int getAge(){
    return age;
    }
    string getCountryName(){
    return country;
    }
};

class Ticket {
private:
    string ticketType;

public:
    int choice;

    void selectTicket() {
        cout << "Select Ticket Type:\n1. Economy\n2. Business\n";
        cout << "Enter choice:";
        while(1){
             cin >> choice;
        if (choice == 1) {
            ticketType = "Economy";
            break;
        } else if (choice == 2) {
            ticketType = "Business";
            break;
        } else {
            cout << "Invalid Choice!Choose again.\n";

        }
        }

    }

    void showTicket() const {
        cout << "Ticket Type: " << ticketType << endl;
    }
    string getTicket(){
    return ticketType;
    }
};

class Booking {
public:
    Person person;
    Ticket ticket;
    string flightType;
    string destination;

    void inputBooking() {
        person.inputDetails();
        cout << "---- Flight Type ----"<< endl;
        cout << "1. Domestic" << endl;
        cout << "2. International" <<endl;
        int type;
        while(1){
            cout << "Enter choice:";
        cin >> type;

        if (type == 1) {
            flightType = "Domestic";
            cout << "Enter Domestic Destination:";
            cin.ignore();
            getline(cin,destination);
            break;
        } else if (type == 2) {
            flightType = "International";
            cout << "Enter International Destination:";
             cin.ignore();
            getline(cin,destination);
            break;
        } else {
            cout << "Invalid flight type,Choose again." << endl;

        }
        }


        ticket.selectTicket();
    }

    void showBooking() const {
        person.showDetails();
        cout << "Flight Type:" << flightType << endl;
        cout << "Destination:" << destination << endl;
        ticket.showTicket();
    }
    void File(ofstream &out){
        out << person.getName() << endl;
        out << person.getAge() << endl;
        out << person.getCountryName() << endl;
        out << person.getPassport() << endl;
        out << flightType << endl;
        out << ticket.getTicket() << endl;
        out << destination << endl;
        out << "------------------" << endl;
    }
};

int main() {
    Booking bookings[10];
    int totalPassengers = 0;
    cout << "-----Airline Management System-----" << endl;

    while (1) {
        cout << "1. Enter Passenger Details" << endl;
        cout << "2. Show Passenger Details" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice:";
        int menuChoice;
        cin >> menuChoice;

        if (menuChoice == 1) {
            cout << "How many passengers do you want to enter:";
            cin >> totalPassengers;
            ofstream outfile("Airplane_Management_file.txt");

            for (int i = 0; i < totalPassengers; i++) {
                cout << "--- Entering details for Passenger " << i + 1 << " ---" << endl;
                bookings[i].inputBooking();
                bookings[i].File(outfile);
            }

        } else if (menuChoice == 2) {
            string searchPassport;
            cout << "Enter Passport Number to Search:";
            cin >> searchPassport;

            bool found = false;
            for (int i = 0; i < totalPassengers; i++) {
                if (bookings[i].person.passport == searchPassport) {
                    cout << "--- Passenger Found ---"<< endl;
                    bookings[i].showBooking();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No passenger found with passport:" << searchPassport << endl;
            }

        } else if (menuChoice == 3) {
            cout << "Thank You..."<< endl;
            break;
        } else {
            cout << "Invalid Option! Please try again."<< endl;
        }
    }

    return 0;
}
