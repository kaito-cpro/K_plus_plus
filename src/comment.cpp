#include "../hdr/comment.h"

void comment(string& src){
    int idx;
    while(1){
        if((idx=src.find("/+"))==string::npos) break;
        int i = src.find("+/");
        src = src.substr(0, idx) + src.substr(i+2);
    }
}
