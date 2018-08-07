#include "../../hdr/prototype.h"

void out_(string& src){
   int idx;
   while (1){
      if ((idx=find(src, "yes()"))<0) break;
      else {
         src = src.substr(0, idx) + "cout << \"Yes\" << endl;" + src.substr(idx+5);
      }
   }
   while (1){
      if ((idx=find(src, "no()"))<0) break;
      else {
         src = src.substr(0, idx) + "cout << \"No\" << endl;" + src.substr(idx+4);
      }
   }
   while (1){
      if ((idx=find(src, "out("))<0) break;
      else {
         int cntk = 1;
         int i = idx+4;
         while (1){
            if (src[i]=='(') ++cntk;
            else if (src[i]==')'){
                --cntk;
                if (cntk==0) break;
            }
            ++i;
         }
         src = src.substr(0, idx) + "cout << " + src.substr(idx+4, i-idx-4) + " << endl;" + src.substr(i+1);
      }
   }
}
