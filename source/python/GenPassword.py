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
    numOfNum = random.randint(1,length-2)
    numOfUpLetter = random.randint(1,length - numOfNum - 1)
    numOfLowLetter = length - numOfNum - numOfUpLetter
    #选中numOfNum个数字
    slcNum = [random.choice(string.digits) for i in range(numOfNum)]
    slcUpLetter = [random.choice(string.ascii_uppercase) for i in range(numOfUpLetter)]
    slcLowLetter = [random.choice(string.ascii_lowercase) for i in range(numOfLowLetter)]
    #选中numOfLetter个字母
    #打乱这个组合    
    slcChar = slcNum + slcUpLetter + slcLowLetter
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
    numOfNum = random.randint(1,length-3)
    numOfUpLetter = random.randint(1,length - numOfNum - 2)
    numOfLowLetter = random.randint(1,length - numOfNum - numOfUpLetter- 1)
    numOfSymbol = length - numOfNum - numOfUpLetter - numOfLowLetter 
    #选中numOfNum个数字
    slcNum = [random.choice(string.digits) for i in range(numOfNum)]
    #选中numOfLetter个字母
    slcUpLetter = [random.choice(string.ascii_uppercase) for i in range(numOfUpLetter)]
    slcLowLetter = [random.choice(string.ascii_lowercase) for i in range(numOfLowLetter)]
    slcSymbol = [random.choice(string.punctuation) for i in range(numOfSymbol)]
    #slcLetter = [random.choice(string.printable) for i in range(numOfLetter)]
    #打乱这个组合    
    #随机出数字的个数
    slcChar = slcNum + slcUpLetter + slcLowLetter + slcSymbol
    random.shuffle(slcChar)
    #生成密码
    genPwd = ''.join([i for i in slcChar])
    return genPwd


if __name__ == '__main__':
    fp=open('pw.txt','a')
    Seed = time.time()
    print(Seed)
    fp.writelines('Seed '+str(Seed)+'\n')
    random.seed(Seed)
    #random.seed(1)
    fp.writelines(GenPasswordSimple(8)+'\n')
    fp.writelines(GenPasswordStandard(8)+'\n')
    fp.writelines(GenPasswordComplex(8)+'\n')
    fp.close
