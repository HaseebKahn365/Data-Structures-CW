

// extracting the Linked List and Person

#include <cstdlib> // for rand() function
#include <ctime>   // for srand() function
#include <iomanip> // for setw() function

#include <string>

#include "BinarySearchTreeForPreferences.h"

#include <iostream>
using namespace std;

// create a basic car class as rest of the above

class Car
{
public:
    string brand;

    Car(string b)
    {
        brand = b;
    }

    void setBrand(string b)
    {
        brand = b;
    }
};

class Wifi
{
    //add a queue as buffer and array of 10 persons
public:
    bool wifi1;

    void changeValue(bool wifi1)
    {
        this->wifi1 = wifi1;
    }
};


class Bluetooth
{
    //add a queue as buffer and array of 10 persons
public:
    bool Bluetooth;

    void changeValue(bool Bluetooth)
    {
        this->Bluetooth = Bluetooth;
    }
};

class Heater
{
public:
    int heaterTemp;

    void changeValue(int heaterTemp)
    {
        this->heaterTemp = heaterTemp;
    }
};

class LightsSet
{
public:
    int lightSetIntensity;

    void changeValue(int lightSetIntensity)
    {
        this->lightSetIntensity = lightSetIntensity;
    }
};

class Phone
{
public:
    bool usesPhone;

    void changeValue(bool usesPhone)
    {
        this->usesPhone = usesPhone;
    }
};

class Tablet
{
public:
    bool usesTablet;

    void changeValue(bool usesTablet)
    {
        this->usesTablet = usesTablet;
    }
};

class Laptop
{
public:
    bool usesLaptop;

    void changeValue(bool usesLaptop)
    {
        this->usesLaptop = usesLaptop;
    }
};

class PC
{
public:
    bool usesPC;

    void changeValue(bool usesPC)
    {
        this->usesPC = usesPC;
    }
};

class Garage
{
public:
    int counter;
    Car *CArrray[2];

    Garage() : counter(0) {}

    void InsertCar(Car *c1)
    {
        if (counter < 2)
        {
            CArrray[counter] = c1;
            counter++;
        }
        else
        {
            cout << "Garage is full";
        }
    }
};

class GenServices
{
public:
    Wifi wifi1;
    Bluetooth b1;
    Heater h1;
    LightsSet set1;
    Garage g1;
};

class SpecServices
{
public:
    Phone p1;
    Tablet t1;
    Laptop L1;
    PC p2; // Note: Corrected from p1 to p2
};

class HPerson
{
public:
    int person_id;
    bool isOwner;
    Prefference *pref;
    HPerson *next;

    HPerson(int id, bool isO, Prefference *p)
    {
        person_id = id;
        isOwner = isO;
        pref = p;
        next = NULL;
    }
};

class HLinkedList
{
    HPerson *head;
    int count;

public:
    HPerson *getNthNode(int n)
    {
        HPerson *temp = head;
        for (int i = 0; i < n; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    void insertFirst(HPerson *p)
    {
        if (head == NULL)
        {
            head = p;
            count++;
        }
        else
        {
            p->next = head;
            head = p;
            count++;
        }
    }

    HPerson *removeFirst()
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            HPerson *temp = head;
            head = head->next;
            count--;
            return temp;
        }
    }

    HLinkedList()
    {
        head = NULL;
        count = 0;
    }

    int size()
    {
        return count;
    }

    HPerson *search(int id)
    {
        HPerson *temp = head;
        while (temp != NULL)
        {
            if (temp->person_id == id)
            {
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }

    void deleteNode(int id)
    {
        HPerson *temp = head;
        HPerson *prev = NULL;

        while (temp != NULL)
        {
            if (temp->person_id == id)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }

                delete temp;
                count--;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }
};


class Home {
public:
    int persCount;
    HLinkedList people;
    AVLTree allPreferences;


    Home() : persCount(0) {}
    //registerUser

    void registerUser() {
        Prefference *pref = new Prefference();
        HPerson *person = new HPerson(persCount, false, pref);
        people.insertFirst(person);
        
        persCount++;
    }

   

    void displayRandomPerson() {
        int randIndex = rand() % people.size();
        HPerson *person = people.getNthNode(randIndex);
        cout << "Person " << person->person_id << " is here\n";
    }

    void personDetected() {
        int randoption = rand() % 3;
        if (people.size() == 0) {
            registerUser();
        } else {
            switch (randoption) {
                case 0:
                    displayRandomPerson();
                    break;
                case 1:
                    removeRandomPerson();
                    break;
                case 2:
                    registerUser();
                    break;
                default:
                    break;
            }
        }

        // Display the main interface after detection actions
        displayMainInterface();
    }

    void displayMainInterface() {
        cout << "Welcome Owner: "; // Assuming you get owner's name here
        string ownerName;
        cin >> ownerName; // Get the owner's name from user input

        cout << "Pick from the following Services:\n";
        cout << "1. General Services\n";
        cout << "2. Special Services\n";
        cout << "3. Delete other preferences\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayGeneralServices(ownerName);
                break;
            case 2:
                displaySpecialServices(ownerName);
                break;
            case 3:
                // Add logic for deleting preferences (not implemented in the provided code)
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }

    void displayGeneralServices(const string& ownerName) {
        cout << "General Services:\n";
        cout << "1. WIFI\n";
        cout << "2. Bluetooth\n";
        cout << "3. Heater\n";
        cout << "4. Lights Intensity\n";

   

        // Display home status after updating services
        displayHomeStatus(ownerName);
    }

    void displaySpecialServices(const string& ownerName) {
        cout << "Special Services:\n";

       

        // Display home status after updating services
        displayHomeStatus(ownerName);
    }

    void displayHomeStatus(const string& ownerName) {
        cout << "Displaying Home Status:\n";

        // Display information for each person in the linked list
        HNodePref *currentNode = allPreferences.getRoot();
        while (currentNode != NULL) {
            HPerson *person = people.search(currentNode->pref_id);
            if (person != NULL) {
                displayPersonServices(person);
            }
            currentNode = currentNode->right;
        }
    }

     void startSmartHome() {
        char userInput;
        do {
            cout << "Press 'D' to simulate person detection, or 'Q' to quit: ";
            cin >> userInput;

            if (userInput == 'D' || userInput == 'd') {
                personDetected();
            } else if (userInput != 'Q' && userInput != 'q') {
                cout << "Invalid input. Try again.\n";
            }
        } while (userInput != 'Q' && userInput != 'q');
    }

private:
    void insertPerson() {
        HPerson *newPerson = createUser();
        allPreferences.insert(new HNodePref(newPerson->person_id, *newPerson->pref));
        people.insertFirst(newPerson);
    }

    void removeRandomPerson() {
        int randomPersonId = getRandomPersonId();
        people.deleteNode(randomPersonId);
        allPreferences.deleteNode(randomPersonId);
    }

    void displayPersonServices(HPerson *person) {
        cout << person->person_id << "- Services:\n";
        cout << "Bluetooth: using [" << setw(3) << rand() % 100 << "%]\n";
        cout << "Wifi: using [" << setw(3) << rand() % 100 << "%]\n";
        cout << "Lights: intensity [" << setw(4) << rand() % 1000 << " lumens]\n";
        cout << "Heater: Temperature [" << setw(3) << rand() % 100 << " C]\n";
        cout << "TV: " << (rand() % 2 ? "watching" : "off") << "\n";
    }

    int getRandomPersonId() {
        if (people.size() > 0) {
            int randomIndex = rand() % people.size();
            HPerson *randomPerson = people.getNthNode(randomIndex);
            return randomPerson->person_id;
        }
        return -1;
    }

    HPerson *createUser() {
        int personId = ++persCount;
        bool isOwner = (rand() % 2 == 0);
        Prefference *pref = createPreference();
        return new HPerson(personId, isOwner, pref);
    }

    Prefference *createPreference() {
        Prefference *pref = new Prefference();
        pref->setWifi(rand() % 2 == 0);
        pref->setBluetooth(rand() % 2 == 0);
        pref->setHeaterTemp(rand() % 100);
        pref->setLightSetIntensity(rand() % 1000);
        pref->setTv(rand() % 2 == 0);
        pref->setUsesLaptop(rand() % 2 == 0);
        pref->setUsesPhone(rand() % 2 == 0);
        pref->setUsesTablet(rand() % 2 == 0);
        pref->setUsesPC(rand() % 2 == 0);
        return pref;
    }

    
};

// int main() {
//     srand(time(0)); // Seed for random number generation

//     Home smartHome;

//     // Simulate person detection (pressing 'D' key)
//     smartHome.startSmartHome();

//     return 0;
// }


//Following content should be displayed according to the project requirements:

// Home User-Interface:
// The home’s services are available all the time whenever the new user enters. This will be simulated using the “D” key which stands for “detection”. The following is what happens when the user presses the D button:
// the person will be detected. This will initiate the personDetected method in the House. This method will first check if there is person in the list of the people of home. If the list is empty then directly call the registerUser method and add the user to the linked list otherwise, we call the selectRandomOption() to display a random person from the list  or remove random person from list or even register an newUser. This will be done at random. The appropriate action will be taken according to the above three random option. After all the detectionAction is done. We will display the main interface in the terminal. This interface will be dynamic. Which means that the values of some of the services will be randomly updated to make the ui more refreshing.
// Here is a generic UI of the terminal from start to end:
// // (d is pressed)
// “Welcome Owner: “ // asks for owner name i.e. “Haseeb”.
// Pick from the following Services:
// 1.	General Services
// 2.	Special Services
// 3.	Delete other preferences
// General Services:
// 1.	WIFI
// 2.	Bluetooth
// 3.	Heater
// 4.	Lights Intensity
// Displaying Home Status:
// 1-	Haseeb
// Services:
// Bluetooth: using [34%] //just for styling the 
// Wifi: using [50%]
// Lights: intensity [500 lumins]
// Heater: Temperature [37 C]
// TV: watching
// //Special Services.
// Phone: using it.
// Laptop: using it.
// Tablet: using it //don’t display the services not being used
// 2-	Friend
// Services:
// Bluetooth: using [34%] // these values update dynamically just for visibility
// Wifi: using [50%]
// Lights: intensity [500 lumins]
// Heater: Temperature [37 C]
// TV: watching

// …and so, one for all the users in the linked list. We will constantly listen for the “D” character 


class Home {
    public:
    int persCount;
    HLinkedList people;
    HBST allPreferences;

    Home() : persCount(0) {}

    void registerUser() {
        Prefference *pref = new Prefference();
        HPerson *person = new HPerson(persCount, false, pref);
        people.insertFirst(person);
        persCount++;
    }

    void displayRandomPerson() {
        int randIndex = rand() % people.size();
        HPerson *person = people.getNthNode(randIndex);
        cout << "Person " << person->person_id << " is here\n";
    }

    void personDetected() {
        
        

        // Display the main interface after detection actions
        displayMainInterface();
    }

    void displayMainInterface() {
        cout << "Welcome Owner: "; // Assuming you get owner's name here
        string ownerName;
        cin >> ownerName; // Get the owner's name from user input

        cout << "Pick from the following Services:\n";
        cout << "1. General Services\n";
        cout << "2. Special Services\n";
        cout << "3. Delete other preferences\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayGeneralServices(ownerName);
                break;
            case 2:
                displaySpecialServices(ownerName);
                break;
            case 3:
                // Add logic for deleting preferences (not implemented in the provided code)
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }

    void displayGeneralServices(const string& ownerName) {
        cout << "General Services:\n";
        cout << "1. WIFI\n";
        cout << "2. Bluetooth\n";
        cout << "3. Heater\n";
        cout << "4. Lights Intensity\n";

        // Assuming you have code here to handle user input for general services
        // ...

        // Display home status after updating services
        displayHomeStatus(ownerName);
    }

    void displaySpecialServices(const string& ownerName) {
        cout << "Special Services:\n";

        // Assuming you have code here to handle user input for special services
        // ...

        // Display home status after updating services
        displayHomeStatus(ownerName);
    }

    void displayHomeStatus(const string& ownerName) {
        cout << "Displaying Home Status:\n";

        // Display information for each person in the linked list
        HNodePref *currentNode = allPreferences.getRoot();
        while (currentNode != NULL) {
            HPerson *person = people.search(currentNode->pref_id);
            if (person != NULL) {
                displayPersonServices(person);
            }
            currentNode = currentNode->right;
        }
    }

    void startSmartHome() {
        char userInput;
        do {
            cout << "Press 'D' to simulate person detection, or 'Q' to quit: ";
            cin >> userInput;

            if (userInput == 'D' || userInput == 'd') {
                personDetected();
            } else if (userInput != 'Q' && userInput != 'q') {
                cout << "Invalid input. Try again.\n";
            }
        } while (userInput != 'Q' && userInput != 'q');
    }

    void displayPersonServices(HPerson *person) {
        cout << person->person_id << "- " << "haseeb" << "\n";
        cout << "Services:\n";

        // Assuming you have code here to display the services of a person
        // ...
    } 

   
};

int main() {
    srand(time(0)); // Seed for random number generation

    Home smartHome;

    // Simulate person detection (pressing 'D' key)
    smartHome.startSmartHome();

    return 0;
}

