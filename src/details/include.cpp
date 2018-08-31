#include "../../hdr/prototype.h"

void include_(string& src){
    src = "#include <iostream>\n"
         "#include <cstdio>\n"
         "#include <cmath>\n"
         "#include <vector>\n"
         "#include <list>\n"
         "#include <set>\n"
         "#include <map>\n"
         "#include <stack>\n"
         "#include <queue>\n"
         "#include <string>\n"
         "#include <cstring>\n"
         "#include <utility>\n"
         "#include <algorithm>\n"
         "#include <functional>\n"
         "#include <deque>\n"
         "#include <cctype>\n"
         "#include <ctime>\n"
         "#include <cstdlib>\n"
         "#include <iomanip>\n"
         "using namespace std;\n\n"
         + pre
         + "\nint main(){\n"
         +src.substr(2)+"}";
}
