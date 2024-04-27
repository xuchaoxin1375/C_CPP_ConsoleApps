{
	"type" : "cppbuild",
	"label" : "task1",
	"command" : "${env:USERNAME}/g++.exe",
	"args" : [
		"-fdiagnostics-color=always",
		"-g",
		"*.cpp",
		"-o",
		"${fileDirname}\\All.exe"
	],
	"options" : {
		"cwd" : "${fileDirname}"
	},
	"problemMatcher" : ["$gcc"],

	"detail" : "build  C++ language files(*.cpp) in the ${fileDirname} directory (not c files) "
},