# smart_piggy_bank

## Introduction
An electronic piggy bank that is capable of differentiating 0.10 RON and 0.50 RON coins and add them to the total when they are inserted.

Exterior design (for the regular user):
![Exterior](https://i.ibb.co/6WMQn9j/exterior.jpg)

Interior design (for the tech user):
![Interior](https://i.ibb.co/jMNpd05/interior.jpg)

## General Description
The user will be able to insert coins from the right side (as presented in the "Exterior design" image). The Piggy Bank will identify the type of the coin, place it in the specific container, and add it's value to the total that will be displayed on the LCD.
The piggy bank is able to identify each coin using two infrared sensors, that detect each coin while sliding.

## Hardware Components
2x Infrared Sensors
1x LCD 16x2
1x Cardboard box
6x Cable mother-mother
16x Cable mother-father

## Electrical Scheme
![Scheme](https://i.ibb.co/pxWqVTt/schema-electrica.jpg)

## Software Design
Very light weight software: a hex file that contains the LCD library and the simple logic of the project:
There are two infrared sensors placed before the whole through the 0.10 RON coin will fall and the one the 0.50 RON coin will fall.
When the first sensor detects the presence of a coin, the total sum is incremented by 0.10 and when the second sensor detects a coin the total sum is incremented by 0.40.

## DEMO:
https://www.youtube.com/watch?v=IcJ4U8hIEmE

## Resources Used:
https://www.optimusdigital.ro/ro/ - For the Technical Schemes of the sensors
http://cs.curs.pub.ro/wiki/pm/ - For LCD instructions
https://www.youtube.com/watch?v=7ILHtAPY29I - Source of Inspiration
