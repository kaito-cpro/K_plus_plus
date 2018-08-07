#include "../../hdr/prototype.h"

void shift_index_(string& src){
    int start = 0;
    int idx;
    while (1){
        if ((idx=(src.substr(start)).find("["))==string::npos) break;
        else {
            int i = start+idx+1;
            if (src[i]=='$'){
                start = i;
                continue;
            }
            string var;
            while (1){
                if (src[i]==']') break;
                var += src[i];
                ++i;
            }
            src = src.substr(0, start+idx+1) + var + "-1" + src.substr(i);
            start = i;
        }
    }
}
