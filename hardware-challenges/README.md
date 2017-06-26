# CrossCTF Hardware Challenge

Creator: Wai Tuck

## Challenge Text 1 (Time to Take a Dump)

```html
There seems to be something running on the FREE arduino!

I wonder if I can talk to it...
```

## Challenge Text 2 (There is No Spoon)

```html
This hardware seems to be more than meets the eye! Please help me figure out what it is doing!

NOTE: You need to finish Time to Take a Dump first before you can attempt this challenge!
```

## Challenge Text 3 (The Great Bank Heist!)

```html
The arduino is generating OTPs! Can we use it to break a bank?

The bank server is running at 127.0.0.1:1343.

NOTE: You need to finish There is No Spoon first before you can attempt this challenge!
```

## Setup Guide

Load firmware and eeprom into arduino with the following command

`TODO`

## Solution Details

### Level 1 

Participants will to dump out the flash memory of the Arduino Mega, and then figure out that there is a base64 encoded string. However, the dictionary it uses is reversed as evident in the strings output, so they just have to write a base64 decode with the new dictionary and run it through there.

To dump the flash in the binary:

`avrdude -p m2560 -P com15 -c wiring -U flash:r:flash.bin:i -F  -C <path to avrdude.conf>`

### Level 2

Participants will have to decode the hint given in Klingon, and assemble two LEDs (or more) to receive the digital write. This simulates data exfiltration via LEDs. From there, they have to encode the information in 0 and 1s, and pass it through any Spoon interpreter.

### Level 3

Dump out EEPROM to find secret key used for the OTP generation. Decrypt it with the XOR key from flash, then submit SHA256(challenge || OTP_key) to the CROSSCTF BANK SERVER.

##

Level 1: `CrossCTF{Bas364_1z_hard}`

Level 2: `CrossCTF{0n3z_N_Z3r0z}`

Level 3: `CrossCTF{F1N@11y_0TP_1Z_Br0k3N}`