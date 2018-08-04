out: obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/for.o obj/include.o obj/indent.o
	g++ -o exe/out obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/for.o obj/include.o obj/indent.o

obj/main.o: src/main.cpp
	g++ -c src/main.cpp -I hdr -o obj/main.o

obj/common.o: src/common.cpp
	g++ -c src/common.cpp -I hdr -o obj/common.o

obj/convert.o: src/convert.cpp
	g++ -c src/convert.cpp -I hdr -o obj/convert.o

obj/in.o: src/details/in.cpp
	g++ -c src/details/in.cpp -I hdr -o obj/in.o

obj/out.o: src/details/out.cpp
	g++ -c src/details/out.cpp -I hdr -o obj/out.o

obj/for.o: src/details/for.cpp
	g++ -c src/details/for.cpp -I hdr -o obj/for.o

obj/include.o: src/details/include.cpp
	g++ -c src/details/include.cpp -I hdr -o obj/include.o

obj/indent.o: src/details/indent.cpp
	g++ -c src/details/indent.cpp -I hdr -o obj/indent.o

clean:
	rm -f out obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/for.o obj/include.o obj/indent.o
