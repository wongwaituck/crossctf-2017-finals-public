import socket
import threading
import SocketServer
import crypto
import time
import binascii
from opcode import opcode as opcode_enm

class ThreadedTCPRequestHandler(SocketServer.BaseRequestHandler):

	def handle(self):

		while True:
			data = self.request.recv(1024)
			cur_thread = threading.current_thread()



			print "asd",cur_thread

			print 'received "%s"' % data

			rdata,opcode,index,xorkey = crypto.decrypt(data)

			print rdata,opcode,index,xorkey

			try:
				opcode = int(opcode,16)
			except:
				return

			if opcode is opcode_enm.hello:
				print "working on hello"
				ls_data = [
					"rule.png",
					"our future.py",
					"faq_flag.png",
					"science_small.jpg",
					"server",
					"moon_landing.txt",
					"space_server.svg",
					""
				]

				xorkey = rdata[:8]
				maxlength = int (rdata[8:10],16)

				for i in ls_data:
					response = crypto.encrypt(binascii.hexlify(i),maxlength,xorkey,"",opcode=opcode_enm.rhello)
					self.request.sendall(response)

			elif opcode is opcode_enm.get:
				print "working on get"

				print "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

				fname = binascii.unhexlify(rdata).rstrip("\x00")
				if fname == "faq_flag.png":
					f_flag = open("flag.png","rb")
					data = binascii.hexlify(f_flag.read())


					msg = str(len(data))
					response = crypto.encrypt(binascii.hexlify(msg),12,xorkey,"",opcode=opcode_enm.rget,index=0)
					self.request.sendall(response)

					splitSize = 256*2 #256 byte
					for i,d in enumerate([data[j:j+splitSize] for j in range(0,len(data),splitSize)]):
						response = crypto.encrypt(d,0,xorkey,crypto.randomOut(3),opcode=opcode_enm.rget,index=i)
						self.request.sendall(response)
				
				elif fname == "server":
					f_flag = open("heap2_participant","rb")
					data = binascii.hexlify(f_flag.read())


					msg = str(len(data))
					response = crypto.encrypt(binascii.hexlify(msg),12,xorkey,"",opcode=opcode_enm.rget,index=0)
					self.request.sendall(response)

					splitSize = 256*2 #256 byte
					for i,d in enumerate([data[j:j+splitSize] for j in range(0,len(data),splitSize)]):
						response = crypto.encrypt(d,0,xorkey,crypto.randomOut(3),opcode=opcode_enm.rget,index=i)
						self.request.sendall(response)

				pass
			else:
				print "===Ending Thread==="
				break;


		#response = data
		#self.request.sendall(response)

class ThreadedTCPServer(SocketServer.ThreadingMixIn, SocketServer.TCPServer):
	pass

def client(ip, port, message):
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.connect((ip, port))
	try:
		sock.sendall(message)
		response = sock.recv(1024)
		print "Received: {}".format(response)
	finally:
		sock.close()

if __name__ == "__main__":
	# Port 0 means to select an arbitrary unused port
	HOST, PORT = "localhost", 2748

	server = ThreadedTCPServer((HOST, PORT), ThreadedTCPRequestHandler)
	ip, port = server.server_address

	# Start a thread with the server -- that thread will then start one
	# more thread for each request
	server_thread = threading.Thread(target=server.serve_forever)
	# Exit the server thread when the main thread terminates
	server_thread.daemon = True
	server_thread.start()
	print "Server loop running in thread:", server_thread.name

	try:
		while True:
			time.sleep(1)
	except KeyboardInterrupt:
		pass



	server.shutdown()
	server.server_close()
