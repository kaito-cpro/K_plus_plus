#include "../hdr/common.h"
#include "../hdr/convert.h"
#include "../hdr/prototype.h"
const int MAX = 200;
string tab = "    ";
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
    }

    string src = "\n";
    char c[MAX];
    while(fgets(c, MAX, fpr) != NULL) src += c;

    convert(src);
    fprintf(fpw, "%s", src.c_str());

    fclose(fpr);
    fclose(fpw);

    cout << "Now compiling..." << endl;
    int res;
    switch (pro){
        case 'a': res = system("g++ code/converted_a.cpp"); break;
        case 'b': res = system("g++ code/converted_b.cpp"); break;
        case 'c': res = system("g++ code/converted_c.cpp"); break;
        case 'd': res = system("g++ code/converted_d.cpp"); break;
    }
    if (res==0){
        cout << "Compiled!" << endl;
        cout << ">>" << endl;
        system(".\\a.exe");
    }
}
