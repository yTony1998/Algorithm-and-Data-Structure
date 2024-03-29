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
mkdir -p build
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
---------------------
第一步，具体措施在使用cmake的时候，必须显示指明生成器，用```-G```切换生成器

```
mkdir -p build
cd build
cmake -G Ninja ..
```
第二步，构建项目:
```
cmake --build .
```
NOTE:
```build.ninja```和``` rules.ninja```: 包含Ninja的所有构建语句和构建规则。

``` cmkae --build .```将```ninja```命令封装在一个跨平台接口中

构建和链接静态库和动态库
---------------------------
Example

第一步，创建静态库
```
add_library(message
    STATIC
        Message.hpp
        Message.cpp
)
```
第二步，创建可执行文件
```
add_executable(hello-world hello-word.cpp)
```
第三步，将目标库连接到可执行目标
```
target_link_libraries(hello-world message)
```

Notes:
```add_library()```：将指定的源码编译到库中
```target_link_libraries()```：将库连接到可执行文件中

```add_library()```：参数
**STATIC**：创建静态库，编译文件的打包存档
**SHARED**：创建动态库，动态连接，在运行时加载的库
**OBJECT**：将```add_library()```中的源码编译到目标文件，没有库，一次性使用
 
 关于**OBJECT**有意思的用法
 ```
 add_library(message-objs
    OBJECT
        Message.hpp
        Message.cpp
    )

add_library(message-shared
    SHARED
        $<TARGET_OBECTS:message-objs>
    )

add_library(message-static
    STATIC
        $<TARGET_OBECTS:message-objs>
    )
 ```

