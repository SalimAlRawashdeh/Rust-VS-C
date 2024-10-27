import random;
import string;
import argparse
import subprocess

parser = argparse.ArgumentParser()
parser.add_argument("valueINT", help="Please give the value needed", type=int)
args = parser.parse_args()
x = args.valueINT

file_path_rust = "RustCode.rs"
file_path_C = "CCode.c"

random_integers = [random.randint(0, 100000) for _ in range(x)]

string_list = [str(i) for i in random_integers]

# Write integers into a file
with open("integers.txt", "w") as file:
    file.write("\n".join(string_list))

parser2 = argparse.ArgumentParser()
parser2.add_argument("valueSTR", help="Please give the value needed", type=int)
args2 = parser2.parse_args()
x = args2.valueSTR

# Generate random strings
def generateStrings(minLength, maxLength):
    length = random.randint(minLength, maxLength)
    return ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(length))

min_length = 7
max_length = 20

random_strings = [generateStrings(min_length, max_length) for _ in range(x)]

# Write integers into a file
with open("strings.txt", "w") as file:
    file.write("\n".join(random_strings))

subprocess.run(["gcc", file_path_C, "-O", "-o", "output"], check=True)
subprocess.run(["./output"])

subprocess.run(["rustc", file_path_rust, "-O"], check=True)
subprocess.run(["./" + file_path_rust[:-3]])



