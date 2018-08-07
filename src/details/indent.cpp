#include "../../hdr/prototype.h"

void indent_(string& src){
   src = tab + src;
   int i = 0;
   while (i<src.size()){
      if (src[i]=='\n'){
          src = src.substr(0, i) + ";\n" + tab + src.substr(i+1);
          i += (";"+tab).size()+1;
      }
      else ++i;
   }
   src = src.substr(0, src.size()-tab.size());
}
