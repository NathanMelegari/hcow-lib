# Hcow v0.0.1

An open-source C library for shell automation.

Hcow allows you to execute shell commands, manage processes, and automate system tasks directly in C code — combining low-level control with shell-like simplicit.

## Build

### Requirements

- GCC or Clang
- CMake

### Generate static library

```bash
mkdir build
cd build
cmake ..
make
```

## Example


### 1.Creating a directory and insert file:

Create a file named: first_hcow.c

And insert into:
```bash
#include <hcow/hcow.h>

int main()
{
    char *directory[] = {"mkdir", "hcow", NULL};
    hcow_run(directory);

    if (hcow_exists(directory[1])) {

        hcow_cd(directory[1]);

        char *file[] = {"touch", "my_first_file.txt", NULL};
        hcow_run(file);

        hcow_log(HCOW_INFO, "directory '%s' and the file '%s' have been created!", directory[1], file[1]);
    }

    return 0;
}
```
Compiling with:
```bash
gcc first_hcow.c -I../lib -L. -lhcow -o first_hcow
```

## Functions

- hcow_run(): Execute shell commands
- hcow_exists(): Check if a file/directory exists
- hcow_cd(): Change diretory
- hcow_log(); Log messages with level (INFO, WARNING, ERROR)
- hcow_async(): Execute shell commands asynchronously
- hcow_capture(): Take the STDOUT from the command line

## Roadmap

- Add new functions (like a pipe process)
- Desenvolve a CLI tool focused in automation

## Contributing

Access [CONTRIBUTING](https://github.com/NathanMelegari/hcow-lib/CONTRIBUTING.md) for know how contribuing with the project, and help Hcow grow up.

## Purpose

Hcow is designed for developers who want:

- Shell automation inside C
- More control than Bash scripts
- Process level and system level interaction

## Why Hcow?

- Replace Bash scripts with compiled C programs
- Better performance and control
- Easier integration with system-level code
