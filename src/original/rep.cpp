#include "../../hdr/prototype.h"

void rep_(string& src){
   int idx;
   while (1){
      if ((idx=find(src, "rep"))<0) break;
      else {
         int i = idx+4;
         string var, ran, arr;
         bool flg = true;
         while (flg){
            if (src[i]==','){
               i += 2;
               while (1){
                  if (src[i]==')'){
                     flg = false;
                     break;
                  }
                  else ran += src[i];
                  ++i;
               }
            }
            else if (src[i]==' '){
               i += 4;
               while (1){
                  if (src[i]==')'){
                     flg = false;
                     break;
                  }
                  else arr += src[i];
                  ++i;
               }
            }
            else var += src[i];
            ++i;
         }
         if (arr=="") src = src.substr(0, idx) + "for (int " + var + " = 1; " + var +" <= " + ran + "; ++" + var + ")" + src.substr(i);
         else src = src.substr(0, idx) + "for (int " + var + " = 1; " + var +" <= " + size(arr) + "; ++" + var + ")" + src.substr(i);
      }
   }
}
