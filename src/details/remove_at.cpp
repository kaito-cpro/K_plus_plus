#include "../../hdr/prototype.h"

void remove_at_(string& src){
    int i = 0;
    while (i<src.size()){
        if (src[i]=='@'){
            src = src.substr(0, i) + src.substr(i+1);
            --i;
        }
        ++i;
    }
}
