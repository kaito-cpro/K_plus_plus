
/+サンプルコード+/
/+ABC093-B+/

in(a, b, c)
sum << a + b + c
ans << 0
while(1){
    if(sum%3==0&&sum/3>=max(a, b, c)) out(ans); return 0
    sum += 2; ++ans
}
