#include "./include/PandaRuntimeLibrary.h"

int main(){
    _ShellToUTF8() ;
    string str = "<html lang=\"en\"><head><title>Hello World</title></head><body><h1>Hello World</h1></body></html><test><test></test>";
    size_t len = 1;
    string *tags = malloc(SIZE_STRING*len);
    dirt *values = Dirt();
    stack *stack = Stack() ;
    size_t tag_start = -1; //-1就是没有开始
    size_t tag_index = 0;
    for(size_t i = 0; i < strlen(str); i++){
        switch (str[i]){
            case '<':
                tag_start = i ;//标记当前位置
                break;
            case '>':
                if(tag_start != -1){
                    string tag = stringcut_(str, tag_start + 1, i - 1);
                    // printf(tag) ;
                    tags[len-1] = Nicts(tag, 0, ' ');
                    size_t lenght = strlen(tags[len-1]);
                    // values[len-1] = Nicts(str, tag_start + lenght + 1, i - tag_start - lenght - 1);
                    if(i - tag_start - lenght - 1 > 0)
                        append_dirt(values, intToString(tag_index), stringcut_(tag, tag_start + lenght + 1, i - 1)) ;
                    len++;
                    tags = realloc(tags, SIZE_STRING*len) ;
                    string value = Nicts(str, i + 1, '<');
                    if(strlen(value) != 0){
                        append_dirt(values, Strsplice("$", intToString(tag_index)), value) ;
                    }
                    if(tag[0] != '/')   tag_index++ ;
                    tag = tags[len-1] ;
                    if(stringcmp(tag, "hello")){
                        printf("Hello World\n") ;
                    }
                    tag_start = -1;
                }else{
                    printError(
                        "PDataStructure.so",
                        "No find tag start",
                        "In Xml file, no find tag start, please check your file"
                    ) ;
                }
                break;
            default:
                break;
        }
    }
    printf("len:%d\n", len);
    for(size_t i = 0; i < len - 1; i++){
        printf("%s\n", tags[i]) ;
    }
    print_dirt(values) ;
}