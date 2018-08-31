#include "../hdr/convert.h"

void exterior(string& src){
    int idx;
    while(1){
        if((idx=src.find("@:"))==string::npos) break;
        int i = src.find(":@");
        pre += src.substr(idx+2, i-idx-2) + ";\n";
        src = src.substr(0, idx) + src.substr(i+2);
    }
}
