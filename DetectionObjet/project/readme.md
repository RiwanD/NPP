# Readme
This file explain the essentials of the ShapeDetection project. Here you'll find the architecture of the project and the instructions to compile it.

ShapeDetection has the objective of indicates the objects into the environment to the Niryo. To make that possible, the software capture the video stream of a camera and determine the shape of each objects frame by frame.

## Project
The application is developped for **Linux** with **C++** language and with the **OpenCV 4.5.2** libraries to capture and work on the video stream.
In addition, **cmake 3.20** is in charge of the compilation.

There is three repertories in this project:
- **src** who contains all cpp source files of the project.
- **include** for the headers.
- **build** wich is created by *cmake* during the compilation. It contains all file needed for the construction of the binary file.

In the root directory of the project, you'll find the `CMakeLists.txt` file who contains the instructions for *cmake*. In addition, the binary is placed here after the compilation.


## Compilation instructions
In order to build and compile the project, run these steps:
1. In the project root repertory, launch `cmake -Bbuild -DCMAKE_BUILD_TYPE=Release`. This will build the project by generated all the necessary files.
2. Then, launch `cmake --build build` to compile. Normally, you will obtain a binary file named **ShapeDetection**.
3. To start the, you juste have to launch `./ShapeDetection` in your terminal.

To ensure a perfect compatibility, make sure to use the version **4.5.2** of OpenCV and **3.20** of cmake.
