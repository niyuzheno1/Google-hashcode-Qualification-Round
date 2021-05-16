import sys
import argparse
from shutil import copyfile
import os

#"a_example", "b_read_on", "c_incunabula", "d_tough_choices", "e_so_many_books",
def main():
    for x in ([ "f_libraries_of_the_world"]):
        copyfile("./{}.txt".format(x), "input.txt")
        os.system(".\solC.exe < input.txt > output.txt")    
        copyfile("output.txt","./{}.out".format(x))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()