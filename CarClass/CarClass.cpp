// Ranjana Rajagopalan
// 04/11/21
// CarClass.cpp

#include <iostream>
using namespace std;

const int SPEED_CHANGE = 5;

class Car
{
private:
    int year;
    string make;
    int speed;
public:
    Car(int y, string m)
    {
        year = y;
        make = m;
        speed = 0;
    }
    int getYear()
    {
        return year;
    }
    string getMake()
    {
        return make;
    }
    int getSpeed()
    {
        return speed;
    }
    void accelerate()
    {
        speed += SPEED_CHANGE;
    }
    void brake()
    {
        if (speed == 0) // don't reduce speed if not moving
            return;
        
        speed -= SPEED_CHANGE;
    }
};

int main ()
{
    int userYear;
    string userMake;
    
    do
    {
        cout << "Which year was the car made? ";
        cin >> userYear;
    } while (userYear < 0);
    
    cout << "Which brand is the car? ";
    cin >> userMake;
    
    Car car(userYear, userMake);
    
    // demonstrating accessor functions
    cout << "This is a " << car.getMake();
    cout << " that was made in the year " << car.getYear() << endl;
    
    cout << "The speed is: " << endl;
    
    car.accelerate();
    cout << car.getSpeed() << endl;
    car.brake();
    cout << car.getSpeed() << endl;
    car.accelerate();
    cout << car.getSpeed() << endl;
    car.accelerate();
    cout << car.getSpeed() << endl;
    car.brake();
    cout << car.getSpeed() << endl;
    
    return 0;

}
