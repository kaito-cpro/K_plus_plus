#include "../../hdr/prototype.h"

void c_(string& src);
void math_(string& src);

void original_format_(string& src){
    c_(src);
    math_(src);
}

void c_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "long"))<0) break;
        else src = src.substr(0, idx) + "@long @long" + src.substr(idx+4);
    }
    while (1){
        if ((idx=find(src, "size("))<0) break;
        else {
            int i = idx+5;
            string name;
            while (1){
                if (src[i]==')') break;
                name += src[i];
                ++i;
            }
            if (dict[name]=="string" || dict[name].substr(0, 7)=="kluster") src = src.substr(0, idx) + name + ".@size()" + src.substr(i+1);
            else src = src.substr(0, idx) + "sizeof(" + name + ")/sizeof(" + name + "[$0])" + src.substr(i+1);
        }
    }
}

void math_(string& src){
    int start = 0;
    int idx, idx2;
    LABEL0:
    while(start<src.size()){
        if((idx=find(src.substr(start), "return "))<0) break;
        idx += start;
        start = idx+6;
        int j = idx-1;
        while(1){
            if(src[j]!=' '&&src[j]!='\n'&&src[j]!='@') break;
            else --j;
        }
        if(src[j]==';'||src[j]=='}'){
            j = idx+6;
            while(1){
                if(src[j]==';') goto LABEL0;
                else if(src[j]!=' '&&src[j]!='\n') break;
                else ++j;
            }
            src = src.substr(0, j) + '(' + src.substr(j);
            while(1){
                if(src[j]==';') break;
                else ++j;
            }
            src = src.substr(0, j) + ')' + src.substr(j);
        }
    }
    start = 0;
    LABEL2:
    while (start<src.size()){
        if ((idx2=(src.substr(start)).find("<"))==string::npos) break;
        idx = start + idx2;
        if (src[idx-1]=='@'){
            ++start;
            continue;
        }
        if (src[idx+1]=='<'){
            start = idx+2;
            continue;
        }
        // a <= x <= b
        string a, p, x, q, b;
        int i = idx+1, i_e;
        p = '<';
        if (src[idx+1]=='='){
            p = "<=";
            i = idx + 2;
        }
        while (1){
            if (src[i]!=' ') break;
            ++i;
        }
        int cntk = 1;
        while (1){
            if (src[i]=='&' || src[i]=='|'){
                src = src.substr(0, idx) + "@<" + src.substr(idx+1);
                break;
            }
            else if (src[i]=='<'){
                q = '<';
                if (src[i+1]=='='){
                    q = "<=";
                    ++i;
                }
                ++i;
                cntk = 1;
                while (1){
                    if (src[i]=='&' || src[i]=='|') goto LABEL;//8行下
                    else if (src[i]=='('){
                        ++cntk;
                        b += src[i];
                    }
                    else if (src[i]==')'){
                        --cntk;
                        if (cntk==0){
                            LABEL:
                            i_e = i;
                            i = idx-1;
                            while (1){
                                if (src[i]!=' ') break;
                                --i;
                            }
                            cntk = -1;
                            while (1){
                                if (src[i]==')'){
                                    --cntk;
                                    a = src[i] + a;
                                }
                                else if (src[i]=='('){
                                    ++cntk;
                                    if (cntk==0){
                                        UP:
                                        src = src.substr(0, i+1) + '(' +  a + '@' + p + x + "&&" +  x + '@' +  q + b + ')' + src.substr(i_e);
                                        goto LABEL2;
                                    }
                                    else a = src[i] + a;
                                }
                                else if (src[i]=='&' || src[i]=='|') goto UP; //6行上
                                else if(a.substr(0, 7)=="return "){
                                    int j = i;
                                    while(1){
                                        if(src[j]!=' '&&src[j]!='\n'&&src[j]!='@') break;
                                        --j;
                                    }
                                    if(src[j]==';'||src[j]=='}'){
                                        a = a.substr(7);
                                        goto LABEL2;
                                    }
                                    else {
                                        a = src[i] + a;
                                        continue;
                                    }
                                }
                                else a = src[i] + a;
                                --i;
                            }
                        }
                        else if(src[i]==';'){
                            goto LABEL;
                        }
                        else b += src[i];
                    }
                    else b += src[i];
                    ++i;
                }
            }
            else if (src[i]=='('){
                ++cntk;
                x += src[i];
            }
            else if (src[i]==')'){
                --cntk;
                if (cntk==0){
                    src = src.substr(0,idx) + "@<" + src.substr(idx+1);
                    break;
                }
                else x += src[i];
            }
            else if(src[i]==';'){
                src = src.substr(0,idx) + "@<" + src.substr(idx+1);
                break;
            }
            else x += src[i];
            ++i;
        }
    }
}
