#include "../../hdr/prototype.h"

void str_(string& src);
void size_(string& src);
void last_(string& src);

void kstr_(string& src){
    str_(src);
    size_(src);
    last_(src);
}

void str_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "kstr"))<0) break;
        src = src.substr(0, idx) + "string" + src.substr(idx+4);
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
            if (dict[name]=="kstr") src = src.substr(0, idx) + name + ".@size()" + src.substr(i+1);
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
