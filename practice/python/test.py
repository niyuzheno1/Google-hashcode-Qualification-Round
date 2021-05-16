import sys
import argparse
from shutil import copyfile
import os


def main():
    for x in (["a_example", "b_little_bit_of_everything", "c_many_ingredients", "d_many_pizzas", "e_many_teams"]):
        copyfile("./{}.in".format(x), "input.txt")
        os.system("python solB.py --file input.txt")    
        copyfile("output.txt","./{}.out".format(x))

def test():
    for x in (["a_example", "b_little_bit_of_everything", "c_many_ingredients", "d_many_pizzas", "e_many_teams"]):
        copyfile("./{}.in".format(x), "input.txt")
        copyfile("./{}.out".format(x), "output.txt")
        os.system("python judge.py")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    test()