/*
Cars game: 
Task Desciption:

This game is a simple console based game. The control flow is described as follows: we first create a grid of points using a function 
static void createPoints(int xCount, int yCount) {
    for (int i = 0; i < xCount; i++) {
      for (int j = 0; j < yCount; j++) {
        allPoints.add(Points(xCord: j, yCord: i)); 
      }
    }
  }

Global Lists:
List<Point> allPoints; //this contains all the grid points of the game;
List<Point> carPositions; //this contains all the positions of the cars
List<Car> carList;
AllPoints in the above case is the list of the points that are created for the game. This means that we can reference a point using allPoints[index] in the list. The following is the description of the Point
Point
Members:
Int xCord;
Int yCord;
Methods:
Points({this. xCord, this. yCord}); //use C++ syntax here
Overload the equality operator for Point:
bool operator ==(Point p2){
if(this.xCord == p2.xCord && this.yCord == p2.yCord){return true;} else {return false;}
}
Bool checkPointPresence (Points &p){
If (point exists in list){
     Return true;
} else {return false;}
}



Cars
Members:
Point position;
Bool team; //indication of red or blue color for the car
Int index; //this is the index of the car
Methods:

Void changeDirection(int direction){
Switch(direction){

Case 1: 
//move forward if not upper boundary
if (position.yCord != 0){
postion.yCord--;// the car moves up so the ycord decreases

}
Break;

Case 2: 
//move backward if not lower boundary
if (position.yCord != noOfYPoints-1){
postion.yCord++; //the car moves down so y coordinate increases
}
Break;

Case 3: 
//move left if not left boundary
if (position.xCord != 0){
postion.xCord--; //the car moves left so x coordinate decreases
}
Break;

Case 4: 
//move right if not right boundary
if (position.xCord != noOfYPoints-1){
postion.xCord++; //the car moves right so x coordinate increases
}
Break;

Default:
Cout<<”invalid direction”;


}

}

Start of the game:
The following description contains pseudocode and is not executable. At the start of the game we have two global int variables that define the boundary of the game ie.
int noOfXPoints = 20; //20 points on horizontal axis.
int noOfYPoints = 20; //20 points on vertical axis.
We also have three global lists ie.
List<Point> allPoints; //this contains all the grid points of the game;
List<Point> carPositions; //this contains all the positions of the cars
List<Car> carList; //this is the list of all the cars created.

We start with creating the grid for the game. This is the screen resolution. The following createPoints() will add the points of the grid to the list of allPoints:
void createPoints(int noOfXPoints, int noOfYPoints) {
    for (int i = 0; i < xCount; i++) {
      for (int j = 0; j < yCount; j++) {
        allPoints.push_back(new Points(xCord: j, yCord: i)); 
      }
    }
  }

After creating the points, now we create cars and add it to the list of the cars. We will create only 10 cars at random positions within the range of boundaries and add these to the list using the constructor of the Car class ie.
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      carList.push_back(new Car(
          position: allPoints[rand() % (noOfXPoints * noOfYPoints - 1)],
          team: true,
          index: i));
    } else {
      carList.push_back(new Car(position: allPoints[rand() % (noOfXPoints * noOfYPoints - 1)], team: false, index: i));
    }
  }

Now we fill out the carPositions list, using the positions of each car in the carList.
for (int i = 0; i < carList.length; i++) {
    carPositions.push_back(carList[i].position);
  }

Checking for collision after cars creation:
Now that the cars are created and we also have their postions in the carPositions lists now we have to see if there are any collisions between the cars. To check this, we simply create a function in which we have to go trough each position in the carPositions list and check if there are more than one instance of the same position in the list if there are several instances of the same position found then, we will display a message that will show the number of cars (using the number of instances of position) that have collided and the xCord and yCord of this position. And we will exit the game.
 void checkCollision() {
    for (int i = 0; i < carPositions.length; i++) {
      int count = 0;
      for (int j = 0; j < carPositions.length; j++) {
        if (carPositions[i] == carPositions[j]) {
          count++;
        }
      }
      if (count > 1) {
        cout << "Collision detected at position: " << carPositions[i].xCord << ", " << carPositions[i].yCord << endl;
        cout << "Number of cars collided: " << count << endl;
        //remove the cars that have collided from the carList

        for (int k = 0; k < carList.length; k++) {
          if (carList[k].position == carPositions[i]) {
            carList.removeAt(k);
          }
        }

        //we will display the remaining cars in the carList the details of the displayRemaining() function are described later.
        void displayRemaining();
        exit(0);
      }
    }
  }

Details of the displayRemaining():
This function is responsible for displaying the cars inside the grid. We display a point or a car using the following logic. We first have to go through every point in the allPoints, if we find a point which matches the position in carPositions, we wil display the car which is on the current position. Here is how we display a car:  if(currentCar.team){cout<<” @ ”;} but this @ symbol should be displayed in red color. While doing this we also have to check if it si the boundary of the grid, if it is, then we will also have to display the cout<<’’\n”, using condition: if(currentPoint.xCord == noOfXPoints -1). Otherwise if the currentCar has team value false, the we will cout<<” # ”; but this time it has to be in blue color. And again we check for the boundary using if(currentPoint.xCord == noOfXPoints -1) then cout<<”\n”.

void displayRemaining() {
    for (int i = 0; i < allPoints.length; i++) {
      Point currentPoint = allPoints[i];
      bool isCar = false;
      for (int j = 0; j < carPositions.length; j++) {
        if (currentPoint == carPositions[j]) {
          isCar = true;
          Car currentCar = carList[j];
          if (currentCar.team) {
            cout << "\033[31m @ \033[0m";
          } else {
            cout << "\033[34m # \033[0m";
          }
          if (currentPoint.xCord == noOfXPoints - 1) {
            cout << "\n";
          }
        }
      }
      if (!isCar) {
        cout << " . ";
        if (currentPoint.xCord == noOfXPoints - 1) {
          cout << "\n";
        }
      }
    }
  }

Randomizing carsPositions:
After checking for collision during the creation of the cars now its time to randomly move the cars 100 times and look for collision each time we randomly move the cars. We will do this by the following logic. We go through every car in the carList and call changeDirection(RandomInt[between 1 and 4]) by doing this we are changing the position of every car in the list using 1,2,3,4 as direction values. After going through every car in the list now we check for collision using checkCollision() and after this we call the displayRemaining again, in case if there were no collision and the control comes out of the checkCollision().

void randomizeCars() {
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < carList.length; j++) {
        carList[j].changeDirection(rand() % 4 + 1);
      }
      checkCollision();
      displayRemaining();
    }
  }



*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int noOfXPoints = 20; // 20 points on horizontal axis.
int noOfYPoints = 20; // 20 points on vertical axis.

class Point {
public:
    int xCord;
    int yCord;

    Point(int x, int y) : xCord(x), yCord(y) {}

    bool operator ==(const Point& p2) const {
        return (xCord == p2.xCord && yCord == p2.yCord);
    }
};

class Car {
public:
    Point position;
    bool team; // Indication of red or blue color for the car
    int index; // This is the index of the car

    Car(const Point& p, bool t, int i) : position(p), team(t), index(i) {}

    void changeDirection(int direction) {
        switch (direction) {
        case 1:
            // Move forward if not upper boundary
            if (position.yCord != 0) {
                position.yCord--;
            }
            break;
        case 2:
            // Move backward if not lower boundary
            if (position.yCord != noOfYPoints - 1) {
                position.yCord++;
            }
            break;
        case 3:
            // Move left if not left boundary
            if (position.xCord != 0) {
                position.xCord--;
            }
            break;
        case 4:
            // Move right if not right boundary
            if (position.xCord != noOfXPoints - 1) {
                position.xCord++;
            }
            break;
        default:
            cout << "Invalid direction" << endl;
        }
    }
};

vector<Point> allPoints;
vector<Point> carPositions;
vector<Car> carList;

void createPoints() {
    for (int i = 0; i < noOfXPoints; i++) {
        for (int j = 0; j < noOfYPoints; j++) {
            allPoints.push_back(Point(j, i));
        }
    }
}

void createCars() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        bool isRed = i < 5; // Alternate between red and blue teams
        Point randomPoint = allPoints[rand() % (noOfXPoints * noOfYPoints)];
        carList.push_back(Car(randomPoint, isRed, i));
    }
}

void fillCarPositions() {
    for (int i = 0; i < carList.size(); i++) {
        carPositions.push_back(carList[i].position);
    }
}

void displayRemaining() {
    for (int i = 0; i < allPoints.size(); i++) {
        Point currentPoint = allPoints[i];
        bool isCar = false;
        for (int j = 0; j < carPositions.size(); j++) {
            if (currentPoint == carPositions[j]) {
                isCar = true;
                Car currentCar = carList[j];
                if (currentCar.team) {
                    cout << "\033[31m @ \033[0m";
                } else {
                    cout << "\033[34m # \033[0m";
                }
                if (currentPoint.xCord == noOfXPoints - 1) {
                    cout << "\n";
                }
            }
        }
        if (!isCar) {
            cout << " . ";
            if (currentPoint.xCord == noOfXPoints - 1) {
                cout << "\n";
            }
        }
    }
}

void checkCollision() {
    for (int i = 0; i < carPositions.size(); i++) {
        int count = 0;
        for (int j = i + 1; j < carPositions.size(); j++) {
            if (carPositions[i] == carPositions[j]) {
                count++;
            }
        }
        if (count > 0) {
            cout << "Collision detected at position: " << carPositions[i].xCord << ", " << carPositions[i].yCord << endl;
            cout << "Number of cars collided: " << count + 1 << endl;
            // Remove the cars that have collided from the carList

            for (int k = carList.size() - 1; k >= 0; k--) {
                if (carList[k].position == carPositions[i]) {
                    carList.erase(carList.begin() + k);
                }
            }

            // We will display the remaining cars in the carList
            displayRemaining();
            exit(0);
        }
    }
}



void randomizeCars() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < carList.size(); j++) {
            carList[j].changeDirection(rand() % 4 + 1);
        }
        checkCollision();
        displayRemaining();
    }
}

int main() {
    createPoints();
    createCars();
    fillCarPositions();
    checkCollision();
    randomizeCars();
    return 0;
}
