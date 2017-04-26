#include <wiringpi.h>


class temp_sensor
{
    public:
        temp_sensor(int);    
        get_temp();
        get_humid();
    private:
        int pin;
}