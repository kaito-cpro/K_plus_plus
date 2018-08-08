#include "../hdr/common.h"

int find(string src, string s){
    while (1){
        int idx, start = 0;
        bool flg = false;

        if ((idx=(src.substr(start)).find(' '+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('\n'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('('+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find(')'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('{'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('}'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('<'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('&'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('|'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('='+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('+'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('-'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('*'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('/'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('%'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('!'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find(','+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find(';'+s))!=string::npos) flg = true;
        else if ((idx=(src.substr(start)).find('?'+s))!=string::npos) flg = true;
        else if (src.find(s)==0) return 0;

        if (flg){
            if (src[start+idx]!='@') return 1+start+idx;
            else ++start;
        }
        else return -1;
    }
}
