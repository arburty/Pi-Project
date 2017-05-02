#include "smoke_sensor.h"
#include <iostream>


//https://create.arduino.cc/projecthub/Aritro/smoke-detection-using-mq-2-gas-sensor-79c54a
// Install Wiring Pi
//http://wiringpi.com/download-and-install/
//http://untitled.es/sensor-gas-mq7-raspberry-pi2/



using namespace std;

//Uses MQ-7 CO detector sensor
   // Return 1 if triggered
   // Return 0 if no detection


   // int pin_MQ7 = 0;    
   // int pin_MQ5 = 2;
   // int pin_MQ3 = 3;
   // int pin_flame = 5;
   // int speaker = 1;

    int smoke_sensor::MQ7()
    {
        pinMode(0, INPUT);
        int state = digitalRead(0);
        return !state;
    }

    int smoke_sensor::MQ5()
    {
        pinMode(2, INPUT);
        int state = digitalRead(2);
       // cout << "MQ5: " << state << "\n";
        return !state;
    }

    int smoke_sensor::MQ3()
    {
        pinMode(3, INPUT);
        int state = digitalRead(3);
        return !state;
    }

    int smoke_sensor::flame()
    {
        pinMode(5, INPUT);
        int state = digitalRead(5);
        //cout << "Flame: " << state << "\n";
        return state;
    }

    bool smoke_sensor::detection()
    {
        int total = MQ7() + MQ5() + MQ3() + flame();

        
        if(( !(total == 0) ))
            alert();
            
        //cout << "total: " << total << "\n";
        // returns true if any sensor is triggered
        return ( !(total == 0) );
    }

    //activates speakers to alarm sound
    void smoke_sensor::alarm_on()
    {
        pinMode(1, PWM_OUTPUT);
        pwmWrite  (1,512);
        
    }

    void smoke_sensor::alarm_off()
    {
        pinMode(1, PWM_OUTPUT);
        pwmWrite  (1,512);
        
    }

    void smoke_sensor::alert()
    {
        for(int i = 0; i < 1000; i++)
        {
            alarm_on();
            
            alarm_off();
        }
    }
