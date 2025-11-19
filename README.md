# Arduino-trafficlight-system
The focus is on embedded C++ coding. I am using the basics of C++ to build a traffic light on an electrical breadboard. Using just 3 LEDs, a push button, and resistors to highlight the fundamentals of C++ and electric circuits. 


<img width="1280" height="535" alt="traffic light schematic" src="https://github.com/user-attachments/assets/d62aad4d-3649-4c93-9edb-6d7b53698f40" /> 

What I learnt during this mini project.
I learnt a few technical skills: 
I implemented a clean switch-case state transition of the LEDs from red to blue to green. (Used blue because I currently do not have a yellow LED). 

I switched from delay() to millis(), because I noticed that the delay function STOPS everything from responding well. 
I had to add the serial 9600, to show debug prints for when the LEDs blink and the pushbutton is pressed. It was basically there during troubleshooting. 

I overcame the following challenges: 
I learnt that using too many delays blocked the entire program.
I had a minor button bounce issues and researched about debouncing the push button. 
Instead of using the standard if-else statements, I used switch-case states and the code looked cleaner and was clearer. 

Future improvements: 
I will add a countdown timer on a 7 segment dispay, which allows me to switch from using a microcontroller, to analogue electronics. 
I will implement adaptive timing based on traffic sensor and DESIGN PCB version in KiCad! 

peeeew!

