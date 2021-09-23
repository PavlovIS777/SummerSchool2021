# -*- coding: utf-8 -*-
"""
Created on Tue Sep 21 16:15:49 2021

@author: Vanushka Ogli Pushka
"""

def isSign(line):
    if (line[-1] != '\n'):
        return True
    else:
        return False

def lineParser(file):
    parsedFile = []
    for line in file:
        temp = ' '.join(line.split())
        if(isSign(temp)):
            temp = temp.replace(' '+temp[-1],temp[-1])
        while(temp.find('\r') > -1):
            temp = temp.replace('\r', '')
        temp = temp + '\n'
        parsedFile.append(temp)  
    return parsedFile

with open("inRus.txt", 'r+', encoding='utf-8') as f:
    file = f.readlines()
    fileOutput = lineParser(file)
    with open("oneginRus.bin", "wb+") as outp:
        for line in fileOutput:
            line = line.encode()
            outp.write(line)

