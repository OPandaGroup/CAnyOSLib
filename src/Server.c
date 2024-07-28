#include "./include/PWindows.h"

char *PipeName = "\\\\.\\pipe\\PandaRun_Deng_test" ;

int main(){
   // HANDLE hPipe = createNamePipe(PipeName, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE|PIPE_READMODE_MESSAGE|PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, 1024, 1024, 0) ;
   HANDLE hPipe = createNamePipe(PipeName, PIPE_ACCESS_DUPLEX,
       PIPE_TYPE_BYTE|PIPE_READMODE_BYTE|PIPE_WAIT,
       PIPE_UNLIMITED_INSTANCES, 0, 0, 0);
   printf("%ld", hPipe) ;
   if(!ConnectNamedPipe(hPipe, NULL)){
		printError("System Call", "create named Pipe", "System Error, create named Pipe time Error, Please try again") ;
		return 0 ;
	}
   if(!writeNamePipe(hPipe, "Hello World"))   printf("writeNamePipe") ;
   printf("%s", readNamePipe(hPipe, 255)) ;

}

// // #include <windows.h>
// // #include <iostream>

// // int pipeServer()
// // {
// // 	HANDLE hPipe;
// // 	/*
// // 	* Windows系统下，管道名称命名规范：
// // 	*	\\.\pipe\pipename
// // 	*	其中'\\.\pipe\'是固定的前缀，表示这是一个命名管道
// // 	*/
// // 	LPCWSTR pipeName = L"\\\\.\\pipe\\MyPipe";
// // 	char buffer[1024];
// // 	DWORD bytesRead;
// // 	DWORD bytesWritten;
// // 	BOOL success;

// // 	// 创建命名管道
// // 	hPipe = CreateNamedPipe(
// // 		pipeName,              // 管道名称
// // 		PIPE_ACCESS_DUPLEX,    // 双向访问
// // 		PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, // 数据类型和读取模式
// // 		1,                     // 最大实例数
// // 		1024,                  // 输出缓冲区大小
// // 		1024,                  // 输入缓冲区大小
// // 		0,                     // 客户端超时时间
// // 		NULL                   // 默认安全属性
// // 	);

// // 	if (hPipe == INVALID_HANDLE_VALUE) {
// // 		std::cerr << "Failed to create pipe." << std::endl;
// // 		return 1;
// // 	}

// // 	std::cout << "Named pipe created successfully." << std::endl;

// // 	// 等待客户端连接
// // 	std::cout << "Waiting for client connection..." << std::endl;
// // 	success = ConnectNamedPipe(hPipe, NULL) ?
// // 		TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);

// // 	if (success) {
// // 		std::cout << "Client connected." << std::endl;
// // 	}
// // 	else {
// // 		CloseHandle(hPipe);
// // 		std::cerr << "Failed to make connection on named pipe." << std::endl;
// // 		return 1;
// // 	}

// // 	// 读写循环
// // 	while (true) {
// // 		// 从客户端读取消息
// // 		success = ReadFile(
// // 			hPipe,
// // 			buffer,
// // 			sizeof(buffer),
// // 			&bytesRead,
// // 			NULL
// // 		);

// // 		if (!success || bytesRead == 0) {
// // 			if (GetLastError() == ERROR_BROKEN_PIPE) {
// // 				std::cerr << "Client disconnected." << std::endl;
// // 			}
// // 			else {
// // 				std::cerr << "Read failed." << std::endl;
// // 			}
// // 			break;
// // 		}

// // 		buffer[bytesRead] = '\0'; // 确保字符串结束符
// // 		std::cout << "Client says: " << buffer << std::endl;

// // 		// 检查是否退出
// // 		if (strcmp(buffer, "quit") == 0) {
// // 			std::cout << "Client initiated termination." << std::endl;
// // 			break;
// // 		}

// // 		// 发送响应到客户端
// // 		const char* response = "Hello, client!";
// // 		success = WriteFile(
// // 			hPipe,
// // 			response,
// // 			(DWORD)strlen(response),
// // 			&bytesWritten,
// // 			NULL
// // 		);

// // 		if (!success) {
// // 			std::cerr << "Failed to send data." << std::endl;
// // 			break;
// // 		}
// // 	}

// // 	// 关闭句柄
// // 	CloseHandle(hPipe);
// // 	std::cout << "Connection closed." << std::endl;
// // 	return 0;
// // }

// // int main()
// // {
// //     pipeServer();
// //     std::cin.get();
// // }
//客户端测试程序
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
#define WriteLog(...) printf(__VA_ARGS__)
#define MAX_BUFFER 1024

//服务端测试程序
void SrvTest()
{
   SetConsoleOutputCP(65001) ;
    HANDLE  hSrvNamePipe;   
    char    szPipeName[MAX_PATH] = {0};
 
    char    szReadBuf[MAX_BUFFER] = {0};
    char    szWritebuf[MAX_BUFFER] = {0};
    DWORD   dwNumRead = 0;
    DWORD   dwNumWrite = 0;
     
    strcpy(szPipeName, "\\\\.\\pipe\\myTestPipe");
 
    //step1:创建管道实例
    hSrvNamePipe = CreateNamedPipeA( "\\\\.\\pipe\\myTestPipe", 
        PIPE_ACCESS_DUPLEX|FILE_FLAG_WRITE_THROUGH,
        PIPE_TYPE_BYTE|PIPE_READMODE_BYTE|PIPE_WAIT,
        PIPE_UNLIMITED_INSTANCES, 0, 0, 0, NULL);
    if( INVALID_HANDLE_VALUE == hSrvNamePipe )
    {
        WriteLog("CreateNamedPipeA err[%#x]", GetLastError());
        return ;
    }
    WriteLog("CreateNamedPipe succ...");
    //step2:等待客户端连接
    BOOL bRt= ConnectNamedPipe(hSrvNamePipe, NULL );
    if( false==bRt && GetLastError() != ERROR_PIPE_CONNECTED )
    {
        WriteLog("等待客户端连接失败,[%#x]", GetLastError());
        return ;
    }
    WriteLog( "收到客户端的连接成功...");
 
    //step3:接收数据
    memset( szReadBuf, 0, MAX_BUFFER );
    bRt = ReadFile( hSrvNamePipe, szReadBuf, MAX_BUFFER-1, &dwNumRead, NULL );
    if( !bRt || dwNumRead == 0 )
    {
        bRt = GetLastError();
        if (bRt == ERROR_BROKEN_PIPE)
        {
            WriteLog("客户已关闭链接" );
            return ;
        }
        else
        {
            WriteLog("读取客户数据失败!,GetLastError=%d", GetLastError() );
            return ;
        }
    }
    WriteLog( "收到客户数据:[%s]", szReadBuf);
    //step4:业务逻辑处理 （只为测试用返回原来的数据）
 
    //step5:发送数据
    if( !WriteFile( hSrvNamePipe, szReadBuf, dwNumRead, &dwNumWrite, NULL ) )
    {
        WriteLog("向客户写入数据失败:[%#x]", GetLastError());
        return ;
    }
 
    WriteLog("写入数据成功...");
}
 
int main(int argc, char* argv[])
{
    SrvTest();
    system("pause");
    return 0;
}