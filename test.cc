#include <iostream>
#include "smoke_sensor.h"
#include <wiringPi.h>


using namespace std;

int main()
{
    wiringPiSetup();

    cout << "main \n";
    smoke_sensor s;

    while(true)
    {
        delay(1000);
       
        if(s.MQ3() == 1)
            cout << "MQ3 Detected \n";
        if(s.MQ5() == 1 )
            cout << "MQ5 Detected \n";
        if(s.MQ7() == 1)
            cout << "MQ7 Detected \n";
        if(s.flame() == 1)
            cout << "flame Detected \n";
        if(s.detection())
            cout << "something trigger \n";
    }
}