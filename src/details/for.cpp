#include "../../hdr/prototype.h"

void for_(string& src){
   int idx;
   while (1){
      if ((idx=find(src, "for"))<0) break;
      else {
         int cntk = 1;
         int i = idx+4;
         string var, ran, arr;
         bool flg = true;
         while (flg){
            if (src[i]==','){
               i += 1;
               while (1){
                  if (src[i]=='('){
                      ++cntk;
                      ran += src[i];
                  }
                  else if (src[i]==')'){
                     --cntk;
                     if (cntk==0){
                         flg = false;
                         break;
                     }
                     else ran += src[i];
                  }
                  else ran += src[i];
                  ++i;
               }
            }
            else if (src[i]==' '){
               i += 4;
               while (1){
                  if (src[i]=='('){
                      ++cntk;
                      arr += src[i];
                  }
                  else if (src[i]==')'){
                     --cntk;
                     if (cntk==0){
                         flg = false;
                         break;
                     }
                     else arr += src[i];
                  }
                  else arr += src[i];
                  ++i;
               }
            }
            else var += src[i];
            ++i;
         }
         if (arr=="") src = src.substr(0, idx) + "@for (int " + var + " = 1; " + var +" @<= " + ran + "; ++" + var + ")" + src.substr(i);
         else src = src.substr(0, idx) + "@for (int " + var + " = 1; " + var +" @<= size(" + arr + "); ++" + var + ")" + src.substr(i);
      }
   }
}
