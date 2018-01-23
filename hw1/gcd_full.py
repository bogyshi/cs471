#! /usr/bin/env python
import sys

def gcdI(i, j):
    while (i!= j):
        if (i > j):
            i = i - j
        else:
            j = j - i;
    return i;


def gcdF(i, j):
    while (i!= j):
        if (i > j):
            if(i%j==0):
                return j
            else:
                return gcdF(i % j,j)
        else:
            if(j%i==0):
                return i
            else:
                return gcdF(i,j%i)
    return i;

if len(sys.argv) != 3:
  print("%s usage: [NUMBER]" % sys.argv[0])
  exit()

print(gcdI(int(sys.argv[1]),int(sys.argv[2])))
print(gcdF(int(sys.argv[1]),int(sys.argv[2])))
