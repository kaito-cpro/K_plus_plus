#include "../../hdr/prototype.h"

void indent_(string& src){
   src = "   " + src;
   int i = 0;
   while (src[i]){
      if (src[i]=='\n') src.insert(i+1, "   ");
      ++i;
   }
   src = src.substr(0, src.size()-3);
}
