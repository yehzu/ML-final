import sys

print 'Input: {0}\nOutput: {1}'.format(sys.argv[1], sys.argv[2])


ifile = open(sys.argv[1], 'r')
ofile = open(sys.argv[2], 'w')

inputLine = ifile.readline().split()

while len(inputLine) > 0: 
	# write prediction (y)
	ofile.write(inputLine[0])
	for i in range(1, len(inputLine)):
		ofile.write(' {0}:{1}'.format(i, inputLine[i]))		
	
	ofile.write('\n')
	
	inputLine = ifile.readline().split()
