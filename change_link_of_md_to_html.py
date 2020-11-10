import re
import os
import sys

def readAndChangeLines(input, output):
    for line in input.readlines():
        arr = re.findall(reg, line)
        if len(arr) > 0:
            for s in arr:
                line = line.replace(s, re.sub('\.md\)$', '.html)', s))
                line = re.sub('\(readme\.html\)$', '(index.html)', line)

        output.write(line)

reg = "\[[^][)(]+?\]\(.*?\.md\)"

PATH = sys.argv[1]
input_path = PATH + "/" + sys.argv[2] + "/"
output_path = PATH + "/temp/"

for name in os.listdir(input_path):
    if os.path.splitext(name)[-1].lower() != ".md":
        continue
    name = re.sub(".md$", "", name)

    input = open(input_path + name + '.md', 'r')
    if "readme" == name.lower():
        name = "index"
    output = open(output_path + name + '.temp', 'w+')

    readAndChangeLines(input, output)
    print(f"{name}.html created...")
    input.close()
    output.close()

# os.system('cmd /c "for /F usebackq %G IN (`dir /a-d /b .\md`) DO (pandoc .\md\%G -f markdown -t html -s -o
# .\html\%~nG.html --quiet)"')
