//http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-the-raspberry-pi/
//http://www.raspberrypi-spy.co.uk/2013/03/raspberry-pi-1-wire-digital-thermometer-sensor/
//http://www.rpiblog.com/2012/11/interfacing-temperature-and-humidity.html

class temp_sensor
{

    void temp_sensor(int given_pin)
    {
        
        pin = given_pin;
    }

    double get_temp()
    {
        //Code to read Temperature

        //Pi sends read request to sensor in pin value
        inMode(pint,OUTPUT);
	    digitalWrite(pin,LOW);
	    delay(18);
	    digitalWrite(pin,HIGH);
	    delayMicroseconds(40);
	    pinMode(pin,INPUT);


        return 10;
    }
    double get_humid()
    {
        //Code to read humidity
        return 17;
    }
}