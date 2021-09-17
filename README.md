# computecpp-cmake-template
A template ComputeCpp/SYCL project using the CMake build automation system.

# Usage
Run the following commands with terminal opened in this repository's directory

1. ```mkdir build```

2. ```cd build```

3. ```cmake .. -DComputeCpp_DIR="<path/to/computecpp/root/dir>"```

If using NVIDIA GPU, add the ```-DCOMPUTECPP_BITCODE=ptx64``` flag to the last command.
