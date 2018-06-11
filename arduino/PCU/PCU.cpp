/*
    PCU.cpp - Process Control Unit Abstraction Class
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

#include "Arduino.h"
#include "PCU.h"

PCU::PCU(int dhtPin)
{
    // Inputs
    _dht = dhtPin;
}


PCU::PCU(int dhtPin, int red_led, int green_led, int blue_led, int button)
{
    // Inputs
    _dht = dhtPin;
    _buttonPin = button;
    pinMode(_buttonPin, INPUT);
    
    // Outputs
    _lowTempPin = blue_led;
    pinMode(_lowTempPin, OUTPUT);
    _midTempPin = green_led;
    pinMode(_midTempPin, OUTPUT);
    _highTempPin = red_led;
    pinMode(_highTempPin, OUTPUT);
    
}

float PCU::getTemperature(){}
void PCU::setTemperature(float t, float hist)
{
    _targetTemp = t;
    _targetTempHist = hist;
}

float PCU::getHumidity(){}
void PCU::setHumidity(float h, float hist)
{
    _targetHumd = h;
}

void PCU::setModeBrewing()
{
    _mode = BREWINGMODE;
}

void PCU::setModeFermentation()
{
    _mode = FERMENTATIONMODE;
}

bool PCU::readInput()
{
    _input[0] = digitalRead(_buttonPin);

}

bool PCU::readSensors() {}
void PCU::buzz() {}
//String PCU::jsonStatus();