out: obj/main.o obj/common.o obj/convert.o obj/exterior.o obj/array.o obj/bracket.o obj/else_process.o obj/for.o obj/in.o obj/include.o obj/indent.o obj/kluster.o obj/original_format.o obj/out.o obj/remove_mark.o obj/semicolon.o obj/string.o obj/variable.o
		g++ -o exe/out obj/main.o obj/common.o obj/convert.o obj/exterior.o obj/array.o obj/bracket.o obj/else_process.o obj/for.o obj/in.o obj/include.o obj/indent.o obj/kluster.o obj/original_format.o obj/out.o obj/remove_mark.o obj/semicolon.o obj/string.o obj/variable.o

obj/main.o: src/main.cpp
	g++ -c src/main.cpp -I hdr -o obj/main.o

obj/common.o: src/common.cpp
	g++ -c src/common.cpp -I hdr -o obj/common.o

obj/convert.o: src/convert.cpp
	g++ -c src/convert.cpp -I hdr -o obj/convert.o

obj/exterior.o: src/exterior.cpp
	g++ -c src/exterior.cpp -I hdr -o obj/exterior.o

obj/array.o: src/details/array.cpp
	g++ -c src/details/array.cpp -I hdr -o obj/array.o

obj/bracket.o: src/details/bracket.cpp
	g++ -c src/details/bracket.cpp -I hdr -o obj/bracket.o

obj/else_process.o: src/details/else_process.cpp
	g++ -c src/details/else_process.cpp -I hdr -o obj/else_process.o

obj/for.o: src/details/for.cpp
	g++ -c src/details/for.cpp -I hdr -o obj/for.o

obj/in.o: src/details/in.cpp
	g++ -c src/details/in.cpp -I hdr -o obj/in.o

obj/include.o: src/details/include.cpp
	g++ -c src/details/include.cpp -I hdr -o obj/include.o

obj/indent.o: src/details/indent.cpp
	g++ -c src/details/indent.cpp -I hdr -o obj/indent.o

obj/kluster.o: src/details/kluster.cpp
	g++ -c src/details/kluster.cpp -I hdr -o obj/kluster.o

obj/original_format.o: src/details/original_format.cpp
	g++ -c src/details/original_format.cpp -I hdr -o obj/original_format.o

obj/out.o: src/details/out.cpp
	g++ -c src/details/out.cpp -I hdr -o obj/out.o

obj/remove_mark.o: src/details/remove_mark.cpp
	g++ -c src/details/remove_mark.cpp -I hdr -o obj/remove_mark.o

obj/semicolon.o: src/details/semicolon.cpp
	g++ -c src/details/semicolon.cpp -I hdr -o obj/semicolon.o

obj/string.o: src/details/string.cpp
	g++ -c src/details/string.cpp -I hdr -o obj/string.o

obj/variable.o: src/details/variable.cpp
	g++ -c src/details/variable.cpp -I hdr -o obj/variable.o

clean:
	rm -f out obj/main.o obj/common.o obj/convert.o obj/exterior.o obj/array.o obj/bracket.o obj/else_process.o obj/for.o obj/in.o obj/include.o obj/indent.o obj/kluster.o obj/original_format.o obj/out.o obj/remove_mark.o obj/semicolon.o obj/string.o obj/variable.o
a:
	cat code/converted_a.cpp | clip
	g++ code/converted_a.cpp
	./a.exe
	cat code/converted_a.cpp | clip

b:
	cat code/converted_b.cpp | clip
	g++ code/converted_b.cpp
	./a.exe
	cat code/converted_b.cpp | clip

c:
	cat code/converted_c.cpp | clip
	g++ code/converted_c.cpp
	./a.exe
	cat code/converted_c.cpp | clip

d:
	cat code/converted_d.cpp | clip
	g++ code/converted_d.cpp
	./a.exe
	cat code/converted_d.cpp | clip

t:
	cat code/converted_t.cpp | clip
	g++ code/converted_t.cpp
	./a.exe
	cat code/converted_t.cpp | clip
