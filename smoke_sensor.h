#include <wiringPi.h>


class smoke_sensor
{
    public:
        bool detection(); // returns true if any sensor is triggerd
        
        //Returns true (1) if the sensors below are triggered else False (0)
        int MQ7(); 
        int MQ5();
        int MQ3();
        int flame();
    private:
        // ints to determine which pins is to which sensor
        // based on wiring pi numbers
        int pin_MQ7;
        int pin_MQ5;
        int pin_MQ3;
        int pin_flame;
};//end class