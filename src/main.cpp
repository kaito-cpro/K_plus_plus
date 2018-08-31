#include "../hdr/common.h"
#include "../hdr/convert.h"
#include "../hdr/exterior.h"
#include "../hdr/prototype.h"
const int MAX = 200;
int num = 0;  //K++が生成する変数の通し番号
string tab = "    ";
string pre = ";\n";
map<string, string> dict;

int main(){
    char pro;
    cout << "Problem: ";
    cin >> pro;

    FILE* fpr;  //read
    FILE* fpw;  //write
    switch (pro){
        case 'a':
            fpr = fopen("code/source_a.cpp", "r");
            fpw = fopen("code/converted_a.cpp", "w");
            break;
        case 'b':
            fpr = fopen("code/source_b.cpp", "r");
            fpw = fopen("code/converted_b.cpp", "w");
            break;
        case 'c':
            fpr = fopen("code/source_c.cpp", "r");
            fpw = fopen("code/converted_c.cpp", "w");
            break;
        case 'd':
            fpr = fopen("code/source_d.cpp", "r");
            fpw = fopen("code/converted_d.cpp", "w");
            break;
        case 't':
            fpr = fopen("code/source_t.cpp", "r");
            fpw = fopen("code/converted_t.cpp", "w");
            break;
    }

    string src = ";\n";
    char c[MAX];
    while(fgets(c, MAX, fpr) != NULL) src += c;

    exterior(src);
    convert(src);
    fprintf(fpw, "%s", src.c_str());

    fclose(fpr);
    fclose(fpw);

    cout << "Now compiling..." << endl;
    int res;
    switch (pro){
        case 'a': system("cat code/converted_a.cpp | clip"); res = system("g++ code/converted_a.cpp"); break;
        case 'b': system("cat code/converted_b.cpp | clip"); res = system("g++ code/converted_b.cpp"); break;
        case 'c': system("cat code/converted_c.cpp | clip"); res = system("g++ code/converted_c.cpp"); break;
        case 'd': system("cat code/converted_d.cpp | clip"); res = system("g++ code/converted_d.cpp"); break;
        case 't': system("cat code/converted_t.cpp | clip"); res = system("g++ code/converted_t.cpp"); break;
    }
    if (res==0){
        cout << "Compiled!" << endl;
        cout << ">>" << endl;
        system(".\\a.exe");
    }
    switch (pro){
        case 'a': system("cat code/converted_a.cpp | clip"); break;
        case 'b': system("cat code/converted_b.cpp | clip"); break;
        case 'c': system("cat code/converted_c.cpp | clip"); break;
        case 'd': system("cat code/converted_d.cpp | clip"); break;
        case 't': system("cat code/converted_t.cpp | clip"); break;
    }
}
