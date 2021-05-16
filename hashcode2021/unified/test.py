import sys
import argparse
from shutil import copyfile
import os
from judge import judge_main


def test():
    f = open("filelist.txt","r")
    flist = f.readline()
    for x in (flist.split()):
        copyfile("./{}.in".format(x), "input.txt")
        copyfile("./{}.out".format(x), "output.txt")
        judge_main()

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    test()