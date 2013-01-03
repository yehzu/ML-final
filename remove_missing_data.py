import sys

if len(sys.argv) < 4:
	print "No enough arguments"
	print "Usage:>>python remove_missing_data.py input_data output_data fill_value"

i_file = open(sys.argv[1], 'r')
o_file = open(sys.argv[2], 'w')

fileInput = i_file.readline()
inputLine = fileInput.split()


while len(inputLine) > 0: 
	for i in range(1, len(inputLine)):
		if inputLine[i] == '?':
			inputLine[i] = sys.argv[3]
	
	for item in inputLine:
		o_file.write('{0} '.format(item))
	o_file.write('\n')
	fileInput = i_file.readline()
	inputLine = fileInput.split()

print "Finish!"
