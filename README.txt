Version control insctruction:
	
- You can check out the Subversion repository at this link : https://projet-lif15.googlecode.com/svn/trunk/

Compilation instructions :

- Download CMAKE

* If you want to use QtCreator :
	- Download QtCreator
	- Open CMakeLists.txt whith QtCreator
	- Choose a compilator in the supported compilator list

* If you want to use Code::Block project :
	- Download Code::Block
	* On Linux:
		- Open a terminal and write: cmake -G "CodeBlocks - Unix Makefiles"
	* On Windows
		- Open a terminal and write: cmake -G "CodeBlocks - NMake Makefiles" to Microsoft Compilator with NMake
		or Open a terminal and write: cmake -G "CodeBlocks - MinGw Makefiles" to use gcc with MinGw
	- A <project_name>.cbp file was created. You can now open it with Code::Block

* If you want to use different project for other IDE such as Eclipse or Visual Studio, please check CMake documentation.

Credits:
	Project developers : Rachid Delory, Guillaume Collombet