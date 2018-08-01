#include "../hdr/common.h"

int find(string src, string s){
   int res = -1;
   if (src.find(' '+s)!=string::npos) res = 1 + src.find(' '+s);
   if (src.find('\n'+s)!=string::npos) res = 1 + src.find('\n'+s);
   if (src.find(s)==0) res = 0;
   return res;
}

string size(string arrayname){
   return dict[arrayname];
}
