#include "./include/PWindows.h"

char *PipeName = "\\\\.\\pipe\\PandaRun_Deng_test" ;

int main(){
    HANDLE hPipe = connectNamePipe(PipeName);
	printf("%ld", hPipe) ;
    if(hPipe == INVALID_HANDLE_VALUE) 
        printf("connectNamePipe error\n");
    readNamePipe(hPipe, 1024) ;
}
// // #include <windows.h>
// // #include <iostream>

// // int pipeClient() {
// // 	HANDLE hPipe;
// // 	/* 
// // 	* Windows系统下，管道名称命名规范：
// // 	*	\\.\pipe\pipename
// // 	*	其中'\\.\pipe\'是固定的前缀，表示这是一个命名管道
// // 	*/
// // 	LPCWSTR pipeName = L"\\\\.\\pipe\\MyPipe";
// // 	BOOL success;
// // 	char buffer[1024];
// // 	DWORD bytesWritten;
// // 	DWORD bytesRead;

// // 	// 尝试连接到命名管道
// // 	hPipe = CreateFile(
// // 		"\\\\.\\pipe\\MyPipe",              // 管道名称
// // 		GENERIC_READ | GENERIC_WRITE, // 读写访问
// // 		0,                     // 不共享
// // 		NULL,                  // 默认安全属性
// // 		OPEN_EXISTING,         // 打开现有的管道
// // 		0,                     // 默认属性
// // 		NULL                   // 不使用模板文件
// // 	);

// // 	if (hPipe == INVALID_HANDLE_VALUE) {
// // 		std::cerr << "Failed to connect to the pipe." << std::endl;
// // 		return 1;
// // 	}

// // 	std::cout << "Connected to the pipe." << std::endl;

// // 	// 向服务端发送消息
// // 	const char* message = "Hello, server!";
// // 	success = WriteFile(
// // 		hPipe,                 // 管道句柄
// // 		message,               // 发送的数据
// // 		(DWORD)strlen(message), // 数据大小
// // 		&bytesWritten,         // 写入的字节数
// // 		NULL                   // 不重叠
// // 	);

// // 	if (!success) {
// // 		std::cerr << "Failed to send data." << std::endl;
// // 		CloseHandle(hPipe);
// // 		return 1;
// // 	}

// // 	std::cout << "Message sent to server, waiting for response..." << std::endl;

// // 	// 从服务端读取响应
// // 	success = ReadFile(
// // 		hPipe,                 // 管道句柄
// // 		buffer,                // 接收缓冲区
// // 		sizeof(buffer),        // 缓冲区大小
// // 		&bytesRead,            // 读取的字节数
// // 		NULL                   // 不重叠
// // 	);

// // 	if (!success || bytesRead == 0) {
// // 		if (GetLastError() == ERROR_BROKEN_PIPE) {
// // 			std::cerr << "Server has disconnected." << std::endl;
// // 		}
// // 		else {
// // 			std::cerr << "Read failed." << std::endl;
// // 		}
// // 		CloseHandle(hPipe);
// // 		return 1;
// // 	}

// // 	buffer[bytesRead] = '\0'; // 确保字符串结束符
// // 	std::cout << "Received: " << buffer << std::endl;

// // 	// 关闭句柄
// // 	CloseHandle(hPipe);
// // 	return 0;
// // }

// // int main()
// // {
// // 	pipeClient();
// // 	std::cin.get();
// // }


// #include <Windows.h>
// #include <stdio.h>
// #include <stdlib.h>
// #define false 0
// #define true 1
// #define WriteLog(...) printf(__VA_ARGS__)
// #define MAX_BUFFER 1024

// #define MAX_BUFFER 1024

// void ClientTest()
// {
// 	SetConsoleOutputCP(65001) ;
//     char    szPipeName[MAX_PATH] = {0};
//     HANDLE  hPipe;
//     DWORD   dwRet;
 
//     char    szReadBuf[MAX_BUFFER] = {0};
//     char    szWritebuf[MAX_BUFFER] = {0};
//     DWORD   dwNumRead = 0;
//     DWORD   dwNumWrite = 0;
 
//     strcpy(szPipeName, "\\\\.\\pipe\\myTestPipe");
 
//     //step1:检测管道是否可用
//     if(!WaitNamedPipeA(szPipeName, 10000))
//     {
//         WriteLog("管道[%s]无法打开", szPipeName);
//         return ;
//     }
 
//     //step2:连接管道
//     hPipe = CreateFileA(szPipeName,
//         GENERIC_READ|GENERIC_WRITE,
//         0,
//         NULL,
//         OPEN_EXISTING,
//         FILE_ATTRIBUTE_NORMAL,
//         NULL);
 
//     if(INVALID_HANDLE_VALUE == hPipe)
//     {
//         //成功
//         WriteLog("连接管道失败[%#x]", GetLastError());
//         return ;
//     }
 
//     WriteLog("管道连接成功...");
 
//     printf("请输入要发送的数据:");
//     scanf( "%s", szWritebuf );
 
//     //step3:发送数据
//     if( !WriteFile( hPipe, szWritebuf, strlen(szWritebuf), &dwNumWrite, NULL ))
//     {
//         WriteLog("发送数据失败,GetLastError=[%#x]", GetLastError());
//         return ;
//     }
 
//     printf("发送数据成功:%s\n", szWritebuf );
     
//     //step4:接收数据
//     if( !ReadFile( hPipe, szReadBuf, MAX_BUFFER-1, &dwNumRead, NULL ) )
//     {
//         WriteLog("接收数据失败,GetLastError=[%#x]", GetLastError() );
//         return ;
//     }
 
//     WriteLog( "接收到服务器返回:%s", szReadBuf );
 
//     //step5:关闭管道
//     CloseHandle(hPipe);
// }
 
// int main(int argc, char* argv[])
// {
//     ClientTest();
//     system("pause");
//     return 0;
// }