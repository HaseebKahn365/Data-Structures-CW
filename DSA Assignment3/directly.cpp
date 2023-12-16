#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Define classes
class Preferences {
public:
    bool wifi;
    bool bluetooth;
    int heaterTemp;
    int lightSetIntensity;
    bool TV;
    bool usesLaptop;
    bool usesPhone;
    bool usesTablet;
    bool usesPC;

    Preferences() {
        // Initialize preferences with default values
        wifi = false;
        bluetooth = false;
        heaterTemp = 0;
        lightSetIntensity = 0;
        TV = false;
        usesLaptop = false;
        usesPhone = false;
        usesTablet = false;
        usesPC = false;
    }
};

class Person {
public:
    int personID;
    bool isOwner;
    string ownerName;
    Preferences preferences;

    Person(int id, bool owner) : personID(id), isOwner(owner) {
        if (isOwner) {
            cout << "Welcome Owner: ";
            cin >> ownerName;
            acquireServicesAndRegister();
        }
    }

    void acquireServicesAndRegister() {
        cout << "Enter preferences for General Services:\n";
        cout << "WiFi (1/0): ";
        cin >> preferences.wifi;
        cout << "Bluetooth (1/0): ";
        cin >> preferences.bluetooth;
        cout << "Heater Temperature: ";
        cin >> preferences.heaterTemp;
        cout << "Lights Intensity: ";
        cin >> preferences.lightSetIntensity;
        cout << "TV (1/0): ";
        cin >> preferences.TV;

        if (isOwner) {
            cout << "Enter preferences for Special Services:\n";
            cout << "Use Laptop (1/0): ";
            cin >> preferences.usesLaptop;
            cout << "Use Phone (1/0): ";
            cin >> preferences.usesPhone;
            cout << "Use Tablet (1/0): ";
            cin >> preferences.usesTablet;
            cout << "Use PC (1/0): ";
            cin >> preferences.usesPC;
        }
    }

    void displayPreferences() {
        cout << "Services:\n";
        cout << "Bluetooth: using [" << (preferences.bluetooth ? "34%" : "0%") << "]\n";
        cout << "WiFi: using [" << (preferences.wifi ? "50%" : "0%") << "]\n";
        cout << "Lights: intensity [" << preferences.lightSetIntensity << " lumens]\n";
        cout << "Heater: Temperature [" << preferences.heaterTemp << " C]\n";
        cout << "TV: " << (preferences.TV ? "watching" : "off") << "\n";

        if (isOwner) {
            cout << "Special Services:\n";
            cout << "Phone: " << (preferences.usesPhone ? "using it" : "not in use") << "\n";
            cout << "Laptop: " << (preferences.usesLaptop ? "using it" : "not in use") << "\n";
            cout << "Tablet: " << (preferences.usesTablet ? "using it" : "not in use") << "\n";
            cout << "PC: " << (preferences.usesPC ? "using it" : "not in use") << "\n";
        }
    }
};

class Home {
public:
    vector<Person> people;

    void personDetected() {
        int randOption = rand() % 3;
        if (people.empty()) {
            insertPerson();
        } else if (randOption == 0) {
            displayRandomPerson();
        } else if (randOption == 1) {
            removeRandomPerson();
        } else {
            insertPerson();
        }
    }

    void insertPerson() {
        int personID = people.size() + 1;
        bool isOwner = (personID == 1);  // The first person is the owner
        Person newPerson(personID, isOwner);
        people.push_back(newPerson);
        displaySmartHouse();
    }

    void removeRandomPerson() {
        if (!people.empty()) {
            int randIndex = rand() % people.size();
            people.erase(people.begin() + randIndex);
            displaySmartHouse();
        }
    }

    void displayRandomPerson() {
        if (!people.empty()) {
            int randIndex = rand() % people.size();
            people[randIndex].displayPreferences();
        }
    }

    void displaySmartHouse() {
        cout << "Displaying Home Status:\n";
        for ( auto &person : people) {
            cout << person.personID << "- " << person.ownerName << "\n";
            person.displayPreferences();
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed for random number generation
    Home smartHome;

    while (true) {
        char input;
        cout << "(d is pressed)\n";
        cout << "Pick from the following Services:\n";
        cout << "1. General Services\n";
        cout << "2. Special Services\n";
        cout << "3. Delete other preferences\n";

        cin >> input;

        if (input == 'd') {
            smartHome.personDetected();
        } else if (input == '1') {
            cout << "General Services:\n";
            smartHome.displaySmartHouse();
        } else if (input == '2') {
            cout << "Special Services:\n";
            smartHome.displaySmartHouse();
        } else if (input == '3') {
            // Implement deletion of preferences if needed
        }
    }

    return 0;
}
