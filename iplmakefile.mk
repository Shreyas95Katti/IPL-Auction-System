iplauc.exe:IPLclientfile.o IPLadminserver.o IPLuserserver.o
	gcc IPLclientfile.o IPLadminserver.o IPLuserserver.o -o iplauc.exe
IPLclientfile.o:IPLclientfile.c IPLheaderfile.h
	gcc -c IPLclientfile.c
IPLadminserver.o:IPLadminserver.c IPLheaderfile.h 
	gcc -c IPLadminserver.c 
IPLuserserver.o:IPLuserserver.c IPLheaderfile.h 
	gcc -c IPLuserserver.c 
