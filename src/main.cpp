#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

#include "../hdr/common.h"
#include "../hdr/convert.h"
const int MAX = 200;

int main(){
   FILE* fpr;  //read
   FILE* fpw;  //write
   fpr = fopen("code/source_code.cpp", "r");
   fpw = fopen("code/converted_code.cpp", "w");

   string src;
   char c[MAX];
   while(fgets(c, MAX, fpr) != NULL) src += c;

   convert(src);
   fprintf(fpw, "%s", src.c_str());

   fclose(fpr);
   fclose(fpw);

   system("g++ code/converted_code.cpp");
   system(".\\a.exe");
}
