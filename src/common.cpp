#include "../hdr/common.h"

int find(string src, string s){
    while(1){
        int idx = INF, start = 0;
        bool flg = false;

        if((src.substr(start)).find(' '+s)!=string::npos&&idx>(src.substr(start)).find(' '+s))   flg = true, idx = (src.substr(start)).find(' '+s);
        if((src.substr(start)).find('\n'+s)!=string::npos&&idx>(src.substr(start)).find('\n'+s)) flg = true, idx = (src.substr(start)).find('\n'+s);
        if((src.substr(start)).find('('+s)!=string::npos&&idx>(src.substr(start).find('('+s)))   flg = true, idx = (src.substr(start)).find('('+s);
        if((src.substr(start)).find(')'+s)!=string::npos&&idx>(src.substr(start).find(')'+s)))   flg = true, idx = (src.substr(start)).find(')'+s);
        if((src.substr(start)).find('{'+s)!=string::npos&&idx>(src.substr(start).find('{'+s)))   flg = true, idx = (src.substr(start)).find('{'+s);
        if((src.substr(start)).find('}'+s)!=string::npos&&idx>(src.substr(start).find('}'+s)))   flg = true, idx = (src.substr(start)).find('}'+s);
        if((src.substr(start)).find('['+s)!=string::npos&&idx>(src.substr(start).find('['+s)))   flg = true, idx = (src.substr(start)).find('['+s);
        if((src.substr(start)).find(']'+s)!=string::npos&&idx>(src.substr(start).find(']'+s)))   flg = true, idx = (src.substr(start)).find(']'+s);
        if((src.substr(start)).find('<'+s)!=string::npos&&idx>(src.substr(start).find('<'+s)))   flg = true, idx = (src.substr(start)).find('<'+s);
        if((src.substr(start)).find('&'+s)!=string::npos&&idx>(src.substr(start).find('&'+s)))   flg = true, idx = (src.substr(start)).find('&'+s);
        if((src.substr(start)).find('|'+s)!=string::npos&&idx>(src.substr(start).find('|'+s)))   flg = true, idx = (src.substr(start)).find('|'+s);
        if((src.substr(start)).find('='+s)!=string::npos&&idx>(src.substr(start).find('='+s)))   flg = true, idx = (src.substr(start)).find('='+s);
        if((src.substr(start)).find('+'+s)!=string::npos&&idx>(src.substr(start).find('+'+s)))   flg = true, idx = (src.substr(start)).find('+'+s);
        if((src.substr(start)).find('-'+s)!=string::npos&&idx>(src.substr(start).find('-'+s)))   flg = true, idx = (src.substr(start)).find('-'+s);
        if((src.substr(start)).find('*'+s)!=string::npos&&idx>(src.substr(start).find('*'+s)))   flg = true, idx = (src.substr(start)).find('*'+s);
        if((src.substr(start)).find('/'+s)!=string::npos&&idx>(src.substr(start).find('/'+s)))   flg = true, idx = (src.substr(start)).find('/'+s);
        if((src.substr(start)).find('%'+s)!=string::npos&&idx>(src.substr(start).find('%'+s)))   flg = true, idx = (src.substr(start)).find('%'+s);
        if((src.substr(start)).find('!'+s)!=string::npos&&idx>(src.substr(start).find('!'+s)))   flg = true, idx = (src.substr(start)).find('!'+s);
        if((src.substr(start)).find(','+s)!=string::npos&&idx>(src.substr(start).find(','+s)))   flg = true, idx = (src.substr(start)).find(','+s);
        if((src.substr(start)).find(';'+s)!=string::npos&&idx>(src.substr(start).find(';'+s)))   flg = true, idx = (src.substr(start)).find(';'+s);
        if((src.substr(start)).find('?'+s)!=string::npos&&idx>(src.substr(start).find('?'+s)))   flg = true, idx = (src.substr(start)).find('?'+s);
        if((src.substr(start)).find('$'+s)!=string::npos&&idx>(src.substr(start).find('$'+s)))   flg = true, idx = (src.substr(start)).find('$'+s);
        if(src.find(s)==0) return 0;

        if(flg){
            if (src[start+idx]!='@') return 1+start+idx;
            else ++start;
        }
        else return -1;
    }
}

void WaitTime(int msec){
    clock_t start, end;
    start = clock();
    while(1){
        end = clock();
        if(end-start >= msec) break;
    }
}
