#include "../../hdr/prototype.h"

void semicolon_(string& src){
    int i = 1;
    while (1){
        if (i==src.size()) break;
        if (src[i]=='}' && src[i-1]!='@'){
            src = src.substr(0, i) + ";" + src.substr(i);
            ++i;
        }
        ++i;
    }
}
