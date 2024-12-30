Shamir's Secret Sharing Polynomial Solver

This project is a simplified implementation of Shamir's Secret Sharing algorithm in C++.

Features:
- Parses input from a JSON file
- Decodes values provided in different bases
- Calculates the constant term (c) of a polynomial using Lagrange interpolation


Requirements:
1. Visual Studio (with C++ workloads installed)
2. vcpkg package manager
3. JSONCPP library (installed via vcpkg)


Setup Instructions:

Step 1: Install Visual Studio
1. Download and install Visual Studio Community Edition from:
   https://visualstudio.microsoft.com/
2. During installation, ensure you select the following workloads:
   - Desktop Development with C++
   - Include MSVC C++ x64/x86 build tools.

Step 2: Clone vcpkg
1. Open a terminal and clone the vcpkg repository:
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
2. Run the bootstrap script to build vcpkg:
   .\bootstrap-vcpkg.bat
3. Integrate vcpkg with Visual Studio:
   .\vcpkg integrate install

Step 3: Install JSONCPP
1. Use vcpkg to install the JSONCPP library:
   .\vcpkg install jsoncpp:x64-windows
2. The library will be installed in:
   vcpkg/installed/x64-windows/

Step 4: Clone the Project
1. Clone this repository to your local machine:
   git clone <repository-url>
   cd <repository-name>

Step 5: Open the Project in Visual Studio
1. Launch Visual Studio.
2. Open the main.cpp file in the repository.
3. Configure the project to use vcpkg:
   vcpkg should automatically integrate with Visual Studio if you ran .\vcpkg integrate install.

Step 6: Build the Project
1. Place the testcase.json file in the same directory as the compiled .exe.
2. Click on Build > Build Solution in Visual Studio.
3. Once the build is successful, navigate to the output directory to find the executable.

Step 7: Run the Program
Run the executable from the terminal or the output directory. Example command:
   main.exe


Example JSON Input:
Save the following content as testcase.json:

{
    "keys": {
        "n": 4,
        "k": 3
    },
    "1": {
        "base": "10",
        "value": "4"
    },
    "2": {
        "base": "2",
        "value": "111"
    },
    "3": {
        "base": "10",
        "value": "12"
    },
    "6": {
        "base": "4",
        "value": "213"
    }
}


Output:
Example output for the above input:
Processing test case: testcase1
The constant term (c) for test case testcase1 is: 2.66667
