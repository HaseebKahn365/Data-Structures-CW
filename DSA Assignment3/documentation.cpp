/*
The planning:
The following is the use-cases of the house. The smart house is going to provide a variety of smart services to the users. The following is what happens:
Registration use-case:
At first there is no one at home. The company issues special digital keys to the owners that will mark the users as owners/residents. The keys are only used for registration as residents they will be recognized automatically later on. For all the other people that enter the house will be marked as guests. 
The owners/residents:
These are the owners of the house that will be able to use all the services of the house, both special and general services.
The guests: 
These will be the people that may come to the house just for a visit or may be party/event etc.
Special services:
These are the shared devices that may only be used by the owners of the house ie. Phone, tablet, laptop that are for house owners (family) only.
General smart services:
These are the services that are available to all types of people that may enter the house. These services include:
Wi-Fi, Bluetooth, Heater, Lights, Garage.
The entrance of people:
The house is going to automatically identify the user and based on the user type provide the specified services. The user will be able to set his preferences for all the services that he uses.  
Using services and saving the preferences:
The user will be able to request services from the smart house. When the user selects the service after the authentication, we will save his preferences or update it if already exists. 

The Software Requirements Documentation:
Home Class:
Class Home{
Int persCount; // used to assign unique id to person_id and pref_id
HLinkedList*<Person> People;
BST*<Preference> allPreferences;
personDetected(){
int randoption = Rand%3;
if(people.isempty()) insertPerson();
elseif(randoption == 0) displayRandomPerson(); //simulate random person entering
elseif(randoption ==1) removeRandomPerson(); //removes the random person from linked list
else insertPerson();
}

displaySmartHouse(); //displays all the users along with their preferences in BST
}
Data Structures:
Garage contains an array of two cars;
People in the house are stored in the linked list;
Preferences objects are stored in the BST;
The buffers of wifi and Bluetooth use Queues.

Home User-Interface:
The home’s services are available all the time whenever the new user enters. This will be simulated using the “D” key which stands for “detection”. The following is what happens when the user presses the D button:
the person will be detected. This will initiate the personDetected method in the House. This method will first check if there is person in the list of the people of home. If the list is empty then directly call the registerUser method and add the user to the linked list otherwise, we call the selectRandomOption() to display a random person from the list  or remove random person from list or even register an newUser. This will be done at random. The appropriate action will be taken according to the above three random option. After all the detectionAction is done. We will display the main interface in the terminal. This interface will be dynamic. Which means that the values of some of the services will be randomly updated to make the ui more refreshing.
Here is a generic UI of the terminal from start to end:
// (d is pressed)
“Welcome Owner: “ // asks for owner name i.e. “Haseeb”.
Pick from the following Services:
1.	General Services
2.	Special Services
3.	Delete other preferences
General Services:
1.	WIFI
2.	Bluetooth
3.	Heater
4.	Lights Intensity
Displaying Home Status:
1-	Haseeb
Services:
Bluetooth: using [34%] //just for styling the 
Wifi: using [50%]
Lights: intensity [500 lumins]
Heater: Temperature [37 C]
TV: watching
//Special Services.
Phone: using it.
Laptop: using it.
Tablet: using it //don’t display the services not being used
2-	Friend
Services:
Bluetooth: using [34%] // these values update dynamically just for visibility
Wifi: using [50%]
Lights: intensity [500 lumins]
Heater: Temperature [37 C]
TV: watching

…and so, one for all the users in the linked list. We will constantly listen for the “D” character 


All classes for services and people and preferences:
Class pref{
// for the general services :
Bool wifi1;
Bool Bluetooth;
Int heaterTemp;
Int lightSetIntensity;
Bool TV;
//for special services:
Bool usesLaptop;
Bool usesPhone;
Bool usesTablet;
Bool usesPC;


};

Class Person{
Int myPersonalID;
Bool isOwner
acquireServicesAndRegister(){
GenServices* g1;
SpecialServices* s1;
//ask the user to enter all the values based on  isOwner. If owner then ask for both g1 and s1 else just g1.
//add the person to the Home’s Linked list and his preferences to the BST using myPersonalID as key.
}

}

Class GenServices{
Wifi wifi1;
Bluetooth b1;
Heater h1;
LightsSet set1;
Garage g1;
}

Class SpecServices{
Phone p1;
Tablet t1;
 laptop L1;
 PC p1;
}
Class Wifi{
Bool wifi1;
changeValue(Bool wifi1){
this->wifi1 = wifi1;
}
}

Class Bluetooth{
Bool Bluetooth;
changeValue(Bool Bluetooth){
this->Bluetooth = Bluetooth;
}
}

Class Heater{
Int heaterTemp;
changeValue(Int heaterTemp){
this->heaterTemp = heaterTemp;
}
}

Class LightsSet{
Int lightSetIntensity;
changeValue(Int lightSetIntensity){
this->lightSetIntensity = lightSetIntensity;
}
}


Class Phone{
Bool usesPhone;
changeValue(Bool usesPhone){
this->usesPhone = usesPhone;
}
}

Class Tablet{
Bool usesTablet;
changeValue(Bool usesTablet){
this->usesTablet = usesTablet;
}
}

Class Laptop{
Bool usesLaptop;
changeValue(Bool usesLaptop){
this->usesLaptop = usesLaptop;
}
}

Class PC{
Bool usesPC;
changeValue(Bool usesPC){
this->usesPC = usesPC;
}
}


Class Garage{
    int counter=0
Car* CArrray[2];

void InsertCar(Car* c1){
    if(counter<2){
        CArrray[counter]=c1;
        counter++;
    })
    else{
        cout<<"Garage is full";
    }

    }
}


Custom DataStructures:
We will be using our own data structures for the linked list of users and BinarySearchTree using Templates so that they could contain any type of objects.

//we need to modify the above Data structures using Template for our needs.
//my name is Haseeb so the name of the data structures will start with H

modifying the Node for BST:

class HNode{
    public:
    int pref_id;
    Prefference pref;
    HNode* left;
    HNode* right; 

    HNode(int id, Prefference p){
        pref_id = id;
        pref = p;
        left = NULL;
        right = NULL;
    } 

    void display(){
        cout<<"Preference ID: "<<pref_id<<endl;
        cout<<"Preference: "<<pref<<endl;
    }
};

modifying the BST:

class HBST{
    HNode* root;

    public:
    HBST(){
        root = NULL;
    }

    void insert(HNode* n){
        if(root == NULL){
            root = n;
        }else{
            HNode* curr = root;
            HNode* parent = NULL;

            while(curr != NULL){
                parent = curr;
                if(n->pref_id < curr->pref_id){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }

            if(n->pref_id < parent->pref_id){
                parent->left = n;
            }else{
                parent->right = n;
            }
        }
    }

    HNode* search(int id){
        HNode* curr = root;

        while(curr != NULL){
            if(curr->pref_id == id){
                return curr;
            }else if(id < curr->pref_id){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        return NULL;
    }

    void deleteNode(int id){
        HNode* curr = root;
        HNode* parent = NULL;

        while(curr != NULL && curr->pref_id != id){
            parent = curr;
            if(id < curr->pref_id){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        if(curr == NULL){
            return;
        }

        if(curr->left == NULL && curr->right == NULL){
            if(parent == NULL){
                root = NULL;
            }else if(parent->left == curr){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
        }else if(curr->left == NULL){
            if(parent == NULL){
                root = curr->right;
            }else if(parent->left == curr){
                parent->left = curr->right;
            }else{
                parent->right = curr->right;
            }
        }else if(curr->right == NULL){
            if(parent == NULL){
                root = curr->left;
            }else if(parent->left == curr){
                parent->left = curr->left;
            }else{
                parent->right = curr->left;
            }
        }else{
            HNode* succParent = curr;
            HNode* succ = curr->right;

            while(succ->left != NULL){
                succParent = succ;
                succ = succ->left;
            }

            if(succParent != curr){
                succParent->left = succ->right;
            }else{
                succParent->right = succ->right;
            }

            succ->left = curr->left;
            succ->right = curr->right;

            if(parent == NULL){
                root = succ;
            }else if(parent->left == curr){
                parent->left = succ;
            }else{
                parent->right = succ;
            }
        }

        delete curr;
    }

    void displayAll(){
        displayAll(root);
    }

    void displayAll(HNode* n){
        if(n != NULL){
            displayAll(n->left);
            n->display();
            displayAll(n->right);
        }
    }
};

modifying the linked list:

class HPerson{
    public:
    int person_id;
    bool isOwner;
    HNode* pref;
    HPerson* next;

    HPerson(int id, bool isO, HNode* p){
        person_id = id;
        isOwner = isO;
        pref = p;
        next = NULL;
    }

    void display(){
        cout<<"Person ID: "<<person_id<<endl;
        cout<<"Is Owner: "<<isOwner<<endl;
        cout<<"Preference: "<<pref<<endl;
    }
};

class HLinkedList{
    HPerson* head;
    int count;

    public:
    HLinkedList(){
        head = NULL;
        count = 0;
    }

    void insertFirst(HPerson* p){
        if(head == NULL){
            head = p;
            count++;
        }else{
            p->next = head;
            head = p;
            count++;
        }
    }

    HPerson* removeFirst(){
        if(head == NULL){
            return NULL;
        }else{
            HPerson* temp = head;
            head = head->next;
            count--;
            return temp;
        }
    }

    int size(){
        return count;
    }

    void displayAll(){
        HPerson* temp = head;
        while(temp != NULL){
            temp->display();
            temp = temp->next;
        }
    }

    HPerson* search(int id){
        HPerson* temp = head;
        while(temp != NULL){
            if(temp->person_id == id){
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }

    void deleteNode(int id){
        HPerson* temp = head;
        HPerson* prev = NULL;

        while(temp != NULL){
            if(temp->person_id == id){
                if(prev == NULL){
                    head = temp->next;
                }else{
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

Developement
Now that we are ready to implement the code. We the output should match the following format.

// (d is pressed)
“Welcome Owner: “ // asks for owner name i.e. “Haseeb”.
Pick from the following Services:
4.	General Services
5.	Special Services
6.	Delete other preferences
General Services:
5.	WIFI
6.	Bluetooth
7.	Heater
8.	Lights Intensity
Displaying Home Status:
3-	Haseeb
Services:
Bluetooth: using [34%] //just for styling the 
Wifi: using [50%]
Lights: intensity [500 lumins]
Heater: Temperature [37 C]
TV: watching
//Special Services.
Phone: using it.
Laptop: using it.
Tablet: using it //don’t display the services not being used
4-	Friend
Services:
Bluetooth: using [34%] // these values update dynamically just for visibility
Wifi: using [50%]
Lights: intensity [500 lumins]
Heater: Temperature [37 C]
TV: watching

…and so, one for all the users in the linked list. We will constantly listen for the “D” character 






*/

//extracting the HBST 

#include <iostream>
#include <string>

using namespace std;



class Prefference{
    public:
    bool wifi;
    bool bluetooth;
    int heaterTemp;
    int lightSetIntensity;
    bool tv;
    bool usesLaptop;
    bool usesPhone;
    bool usesTablet;
    bool usesPC;
    Prefference(){
        wifi = false;
        bluetooth = false;
        heaterTemp = 0;
        lightSetIntensity = 0;
        tv = false;
        usesLaptop = false;
        usesPhone = false;
        usesTablet = false;
        usesPC = false;
    }
    //setter for all the services
    void setWifi(bool w){
        wifi = w;
    }

    void setBluetooth(bool b){
        bluetooth = b;
    }

    void setHeaterTemp(int t){
        heaterTemp = t;
    } 

    void setLightSetIntensity(int i){
        lightSetIntensity = i;
    }

    void setTv(bool t){
        tv = t;
    }

    void setUsesLaptop(bool l){
        usesLaptop = l;
    }

    void setUsesPhone(bool p){
        usesPhone = p;
    }

    void setUsesTablet(bool t){
        usesTablet = t;
    }

    void setUsesPC(bool p){
        usesPC = p;
    }


};


class HNode{
    public:
    int pref_id;
    Prefference pref;
    HNode* left;
    HNode* right; 

    HNode(int id, Prefference p){
        pref_id = id;
        pref = p;
        left = NULL;
        right = NULL;
    } 

    
};

class HBST{
    HNode* root;

    public:
    HBST(){
        root = NULL;
    }

    void insert(HNode* n){
        if(root == NULL){
            root = n;
        }else{
            HNode* curr = root;
            HNode* parent = NULL;

            while(curr != NULL){
                parent = curr;
                if(n->pref_id < curr->pref_id){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }

            if(n->pref_id < parent->pref_id){
                parent->left = n;
            }else{
                parent->right = n;
            }
        }
    }

    HNode* search(int id){
        HNode* curr = root;

        while(curr != NULL){
            if(curr->pref_id == id){
                return curr;
            }else if(id < curr->pref_id){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        return NULL;
    }

    void deleteNode(int id){
        HNode* curr = root;
        HNode* parent = NULL;

        while(curr != NULL && curr->pref_id != id){
            parent = curr;
            if(id < curr->pref_id){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        if(curr == NULL){
            return;
        }

        if(curr->left == NULL && curr->right == NULL){
            if(parent == NULL){
                root = NULL;
            }else if(parent->left == curr){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
        }else if(curr->left == NULL){
            if(parent == NULL){
                root = curr->right;
            }else if(parent->left == curr){
                parent->left = curr->right;
            }else{
                parent->right = curr->right;
            }
        }else if(curr->right == NULL){
            if(parent == NULL){
                root = curr->left;
            }else if(parent->left == curr){
                parent->left = curr->left;
            }else{
                parent->right = curr->left;
            }
        }else{
            HNode* succParent = curr;
            HNode* succ = curr->right;

            while(succ->left != NULL){
                succParent = succ;
                succ = succ->left;
            }

            if(succParent != curr){
                succParent->left = succ->right;
            }else{
                succParent->right = succ->right;
            }

            succ->left = curr->left;
            succ->right = curr->right;

            if(parent == NULL){
                root = succ;
            }else if(parent->left == curr){
                parent->left = succ;
            }else{
                parent->right = succ;
            }
        }

        delete curr;
    }

    void inorder(){
        inorder(root);
    }

    void inorder(HNode* node){
        if(node != NULL){
            inorder(node->left);
            cout<<node->pref_id<<" ";
            inorder(node->right);
        }
    }
    
};

