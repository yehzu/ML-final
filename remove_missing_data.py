import sys

if len(sys.argv) < 3:
	print "No enough arguments"
	print "Usage: python remove_missing_data.py input_data output_data"

i_file = open(sys.argv[1], 'r')
o_file = open(sys.argv[2], 'w')

fileInput = i_file.readline()
inputLine = fileInput.split()

line = 0;

while len(inputLine) > 0: 
	miss = False
	for i in range(1, len(inputLine)):
		if inputLine[i] == '?':
			miss = True
			break
	if not miss:
		o_file.write(fileInput)
		line = line + 1

	fileInput = i_file.readline()
	inputLine = fileInput.split()

print "There are {0} data".format(line)
