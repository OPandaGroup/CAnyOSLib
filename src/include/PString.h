//
// @date:2024/07/16
// @file:PString.h
// @author:Writing 
// @copyright: Panda, 2024
//
#ifndef _PSing_H
#define _PSing_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define None "None"

typedef size_t ull;
typedef _Bool bool;
typedef char * string;

_Bool stringcmp(char *_Str1, char *_Str2); //如果一样返回true
ull stringsearch(char *str1, char *str2); 
char *erase(char *str,ull index,ull len);
char *Strsplice(char *str, char *str2);
char *stringcut(char *str, ull index, ull len);
char *stringcut_(char *str, ull index, ull len);
//Reverse_Ergodic和Reverse_Icts一样
string Strclone(string str) ;
string stringFlip(string str);
string insert(string str, ull index, char *str2);
void inserts(string str, ull index, char *str2);
void Flip(string str);
/*
    可以直接使用的函数,方便你使用的函数,就是单/双引号内的数据不会记入无效数据
*/
//这里面的无效字符指的是空格,换行符,制表符 默认将保留" ,'中的字符串内容
string Anicts(string str, ull index, char stop) ;//到...字符停止，中间不保留无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 hello    确定起点遍历
string Reverse_Anicts(string str, ull index, char stop) ; //到...字符停止，中间不保留无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 ow   确定终点遍历
string Aicts(string str, ull index, char stop) ; //到...字符停止，中间保留无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 h ello,world!
string Reverse_Aicts(string str, ull index, char stop) ; //到...字符停止，中间保留无效字符，倒序 例如 : he llo,wo rld! stop = ',' index = 8 结果为 !dlr ow
bool Anicts_bool(string str, ull index, char stop) ; //到...字符停止，中间不包含无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 false
bool Aicts_bool(string str, ull index, char stop) ; //到...字符停止，中间包含无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 true
bool Reverse_Anicts_bool(string str, ull index, char stop) ; //到...字符停止，中间不包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 true
bool Reverse_Aicts_bool(string str, ull index, char stop) ; //到...字符停止，中间包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 false
//跟上面类似，只不过可以指定无效字符,默认将保留" ,'中的字符串内容
string Anictsc(string str, char ch[], ull index, char stop) ;//到...字符停止，中间不保留无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 hello    确定起点遍历
string Reverse_Anictsc(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不保留无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 ow   确定终点遍历 ; //到...字符停止，中间保留无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 h ello,world! ; //到...字符停止，中间保留无效字符，倒序 例如 : he llo,wo rld! stop = ',' index = 8 结果为 !dlr ow
bool Anictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不包含无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 false
bool Aictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间包含无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 true
bool Reverse_Anictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 true
bool Reverse_Aictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 false
string delchar(string str, char ch); //在字符串中删除指定字符 不包含" ,' 中的任何字符
//替换
string Replace(string str, char ch1, char ch2);

#endif