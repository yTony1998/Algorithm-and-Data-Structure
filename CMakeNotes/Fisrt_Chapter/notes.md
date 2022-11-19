单个源码文件编译成可执行文件
==============================
编写CMakeLists.txt
--------------------------
设置最低版本: ```cmake_minimum_reqiured(VERSION 3.5 FATAL_ERROR)```

申明项目名称: ```project(Name LANGUAGES CXX)```

指定一个生成目标: ```add_executable(exe_name src.cpp)```

将CMakeLists.txt和原文件放到同一个路径下

创建build目录并生成makefile文件
```
mkdir -p bui;d
cd build
cmake ..
```

代替上述代码块的命令
```
cmake -H. -Bbuild
```

NOTE:
CMake语言不区分大小写，但是参数区分大小写
采用源外构建的方式可以避免混合代码和项目的目录树

CMakefile: 包含临时文件的目录，CMake用于检测操作系统、编译器等。

cmake_install.make: 处理安装规则的CMake脚本，在本项目安装时使用。

CMakeCache.txt: CMake缓存。CMake重新运行时会使用。

切换生成器
=======================
