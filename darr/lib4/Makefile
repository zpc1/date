.PHONY:install
all:
	gcc -shared -fPIC -o libdarr.so darr.c -I.
install:
	mv libdarr.so /lib64
	gcc -o softarr main.c -ldarr -I.
clean:
	rm -f softarr 

