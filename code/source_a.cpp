
//サンプルコード
//ABC093-A

in(kstr s)
kluster<char> klst <<
for(i in s) push(klst, s[i])
sort(klst)
if(klst[1]=='a'&&klst[2]=='b'&&klst[3]=='c') yes()
else no()
