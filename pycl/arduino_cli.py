#arduino-cli core install arduino-avr




def subprocess_run_and_print(argvec):
	from subprocess import Popen, PIPE
	print("○ Executing: ", argvec)
	process = Popen(argvec, stdout=PIPE, stderr=PIPE, shell=True, universal_newlines=True)
	stdout, stderr = process.communicate()

	print("Output: ", stdout.encode().decode('unicode-escape'))
	print("Errors: ", stderr.encode().decode('unicode-escape'))

	return process.returncode


def compile(board, sketch_folder, verbose=False):
	cmd = f"arduino-cli compile -b {board} {sketch_folder}"

	if verbose:
		cmd += f" -v"

	return subprocess_run_and_print(cmd)

def compile(port, board, sketch_folder, verbose=False):
	attach_cmd = f"arduino-cli board attach -p {port} -b {board} {sketch_folder}"

	#cmd = f"cd {sketch_folder}; arduino-cli compile"
	cmd = f"arduino-cli compile {sketch_folder}"

	if verbose:
		attach_cmd += f" -v"
		cmd += f" -v"

	subprocess_run_and_print(attach_cmd)
	return subprocess_run_and_print(cmd)


def upload(port, sketch_folder, verbose=False):
	# Read current folder name - pure

	cmd = f"arduino-cli upload -p {port} {sketch_folder}"

	if verbose:
		cmd += f" -v"

	return subprocess_run_and_print(cmd)

def compile_upload(sketch_folder, verbose=False):
	
	cmd = f"cd {sketch_folder} arduino-cli compile --upload"
	
	if verbose:
		cmd += f" -v"

	return subprocess_run_and_print(cmd)

