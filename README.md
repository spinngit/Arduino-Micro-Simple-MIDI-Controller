# Arduino-Micro-Simple-MIDI-Controller

This is a simple USB MIDI controller with 1 Pitch Fader, 1 Toggle Switch, 1LED and Arduino Micro.

- MIDIUSB library is required.
https://github.com/arduino-libraries/MIDIUSB

<h2>Use case (NI Traktor Pro 3)</h2>
1. Connect this controller for your DAW or PCDJ software. I use Native Instruments Traktor pro 3.

2. Open Controller Settings on Traktor PRO

3. Choose the "Controller Manager", select "General Midi" and set IN-port to "Arduino Micro"

4. Set the Modifier Condition of M8 as C3= 1 / D3= 2 by notes from toggle switches.

![image](https://user-images.githubusercontent.com/90672633/133881957-397f99d8-7c55-47b2-81b1-0a62c07269e4.png)

5. Set Control Change value to Tempo Adjust (=pitch fader) with Modifier. If M8=1 then Assignment="Deck A" and If MB=2 then Assignment="Deck B".

![image](https://user-images.githubusercontent.com/90672633/133881995-55ecfdb2-9e8d-4911-8a8c-e6558d207940.png)

6. So you can pitch up/ pitch down with SL-1200 fader, and select Target Deck (A/B) by the toggle switch!


<h2>Images</h2>

![_DSC0159_note1240 1](https://user-images.githubusercontent.com/90672633/133880499-0fc70cef-eaa9-44c8-b0c2-195c6d79a879.png)
The Circuit

![_DSC0145_note1240](https://user-images.githubusercontent.com/90672633/133880514-f1708564-df05-4910-871c-7db03b5481d5.png)
I use classic Technics SL-1200's pitch fader for this controller. I got it from Yahoo auction in Japan.
