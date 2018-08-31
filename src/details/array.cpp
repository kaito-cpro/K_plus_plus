#include "../../hdr/prototype.h"

void sort_(string& src);
void reverse_(string& src);  //dictで型参照
void max_(string& src);
void min_(string& src);

void array_(string& src){
    sort_(src);
    max_(src);
    min_(src);
}

void sort_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "sort("))<0) break;
        string name, st, en;
        int i = idx+5;
        while (1){
            if (src[i]!=' ') break;
            ++i;
        }
        int cntk = 0;
        bool flg = true;
        while (flg){
            if (src[i]==','){
                if (cntk==0){
                    int j = name.size()-1;
                    int cnts = 0;
                    while (j>=0){
                        if (name[j]!=' ') break;
                        else ++cnts;
                        --j;
                    }
                    name = name.substr(0, name.size()-cnts);
                    if (dict[name].substr(0, 7)=="kluster") goto KLUSTER; //下の方
                    ++i;
                    while (flg){
                        if (src[i]=='~'){
                            ++i;
                            cntk = 0;
                            while (flg){
                                if (src[i]=='('){
                                    ++cntk;
                                    en += src[i];
                                    ++i;
                                }
                                else if (src[i]==')'){
                                    --cntk;
                                    if (cntk==-1){
                                        flg = false;
                                        break;
                                    }
                                    else {
                                        en += src[i];
                                        ++i;
                                    }
                                }
                                else {
                                    en += src[i];
                                    ++i;
                                }
                            }
                        }
                        else {
                            st += src[i];
                            ++i;
                        }
                    }
                }
                else {
                    name += src[i];
                    ++i;
                }
            }
            else if (src[i]=='('){
                ++cntk;
                name += src[i];
                ++i;
            }
            else if (src[i]==')'){
                --cntk;
                if (cntk==-1){
                    int j = name.size()-1;
                    int cnts = 0;
                    while (j>=0){
                        if (name[j]!=' ') break;
                        else ++cnts;
                        --j;
                    }
                    name = name.substr(0, name.size()-cnts);
                    flg = false;
                    if (dict[name].substr(0, 7)=="kluster") goto KLUSTER; //下の方
                    break;
                }
                name += src[i];
                ++i;
            }
            else {
                name += src[i];
                ++i;
            }
        }
        if (st==""){
            src = src.substr(0, idx) + "@sort(" + name + ", " + name + "+" + "size(" + name + "));" + src.substr(i+1);
        }
        else if (st!=""){
            src = src.substr(0, idx) + "@sort(" + name + "+" + st + ", " + name + "+" + en + "+1);" + src.substr(i+1);
        }
        else {
            KLUSTER:;
            if(flg){
                ++i;
                string n;
                while(1){
                    if(src[i]==')'){
                        break;
                    }
                    else if(src[i]==' '){
                        ++i;
                    }
                    else {
                        n += src[i];
                        ++i;
                    }
                }
                src = src.substr(0, idx) + "@sort(" + name + ".begin(), " + name + ".end(), comp_" + name + "_" + n + "_);" + src.substr(i+1);
            }
            else {
                src = src.substr(0, idx) + "@sort(" + name + ".begin(), " + name + ".end(), comp_" + name + "_);" + src.substr(i+1);
            }
        }
    }
}

void max_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "max("))<0) break;
        vector<string> vs;
        int i = idx+4;
        int cntk = 0;
        int k = 0;
        string tp;
        bool flg = true;
        while (1){
            if (src[i]!=' ') break;
            ++i;
        }
        while (flg){
            if (src[i]==','){
                if (cntk==0){
                    vs.push_back(tp);
                    ++k;
                    tp = "";
                    ++i;
                    while (1){
                        if (src[i]!=' ') break;
                        ++i;
                    }
                }
                else {
                    tp += src[i];
                    ++i;
                }
            }
            else if (src[i]=='('){
                ++cntk;
                tp += src[i];
                ++i;
            }
            else if (src[i]==')'){
                --cntk;
                if (cntk==-1){
                    vs.push_back(tp);
                    ++k;
                    flg = false;
                    break;
                }
                else {
                    tp += src[i];
                    ++i;
                }
            }
            else {
                tp += src[i];
                ++i;
            }
        }
        --k;
        if (k==0){
            int j = vs[0].size()-1;
            int cnts = 0;
            while (j>=0){
                if (vs[0][j]!=' ') break;
                else ++cnts;
                --j;
            }
            vs[0] = vs[0].substr(0, vs[0].size()-cnts);
            string type = dict[vs[0]];
            j = 0;
            while (1){
                if (type[j]=='[') break;
                ++j;
            }
            type = type.substr(0, j);
            j = idx-1;
            while (1){
                if (src[j]==';' || src[j]=='}') break;
                --j;
            }
            string ins;
            ins += "\n" + type + " mx_" + to_string(num) + "_ = " + vs[0] + "[$0];\n";
            ins += "@for(int i_" + to_string(num+1) + "_ = 0; i_" + to_string(num+1) + "_ @< size(" + vs[0] + "); ++i_" + to_string(num+1) + "_){;\n";
            ins += tab + "@if(mx_" + to_string(num) + "_@<" + vs[0] + "[$i_" + to_string(num+1) + "_]) {; mx_" + to_string(num) + "_ = " + vs[0] + "[$i_" + to_string(num+1) + "_];};\n";
            ins += "};";
            src = src.substr(0, j+1) + ins + src.substr(j+1, idx-j-1) + "mx_" + to_string(num) + "_" + src.substr(i+1);
            num += 2;
        }
        else {
            string ins;
            for (int l = 0; l < k; ++l) ins += "@max(";
            ins += vs[0];
            for (int l = 1; l <= k; ++l) ins += ", " + vs[l] + ")";
            src = src.substr(0, idx) + ins + src.substr(i+1);
        }
    }
}

void min_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "min("))<0) break;
        vector<string> vs;
        int i = idx+4;
        int cntk = 0;
        int k = 0;
        string tp;
        bool flg = true;
        while (1){
            if (src[i]!=' ') break;
            ++i;
        }
        while (flg){
            if (src[i]==','){
                if (cntk==0){
                    vs.push_back(tp);
                    ++k;
                    tp = "";
                    ++i;
                    while (1){
                        if (src[i]!=' ') break;
                        ++i;
                    }
                }
                else {
                    tp += src[i];
                    ++i;
                }
            }
            else if (src[i]=='('){
                ++cntk;
                tp += src[i];
                ++i;
            }
            else if (src[i]==')'){
                --cntk;
                if (cntk==-1){
                    vs.push_back(tp);
                    ++k;
                    flg = false;
                    break;
                }
                else {
                    tp += src[i];
                    ++i;
                }
            }
            else {
                tp += src[i];
                ++i;
            }
        }
        --k;
        if (k==0){
            int j = vs[0].size()-1;
            int cnts = 0;
            while (j>=0){
                if (vs[0][j]!=' ') break;
                else ++cnts;
                --j;
            }
            vs[0] = vs[0].substr(0, vs[0].size()-cnts);
            string type = dict[vs[0]];
            j = 0;
            while (1){
                if (type[j]=='[') break;
                ++j;
            }
            type = type.substr(0, j);
            j = idx-1;
            while (1){
                if (src[j]==';' || src[j]=='}') break;
                --j;
            }
            string ins;
            ins += "\n" + type + " mn_" + to_string(num) + "_ = " + vs[0] + "[$0];\n";
            ins += "@for(int i_" + to_string(num+1) + "_ = 0; i_" + to_string(num+1) + "_ @< size(" + vs[0] + "); ++i_" + to_string(num+1) + "_){;\n";
            ins += tab + "@if(mn_" + to_string(num) + "_>" + vs[0] + "[$i_" + to_string(num+1) + "_]) {; mn_" + to_string(num) + "_ = " + vs[0] + "[$i_" + to_string(num+1) + "_];};\n";
            ins += "};";
            src = src.substr(0, j+1) + ins + src.substr(j+1, idx-j-1) + "mn_" + to_string(num) + "_" + src.substr(i+1);
            num += 2;
        }
        else {
            string ins;
            for (int l = 0; l < k; ++l) ins += "@min(";
            ins += vs[0];
            for (int l = 1; l <= k; ++l) ins += ", " + vs[l] + ")";
            src = src.substr(0, idx) + ins + src.substr(i+1);
        }
    }
}
