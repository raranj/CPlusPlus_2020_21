// Ranjana Rajagopalan
// 09/27/20
// celsFahr.cpp
// This program lists a table of temperatures with values in °C and °F.

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    float cels;
    int fahr;
    cout << left << setw(12) << "Fahrenheit" ; // Creating Fahrenheit header for table
    cout << "Celsius" << endl; // Creating Celsius header for table
    
    // Each block of code corresponds to one Fahrenheit value.
    
    fahr = 0;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(12) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 20;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(12) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 40;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;

    fahr = 60;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 80;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 100;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 120;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 140;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 160;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 180;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    fahr = 200;
    cels = (5.0/9.0)*(fahr - 32);
    cout << left << setw(13) << fahr;
    cout << fixed << setprecision(1) << cels << endl;
    
    return 0;

}
    

