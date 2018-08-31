#include "../../hdr/prototype.h"

void bracket_(string& src){
    int idx;
    int start = 0;
    while(1){
        idx = INF;
        if(max(max(find(src.substr(start), "for("), find(src.substr(start), "if(")), find(src.substr(start), "while("))<0) break;
        if(find(src.substr(start), "for(")>=0) idx = min(idx, find(src.substr(start), "for("));
        if(find(src.substr(start), "if(")>=0) idx = min(idx, find(src.substr(start), "if("));
        if(find(src.substr(start), "while(")>=0) idx = min(idx, find(src.substr(start), "while("));
        idx += start;
        start = idx+3;
        int i = idx;
        int cntk = 0;
        while(1){
            if(src[i]=='('){
                ++cntk;
                ++i;
            }
            else if(src[i]==')'){
                --cntk;
                if(cntk==0){
                    ++i;
                    break;
                }
                else ++i;
            }
            else ++i;
        }
        while(1){
            if(src[i]!=' ') break;
            ++i;
        }
        if(src[i]=='{'){
            src = src.substr(0, i+1) + ';' + src.substr(i+1);
            cntk = 0;
            while(1){
                if(src[i]=='{'){
                    ++cntk;
                    ++i;
                }
                else if(src[i]=='}'){
                    --cntk;
                    if(cntk==0){
                        src = src.substr(0, i+1) + ';' + src.substr(i+1);
                        break;
                    }
                    else ++i;
                }
                else ++i;
            }
        }
        else {
            src = src.substr(0, i) + "{;" + src.substr(i);
            while(1){
                if(src[i]=='\n') break;
                else ++i;
            }
            src = src.substr(0, i) + "};" + src.substr(i);
        }
    }
    idx = 0;
    start = 0;
    int turn = 1;
    while(1){
        if(start>src.size()-1){
            if(turn==2) break;
            if(turn==1){
                start = 0;
                turn = 2;
                continue;
            }
        }
        if((idx=find(src.substr(start), "else"))<0){
            if(turn==2) break;
            if(turn==1){
                turn = 2;
                start = 0;
                continue;
            }
        }
        idx = idx+start;
        start = idx+4;
        int ifc = idx+4;
        int ct = 0;
        string check = "";
        while(1){
            if(src[ifc]!=' '){
                ++ct;
                check += src[ifc];
                ++ifc;
            }
            else ++ifc;
            if(ct==3) break;
        }
        if(check.substr(0, 2)=="if"&&check[2]=='('&&turn==1) continue;
        else if(turn==1){
            int i = idx+4;
            while(1){
                if(src[i]!=' ') break;
                ++i;
            }
            if(src[i]=='{'){
                src = src.substr(0, i+1) + ';' + src.substr(i+1);
                int cntk = 0;
                while(1){
                    if(src[i]=='{'){
                        ++cntk;
                        ++i;
                    }
                    else if(src[i]=='}'){
                        --cntk;
                        if(cntk==0){
                            src = src.substr(0, i+1) + ';' + src.substr(i+1);
                            break;
                        }
                        else ++i;
                    }
                    else ++i;
                }
            }
            else {
                src = src.substr(0, i) + "{;" + src.substr(i);
                while(1){
                    if(src[i]=='\n') break;
                    else ++i;
                }
                src = src.substr(0, i) + "};" + src.substr(i);
            }
        }
        else if(check.substr(0, 2)=="if"&&check[2]=='('&&turn==2){
            src = src.substr(0, idx) + "else {;" + src.substr(idx+4);
            int cntk = 0;
            int ifk = idx+7;
            int ifk2, i_pre;
            while(1){
                if(src[ifk]=='{'){
                    ++cntk;
                    ++ifk;
                }
                else if(src[ifk]=='}'){
                    --cntk;
                    if(cntk==0){
                        ifk2 = ifk+1;
                        i_pre = ifk2;
                        string chc = "";
                        int ct = 0;
                        while(ct<7){
                            if(src[ifk2]!=' '&&src[ifk2]!=';'&&src[ifk2]!='\n'){
                                chc += src[ifk2];
                                ++ct;
                                ++ifk2;
                            }
                            else ++ifk2;
                        }
                        if(chc.substr(0, 4)=="else"&&chc.substr(4, 3)!="if("){
                            cntk = 0;
                            ifk2 = i_pre;
                            while(1){
                                if(src[ifk2]=='{'){
                                    ++ifk2;
                                    ++cntk;
                                }
                                else if(src[ifk2]=='}'){
                                    --cntk;
                                    if(cntk==0) break;
                                    else ++ifk2;
                                }
                                else ++ifk2;
                            }
                            src = src.substr(0, ifk2+2) + "};" + src.substr(ifk2+2);
                            break;
                        }
                        else {
                            src = src.substr(0, ifk+2) + "};" + src.substr(ifk+2);
                            break;
                        }
                    }
                    else ++ifk;
                }
                else ++ifk;
            }
        }
    }
}
