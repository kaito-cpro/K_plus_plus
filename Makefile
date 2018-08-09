out: obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/for.o obj/if_else.o obj/variable.o obj/kstr.o obj/kluster.o obj/array.o obj/original_format.o obj/include.o obj/indent.o obj/semicolon.o obj/shift_index.o obj/remove_mark.o
	g++ -o exe/out obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/for.o obj/if_else.o obj/variable.o obj/kstr.o obj/kluster.o obj/array.o obj/original_format.o obj/include.o obj/indent.o obj/semicolon.o obj/shift_index.o obj/remove_mark.o

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

obj/if_else.o: src/details/if_else.cpp
	g++ -c src/details/if_else.cpp -I hdr -o obj/if_else.o

obj/variable.o: src/details/variable.cpp
	g++ -c src/details/variable.cpp -I hdr -o obj/variable.o

obj/kstr.o: src/details/kstr.cpp
	g++ -c src/details/kstr.cpp -I hdr -o obj/kstr.o

obj/kluster.o: src/details/kluster.cpp
	g++ -c src/details/kluster.cpp -I hdr -o obj/kluster.o

obj/array.o: src/details/array.cpp
	g++ -c src/details/array.cpp -I hdr -o obj/array.o

obj/original_format.o: src/details/original_format.cpp
	g++ -c src/details/original_format.cpp -I hdr -o obj/original_format.o

obj/include.o: src/details/include.cpp
	g++ -c src/details/include.cpp -I hdr -o obj/include.o

obj/indent.o: src/details/indent.cpp
	g++ -c src/details/indent.cpp -I hdr -o obj/indent.o

obj/semicolon.o: src/details/semicolon.cpp
	g++ -c src/details/semicolon.cpp -I hdr -o obj/semicolon.o

obj/shift_index.o: src/details/shift_index.cpp
	g++ -c src/details/shift_index.cpp -I hdr -o obj/shift_index.o

obj/remove_mark.o: src/details/remove_mark.cpp
	g++ -c src/details/remove_mark.cpp -I hdr -o obj/remove_mark.o

clean:
	rm -f out obj/main.o obj/convert.o obj/common.o obj/in.o obj/out.o obj/for.o obj/if_else.o obj/variable.o obj/kstr.o obj/kluster.o obj/array.o obj/original_format.o obj/include.o obj/indent.o obj/semicolon.o obj/shift_index.o obj/remove_mark.o
