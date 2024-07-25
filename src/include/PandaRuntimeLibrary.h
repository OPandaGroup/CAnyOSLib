// 
// @author : writing DengWirte@outlook.com
// @date :2024/7/22
// 这个文件是独立文件,将所有运行时库函数放在这里
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define true 1
#define false 0

// Typedef
typedef size_t ull;
typedef _Bool bool;
typedef char * string;

//define
#define None "None"
#define endl printf("\n")
#define Debug(...) printf(__VA_ARGS__)
#define SIZE_STRING sizeof(string)

// PColor.h

// @copyright MoDa_Li(csdn)
#define NONE                  "\e[0m"           //清除颜色，即之后的打印为正常输出，之前的不受影响
#define BLACK                 "\e[0;30m"         //深黑
#define L_BLACK             "\e[1;30m"            //亮黑，偏灰褐
#define RED                     "\e[0;31m"      //深红，暗红
#define L_RED                 "\e[1;31m"        //鲜红
#define GREEN                "\e[0;32m"         //深绿，暗绿
#define L_GREEN            "\e[1;32m"           //鲜绿
#define BROWN               "\e[0;33m"          //深黄，暗黄
#define YELLOW              "\e[1;33m"          //鲜黄
#define BLUE                    "\e[0;34m"      //深蓝，暗蓝
#define L_BLUE                "\e[1;34m"        //亮蓝，偏白灰
#define PURPLE               "\e[0;35m"         //深粉，暗粉，偏暗紫
#define L_PURPLE           "\e[1;35m"           //亮粉，偏白灰
#define CYAN                   "\e[0;36m"       //暗青色
#define L_CYAN               "\e[1;36m"         //鲜亮青色
#define GRAY                   "\e[0;37m"       //灰色
#define WHITE                  "\e[1;37m"       //白色，字体粗一点，比正常大，比bold小
#define BOLD                    "\e[1m"         //白色，粗体
#define UNDERLINE         "\e[4m"               //下划线，白色，正常大小
#define BLINK                   "\e[5m"         //闪烁，白色，正常大小
#define REVERSE            "\e[7m"              //反转，即字体背景为白色，字体为黑色
#define HIDE                     "\e[8m"        //隐藏
#define CLEAR                  "\e[2J"          //清除
#define CLRLINE               "\r\e[K"          //清除行
#define SetColor(...) printf(__VA_ARGS__)
#define ClearColor() printf(NONE)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PDataStructure.h

//data structure
/*The code that follows is the stack definition, 
the struct and function definition*/
typedef struct stack{
    int len;
    struct stack_node *top,*end;
}stack;
struct stack_node{
    string data;
    void *more_data;
    int add_len ;
    struct stack_node *next;
    struct stack_node *last;
};
/*function definition of stack*/
struct stack *Stack();
void push_stack(struct stack *stack, string data);
void add_stack_data(struct stack *stack, void *data); //默认给栈顶添加数据
void pop_stack(struct stack *stack);
void print_stack(struct stack *stack);
struct stack_node *get_stack_top(struct stack *stack);//获得栈顶
/*The following code is the list definition, 
the struct and function definition*/
typedef struct list{
    int len;
    struct list_node *head,*tail;
}list;
struct list_node{
    string data;
    struct list_node *next;
    struct list_node *last;
};
/*function definition of list*/
struct list *List();
struct list *split(string str, char delimiter);
struct list_node *get_list_node(struct list *list, int index);
void append_list(struct list *list, string data);
void append_list_plus(struct list *list, string data) ;//添加数据,主要针对一些特殊字符处理,例如:"", "None", "(null)"就不允许被添加进list
void remove_list(struct list *list, int index);
void print_list(struct list *list);

/*The following code is the dirt definition, 
the struct and function definition*/
typedef struct dirt{
    int len;
    struct dirt_node *head,*tail;
}dirt;
struct dirt_node{
    string key,value;
    struct dirt_node *next;
    struct dirt_node *last;
};
/*function definition of dirt*/
struct dirt *Dirt();
void print_dirt(struct dirt *dirt);
void remove_dirt_key(struct dirt *dirt, string key);
bool find_dirt_key(struct dirt *dirt, string key);
string get_key(struct dirt_node *dirt_node);
string get_value(struct dirt_node *dirt_node);
struct dirt_node *get_dirt_node(struct dirt *dirt, string key);
void append_dirt(struct dirt *dirt, string key, string value);
/*The following code is the tree definition, 
the struct and function definition*/
typedef struct tree{
    int child_num;
    struct tree *parent;
    struct tree **child;
    void **add_data;
    int data_num;
    dirt *more;
    string data;
    string key;
}tree;
/*function definition of tree*/
struct tree *Tree(string data, string key, struct tree *parent);
void append_tree(struct tree *tree, string data, string key);
void print_tree(struct tree *tree, int level);
void add_tree_data(struct tree *tree, void *data);
void append_more_data(struct tree *tree, string key, string data);
string get_tree_XML(struct tree *tree,int level); //Format: xml
tree *get_child(tree *tree, int index);
tree *get_tree_from_XML(string xml);
/*The following code is the resources definition, 
the struct and function definition*/
typedef struct resources{
    int len;
    void **data;
}resources;
resources *Resources();
void append_resources(resources *resources, void *data);
void remove_resources(resources *resources, int index);
void *get_resources(resources *resources, int index);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PDataTypeConversion.h

string intToString(int num);
int stringToInt(string str);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PDebug.h

void PDebug(string message) ;
void PDebugLine(string message, _Bool newline) ;
void init_DebugFile();
void print_DebugFile(string message);
void print_DebugFileLine(string message, _Bool newline);
void print_String(string message);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//System
void gotoXY(int x, int y);
void ShellToUTF8();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PSystem.h

void _ShellToUTF8();
void _gotoXY(int x, int y);
char *_getSystem() ;
char *_runShell(char *cmd) ;
char *_getFilePath(char *path) ;//获取文件所在文件夹 比如 /home/user/file.txt 返回/home/user/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Pprint.h

void printError(char *sender, char *error, char *situation);

//PFile.h

FILE *openfile(const char *filename, char *mode);
string readfile(FILE *file, ull len);
void closefile(FILE *file);
void writetofile(FILE *file, char *str);
ull fileSize(FILE *file);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PString.h

_Bool stringcmp(char *_Str1, char *_Str2); //如果一样返回true
ull stringsearch(char *str1, char *str2); 
char *erase(char *str,ull index,ull len);
char *Strsplice(char *str, char *str2);
char *stringcut(char *str, ull index, ull len);
char *stringcut_(char *str, ull index, ull len);
//Reverse_Ergodic和Reverse_Icts一样
string Reverse_Ergodic(string str, ull index, char stop) ;
string stringFlip(string str);
string insert(string str, ull index, char *str2);
void inserts(string str, ull index, char *str2);
void Flip(string str);
//这里面的无效字符指的是空格,换行符,制表符 默认将保留" ,'中的字符串内容
string Nicts(string str, ull index, char stop) ;//到...字符停止，中间不保留无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 hello    确定起点遍历
string Reverse_Nicts(string str, ull index, char stop) ; //到...字符停止，中间不保留无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 ow   确定终点遍历
string Icts(string str, ull index, char stop) ; //到...字符停止，中间保留无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 h ello,world!
string Reverse_Icts(string str, ull index, char stop) ; //到...字符停止，中间保留无效字符，倒序 例如 : he llo,wo rld! stop = ',' index = 8 结果为 !dlr ow
bool Nicts_bool(string str, ull index, char stop) ; //到...字符停止，中间不包含无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 false
bool Icts_bool(string str, ull index, char stop) ; //到...字符停止，中间包含无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 true
bool Reverse_Nicts_bool(string str, ull index, char stop) ; //到...字符停止，中间不包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 true
bool Reverse_Icts_bool(string str, ull index, char stop) ; //到...字符停止，中间包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 false
//跟上面类似，只不过可以指定无效字符,默认将保留" ,'中的字符串内容
string Nictsc(string str, char ch[], ull index, char stop) ;//到...字符停止，中间不保留无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 hello    确定起点遍历
string Reverse_Nictsc(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不保留无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 ow   确定终点遍历 ; //到...字符停止，中间保留无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 h ello,world! ; //到...字符停止，中间保留无效字符，倒序 例如 : he llo,wo rld! stop = ',' index = 8 结果为 !dlr ow
bool Nictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不包含无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 false
bool Ictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间包含无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 true
bool Reverse_Nictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 true
bool Reverse_Ictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 false
string delchar(string str, char ch); //在字符串中删除指定字符 不包含" ,' 中的任何字符
//替换
string Replace(string str, char ch1, char ch2);
