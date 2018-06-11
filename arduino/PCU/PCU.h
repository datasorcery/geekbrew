/*
    PCU.h - Process Control Unit Abstraction Class
    Created by Fabio Franco Costa, June 2, 2018.
  
    This file is part of GEEKBREW.

    GEEKBREW is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    GEEKBREW is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GEEKBREW.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef PCU_h
#define PCU_h

#include "Arduino.h"

#define BREWINGMODE 1
#define FERMENTATIONMODE 2
#define INPUTS 1
#define OUTPUTS 3
#define SENSORS 2

class PCU
{
    public:
        PCU(int dhtPin);
        PCU(int dhtPin, int red_led, int green_led, int blue_led, int button);
        // TODO: BMP280, DS18B20, OLED
        void    setTemperature(float t, float hist);
        float   getTemperature();
        void    setHumidity(float h, float hist);
        float   getHumidity();
        void    setModeBrewing();
        void    setModeFermentation();
        bool    readSensors();
        bool    readInput();
        void    buzz();
        //String  jsonStatus();

    private:
        // Current device setings
        int _targetTemp;
        int _targetTempHist;
        int _targetHumd;
        int _humdHist;
        int _mode;  // Brassagem, Fermentacao
        int _deviceID;

        // Sensor and actuators IO
        int _dht;
        int _lowTempPin;
        int _midTempPin;
        int _highTempPin;
        int _buttonPin;
        // TODO: int _buzzerPin;

        // Current input and output values
        float _input[INPUTS];
        float _sensors[SENSORS];
        int _output[OUTPUTS];
};

#endif