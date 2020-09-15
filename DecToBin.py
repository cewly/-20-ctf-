dec = input("请输入待转换的十进制数:")
dec = int(dec)
pvs = []
while dec!=0:
    pv = dec%2

    if pv==1:
        pvs.append('1')
        dec=dec-1
        dec=dec/2
    else:
        pvs.append('0')
        dec=dec/2
pvs.reverse()
bin="".join(pvs)
print(bin)



