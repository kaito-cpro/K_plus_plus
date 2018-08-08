#include "../hdr/convert.h"

void convert(string& src){
    in_(src);
    out_(src);
    for_(src);
    kstr_(src);
    original_format_(src);
    indent_(src);
    semicolon_(src);
    if_else_(src);
    include_(src);
    shift_index_(src);
    remove_mark_(src);
}
