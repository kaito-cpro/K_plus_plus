
//;様々な機能

//;色々対応可能;
in(n, m, arr[n], string str, double d[n][m])

//;型は省略可能な場合がある;
ans <<; count << 0; f << false

//;forは{}がないとき、その行全体をスコープとする;
for(i in str) out(str[i]); ++count

//;forは色々対応可能;
for(i in (10~3), (1~size(arr))) out(i)

a << 2; b << 3; c << 4

//;不等号を２つ一気に使える;
if(a <= b <= c) f = true

//;maxは引数は何個でもOK;
max1 << max(a, b, c)

//;maxは配列にも対応;
max2 << max(arr)

//;outも色々対応可能;
out("hoge ", count, " ", str, -endl)


kluster<int, string, int> klst <<

t << 0

for(i, min(size(arr), size(str))){

    //;klstへpush;
    push(klst, (t, str, arr[i]))

    ++t

}

//;指定した要素でsort可能;
sort(klst, 0)

//;klusterオブジェクトへのアクセス;
out(klst[0][2])

//;substrを使いやすく改良;
string u << sub(str, 3~6)

//;競プロ用の関数も定義;
yes()

out("END OF INTRODUCTION")
