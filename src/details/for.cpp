#include "../../hdr/prototype.h"

void for_(string& src){
   int idx;
   while (1){
      if ((idx=find(src, "for("))<0) break;
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
                   if (src[i]!=' ') break;
                   ++i;
               }
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
         if (arr==""){
             int p = i;
             while (1){
                 if (src[p]!=' ') break;
                 ++p;
             }
             if (src[p]=='{'){
                 src = src.substr(0, idx) + "@for(int " + var + " = 1; " + var +" @<= " + ran + "; ++" + var + ")" + src.substr(i);
             }
             else {
                 p = i;
                 while (1){
                     if (src[p]=='\n') break;
                     ++p;
                 }
                 --p;
                 while (1){
                     if (src[p]!=' ') break;
                     --p;
                 }
                 src = src.substr(0, idx) + "@for(int " + var + " = 1; " + var +" @<= " + ran + "; ++" + var + "){" + src.substr(i, p-i+1) + ";}" + src.substr(p+1);
             }
         }
         else if (arr[0]=='('){
             vector<string> vs;
             int j = 1, k = 0;
             cntk = -1;
             string sp;
             bool flag = true;
             while (flag){
                 if (j==arr.size()){
                     flag = false;
                     goto LAB; //16行下
                     break;
                 }
                 else if (arr[j]=='('){
                     ++cntk;
                     if (k%2==0&&cntk==-1);
                     else sp += arr[j];
                 }
                 else if (arr[j]==')'){
                     --cntk;
                     if (k%2==1&&cntk==-2);
                     else sp += arr[j];
                 }
                 else if (arr[j]==','){
                     if ((k%2==0&&cntk==-1)||(k%2==1&&cntk==-2)){
                         LAB:
                         vs.push_back(sp);
                         sp = "";
                         ++k;
                         ++j;
                         while (1){
                             if (arr[j]!=' ') break;
                             ++j;
                         }
                         if (arr[j]==')'){
                             break;
                         }
                         else --j;
                     }
                     else {
                         sp += arr[j];
                     }
                 }
                 else {
                     sp += arr[j];
                 }
                 ++j;
             }
             --k;
             string ends = src.substr(i);
             src = src.substr(0, idx);
             if (k/2+1==1){
                 int p = 0;
                 while (1){
                    if (ends[p]!=' ') break;
                    ++p;
                 }
                 if (ends[p]=='{'){
                     src += "@for(int " + var + " = " + vs[0] + "; " + var +" @<= " + vs[1] + "; ++" + var + ")" + ends;
                 }
                 else {
                     while (1){
                         if (ends[p]=='\n') break;
                         ++p;
                     }
                     --p;
                     while (1){
                         if (ends[p]!=' ') break;
                         --p;
                     }
                     src += "@for(int " + var + " = " + vs[0] + "; " + var +" @<= " + vs[1] + "; ++" + var + "){" + ends.substr(0, p+1) + ";}" + ends.substr(p+1);
                 }
             }
             else {
                 int p = 0;
                 while (1){
                     if (ends[p]!=' ') break;
                     ++p;
                 }
                 if (ends[p]=='{'){
                     int q = p, ctk = 0;
                     while (q < ends.size()){
                         if (ends[q]=='{'){
                             ++ctk;
                             ++q;
                         }
                         else if (ends[q]=='}'){
                             --ctk;
                             if (ctk==0) break;
                             else ++q;
                         }
                         else ++q;
                     }
                     src += "@for(int i_ = 0; i_@ < " + to_string(k/2+1) + "; ++i_){\n";
                     src += tab + "int sec[$" + to_string(k/2+1) + "][$2];\n";
                     for (int k_ = 0; k_ < k/2+1; ++k_){
                         src += tab + "sec[$" + to_string(k_) + "][$0] = " + vs[k_*2] + ";  sec[$" + to_string(k_) + "][$1] = " + vs[k_*2+1] + "\n";
                     }
                     src += tab + "@for(int " + var + " = sec[$i_][$0]; " + var + " <= sec[$i_][$1]; ++" + var + ")" + ends.substr(0, q+1) + tab +  ";}" + ends.substr(q+1);
                 }
                 else {
                     while (1){
                         if (ends[p]=='\n') break;
                         ++p;
                     }
                     --p;
                     while (1){
                         if (ends[p]!=' ') break;
                         --p;
                     }
                     src += "@for(int i_ = 0; i_@ < " + to_string(k/2+1) + "; ++i_){\n";
                     src += tab + "int sec[$" + to_string(k/2+1) + "][$2];\n";
                     for (int k_ = 0; k_ < k/2+1; ++k_){
                         src += tab + "sec[$" + to_string(k_) + "][$0] = " + vs[k_*2] + ";  sec[$" + to_string(k_) + "][$1] = " + vs[k_*2+1] + "\n";
                     }
                     src += tab + "@for(int " + var + " = sec[$i_][$0]; " + var + " <= sec[$i_][$1]; ++" + var + "){" + ends.substr(0, p+1) + ";}\n;}" + ends.substr(p+1);

                 }
             }
         }
         else {
             int p = i;
             while (1){
                 if (src[p]!=' ') break;
                 ++p;
             }
             if (src[p]=='{'){
                 src = src.substr(0, idx) + "@for(int " + var + " = 1; " + var + " @<= sizeof(" + arr + ")/sizeof(" + arr + "[$0]); ++" + var + ")" + src.substr(i);
             }
             else {
                 p = i;
                 while (1){
                     if (src[p]=='\n') break;
                     ++p;
                 }
                 --p;
                 while (1){
                     if (src[p]!=' ') break;
                     --p;
                 }
                 src = src.substr(0, idx) + "@for(int " + var + " = 1; " + var +" @<= sizeof(" + arr + ")/sizeof(" + arr + "[$0]); ++" + var + "){" + src.substr(i, p-i+1) + ";}" + src.substr(p+1);
             }

         }
      }
   }
}
