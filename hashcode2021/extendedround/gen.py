import sys
import argparse
from shutil import copyfile
import os


def main():
    f = open("filelist.txt","r")
    flist = f.readline()
    for x in (flist.split()):
        copyfile("./{}.in".format(x), "input.txt")
        os.system("python solB.py --file input.txt")    
        copyfile("output.txt","./{}.out".format(x))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()