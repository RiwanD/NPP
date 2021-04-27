# Readme
## Project
This project get the video stream of a camera and detect shapes of objects.  
For application is developped with **C++** language and with the **OpenCV** libraries to capture and work on the video stream.

There is three repertories in this project:
- **src** who contains all cpp source files of the project.
- **include** with the headers.
- **build** wich is created by *cmake* during the compilation. It contains all file needed for the construction of binary.

In addition, the `CMakeLists.txt` allows *cmake* to build correctly the project. After compilation, the binary file is created in the project root repertory.


## Compilation instructions
In order to build and compile the project, run these steps:
1. In the project root repertory, launch `cmake -Bbuild -DCMAKE_BUILD_TYPE=Release`. This will build the project by generated all the necessary files.
2. Then, launch `cmake --build build` to compile. Normally, you will obtain a binary file named **ShapeDetection**.
3. To start the program independantly of *ROS*, you juste have to launch `./ShapeDetection` in your terminal.

In addition, it is necessary to have OpenCV installed (release **4.5.2**) and cmake in the **3.20** version to ensure a good compilation.
