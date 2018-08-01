#include "../../hdr/prototype.h"

void in_(string& src){
   while (1){
      int idx;
      if ((idx=find(src, "in("))<0) break;
      if ((idx=find(src, "in("))>=0){
         vector<P> v;
         int i = idx+3;
         bool flg = true;
         while (flg){
            string type, name;  string key;
            while (1){
               if (src[i]==')'){
                  flg = false;
                  break;
               }
               else if (src[i]=='['){
                  while (1){
                     if (src[i]==',') break;
                     if (src[i]==')'){
                        flg = false;
                        break;
                     }
                     key += src[i];
                     ++i;
                  }
                  ++i;
                  break;
               }
               else if (src[i]==' '){
                  ++i;
                  while (1){
                     if (src[i]==','){
                        ++i;
                        break;
                     }
                     else if (src[i]==' '){
                        flg = false;
                        break;
                     }
                     else if (src[i]=='['){
                        while (1){
                           if (src[i]==',') break;
                           if (src[i]==')'){
                              flg = false;
                              break;
                           }
                           key += src[i];
                           ++i;
                        }
                        ++i;
                        break;
                     }
                     else {
                        name += src[i];
                        ++i;
                     }
                  }
                  break;
               }
               else if (src[i]==','){
                  ++i;
                  break;
               }
               else {
                  type += src[i];
                  ++i;
                  continue;
               }
            }
            if (name==""){
               name = type;
               if (!v.empty()) type = v[v.size()-1].first;
               else type = "int";
            }
            type += key;
            v.push_back(P(type, name));
            ++i;
         }
         string strend = src.substr(i);
         src = src.substr(0, idx);
         string type = v[0].first;
         int i_s = 0, i_e = 0;
         i = 0;
         while (i <= v.size()){
            if (i==v.size()) goto LABEL;
            if (v[i].first==type) i_e = i;
            else {
               LABEL:
               if (type.find("[")==string::npos){
                  src += type;
                  for (int i = i_s; i <= i_e; ++i){
                     if (i!=i_s) src += ",";
                     src += " " + v[i].second;
                  }
                  dict[v[i].second] = "no size";
                  src += ";\ncin";
                  for (int i = i_s; i <= i_e; ++i){
                     src += " >> " + v[i].second;
                  }
                  src += ";\n";
                  i_s =  i;  i_e = i;
               }
               else {
                  int cnt = 0;
                  for (int j = 0; j < type.size(); ++j) if (type[j]=='[') ++cnt;
                  switch (cnt){
                     case 1: {
                        src += type.substr(0, type.find("["));
                        string k = type.substr(type.find("[")+1, type.find("]")-type.find("[")-1);
                        for (int i = i_s; i <= i_e; ++i){
                           if (i!=i_s) src += ",";
                           src += " " + v[i].second + "[" + k + "]";
                        }
                        dict[v[i].second] = type.substr(type.find("[")+1, type.find("]")-type.find("[")-1);
                        src += ";\n";
                        src += "for (int i = 1; i <= " + k + "; ++i) cin";
                        for (int i = i_s; i <= i_e; ++i){
                           src += " >> " + v[i].second + "[i]";
                        }
                        src += ";\n";
                        i_s =  i;  i_e = i;
                        break;
                     }
                     case 2: {
                        src += type.substr(0, type.find("["));
                        string n = type.substr(type.find("[")+1, type.find("]")-type.find("[")-1);
                        string m = type.substr(type.rfind("[")+1, type.rfind("]")-type.rfind("[")-1);
                        for (int i = i_s; i <= i_e; ++i){
                           if (i!=i_s) src += ",";
                           src += " " + v[i].second + "[" + n + "]" + "[" + m + "]";
                        }
                        dict[v[i].second] = type.substr(type.find("[")+1, type.find("]")-type.find("[")-1) + ", " + type.substr(type.rfind("[")+1, type.rfind("]")-type.rfind("[")-1);
                        src += ";\n";
                        src += "for (int i = 1; i <= " + n + "; ++i){\n";
                        src += "   for (int j = 1; j <= " + m + "; ++j){\n      cin";
                        for (int i = i_s; i <= i_e; ++i){
                           src += " >> " + v[i].second + "[i][j]";
                        }
                        src += ";\n   }\n}\n";
                        i_s =  i;  i_e = i;
                        break;
                     }
                  }
               }
            }
            if (i!=v.size()) type = v[i].first;
            ++i;
         }
         src += strend;
      }
   }
}
