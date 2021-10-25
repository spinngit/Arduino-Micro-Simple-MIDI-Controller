# Arduino-Micro-Simple-MIDI-Controller

This is a simple USB MIDI controller with 1 Pitch Fader, 1 Toggle Switch, 1LED, up/down Pitch Benders and Arduino Micro.

- Arduino Micro (Official)
https://store.arduino.cc/products/arduino-micro

- MIDIUSB library is required.
https://github.com/arduino-libraries/MIDIUSB

<h2>Use case (NI Traktor Pro 3)</h2>
1. Connect this controller for your DAW or PCDJ software. I use Native Instruments Traktor pro 3.

2. Open Controller Settings on Traktor PRO

3. Choose the "Controller Manager", select "General Midi" and set IN-port to "Arduino Micro"

4. Set the Modifier Condition of M8 as C3= 1 / D3= 2 by notes sent from toggle switch.

5. Set Control Change value to Tempo Adjust (=pitch fader) with Modifier8(M8). If M8=1 then Assignment="Deck A" and If M8=2 then Assignment="Deck B".

![image](https://user-images.githubusercontent.com/90672633/133881995-55ecfdb2-9e8d-4911-8a8c-e6558d207940.png)

6. Set Pitch Bend

![image](https://user-images.githubusercontent.com/90672633/138655006-35663bbb-ec43-4d7f-83fb-3adea0996891.png)

7. So you can pitch up/down with SL-1200 fader, and select Target Deck (A/B) by the toggle switch!


<h2>Images</h2>
![_DSC0193_note1240]

![image](https://user-images.githubusercontent.com/90672633/135750254-18e1ad4d-cd32-4856-9b78-ff7fbbd5076c.png)
The Circuit

![image](https://user-images.githubusercontent.com/90672633/135750316-cababafb-a1ab-40b3-ba5e-fc20f714d0f0.png)
The Connection Chart

![_DSC0145_note1240](https://user-images.githubusercontent.com/90672633/133880514-f1708564-df05-4910-871c-7db03b5481d5.png)
I use classic Technics SL-1200's pitch fader for this controller. I got it from Yahoo auction in Japan.

![_DSC0194_note1240](https://user-images.githubusercontent.com/90672633/135750390-ed0f297f-213b-4c8c-bb6c-e03de960f1b2.png)
SL1200_fader_housing.stl for LENOVO ThinkPad T490

![_DSC0201_note1240](https://user-images.githubusercontent.com/90672633/135750456-e8f8f67a-c00a-45d7-94b0-23ea6fc4d448.png)
Mission Completed.
