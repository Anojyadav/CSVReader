
# Configuration Loader

This project demonstrates how to load and parse a configuration file (`config.csv`) into a C++ program using standard libraries. The configuration file contains a set of parameters that are read and stored in a custom data structure for later use.

## Project Structure

- `config.csv`: The configuration file that contains the parameters to be loaded by the program.
- `main.cpp`: The main C++ source file that reads the configuration file and parses it into a vector of `TestConfigurationParameter` structures.
- `README.md`: This file, providing an overview of the project and instructions on how to run it.

## Configuration File Structure

The `config.csv` file contains the following columns:

- `seq`: Sequence number (not used in the program).
- `is_set_x`: Boolean flag indicating if `x` is set.
- `is_set_y`: Boolean flag indicating if `y` is set.
- `x`: An integer value.
- `y`: A floating-point value.

Example content of `config.csv`:

```csv
seq,is_set_x,is_set_y,x,y
1,True,False,0,0.75
2,True,False,1,10.75
3,True,False,0,-12.75
```

## Code Overview

### Struct

```cpp
struct TestConfigurationParameter
{
    bool is_set_x;
    bool is_set_y;
    int x;
    float y;
};
```

This structure holds the parameters read from each row of the CSV file.

### Functions

- `extractArgument`: Extracts the value of a command-line argument.
- `loadParams`: Reads and parses the configuration file, storing the data in a vector of `TestConfigurationParameter`.

### Main Function

The main function does the following:

1. Parses command-line arguments to get the configuration file path.
2. Loads the parameters from the specified file using `loadParams`.
3. Outputs some of the loaded values to demonstrate successful loading.

## How to Compile and Run

### Prerequisites

- A C++ compiler (e.g., g++) should be installed on your system.

### Compilation

Compile the `main.cpp` file using g++:

```bash
g++ main.cpp -o exe
```

### Execution

Run the compiled executable with the `--configFile` argument pointing to your `config.csv` file:

```bash
./exe --configFile config.csv
```

### Expected Output

Based on the provided `config.csv` file, the program will print:

```
Configuration file provided! config.csv will be used for initialization.
print from 0 0
print from 1 10.75
```

## Customization

You can modify the `config.csv` file or the `main.cpp` code to suit your specific needs. The code is structured to easily allow for additional parameters or different file formats.

## License

This project is open-source and available under the MIT License.
