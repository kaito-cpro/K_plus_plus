#include "../../hdr/prototype.h"

void access_(string& src);
void push_(string& src);
void pop_(string& src);
void sort_(string& src);

void kluster_(string& src){
    access_(src);
    push_(src);
    //pop_(src);
    //sort_(src);
}

void access_(string& src){
    int idx;
    int start = 0;
    while (start<src.size()){
        if ((idx=((src.substr(start)).find("[")))==string::npos) break;
        int i = start+idx-1;
        string name;
        if (src[i]=='@'){
            ++start;
            continue;
        }
        while (1){
            if ((src[i]<'a'||src[i]>'z')&&(src[i]<'A'||src[i]>'Z')&&src[i]!='_'&&(src[i]<'0'||src[i]>'9')) break;
            else {
                name += src[i];
                --i;
            }
        }
        int prei = i;
        int j = 0;
        if (name.size()==0){
            ++start;
            continue;
        }
        while (j<=(int)name.size()/2-1){
            cout << j << endl;
            char tp = name[j];
            name[j] = name[name.size()-j-1];
            name[name.size()-j-1] = tp;
            ++j;
        }
        auto itr = dict.find(name);
        if (itr!=dict.end()){
            string type = dict[name];
            if (type.substr(0, 7)=="kluster"){
                i = start+idx+1;
                string index1, index2;
                int cntk = 1;
                while (1){
                    if (src[i]=='['){
                        ++cntk;
                        index1 += src[i];
                        ++i;
                    }
                    else if (src[i]==']'){
                        --cntk;
                        if (cntk==0){
                            ++i;
                            break;
                        }
                        else {
                            index1 += src[i];
                            ++i;
                        }
                    }
                    else {
                        index1 += src[i];
                        ++i;
                    }
                }
                bool flg = true;
                while (flg){
                    if (src[i]=='['){
                        cntk = 1;
                        ++i;
                        while (flg){
                            if (src[i]=='['){
                                ++cntk;
                                index2 += src[i];
                                ++i;
                            }
                            else if (src[i]==']'){
                                --cntk;
                                if (cntk==0){
                                    flg = false;
                                    break;
                                }
                                else {
                                    index2 += src[i];
                                    ++i;
                                }
                            }
                            else {
                                index2 += src[i];
                                ++i;
                            }
                        }
                    }
                    else {
                        break;
                    }
                }
                int prei2 = i;
                //flg==true:  name[index1] の形
                //flg==false: name[index1][index2] の形
                string ins;
                if (flg==true){
                    string type = dict[name].substr(8);
                    j = type.size()-1;
                    bool f = true;
                    while (f){
                        if (type[j]=='>'){
                            while (f){
                                --j;
                                if (type[j]!=' '){
                                    f = false;
                                    break;
                                }
                                else --j;
                            }
                        }
                        else --j;
                    }
                    type = type.substr(0, j+1);
                    ins += type + " val_" + to_string(num) + "_ = " + name + "@[" + index1 + "];";
                    i = prei;
                    while (1){
                        if (src[i]==';' || src[i]=='}') break;
                        --i;
                    }
                    src = src.substr(0, i+1) + "\n" + ins + src.substr(i+1, prei-i) + "val_" + to_string(num) + "_" + src.substr(prei2);
                    ++num;
                }
                else if (flg==false){
                    string type = dict[name];
                    int po = 8;
                    int n = stoi(index2);
                    int ctcm = 0;
                    string typ;
                    bool fg = true;
                    if (n!=1){
                        while (1){
                            if (type[po]==','){
                                ++ctcm;
                                if (ctcm==n-1){
                                    break;
                                }
                                else ++po;
                            }
                            else ++po;
                        }
                        ++po;
                    }
                    while (1){
                        if (type[po]!=' ') break;
                        ++po;
                    }
                    while (fg){
                        if (type[po]=='>' || type[po]==','){
                            break;
                        }
                        else if (type[po]!=' '){
                            typ += type[po];
                            ++po;
                        }
                        else {
                            fg = false;
                            break;
                        }
                    }
                    int cpnnum = 1;
                    int pti = 0;
                    string t = dict[name].substr(8);
                    while (1){
                        if (t[pti]==','){
                            ++cpnnum;
                            ++pti;
                        }
                        else if (t[pti]=='>'){
                            break;
                        }
                        else ++pti;
                    }
                    ins += typ + " val_" + to_string(num) + "_;\n";
                    if (n==1){
                        ins += "val_" + to_string(num) + "_ = " + name + "@[" + index1 + "]";
                        for (int k = 0; k < cpnnum-1; ++k){
                            ins += ".first";
                        }
                        ins += ";\n";
                    }
                    else {
                        ins += "val_" + to_string(num) + "_ = " + name + "@[" + index1 + "]";
                        for (int kk = 0; kk < cpnnum-n; ++kk){
                            ins += ".first";
                        }
                        ins += ".second;\n";
                    }
                    i = prei;
                    while (1){
                        if (src[i]==';' || src[i]=='}') break;
                        --i;
                    }
                    src = src.substr(0, i+1) + "\n" + ins + src.substr(i+1, prei-i) + "val_" + to_string(num) + "_" + src.substr(prei2+1);
                    ++num;
                }
            }
        }
        ++start;
    }
}

void push_(string& src){
    int idx;
    while (1){
        if ((idx=find(src, "push("))<0) break;
        int i = idx+5;
        string name;
        vector<string> v;
        while (1){
            if (src[i]!=' ') break;
            ++i;
        }
        bool flg = true;
        while (flg){
            if (src[i]==','){
                ++i;
                while (1){
                    if (src[i]=='(') break;
                    else if (src[i]!=' '){
                        --i;
                        break;
                    }
                    ++i;
                }
                ++i;
                int cntk = 1;
                string tmp;
                while (1){
                    if (src[i]=='('){
                        ++cntk;
                        tmp += src[i];
                        ++i;
                    }
                    else if (src[i]==')'){
                        --cntk;
                        if (cntk==0){
                            v.push_back(tmp);
                            flg = false;
                            break;
                        }
                        else {
                            tmp += src[i];
                            ++i;
                        }
                    }
                    else if (src[i]==','){
                        if (cntk==1){
                            v.push_back(tmp);
                            tmp = "";
                            ++i;
                        }
                        else {
                            tmp += src[i];
                            ++i;
                        }
                    }
                    else {
                        tmp += src[i];
                        ++i;
                    }
                }
            }
            else if (src[i]==' '){
                ++i;
            }
            else {
                name += src[i];
                ++i;
            }
        }
        string ends = src.substr(i+1);
        src = src.substr(0, idx);
        src += name + ".push_back(";
        if (v.size()>1){
            string type = dict[name];
            type = "pair@" + type.substr(7);
            for (int j = 0; j < v.size()-2; ++j) type = "pair@<" + type;
            for (int j = 0; j < v.size()-2; ++j){
                int pt = type.size()-1;
                while (1){
                    if (type[pt]==',' && type[pt-1]!='>'){
                        type = type.substr(0, pt) + ">" + type.substr(pt);
                        break;
                    }
                    --pt;
                }
            }
            for (int j = 0; j < v.size()-1; ++j){
                src += type + "(";
                int ix = type.size()-1;
                while (1){
                    if (type[ix]==',') break;
                    --ix;
                }
                type = type.substr(0, ix);
                ix = 0;
                while (1){
                    if (type[ix]=='<') break;
                    ++ix;
                }
                type = type.substr(ix+1);
            }
            src += v[0];
            for (int j = 1; j < v.size(); ++j){
                src += "," + v[j] + ")";
            }
            src += ends;
        }
        else {
            src += v[0] + ");" + ends;
        }
    }
}
