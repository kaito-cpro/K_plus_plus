#include "../../hdr/prototype.h"

void reverse_(string& src);
void size_(string& src);
void last_(string& src);
void sub_(string& src);

void kstr_(string& src){
    reverse_(src);
    size_(src);
    last_(src);
    sub_(src);
}

void reverse_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "reverse("))<0) break;
        int i = idx+8;
        string name;
        int cntk = 1;
        while (1){
            if (src[i]!=' ') break;
            ++i;
        }
        while (1){
            if (src[i]=='('){
                ++cntk;
                name += src[i];
            }
            else if (src[i]==')'){
                --cntk;
                if (cntk==0) break;
                else name += src[i];
            }
            else name += src[i];
            ++i;
        }
        string ends = src.substr(i+1);
        src = src.substr(0, idx) + "int i_" + to_string(num) + "_ = 0;\nwhile(i_" + to_string(num) + "_<size(" + name + ")/2){\n" + tab + "char tp_ = " + name + "[$i_" + to_string(num) + "_];\n";
        src += tab + name + "[$i_" + to_string(num) + "_] = " + name + "[$size(" + name + ")-i_" + to_string(num) + "_-1];\n";
        src += tab + name + "[$size(" + name + ")-i_" + to_string(num) + "_-1] = tp_;\n" + tab + "++i_" + to_string(num) + "_;\n" + "}" + ends;
        ++num;
    }
}

void size_(string& src){
    int idx;
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
            if (dict[name]=="kstr" || dict[name].substr(0, 7)=="kluster") src = src.substr(0, idx) + name + ".@size()" + src.substr(i+1);
            else src = src.substr(0, idx) + "sizeof(" + name + ")/sizeof(" + name + "[$0])" + src.substr(i+1);
        }
    }
}

void last_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "last("))<0) break;
        else {
            int i = idx+5;
            string name;
            while (1){
                if (src[i]==')') break;
                name += src[i];
                ++i;
            }
            if (dict[name]=="kstr") src = src.substr(0, idx) + name + ".@size()" + src.substr(i+1);
            else src = src.substr(0, idx) + "sizeof(" + name + ")/sizeof(" + name + "[$0])" + src.substr(i+1);
        }
    }
}

void sub_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "sub("))<0) break;
        int i = idx+4;
        string name, st, en;
        int cntk = 0;
        bool flg = true;
        while (flg){
            if (src[i]=='('){
                ++cntk;
                name += src[i];
                ++i;
            }
            else if (src[i]==')'){
                --cntk;
                name += src[i];
                ++i;
            }
            else if (src[i]==','){
                if (cntk==0){
                    ++i;
                    while (flg){
                        if (src[i]=='~'){
                            ++i;
                            while (flg){
                                cntk = 0;
                                if (src[i]=='('){
                                    ++cntk;
                                    en += src[i];
                                    ++i;
                                }
                                else if (src[i]==')'){
                                    --cntk;
                                    if (cntk==-1){
                                        flg = false;
                                        break;
                                    }
                                    else {
                                        en += src[i];
                                        ++i;
                                    }
                                }
                                else {
                                    en += src[i];
                                    ++i;
                                }
                            }
                        }
                        else st += src[i];
                        ++i;
                    }
                }
                else {
                    name += src[i];
                    ++i;
                }
            }
            else {
                name += src[i];
                ++i;
            }
        }
        int j = name.size()-1;
        int cnts = 0;
        while (j>=0){
            if (name[j]==' ') ++cnts;
            else if (name[j]!=' ') break;
            --j;
        }
        name =  name.substr(0, name.size()-cnts);
        src = src.substr(0, idx) + name + ".substr(" + st + "-1, " + en + "-" + st + "+1)" + src.substr(i);
    }
}
