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
            src = src.substr(0, idx) + "@sort(" + name + "+" + st + "-1, " + name + "+" + en + ");" + src.substr(i+1);
        }
        else {
            KLUSTER:
            if (flg==false){
                src = src.substr(0, idx) + "@sort(" + name + ".begin(), " + name + ".end());" + src.substr(i+1);
            }
            else {
                string arg;
                ++i;
                while (1){
                    if (src[i]==')'){
                        break;
                    }
                    else if (src[i]==' '){
                        ++i;
                    }
                    else {
                        arg+= src[i];
                        ++i;
                    }
                }
                string ins;
                string sub;
                string tp;
                int cpnnum = 1;
                if (arg=="1"){
                    string t = dict[name].substr(8);
                    int pti = 0;
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
                    for (int kkk = 0; kkk < cpnnum-1; ++kkk){
                        sub += ".first";
                    }
                    int po = 0;
                    while (1){
                        if (t[po]!=' ') break;
                        ++po;
                    }
                    while (1){
                        if (t[po]=='>' || t[po]==','){
                            break;
                        }
                        else if (t[po]!=' '){
                            tp += t[po];
                            ++po;
                        }
                        else {
                            break;
                        }
                    }
                }
                else {
                    string u = dict[name].substr(8);
                    int po = 0;
                    if (1){
                        int ctcm = 0;
                        while (1){
                            if (u[po]==','){
                                ++ctcm;
                                if (ctcm==stoi(arg)-1){
                                    break;
                                }
                                else ++po;
                            }
                            else ++po;
                        }
                        ++po;
                    }
                    while (1){
                        if (u[po]!=' ') break;
                        ++po;
                    }
                    while (1){
                        if (u[po]=='>' || u[po]==','){
                            break;
                        }
                        else if (u[po]!=' '){
                            tp += u[po];
                            ++po;
                        }
                        else {
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
                    for (int kkk = 0; kkk < cpnnum-stoi(arg); ++kkk){
                        sub += ".first";
                    }
                    sub += ".second";
                }
                string tt = dict[name].substr(8);
                vector<string> vt;
                int g = 0;
                string sg;
                while (1){
                    if (tt[g]==' '){
                        ++g;
                    }
                    else if (tt[g]==','){
                        vt.push_back(sg);
                        sg = "";
                        ++g;
                    }
                    else if (tt[g]=='>'){
                        vt.push_back(sg);
                        break;
                    }
                    else {
                        sg += tt[g];
                        ++g;
                    }
                }
                ins += "@for(int i_" + to_string(num) + "_" + " = 0; i_" + to_string(num) + "_ @< size(" + name + ")-1; ++i_" + to_string(num) + "_){\n";
                ins += tab + "@for(int j_" + to_string(num) + "_" + " = size(" + name + ")-1; j_" + to_string(num) + "_ > i_" + to_string(num) + "_; --j_" + to_string(num) + "_){\n";
                ins += tab + tab + "@if(" + name + "@[$j_" + to_string(num) + "_-1]" + sub + ">" + name + "@[$j_" + to_string(num) + "_]" + sub + "){\n";
                sub = "";
                for (int ij = 0; ij < cpnnum-1; ++ij) sub += ".first";
                for (int sl = 0; sl < cpnnum; ++sl){
                    ins += tab + tab + tab + vt[sl] + " tmp_" + to_string(num) + "_" + to_string(sl) + "_ = " + name + "@[$j_" + to_string(num) + "_]" + sub + ";\n";
                    ins += tab + tab + tab + name + "@[$j_" + to_string(num) + "_]" + sub + " = " + name + "@[$j_" + to_string(num) + "_-1]" + sub + ";\n";
                    ins += tab + tab + tab + name + "@[$j_" + to_string(num) + "_-1]" + sub + " = tmp_" + to_string(num) + "_" + to_string(sl) + "_" + ";\n";
                    if (sl==0) sub = sub.substr(0, 6*(cpnnum-2)) + ".second";
                    else sub = sub.substr(6);
                }
                ins += tab + tab + ";}\n" + tab + ";}\n;}\n";

                src = src.substr(0, idx) + ins + src.substr(i+1);
                ++num;
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
            ins += "@for(int i_" + to_string(num+1) + "_ = 0; i_" + to_string(num+1) + "_ @< size(" + vs[0] + "); ++i_" + to_string(num+1) + "_){\n";
            ins += tab + "@if(mx_" + to_string(num) + "_@<" + vs[0] + "[$i_" + to_string(num+1) + "_]) mx_" + to_string(num) + "_ = " + vs[0] + "[$i_" + to_string(num+1) + "_];\n";
            ins += "}";
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
            ins += "@for(int i_" + to_string(num+1) + "_ = 0; i_" + to_string(num+1) + "_ @< size(" + vs[0] + "); ++i_" + to_string(num+1) + "_){\n";
            ins += tab + "@if(mn_" + to_string(num) + "_@<" + vs[0] + "[$i_" + to_string(num+1) + "_]) mn_" + to_string(num) + "_ = " + vs[0] + "[$i_" + to_string(num+1) + "_];\n";
            ins += "}";
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
