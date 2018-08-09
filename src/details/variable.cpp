#include "../../hdr/prototype.h"

void variable_(string& src){
    int i = 1;
    while (i++ < src.size()-1){
        if (src[i-1]!='@' && src[i]=='<' && src[i+1]=='<'){
            int idx = i;
            int p = i+2, q = i-1;
            while (1){
                if (src[p]!=' ') break;
                ++p;
            }
            string ele, tandn;
            while (1){
                if (src[p]=='\n' || src[p]==';') break;
                else ele += src[p];
                ++p;
            }
            while (1){
                if (src[q]!=' ') break;
                --q;
            }
            while (1){
                if (src[q]=='\n' || src[q]==';' || src[q]=='}') break;
                else tandn += src[q];
                --q;
            }
            int j = 0;
            bool flg = true;
            while (j < tandn.size() && flg){
                if (tandn[j]==' '){
                    ++j;
                    while (j < tandn.size()){
                        if (tandn[j]!=' '){
                            flg = false;
                            --j;
                            break;
                        }
                        ++j;
                    }
                }
                ++j;
            }
            int m = 0;
            bool fele = false;
            while (m < ele.size()){
                if (ele[m]!=' '){
                    fele = true;
                    break;
                }
                ++m;
            }
            if (fele){
                int id = 0;
                while (id < ele.size()){
                    if (ele[id]=='}'){
                        ele = ele.substr(0, id) + "@" + ele.substr(id);
                        id += 2;
                    }
                    else ++id;
                }
            }
            string name, type;
            if (flg==false){
                string n = tandn.substr(0, j-1);
                for (int k = n.size()-1; k >= 0; --k) name += n[k];
                int cnts = 0;
                m = 0;
                while (m < name.size()){
                    if (name[m]==' ') ++cnts;
                    else if (name[m]!=' ') break;
                    ++m;
                }
                name = name.substr(cnts);
                bool farr = false;
                m = 0;
                while (m < name.size()){
                    if (name[m]=='['){
                        farr = true;
                        break;
                    }
                    else ++m;
                }
                string forarr = name.substr(m);
                string spc;
                for (int r = 0; r < cnts; ++r) spc += ' ';
                string t = tandn.substr(j);
                int l = t.size()-1;
                while (1){
                    if (t[l]!=' ') break;
                    --l;
                }
                for (int k = l; k >= 0; --k) type += t[k];
                if (type.substr(0, 7)=="kluster"){
                    vector<string> v;
                    string tmp;
                    int k = 7;
                    while (1){
                        if (type[k]!=' ') break;
                        ++k;
                    }
                    int cntk = 0;
                    while (1){
                        if (type[k]=='<'){
                            ++cntk;
                            ++k;
                        }
                        else if (type[k]=='>'){
                            --cntk;
                            if (cntk==0){
                                v.push_back(tmp);
                                break;
                            }
                            else {
                                tmp += type[k];
                                ++k;
                            }
                        }
                        else if (type[k]==' '){
                            ++k;
                        }
                        else if (type[k]==','){
                            v.push_back(tmp);
                            tmp = "";
                            ++k;
                        }
                        else {
                            tmp += type[k];
                            ++k;
                        }
                    }
                    string ends = src.substr(p);
                    src = src.substr(0, src.find("kluster"));
                    src += "vector@<";
                    for (int i_ = 0; i_ < v.size()-1; ++i_) src += "pair@<";
                    src += v[0];
                    for (int i_ = 1; i_ < v.size(); ++i_) src += ", " + v[i_] + ">";
                    src += "> " + name + ";" + ends;
                    string dicttype = "kluster<";
                    for (int i_ = 0; i_ < v.size()-1; ++i_){
                        dicttype += v[i_] + ", ";
                    }
                    dicttype += v[v.size()-1] + ">";
                    dict[name] = dicttype;
                }
                else {
                    if (farr){
                        dict[name.substr(0, m)] = type + forarr;
                        int ix = 0;
                        while (ix < name.size()){
                            if (name[ix]=='['){
                                name = name.substr(0, ix+1) + "$" + name.substr(ix+1);
                                ix += 2;
                            }
                            else ++ix;
                        }
                        if (fele) src = src.substr(0, q+1) + spc + type + " " + name + " = " + ele + ";" + src.substr(p);
                        else src = src.substr(0, q+1) + spc + type + " " + name + ";" + src.substr(p);
                    }
                    else {
                        dict[name] = type;
                        if (fele) src = src.substr(0, q+1) + spc + type + " " + name + " = " + ele + ";" + src.substr(p);
                        else src = src.substr(0, q+1) + spc + type + " " + name + ";" + src.substr(p);
                    }
                }
            }
            else {
                string n = tandn;
                for (int k = n.size()-1; k >= 0; --k) name += n[k];
                int cnts = 0;
                m = 0;
                while (m < name.size()){
                    if (name[m]==' ') ++cnts;
                    else if (name[m]!=' ') break;
                    ++m;
                }
                name = name.substr(cnts);
                bool farr = false;
                m = 0;
                while (m < name.size()){
                    if (name[m]=='['){
                        farr = true;
                        break;
                    }
                    else ++m;
                }
                string forarr = name.substr(m);
                string spc;
                for (int r = 0; r < cnts; ++r) spc += ' ';

                if (ele.find("\"")!=string::npos){
                    type = "kstr";
                }
                else if (ele.find("'")!=string::npos){
                    type = "char";
                }
                else if ((ele.find("true")!=string::npos || ele.find("false")!=string::npos) && ele.find("\"")==string::npos){
                    type = "bool";
                }
                else if (ele.find(".")!=string::npos && ele.find("\"")==string::npos){
                    type = "double";
                }
                else type = "int";
                if (farr){
                    dict[name.substr(0, m)] = type + forarr;
                    int ix = 0;
                    while (ix < name.size()){
                        if (name[ix]=='['){
                            name = name.substr(0, ix+1) + "$" + name.substr(ix+1);
                            ix += 2;
                        }
                        else ++ix;
                    }
                    if (fele) src = src.substr(0, q+1) + spc + type + " " + name + " = " + ele + ";" + src.substr(p);
                    else src = src.substr(0, q+1) + spc + type + " " + name + ";" + src.substr(p);
                }
                else {
                    dict[name] = type;
                    if (fele) src = src.substr(0, q+1) + spc + type + " " + name + " = " + ele + ";" + src.substr(p);
                    else src = src.substr(0, q+1) + spc + type + " " + name + ";" + src.substr(p);
                }
            }
        }
    }
}
