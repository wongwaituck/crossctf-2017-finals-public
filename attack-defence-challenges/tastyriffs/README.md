# Tastyriffs

Difficult exploitation challenge. Flow of exploitation is as follows:

1. Use the arbitrary file read vulnerability in greatest.py to read the
   `/picpic` file.
2. Send the contents of the secret value to trigger the cleanup condition.
3. Craft a JSON payload to overflow one byte after the rockstar notes in the
   rockstar struct to point to the deathrocker method. The method will be called
   on an argument passed through the rocker name
4. Setting the name to `;/home/tastyriffs/helper` will run the setuid binary
   that prints the flag.

Creator: amon

## Challenge Text

```html
Please connect to xxx.xxx.xxx.xxx:2010
```

## Setup Guide

The Dockerfile and associated dockerbuild.sh and dockerrun.sh scripts are
included for easy setup.

Either host this as an attack-defence challenge and remove the .c source files
from the machine or host it as a remote challenge in the black box style. In
which case no binaries or source should be provided.

## Solution Details

Exploit is in service/exploit.py.

## Flag

`CrossCTF{l34k_my_stuff_4_teh_pwn}`
