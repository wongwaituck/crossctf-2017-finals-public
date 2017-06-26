all: heap2 

heap2: heap2.c
	gcc $^ -m32 -fPIC -pie -o $@ common-server.c

clean: 
	rm -rf heap2
