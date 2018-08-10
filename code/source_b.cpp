
//サンプルコード
//ABC093-A

in(a, b, k)
kluster<int> klst <<
for(i in (0~k-1)){
    flg << true
    if(a+i<=b){
        for(j, size(klst)) if(klst[j]==a+i) flg = false; break
        if(flg) out(a+i); push(klst, a+i)
    }
}
for(i in (k-1~0)){
    flg << true
    if(b-i>=a){
        for(j, size(klst)) if(klst[j]==b-i) flg = false; break
        if(flg) out(b-i); push(klst, b-i)
    }
}
