# Autopsy
C++ training for students


# How to install Google Test

Download the sources or clone the repository from github: https://github.com/google/googletest

## Build the project
### Linux / MacOS

Run the following commands:

```
cd <WORKSPACE> # Where <WORKSPACE> is the directory containing your Autopsy repository
mkdir thirdParty
cd thirdParty
mkdir src
git clone https://github.com/google/googletest.git
mkdir lib
cd lib/
mkdir googletest
cd googletest/
```

You should have this file structure:
```
<WORKSPACE>/
    Autopsy/ <-- Your Autopsy repository clone
	thirdParty/
	    src/
		    googletest/
		lib/
		    googletest/ <-- Current directory
```

Then run:
```
cmake ../../src/googletest/googletest/
make
```

In MacOS, you may use clang instead of gcc. Then, replace the `cmake` command by:
```
cmake -DCMAKE_CXX_COMPILER="clang++" -DCMAKE_CXX_FLAGS="-std=c++11 -stdlib=libc++" ../../src/googletest/googletest/
```

### Windows:

Create the following file structure:
```
<WORKSPACE>/
    Autopsy/ <-- Your Autopsy repository clone
	thirdParty/
	    src/
		lib/
```

Where <WORKSPACE> is the absolute path to the work directory.

Clone googletest from https://github.com/google/googletest into <WORKSPACE>/thirdParty/src/

- Run Qt Creator
- In `File` menu, click on `Open File or Project` and select the file <WORKSPACE>/thirdParty/src/googletest/googletest/
- Select your kit (it should be the same for Autopsy project)
- Click on `Project` and check in `Active Project` if gtest is selected
- In `build directory`, enter <WORKSPACE>\thirdParty\lib\googletest
- Click on `Build Project` (check if the **gtest** project is selected before)
- Open Autopsy project
- Click on `Build Project` (check if the **Autopsy** project is selected before)
