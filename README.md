# ArduinoMicroMIDIController

This is a simple USB MIDI controller with 1 Pitch Fader, 1 Toggle Switch, 1LED and Arduino Micro.

- MIDIUSB library is required.
https://github.com/arduino-libraries/MIDIUSB

<h2>Use case</h2>
1. Connect this controller for your DAWs or PCDJ software. I use Native Instruments Traktor pro 3.

2. Open and configure Controller Settings on Traktor PRO

3. Choose the "Controller Manager" and select "General Midi" 

4. Set notes from Togggle to Modifier Condition of M8 as C3= 1 / D3= 2.

![image](https://user-images.githubusercontent.com/90672633/133881957-397f99d8-7c55-47b2-81b1-0a62c07269e4.png)

4. Set Control Change value to Tempo Adjust (=pitch fader) with Modifier. if M8=1, Assignment="DeckA" and if MB=2, Assignment="Deck B".

![image](https://user-images.githubusercontent.com/90672633/133881995-55ecfdb2-9e8d-4911-8a8c-e6558d207940.png)

5. So you can pitch up/ pitch down with SL-1200 fader, and select Target Deck A/B by the toggle switch.


<h2>Images</h2>

![_DSC0159_note1240 1](https://user-images.githubusercontent.com/90672633/133880499-0fc70cef-eaa9-44c8-b0c2-195c6d79a879.png)
The Circuit

![_DSC0145_note1240](https://user-images.githubusercontent.com/90672633/133880514-f1708564-df05-4910-871c-7db03b5481d5.png)
I use classic Technics SL-1200mkII's pitch fader for this controller. I got it from junk auction.
