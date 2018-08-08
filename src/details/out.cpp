#include "../../hdr/prototype.h"

void out_(string& src){
   int idx;
   while (1){
      if ((idx=find(src, "yes()"))<0) break;
      else {
         src = src.substr(0, idx) + "cout @<@< \"Yes\" @<@< endl;" + src.substr(idx+5);
      }
   }
   while (1){
      if ((idx=find(src, "no()"))<0) break;
      else {
         src = src.substr(0, idx) + "cout @<@< \"No\" @<@< endl;" + src.substr(idx+4);
      }
   }
   while (1){
      if ((idx=find(src, "out("))<0) break;
      else {
         int cntk = 0, cntq = 0;
         int i = idx+4;
         vector<string> vs;
         string tp;
         int k = 0;
         bool flg = true;
         while (flg){
            if (src[i]=='('){
                tp += src[i];
                ++cntk;
            }
            else if (src[i]==')'){
                --cntk;
                if (cntk==-1){
                    flg = false;
                    vs.push_back(tp);
                    ++k;
                    break;
                }
                else tp += src[i];
            }
            else if (src[i]=='"'){
                tp += src[i];
                ++cntq;
            }
            else if (src[i]==','){
                if (cntk==0 && cntq%2==0){
                    vs.push_back(tp);
                    ++k;
                    tp = "";
                    ++i;
                    while (1){
                        if (src[i]!=' ') break;
                        ++i;
                    }
                    --i;
                }
                else tp += src[i];
            }
            else tp += src[i];
            ++i;
         }
         string ends = src.substr(i+1);
         src = src.substr(0, idx) + "cout";
         for (int l = 0; l < k-1; ++l){
            src += " @<@< (" + vs[l] + ")";
         }
         if (vs[k-1]=="-endl") src += ";" + ends;
         else src += " @<@< (" + vs[k-1] + ") @<@< endl;" + ends;
      }
   }
}
