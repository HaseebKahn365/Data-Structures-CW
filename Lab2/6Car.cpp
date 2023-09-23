#include <iostream>

using namespace std;

class Car
{
    int xCord = 0;
    int yCord = 0;
    int speed = 0;

public:g
    void aceelerate()
    {
        speed++;
        cout << "Accelerating, speed: " << speed << endl;
    }
    void decelerate()
    {
        speed--;
        cout << "Decelerating, speed: " << speed << endl;
    }

    void turnRight()
    {
        cout << "Turning right" << endl;
        xCord++;
    }

    void turnLeft()
    {
        cout << "Turning left" << endl;
        xCord--;
    }

    void moveForward()
    {
        cout << "Moving forward" << endl;

        yCord += speed;
    }

    void moveBack()
    {
        cout << "Moving Back" << endl;
        yCord -= speed;
    }

    void carState()
    {
        cout << "The car is now at (" << xCord << ", " << yCord << ") \n";
        cout << "speed is: " << speed << endl;
    }
};

// enum direction {right, left, forward, back};

int main()
{

    Car *car = new Car();

    car->aceelerate();
    car->aceelerate();

    car->moveForward();
    car->moveForward();

    car->carState();
    car->turnLeft();
    car->turnLeft();

    car->carState();
}