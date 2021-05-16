import sys
import argparse
from shutil import copyfile
import os
from judge import judge_main

bestsofar = [21,5822900,5467966,5026255,4287386, 2703359]
                
def test():
    print("current max: {}".format(  sum(bestsofar)))
    total = 0
    t = 0
    cur = 0
    for x in (["a_example", "b_read_on", "c_incunabula", "d_tough_choices", "e_so_many_books", "f_libraries_of_the_world"]):
        copyfile("./{}.txt".format(x), "input.txt")
        copyfile("./{}.out".format(x), "output.txt")
        total = judge_main()
        if total > bestsofar[cur]:
            print(x + " is better")
        t += max(total, bestsofar[cur])
        cur = cur + 1
    print(t)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    test()