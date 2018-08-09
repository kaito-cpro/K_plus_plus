#include "../hdr/convert.h"

void convert(string& src){
    in_(src);
    out_(src);
    for_(src);
    variable_(src);
    semicolon_(src);
    array_(src);
    kstr_(src);
    kluster_(src);
    indent_(src);
    if_else_(src);
    original_format_(src);
    include_(src);
    shift_index_(src);
    remove_mark_(src);
    //変数管理の表示
    for(auto itr = dict.begin(); itr != dict.end(); ++itr)
        cout << "key = " << setw(8) << left <<  itr->first << ", val = " << itr->second << endl;
}
