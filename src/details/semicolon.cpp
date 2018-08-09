#include "../../hdr/prototype.h"

void semicolon_(string& src){
    int i = 1;
    while (1){
        if (i==src.size()) break;
        if (src[i]=='}' && src[i-1]!='@'){
            src = src.substr(0, i) + ";" + src.substr(i);
            ++i;
        }
        else if (src[i]=='{' && src[i-1]!='@'){
            src = src.substr(0, i+1) + ";" + src.substr(i+1);
            ++i;
        }
        else if (src[i]=='\n'){
            src = src.substr(0, i) + ";" + src.substr(i);
            ++i;
        }
        ++i;
    }
}
