import socket
import sys
import crypto
from opcode import opcode as opcode_enm
import binascii
import time

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port on the server given by the caller
server_address = ("localhost", 2748)
print >>sys.stderr, 'connecting to %s port %s' % server_address
sock.connect(server_address)

try:

	InitialKey = "41424344"
	InitialSize = "40" #0x64
	msg = InitialKey+InitialSize
	message = crypto.encryptBasic(msg,len(msg)/2,"","",opcode_enm.hello,pad=False)
	print "sending ",message
	sock.sendall(message)



	selected_fun = ""
	selected_server = ""

	while True:
		data = sock.recv(64*2+48)
		if not data:
			break

		print len(data)
		print >>sys.stderr, 'received "%s"' % data
		rdata,opcode,index,_ = crypto.decrypt(data)
		ddata = binascii.unhexlify(rdata).rstrip("\x00")


		print index,ddata,"\""

		print binascii.hexlify(ddata),"hexlify data"

		if ddata == "faq_flag.png":
			selected_fun = rdata
			print "rdata selected flag",rdata
		if ddata == "server":
			selected_server = rdata
			print "rdata selected server",rdata
		if ddata == "":
			break

	#sock.close()
	#sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	#sock.connect(server_address)

	print "##Starting get flag"
	message = crypto.encrypt(selected_fun,0,InitialKey,"",opcode_enm.get)
	sock.sendall(message)

	data = sock.recv(24+48)
	rdata,opcode,index,_ = crypto.decrypt(data)
	ddata = binascii.unhexlify(rdata).rstrip("\x00")
	fsize = int(ddata)
	rsize = 0

	edata = ""

	while rsize < fsize:
		data = sock.recv(256*2+48)

		if not data:
			break

		print len(data)
		print >>sys.stderr, 'received "%s"' % data
		rdata,opcode,index,_ = crypto.decrypt(data)

		edata += rdata
		rsize += len(rdata)

	edata = edata[:fsize]
	o_flag = open("out_flag.png","wb")
	o_flag.write(binascii.unhexlify(edata))
	o_flag.close()
	
	print "##Starting get server"
	message = crypto.encrypt(selected_server,0,InitialKey,"",opcode_enm.get)
	sock.sendall(message)

	data = sock.recv(24+48)
	rdata,opcode,index,_ = crypto.decrypt(data)
	ddata = binascii.unhexlify(rdata).rstrip("\x00")
	fsize = int(ddata)
	rsize = 0

	edata = ""

	while rsize < fsize:
		data = sock.recv(256*2+48)

		if not data:
			break

		print len(data)
		print >>sys.stderr, 'received "%s"' % data
		rdata,opcode,index,_ = crypto.decrypt(data)

		edata += rdata
		rsize += len(rdata)

	
	edata = edata[:fsize]
	print fsize
	print len(edata)
	print ""
	print ""
	print ""
	print ""
	print ""
	print ""
	o_flag = open("out_heap2_participant","wb")
	o_flag.write(binascii.unhexlify(edata))
	o_flag.close()

	message = crypto.encryptBasic("",0,"","",255)
	sock.sendall(message)

finally:
	sock.close()
