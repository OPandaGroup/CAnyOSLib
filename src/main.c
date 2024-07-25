#include "./include/PSystem.h"
#include "./include/PString.h"
#include "./include/PDataStructure.h"

int main(){
    _ShellToUTF8() ;
    string str = "<head><title>Document</title></head>";
    //////////////00000000011111111112222222222333333333344444444445555555555666666666677777777
    //////////////12345678901234567890123456789012345678901234567890123456789012345678901234567
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
                    printf("tag:%s %ld start : %ld\n", tag, tag_start + lenght + 1, tag_start) ;
                    if(i - tag_start - lenght - 1 > 0)
                        append_dirt(values, intToString(tag_index), stringcut_(tag, lenght, strlen(tag))) ;
                    len++;
                    tags = realloc(tags, SIZE_STRING*len) ;
                    string value = Nicts(str, i + 1, '<');  
                    if(strlen(value) != 0){
                        append_dirt(values, Strsplice("$", intToString(tag_index)), value) ;
                    }
                    if(tag[0] != '/')   tag_index++ ;
                    tag = tags[len-1] ;
                    // if(stringcmp(tag, "hello")){
                    //     printf("Hello World\n") ;
                    // }
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
    len --; 
    printf("len:%d\n", len);
    for(size_t i = 0; i < len; i++){
        printf("%s\n", tags[i]) ;
    }
    print_dirt(values); endl;
    tree *trees = NULL ;
    for(size_t i = 0; i < len; i++){
        if(stringcmp(stringcut(tags[i], 0, 3), "!--")){
            continue;
        }else if(stringcmp(stringcut(tags[i], 0, 1), "?")){
            //版本信息
        }else if(stringcmp(stringcut(tags[i], 0, 1), "/")){
            if(get_stack_top(stack) == NULL){
                printError(
                    "PDataStructure.so",
                    "No find tag start",
                    "In Xml file, no find tag start, please check your file"
                ) ;
            }else{
                if(get_stack_top(stack) == NULL)
                    printError(
                        "PDataStructure.so",
                        "No find tag start",
                        "In Xml file, no find tag start, please check your file"
                    ) ;
                else{
                    if(stringcmp(tags[i], Strsplice("/", get_stack_top(stack)->data))){
                        pop_stack(stack) ;
                    }else{
                        printError(
                            "PDataStructure.so",
                            "No find tag start",
                            "In Xml file, no find tag start, please check your file"
                        ) ;
                    }
                }

                pop_stack(stack) ;
            }
        }else{
            // if(stringcmp(stringcut(tags[i], strlen(tags[i]-1), 1), "/")){
            //     if(get_stack_top(stack) == NULL){
            //         printError(
            //             "PDataStructure.so",
            //             "No find tag start",
            //             "In Xml file, no find tag start, please check your file"
            //         ) ;
            //     }else{
            //         tree *parent = get_stack_top(stack)->more_data ;
            //         append_tree(parent, tags[i], None) ;
            //     }
            // }else{
            if(get_stack_top(stack) == NULL){
                trees = Tree(None, tags[i], NULL) ;
                push_stack(stack, tags[i]) ;
                get_stack_top(stack)->more_data = trees;
            }
                tree *parent = get_stack_top(stack)->more_data ;
                append_tree(parent, tags[i], None) ;
                push_stack(stack, tags[i]) ;
                get_stack_top(stack)->more_data = parent->child[parent->child_num-1] ;
            // }
        }
    }
    print_tree(trees, 0) ;
} 