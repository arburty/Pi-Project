#include <string>
#include <iostream>
#include <map>
#include "smoke_sensor.h"
#include "temp_sensor.h"

//Must Use Wiring pi to initialize system and read data from pins
//http://wiringpi.com/reference/setup/
using namespace std;

//individual Gas sensors if set
int check_smoke_sensors(smoke_sensor s, ofstream o){
    //MQh3
    if(s.MQ3() == 1){
	cout << "\t-MQ3 sensor is activated" << '\n';
	return 3;
    }
    //MQ5
    if(s.MQ5() == 1){
	cout << "\t-MQ5 sensor is activated" << '\n';
	return 5;
    }
    //MQ7
    if(s.MQ7() == 1){
	cout << "\t-MQ7 sensor is activated" << '\n';
    	return 7;
    }
    //flame
    if(s.flame() == 1){
    	cout << "\t-Flame detected" << '\n';
	return 10;
    }
}
double get_temp(temp_sensor t){
    return 0.0;
}
double get_humidity(temp_sensor t){
    return 0.0;
}
int main(void)
{
    map <string, bool> sensors;
    wiringPiSetup();
    
    smoke_sensor sensor_s;
    temp_sensor sensor_t;
    //Start smoke_sensor
    
    //opens output file as csv
    ofstream output ("output.csv");
    //Get temp;
    output << "Temperature,";
    output << get_temp(sensor_t) << '\n';
    output << "Humidity,";
    output << get_humidity(sensor_t) << '\n';
    
    //Check smoke sensor;
    if(sensor_s.detection){
	cout << "Smoke sensor is activated" << '\n';
        output << "Smoke,\n";
	outputcheck_smoke_sensors(sensor_s, output);
    }
    
    output.close();
    cout << " \n";
	return 0;
}
