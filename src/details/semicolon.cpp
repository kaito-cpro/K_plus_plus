#include "../../hdr/prototype.h"

void semicolon_(string& src){
    int i = 1;
    while(i<src.size()){
        if(src[i]=='\n'){
            src = src.substr(0, i) + ";" + src.substr(i);
            ++i;
        }
        else if(src[i]=='{'&&src[i-1]!='@'){
            int j = i-1;
            bool flg = true;
            while(1){
                if(src[j]!=' '){
                    if(src[j]=='<'&&src[j-1]=='<'){
                        flg = false;
                    }
                    break;
                }
                else --j;
            }
            if(flg) src = src.substr(0, i+1) + ';' + src.substr(i+1);
            ++i;
        }
        else if(src[i]=='}'&&src[i-1]!='@'){
            src = src.substr(0, i+1) + ';' + src.substr(i+1);
            ++i;
        }
        ++i;
    }
}
