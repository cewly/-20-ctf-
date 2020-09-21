dec = input("请输入待转换的十进制数:")   
dec = int(dec)      #输入的内容默认被视作字符串，需更改为整数
pvs = []            #定义空列表，方便后续使用
while dec!=0:       
    pv = dec%2      #取模运算
    if pv==1:
        pvs.append('1')    #添加1到空列表的末尾
        dec=dec-1
        dec=dec/2
    else:
        pvs.append('0')
        dec=dec/2
pvs.reverse()   #倒置空列表的所有内容
bin="".join(pvs)  #“缝合”所有内容，便于后续整体输出
print(bin)   
