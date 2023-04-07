# STM32 Bare Metal Embedded Alarm Clock
Over the prior months I have developed an intrest in embedded systems leading to me taking a range of courses on Udemy by Fastbit Academy in topics such as GPIO, SPI, I2C, UART, DMA, TIMERs and ARM MCU archiectecture.
To cap of this learning I wanted to develop something phyisical as a reflection of my work. I decided to make an alarm clock using a STM32F103C8T6 (Blue Pill). 
To challenge myself I decided to make use of no HAL for this project and write all of the drivers used myself.

The functionality I implemented on the clock was:
- Displaying of time in 24 hour format
- Abiltiy to change time on clock
- Alarm that buzzed at a set time
- Ability to enable and disable the alarm

![alarm clock](https://user-images.githubusercontent.com/60488797/230689714-15602e72-62c9-4586-ae71-96d1672854f1.jpg)

## Components used 
- STM32F103C8T6 (Blue pill)
- DS1307 I2C RTC (I realize I could have used the RTC on the blue pill, but opted to use this to practice with the I2C protocol)
- SK6812 Led Strip (I developed a bitbanging SPI DMA protocol for these LED but didnt end up using these LEDs in the end as they didnt fit the design I wanted)
- Black Jiffy Box - 130 x 68 x 44mm
- Active Buzzer Alarm - 3V
- Adafruit Perma-Proto Half-sized Breadboard PCB
- Orange LEDs
- Various buttons + switches
- 470Ohm resistors

## Photos of assembly proccess
Testing of SK6812 LED strip (not used in the end as it didn't fit overall design)

![20230201_123611](https://user-images.githubusercontent.com/60488797/230691054-538fac3f-2bb2-4ae8-8133-3f09e3aa5176.jpg)

Final test of alarm clock before assembly. RTC shown on left communicates with Blue Pill through I2C causing LEDs to change when time updates.
Buttons on the right of the breadboard allow the user to change the time and set an alarm.

![20230207_131926](https://user-images.githubusercontent.com/60488797/230691150-518e6e53-ad5b-4536-a431-cfd1150a5030.jpg)

Beggining of assembly proccess of alarm clock. Two LEDs had to be soldered together and attached to a resistor. This was repeated 28 times for each of the dashes that make up the numbers.

![20230210_095818](https://user-images.githubusercontent.com/60488797/230691343-54874e09-9ce1-44e0-8a8e-226a5ffc0d69.jpg)

Drilling holes in Jiffy Box to push LEDs through.

![20230210_111300](https://user-images.githubusercontent.com/60488797/230691443-b7ea7c18-bb86-4492-988c-b46771c8271f.jpg)

Due to a lack of a PCB I grounded all the LEDS by soldering them to a common line on Perma Proto Bread Board.

![20230210_205502](https://user-images.githubusercontent.com/60488797/230691483-463533b2-993a-4f89-9561-a43d1538f13c.jpg)

Had to buy a new Bluepill and resolder all LEDs to it in the final hour of the project, which was a major set back. This was due to me accidentally soldering pins of the MCU togehter (zoom in) and not being able to desolder it.

![20230212_202422](https://user-images.githubusercontent.com/60488797/230691565-e73e4c04-ec4b-48cb-b27f-50ab48bac4ad.jpg)

Mess of wires and solder presented one final challenge of getting everything into the jiffy box.

![20230217_174226](https://user-images.githubusercontent.com/60488797/230691690-f8afb3c3-0dbf-4d37-8e93-39f116fb5acf.jpg)



