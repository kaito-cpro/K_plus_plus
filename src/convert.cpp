#include "../hdr/convert.h"

void convert(string& src){
    static bool flg = false;
    semicolon_(src);
    cout << "semicolon" << endl;
    bracket_(src);
    cout << "bracket" << endl;

    variable_(src);
    cout << "variable" << endl;
    in_(src);
    cout << "in" << endl;
    out_(src);
    cout << "out" << endl;
    for_(src);
    cout << "for" << endl;
    array_(src);
    cout << "array" << endl;
    string_(src);
    cout << "string" << endl;
    kluster_(src);
    cout << "kluster" << endl;
    original_format_(src);
    cout << "original_format" << endl;
    else_process_(src);
    cout << "else_prcess" << endl;
    remove_mark_(src);
    cout << "remove_mark" << endl;

    if(flg) return;
    flg = true;
    convert(pre);

    indent_(src);
    cout << "indent" << endl;
    include_(src);
    cout << "include" << endl;

    //変数管理の表示
    for(auto itr = dict.begin(); itr != dict.end(); ++itr)
        cout << "name = " << setw(8) << left <<  itr->first << ", type = " << itr->second << endl;
}
