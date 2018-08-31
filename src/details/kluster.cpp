#include "../../hdr/prototype.h"

void access_(string& src);
void push_(string& src);
void pop_(string& src);
void sort_(string& src);  //array.cppに統合

void kluster_(string& src){
    access_(src);
    push_(src);
    //pop_(src);
}

void access_(string& src){
    int idx, start = 0;
    while(start<src.size()){
        if((idx=(src.substr(start)).find("["))==string::npos) break;
        idx += start;
        if(src[idx-1]=='@'){
            start = idx+1;
            continue;
        }
        string name;
        int i = idx-1;
        while (1){
            if ((src[i]<'a'||src[i]>'z')&&(src[i]<'A'||src[i]>'Z')&&src[i]!='_'&&(src[i]<'0'||src[i]>'9')) break;
            else {
                name += src[i];
                --i;
            }
        }
        if (name.size()==0){
            start = idx+1;
            continue;
        }
        int j = 0;
        while (j<=(int)name.size()/2-1){
            char tp = name[j];
            name[j] = name[name.size()-j-1];
            name[name.size()-j-1] = tp;
            ++j;
        }
        auto itr = dict.find(name);
        if (itr!=dict.end()){
            if(dict[name].substr(0, 7)!="kluster"){
                start = idx+1;
                continue;
            }
            string index1, index2;
            i = idx+1;
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
                                ++i;
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
            while(1){
                if(index2[0]!=' ') break;
                index2 = index2.substr(1);
            }
            //flg==true:  name[index1] の形
            //flg==false: name[index1][index2] の形
            if(flg){
                index2 = "0";
            }
            string alt = "@[" + index1 + "].m_" + index2;
            src = src.substr(0, idx) + alt + src.substr(i);
        }
        start = idx+1;
    }
}

void push_(string& src){
    int idx;
    while(1){
        if((idx=find(src, "push("))<0) break;
        int i = idx+5;
        string name = "";
        while(1){
            if(src[i]!=' ') break;
            ++i;
        }
        vector<string> vec;
        string tmp = "";
        while(1){
            if(src[i]==','){
                ++i;
                while(1){
                    if(src[i]=='('){
                        ++i;
                        int cntk = 0;
                        while(1){
                            if(src[i]==','){
                                if(cntk==0){
                                    vec.push_back(tmp);
                                    tmp = "";
                                    ++i;
                                }
                                else {
                                    tmp += src[i];
                                    ++i;
                                }
                            }
                            else if(src[i]=='('){
                                ++cntk;
                                tmp += src[i];
                                ++i;
                            }
                            else if(src[i]==')'){
                                --cntk;
                                if(cntk==-1){
                                    vec.push_back(tmp);
                                    goto ENDOFWHILE;
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
                    else if(src[i]==' '){
                        ++i;
                    }
                    else {
                        while(1){
                            if(src[i]==')'){
                                vec.push_back(tmp);
                                goto ENDOFWHILE;
                            }
                            else {
                                tmp += src[i];
                                ++i;
                            }
                        }
                    }
                }
            }
            else if(src[i]==' '){
                ++i;
            }
            else {
                name += src[i];
                ++i;
            }
        }
        ENDOFWHILE:
        while(1){
            if(src[i]==';') break;
            ++i;
        }
        string ends = src.substr(i+1);
        src = src.substr(0, idx) + name + ".push_back(@{";
        for(int j = 0; j < vec.size(); ++j){
            src += vec[j];
            if(j!=vec.size()-1) src += ",";
        }
        src += "});" + ends;
    }
}
