
import os
import sys
sys.path.append(os.path.join(".", "pycl")) #Add pycl directory to the interpreter path

import arduino_cli as arduino
import syringe


# Configuration

port = "COM11"
board = "arduino:avr:uno"
# board name needs to be a "Fully Qualified Board Name (FQBN)". Run "arduino-cli board list" to find the FQBN. 


# 0. Check for sequence file
if len(sys.argv) > 1:
	
	seq_path = os.path.abspath(sys.argv[1])
	print(f"Sequence file passed: {seq_path}")
else:
	print("No sequence file provided. Program will terminate!")
	sys.exit(1)

#1. Fix filename and convert to dict
sketch_folder = os.path.abspath("SyringeStage")

seq_cpp_path = os.path.join(sketch_folder, "sequence_file.hpp")
print("Sequence file will be generated at: ", seq_cpp_path)


# Convert to dict based on filepaths
if seq_path.endswith(".csv"):
	# Generate CPP file from CSV
	config = syringe.csv_to_dict(seq_path, syringe_dia_mL=20)

elif any(seq_path.endswith(ext) for ext in [".json", ".yml", ".yaml"]):
	from configr.configr import Configr
	config_loader = Configr()
	config = config_loader.load(seq_path)
else:
	raise Exception(f"Unsupported file type: {seq_path}")

 

# Generate CPP resources
syringe.create_cpp_resources(config, seq_cpp_path, specifiers="const")

#sys.exit(0)
# Compile and upload
print(f"Sketch folder is set to: {sketch_folder}")
arduino.compile(port, board, sketch_folder, verbose=False)
arduino.upload(port, sketch_folder, verbose=False)


# exit or launch other utility

