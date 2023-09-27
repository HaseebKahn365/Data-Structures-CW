#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int noOfXPoints = 10;
int noOfYPoints = 10;

class Point {
public:
    int xCord;
    int yCord;

    Point() : xCord(0), yCord(0) {}

    Point(int x, int y) : xCord(x), yCord(y) {}

    bool operator==( Point& p2)  {
        return (xCord == p2.xCord && yCord == p2.yCord);
    }
};

class Car {
public:
    Point position;
    bool team;
    int index;

    Car(Point p, bool t, int i) : position(p), team(t), index(i) {}

    void changeDirection(int direction) {
        switch (direction) {
            case 1:
                if (position.yCord != 0) {
                    position.yCord--;
                }
                break;
            case 2:
                if (position.yCord != noOfYPoints - 1) {
                    position.yCord++;
                }
                break;
            case 3:
                if (position.xCord != 0) {
                    position.xCord--;
                }
                break;
            case 4:
                if (position.xCord != noOfXPoints - 1) {
                    position.xCord++;
                }
                break;
            default:
                cout << "Invalid direction" << endl;
                break;
        }
    }
};

vector<Point> allPoints;
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


void displayRemaining() {
    for (int i = 0; i < allPoints.size(); i++) {
        Point currentPoint = allPoints[i];
        bool isCar = false;
        for (int j = 0; j < carList.size(); j++) {
            if (currentPoint == carList[j].position) {
                isCar = true;
                if (carList[j].team) {
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

    cout<<"\n\n"; // Add some space between each iteration
}

void checkCollision() {
    for (int i = 0; i < carList.size(); i++) {
        for (int j = i + 1; j < carList.size(); j++) {
            if (carList[i].position == carList[j].position) {
                cout << "Collision detected at position: " << carList[i].position.xCord << ", " << carList[i].position.yCord << endl;
                cout << "Number of cars collided: 2" << endl;
                carList.erase(carList.begin() + j);
                carList.erase(carList.begin() + i);

                displayRemaining();
                
                cout<<"\nExiting the program as collision detected\n";

                exit(0);
                return; // Exit after detecting collision
            }
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
        cout<<"Iteration "<<i+1<<"\n\n"; // Add some space between each iteration
    }
}

int main() {
    createPoints();
    createCars();
    checkCollision();
    randomizeCars();
    return 0;
}
