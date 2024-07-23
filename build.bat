@echo off 
set Debug=0
chcp 65001
echo Building...(X64)
echo 准备编译...(X64)
timeout /t 10
echo [%time%]:启动编译流程 > build.log
del ..\build\PandaRunTimeLibrary /Q /S
echo [%time%]:删除老文件 >> build.log
xcopy ".\*.*" "..\build\PandaRunTimeLibrary" /E /I /Y
echo [%time%]:复制完整代码 >> build.log
echo [%time%]:开始编译 >> build.log
del ..\build\PandaRunTimeLibrary\build.log 
del ..\build\PandaRunTimeLibrary\build.bat 
del /q ..\build\PandaRunTimeLibrary\lib
echo 删除编译日志
gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\Pprint.c -o ..\build\PandaRunTimeLibrary\lib\Pprint.so
echo [%time%]:编译Pprint完成 >> build.log
gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\PString.c -o ..\build\PandaRunTimeLibrary\lib\PString.so
echo [%time%]:编译PString完成 >> build.log
gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\PFile.c -o ..\build\PandaRunTimeLibrary\lib\PFile.so
echo [%time%]:编译PFile完成 >> build.log
gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\PDataTypeConversion.c ..\build\PandaRunTimeLibrary\lib\PString.so -o ..\build\PandaRunTimeLibrary\lib\PDataTypeConversion.so
echo [%time%]:编译PDataTypeConversion完成 >> build.log
if %Debug% == 1 (gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\PDebug.c ..\build\PandaRunTimeLibrary\lib\PString.so ..\build\PandaRunTimeLibrary\lib\PFile.so -D__Panda_Debug__ -o ..\build\PandaRunTimeLibrary\lib\PDebug.so) else (gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\PDebug.c ..\build\PandaRunTimeLibrary\lib\PString.so ..\build\PandaRunTimeLibrary\lib\PFile.so -o ..\build\PandaRunTimeLibrary\lib\PDebug.so)
echo [%time%]:编译PDebug完成 >> build.log
:: Windows
gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\PWindows.c ..\build\PandaRunTimeLibrary\lib\PString.so -o ..\build\PandaRunTimeLibrary\lib\PWindows.so
echo [%time%]:编译PWindows完成 >> build.log
:: Linux
:: 由于这个bat文件是针对Windows的,所以不用编译Linux的so库
gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\PSystem.c -DWin_NT ..\build\PandaRunTimeLibrary\lib\PWindows.so -o ..\build\PandaRunTimeLibrary\lib\PSystem.so ..\build\PandaRunTimeLibrary\lib\PString.so ..\build\PandaRunTimeLibrary\lib\PFile.so
gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\PDataStructure.c ..\build\PandaRunTimeLibrary\lib\PDataTypeConversion.so ..\build\PandaRunTimeLibrary\lib\PFile.so ..\build\PandaRunTimeLibrary\lib\PDebug.so ..\build\PandaRunTimeLibrary\lib\PString.so ..\build\PandaRunTimeLibrary\lib\Pprint.so ..\build\PandaRunTimeLibrary\lib\PSystem.so -o ..\build\PandaRunTimeLibrary\lib\PDataStructure.so
gcc -shared -fpic ..\build\PandaRunTimeLibrary\src\Pprint.c ..\build\PandaRunTimeLibrary\src\PString.c ..\build\PandaRunTimeLibrary\src\PFile.c ..\build\PandaRunTimeLibrary\src\PDataTypeConversion.c ..\build\PandaRunTimeLibrary\src\PDebug.c ..\build\PandaRunTimeLibrary\src\PDataStructure.c ..\build\PandaRunTimeLibrary\src\PSystem.c -DWin_NT -D__Panda_Debug__ ..\build\PandaRunTimeLibrary\lib\PWindows.so -o ..\build\PandaRunTimeLibrary\lib\PandaRunTimeLibrary.so 
echo [%time%]:编译PDataStructure完成 >> build.log
echo [%time%]:编译PSystem完成 >> build.log
echo [%time%]:so库编译完成 >> build.log
xcopy "..\build\PandaRunTimeLibrary\lib" ".\lib" /E /I /Y