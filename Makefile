out: obj/main.o obj/convert.o obj/common.o
	g++ -o exe/out obj/main.o obj/convert.o obj/common.o

obj/main.o: src/main.cpp
	g++ -c src/main.cpp -I hdr -o obj/main.o

obj/common.o: src/common.cpp
	g++ -c src/common.cpp -I hdr -o obj/common.o

obj/convert.o: src/convert.cpp
	g++ -c src/convert.cpp -I hdr -o obj/convert.o

clean:
	rm -f out obj/main.o obj/convert.o obj/common.o
