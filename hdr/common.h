#ifndef _INC_COMMON_
#define _INC_COMMON_

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define P pair<string, string>
#define INF 1e9
extern string tab;
extern string pre;
extern int num;  //K++が生成する変数の通し番号
extern map<string, string> dict;  //typeとnameを管理

int find(string src, string s);
void WaitTime(int msec);

#endif
