#!/usr/bin/python
#prints CrossCTF{0n3z_N_Z3r0z}
spoon = "1 1 1 1 1 1 1 1 1 1 00100 010 1 010 1 1 1 010 1 1 1 1 1 1 1 010 1 1 1 1 1 1 1 1 1 1 011 011 011 011 000 0011 010 010 010 000 000 000 001010  010 1 1 1 1 1 1 1 1 1 1 1 1 1 1 001010  000 000 000 001010  1 1 1 1 001010  001010  011 001010  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 001010  000 000 000 000 000 000 000 000 000 000 000 000 000 000 001010  010 1 1 1 1 1 1 1 1 001010  011 011 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 001010  010 010 000 000 000 000 000 000 000 000 000 000 000 000 000 001010  011 011 1 1 1 001010  010 010 1 1 1 1 1 1 1 1 1 1 1 1 001010  011 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 001010  000 000 000 000 000 000 000 000 000 000 000 000 000 000 000 000 000 001010  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 001010  000 000 000 000 000 001010  011 001010  010 010 000 000 000 000 000 000 000 000 001010  011 011 000 000 000 001010  010 010 1 1 1 1 1 1 1 1 001010  1 1 1 001010"

spoonlist = spoon.split(" ")

#turn of both LEDS
space_print = "digitalWrite(LED_SET_1_2, LOW); digitalWrite(LED_SET_1_1, LOW); delay(1000);"

one_print = "digitalWrite(LED_SET_1_1, HIGH);delay(100);digitalWrite(LED_SET_1_1, LOW);delay(100);"

zero_print = "digitalWrite(LED_SET_1_2, HIGH);delay(100);digitalWrite(LED_SET_1_2, LOW);delay(100);"


finalcommands = ""
for i in spoonlist:
	for ch in i:
		if ch == '1':
			finalcommands += one_print
		elif ch == '0':
			finalcommands += zero_print
	
	finalcommands += space_print
	
space_print_alt = "digitalWrite(LED_SET_2_2, LOW); digitalWrite(LED_SET_2_2, LOW); delay(1000);"

one_print_alt = "digitalWrite(LED_SET_2_1, HIGH);delay(100);digitalWrite(LED_SET_2_1, LOW);delay(100);"

zero_print_alt = "digitalWrite(LED_SET_2_2, HIGH);delay(100);digitalWrite(LED_SET_2_2, LOW);delay(100);"

finalcommands_alt = ""
for i in spoonlist:
	for ch in i:
		if ch == '1':
			finalcommands_alt += one_print_alt
		elif ch == '0':
			finalcommands_alt += zero_print_alt
	
	finalcommands_alt += space_print_alt
	
	
f = open('org', 'w')
f.write(finalcommands)
f.close()

f = open('org_alt', 'w')
f.write(finalcommands_alt)
f.close()