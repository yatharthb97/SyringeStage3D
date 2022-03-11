

# Syringe Stage



This repository uses `submodules`, to clone the submodules too use: `git clone <repo_url> --recursive`.



## Installation:

1. If `arduino-cli` is installed, run: `arduino-cli core install arduino:avr`.



## Dependencies:

* `arduino-cli` : Used to compile and upload the code. Installation guide: https://arduino.github.io/arduino-cli/0.21/installation/ . (Not included in the repo)
* `configr.py` : Utility used to process `json` and `yaml` files. Source: https://gist.github.com/yatharthb97/086f24c9a01bb5a508821fae80e190c9



## List of modules:

* `pycl` : Python  based Control Layer which is used to insert the sequence of operations into the sketch folder, compile, and upload the code using `arduino-cli`.

* `SyringeStage`: Arduino side code written in C++. And the default `sketch_folder`.

  



## Load through `.csv` file (Excel file)


Execution:
```bash
$ > python ./run.py sequence_file.csv
```



### General format of CSV files:

1. Run a single sequence. The keyword **"sequence"** is used to identify the specific mode of working and must be used exactly without any spaces.

   | sample | sequence |      |
   | ------ | -------- | ---- |
   | 1      | 1.1      |      |
   | 2      | 1.2      |      |
   | 3      | 1.3      |      |
   | 4      | 1.4      |      |



2. Run a single sequence on repeat. The keyword **"repeat"** is used to identify the specific mode of working and must be used exactly without any spaces.

   | sample | repeat |      |
   | ------ | ------ | ---- |
   | 1      | 1.1    |      |
   | 2      | 1.2    |      |
   | 3      | 1.3    |      |
   | 4      | 1.4    |      |

   This will keep on repeating the sequence until the device is stopped.

   

3. Perform multiple sequences one after the other. Each sequence column must contain the word **"sequence"**.

   | sample | sequence1 | sequence2 | sequence3 |
   | ------ | --------- | --------- | --------- |
   | 1      | 1.1       | 2.1       | 3.1       |
   | 2      | 1.2       | 2.2       | 3.2       |
   | 3      | 1.3       | 2.3       | 3.3       |
   | 4      | 1.4       | 2.4       | 3.4       |

​	The program will perform the sequences one after the other and then stop.



## Load through `.json` or `.yaml`files

Execution:

```bash
$ > python ./run.py sequence_file.json
```

Check the entity `default_seq_file` in `./pycl/syrenge.py` file to know the format for the `json` and `yaml` files.
