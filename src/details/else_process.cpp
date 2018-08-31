#include "../../hdr/prototype.h"

void else_process_(string& src){
    int idx;
    while(1){
        if((idx=find(src, "else"))<0) break;
        string ins = "";
        int i = idx-1;
        while(1){
            if(src[i]==';'&&src[i-1]=='}') break;
            else if(src[i]=='\n'){
                ins += '\n';
                --i;
            }
            else {
                ins += ' ';
                --i;
            }
        }
        int n = 0;
        while(n<(int)(ins.size())/2){
            char tmp = ins[n];
            ins[n] = ins[ins.size()-n-1];
            ins[ins.size()-n-1] = tmp;
            ++n;
        }
        src = src.substr(0, i) + ins + '@' + src.substr(idx);
    }
}
