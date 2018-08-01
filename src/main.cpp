#include "../hdr/common.h"
#include "../hdr/convert.h"
#include "../hdr/prototype.h"
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

   int res = system("g++ code/converted_code.cpp");
   if (res==0){
      cout << "Completed!" << endl;
      system(".\\a.exe");
   }
}
