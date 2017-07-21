# -*- coding: utf-8 -*-
"""
Created on Fri Jul 21 15:04:54 2017

@author: zhang.zhi
"""


#!/usr/bin/env python
# -*- coding:utf-8 -*-
#导入random和string模块
import random, string, time
def GenPasswordStandard(length):
    #随机出数字的个数
    numOfNum = random.randint(1,length-1)
    numOfLetter = length - numOfNum
    #选中numOfNum个数字
    slcNum = [random.choice(string.digits) for i in range(numOfNum)]
    #选中numOfLetter个字母
    slcLetter = [random.choice(string.ascii_letters) for i in range(numOfLetter)]
    #slcLetter = [random.choice(string.printable) for i in range(numOfLetter)]
    #打乱这个组合    
    slcChar = slcNum + slcLetter
    random.shuffle(slcChar)
    #生成密码
    genPwd = ''.join([i for i in slcChar])
    return genPwd

def GenPasswordSimple(length):
    #随机出数字的个数
    slcNum = [random.choice(string.digits) for i in range(length)]
    #生成密码
    genPwd = ''.join([i for i in slcNum])
    return genPwd

def GenPasswordComplex(length):
    #随机出数字的个数
    slcPrint = [random.choice(string.printable) for i in range(length)]
    #生成密码
    genPwd = ''.join([i for i in slcPrint])
    return genPwd


if __name__ == '__main__':
    fp=open('pw.txt','a')
    Seed = time.time()
    print(Seed)
    fp.writelines('Seed '+str(Seed)+'\n')
    random.seed(Seed)
    #random.seed(1)
    fp.writelines(GenPasswordSimple(6)+'\n')
    fp.writelines(GenPasswordStandard(6)+'\n')
    fp.writelines(GenPasswordComplex(6)+'\n')
    fp.close