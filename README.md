# Low Latency Workshop

This is the code we are going to use during the Low Latency C++ Workshop.

Please, make sure you are able to compile and run the code.

# Requirements

* CMake
* C++-14 capable compiler (gcc 5+, VisualStudio 2017+)

# Linux Build
```
$ git clone --recursive https://github.com/maciekgajewski/LowLatencyWorkshop.git
$ mkdir LowLatencyWorkshop-build
$ cd LowLatencyWorkshop-build
$ cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ../LowLatencyWorkshop
$ make
```

# Windows build instructions
Using VS2017 Native Tools Command Prompt

```
$ git clone --recursive https://github.com/maciekgajewski/LowLatencyWorkshop.git
$ mkdir LowLatencyWorkshop-build
$ cd LowLatencyWorkshop-build
$ cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -G "NMake Makefiles" ../LowLatencyWorkshop
$ nmake
```
