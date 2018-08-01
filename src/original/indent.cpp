#include "../../hdr/prototype.h"

void indent_(string& src){
   src = tab + src;
   int i = 0;
   while (src[i]){
      if (src[i]=='\n') src.insert(i+1, tab);
      ++i;
   }
   src = src.substr(0, src.size()-tab.size());
}
