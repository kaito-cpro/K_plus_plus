#include "../../hdr/prototype.h"

void if_else_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "if("))<0) break;
        int i = idx+3;
        int cntk = 1;
        while (1){
            if (src[i]=='('){
                ++cntk;
                ++i;
            }
            else if (src[i]==')'){
                --cntk;
                if (cntk==0) break;
                else ++i;
            }
            else ++i;
        }
        int ki = i;
        ++i;
        while (1){
            if (src[i]!=' ') break;
            ++i;
        }
        if (src[i]!='{'){
            while (1){
                if (src[i]=='\n') break;
                ++i;
            }
            --i;
            while (1){
                if (src[i]!=' ') break;
                --i;
            }
            src = src.substr(0, idx) + "@if(" + src.substr(idx+3, ki-idx-2) + "{" + src.substr(ki+1, i-ki) + "}" + src.substr(i+1);
        }
        else {
            src = src.substr(0, idx) + "@if(" + src.substr(idx+3, ki-idx-2) + src.substr(ki+1);
        }
    }
    while (1){
        if ((idx=find(src, "else"))<0) break;
        int i = idx+4;
        while (1){
            if (src[i]!=' ') break;
            ++i;
        }
        if (src[i]!='{'){
            if (src.substr(i, 4)=="@if("){
                src = src.substr(0, idx) + "@else" + src.substr(idx+4);
            }
            else {
                ++i;
                while (1){
                    if (src[i]=='\n') break;
                    ++i;
                }
                --i;
                while (1){
                    if (src[i]!=' ') break;
                    --i;
                }
                src = src.substr(0, idx) + "@else {" + src.substr(idx+4, i-idx-3) + "}" + src.substr(i+1);
            }
        }
        else {
            src = src.substr(0, idx) + "@else" + src.substr(idx+4);
        }
        i = idx-1;
        int cntsc = 0;
        while (1){
            if (src[i]==';'){
                ++cntsc;
                --i;
            }
            else if (src[i]=='}') break;
            else --i;
        }
        i = idx-1;
        if (cntsc!=0){
            while (1){
                if (src[i]==';'){
                    --cntsc;
                    src = src.substr(0, i) + src.substr(i+1);
                    if (cntsc==0){
                        break;
                    }
                    else --i;
                }
                else --i;
            }
        }
    }
}
