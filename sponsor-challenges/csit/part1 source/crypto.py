import binascii

def toledword(inpt):
	inpt = inpt + "0" * int(len(inpt)%4)

	c = inpt
	return "".join(["".join([c[i:i+2] for i in range(0,len(c),2)][-j:-j-4:-1]) for j in range(1,len(c)/2,4)][::-1])

def fromledword(inpt):
	c = inpt
	return "".join(["".join([c[i:i+2] for i in range(0,len(c),2)][-j:-j-4:-1]) for j in range(1,len(c)/2,4)][::-1])

def padMessage(size,message):

	print size,"zz"
	size = size if size else len(message)/2

	size = size if not size %4 else size + 4-size%4
	message = message.ljust(2*size,"0")
	print size,"zz"
	return size,message

def hexor(a,b):
	return hex(int(a[0],16)^int(b[0],16))[-1]+hex(int(a[-1],16)^int(b[-1],16))[-1]

# Format of packet
# XXXX XX XXX XXX XXX XXXX XXXX X XXXXXXXXXXXXXXXXXXXXXXXXXX
#
# ^ xor key (4)  4213
#      ^ rubbish (2)
#         ^salt (3)
#             ^ rubbish(3)
#                 ^ size(3)
#                          ^ index (4)
#                              ^ rubbish (4)
#                                      ^ opcode(1)
#                                              ^ data
from random import randint
def randomOut2(dwordcount):
	return "".join([ hex(randint(0,15))[-1]+hex(randint(0,15))[-1] for i in range(dwordcount)])
def randomOut(dwordcount):
	return "".join([ "{0:02x}".format(randint(0,255)) for i in range(dwordcount)])


def getSizeFromHeader(emessage):
	if len(emessage) < 30:
		return -1
	else:
		return int(message[24:30],16)


def decrypt(emessage,):
	xorkey = emessage[:8]
	salt = emessage[12:18]
	size = emessage[24:30]
	index = emessage[30:38]
	opcode = emessage[46:48]
	data = emessage[48:]

	print xorkey,salt,size,index,opcode,data

	print salt == "000000"
	print xorkey == "00000000"

	if salt == "000000" and xorkey == "00000000":
		pass
	else:
		data = xorData(data,xorkey,salt)

	if int(opcode,16) >= 128:
		data = toledword(data)

	return data,opcode,index,xorkey


def encryptBasic(message,size,xorkey,salt,opcode,pad=False):
	return encrypt(message,size,xorkey,salt,opcode,pad=pad,rubbish1=False,rubbish2=False,rubbish3=False)

def encrypt(message,size,xorkey,salt,opcode=0,index=0,pad=True,rubbish1=True,rubbish2=True,rubbish3=True):
	print "size",size
	print "xorkey",xorkey
	size = size if size else len(message)/2
	flip = False
	if opcode >= 128:
		flip = True




	if pad or flip:
		size,message = padMessage(size,message)

	print pad,flip

	print size
	size += 24
	print size
	size = hex(size)[2:].zfill(6)



	opcode = hex(opcode)[2:].zfill(2)
	print size

	xorkey = xorkey.ljust(8,"0")
	salt = salt.ljust(6,"0")
	index = hex(index)[2:].zfill(8)

	#flip dword first
	if pad and flip:
		message = toledword(message)

	if salt == "000000" and xorkey == "00000000":
		emessage = message
	else:
		emessage = xorData(message,xorkey,salt)

	rubbish1 = randomOut(2) if rubbish1 else "".zfill(4)
	rubbish2 = randomOut(3) if rubbish2 else "".zfill(6)
	rubbish3 = randomOut(4) if rubbish3 else "".zfill(8)
	header = xorkey+rubbish1+salt+rubbish2+size+index+rubbish3+opcode
	print len(header)

	#flip dword later
	#data = toledword(emessage)
	data = emessage

	print len(data)
	print data

	return header+data


def xorData(message,xorkey,salt):

	xorkey3,xorkey2,xorkey4,xorkey1 = [xorkey[i:i+2] for i in range(0,len(xorkey),2)]

	salt1,salt2,salt3 = [salt[i:i+2] for i in range(0,len(salt),2)]

	xorkey1 = int(xorkey1,16)
	xorkey2 = int(xorkey2,16) + int(salt1,16) + 3
	xorkey3 = int(xorkey3,16) + int(salt2,16) - 19
	xorkey4 = int(xorkey4,16) + int(salt3,16) + 12

	xorkey = ["{0:02x}".format(xorkey1),"{0:02x}".format(xorkey2),"{0:02x}".format(xorkey3),"{0:02x}".format(xorkey4)]

	message = [message[i:i+2] for i in range(0,len(message),2)]

	print message,
	print xorkey

	emessage = ""
	for i,p in enumerate(message):
		xor = (hexor(xorkey[i % len(xorkey)],p))
		emessage += xor

	print len(emessage)

	return emessage
