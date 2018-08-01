out: obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/rep.o obj/include.o obj/indent.o
	g++ -o exe/out obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/rep.o obj/include.o obj/indent.o

obj/main.o: src/main.cpp
	g++ -c src/main.cpp -I hdr -o obj/main.o

obj/common.o: src/common.cpp
	g++ -c src/common.cpp -I hdr -o obj/common.o

obj/convert.o: src/convert.cpp
	g++ -c src/convert.cpp -I hdr -o obj/convert.o

obj/in.o: src/original/in.cpp
	g++ -c src/original/in.cpp -I hdr -o obj/in.o

obj/out.o: src/original/out.cpp
	g++ -c src/original/out.cpp -I hdr -o obj/out.o

obj/rep.o: src/original/rep.cpp
	g++ -c src/original/rep.cpp -I hdr -o obj/rep.o

obj/include.o: src/original/include.cpp
	g++ -c src/original/include.cpp -I hdr -o obj/include.o

obj/indent.o: src/original/indent.cpp
	g++ -c src/original/indent.cpp -I hdr -o obj/indent.o

clean:
	rm -f out obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/rep.o obj/include.o obj/indent.o
