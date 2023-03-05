# CSE 8086 C-Compiler
This compiler is a culmination of the four assignments of the [CSE310 Compiler Sessional](/..) course, each of which incrementally cover the four steps of compilation. The compiler compiles a subset of the C language with a [simplified grammar](../F3/grammar.txt) to assembly code for the [EMU8086](./emu8086-setup.exe), an emulator of the ancient [Intel 8086](https://en.wikipedia.org/wiki/Intel_8086) CPU. 

## Usage

The compiler was built on a [Debian GNU/Linux](https://www.debian.org/download) platform, as recommended for running [flex](https://github.com/westes/flex) and [Bison](https://github.com/akimd/bison). [Wine](https://wiki.winehq.org/Download) was needed to run EMU8086 which is distributed for Windows platforms only.

It is most common for students taking this course to be running flex and Bison on a Debian or Ubuntu-based Linux platform. In case you don't have these tools installed, run 
```
sudo apt update
sudo apt install flex
sudp apt install bison
```
Then in the directory of the compiler, place a [sample](../F4/inputs/) or custom `.c` file  (`<source_file>`)  and run 
```
sudo chmod +x 1905084.sh 
```
(This grants permission to the shell script to be run as an execultable.)
```
./1905084.sh <source_file>
```
The compiler will produce a file called `optimised_code.asm` which can be run on EMU8086.