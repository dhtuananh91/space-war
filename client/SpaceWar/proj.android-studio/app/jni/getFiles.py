import os,sys
current_path = sys.argv[1]
skip_folders = ['BoostAsio','OpenSSL','ZLib']

def isNotInExclude(folder):
	for dir in skip_folders:
		if dir == folder:
			return 1
	return 0
	

def travel_folder(folder):
	dirs = os.listdir(folder)
	for file in dirs:
		if os.path.isfile(folder + file):
			if os.path.splitext(file)[1] == '.cpp':
				print folder + file + ' \\'
		elif isNotInExclude(file) == 0:
			travel_folder(folder + file + '/')


travel_folder(current_path)