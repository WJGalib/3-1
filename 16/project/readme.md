# Race
This directory contains all of the resources related to our CSE316 Microcontroller term project. Our project was a Bluetooth-controlled racing game with two cars. Here is a **[demonstration video](https://www.youtube.com/watch?v=mE63gsLWX4w)**.

![Race Game Setup](https://github.com/WJGalib/3-1/blob/main/16/project/_PROJECT_FINAL/design/game.jpg)

 
## Motivation
Promoting physical activities, movement and fun combined with  technological involvement. Remote controlled race cars were a thing in our childhood, but its popularity diminished along with many other hardware-based games while software games became more dominant over the years.

We aim to bring back our good times from childhood, considering the mindsets of the younger generation which includes competitiveness, fast paced action and result, improvisation with modern technology to create a complete race car game which will cover the necessary features.


## Description
The game will consist of a race track and two race cars controlled by smartphones, through Bluetooth. 

There will be a central control system running on an Arduino Uno, with start/reset buttons and a display board which will show the standings, lap times, and announce the winners when the game is over. The system will communicate with the two cars using an RF module. 

The two race cars will be identical to each other, each being controlled by an Arduino Nano and powered by Li-ion or Li-Po batteries. They will move using gear motors driven by a motor driver. They will receive the player’s instructions from an [Android application](https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller) through their Bluetooth modules. Each car will also have an RFID module to detect its position in the track, and an RF module to communicate with the central system.

The track will actually contain no circuit elements. It will be a passive structure with a start/finish line and another line to detect the motion of the cars somewhere in the middle. The finish and start lines will be right next to each other as the track will be a loop. These lines will each consist of a row of RFID cards that will have unique IDs mapped to the identity of the line it constitutes. There will also be another line with RFID keyrings which will act as power-downs or hazard obstacles in the second lap of the game. Driving right over one will cause the player to be slowed down or stalled.

The central system will notify the cars when the users prompt it to start a game. Entering that state, the cars will be allowed to start moving only when they are placed on the start line, and the game is started. Whenever a car crosses a specific line, its RFID module will detect the identity of the line and change the “state” of the car in the microcontroller’s program. When a car passes through the sequence of “start-middle-finish”, that movement will be recognised as the completion of a lap in the race, and the car will inform the central system through its RF module that it has completed a lap. All other state sequences will be rejected. The central system will keep track of how many laps each car has completed and in how much time. When a car completes N loops in the least amount of time from game start, the game will end and the central system will display the winner, and then shortly afterwards, prompt to start another game. We may keep the value of N (the number of laps in a game) fixed, or add functionality to customise it through some form of user input later. It is worth mentioning that the task of recognising lap completion is to be done by the cars instead of the central system, because RFID modules of suitable size or any other sensors to reliably scan an area of such size and then also recognise specifically which car crossed, seemed to not be available. 


## Instruments

| Name                     | Model Number        | Units    |
| ------------------------ | ------------------- | -------- |
| Microcontroller (system) | Arduino Uno         | 1        |
| Microcontroller (car)    | Arduino Nano        | 2        |
| Bluetooth Module         | HC-05               | 2        |
| Li-Po battery pack       | 7.4v 900MAh         | 2        |
| Motor Driver             | L298N               | 2        |
| Gear Motor + Wheels      | N20 6V 200rpm       | 8        |
| RF Comm. Module          | nRF24L01            | 3        |
| Buzzer                   | 5V passive          | 3        |
| RFID Module              | MRC522              | 2        |
| RFID Card + Keyring      | 13.65 MHz MIFARE    | 21 + 3   |
| Character LCD Display    | LCD2004             | 1        |
| Display adapter          | i2C adapter module  | 1        |
| LED                      | Various colours     | Many     |
| Switch/Button            | Slider / Push       | Several  |
| Bread Board              | Mini (17x10)        | Several  |
| PVC Sheet                | 3mm A4 / 24"x20"    | Lots     |
| Voltage Converter        | Buck Module         | 2        |

## Design Outline

Design details can be seen [here](_PROJECT_FINAL/design).

![Block Diagram](https://github.com/WJGalib/3-1/blob/main/16/project/_PROJECT_FINAL/design/block_diagram.jpg)


## Hardware Implementation 

The cars and the central system:

![Cars and System](https://github.com/WJGalib/3-1/blob/main/16/project/_PROJECT_FINAL/design/hardware.jpg)

The track elements (start/middle/end line and power-down pickups): 

![Track Elements](https://github.com/WJGalib/3-1/blob/main/16/project/_PROJECT_FINAL/design/track_elements.jpg)


## Contributions
The Team :
1. Tareq Ahmed
2. Mehreen Maliha
3. [Kazi Reyazul Hasan](https://github.com/kreyazulh)
4. [Wasif Jalal](https://github.com/WJGalib)
5. [Mubasshira Musarrat](https://github.com/MubasshiraMusarrat)
