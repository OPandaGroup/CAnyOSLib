#include "./include/PSystem.h"
#include "./include/PString.h"
#include "./include/PDataStructure.h"
#include "./include/PColor.h"

dirt *getTreeData(string str){
    if(stringcmp(None, str))
        return NULL ;
    size_t start = 0, end = 0;
    while(str[start] == ' ')
        start++;
    endl ;
    bool is_str = false, is_str_dm = false;
    string data = malloc(strlen(str)); memset(data, 0, strlen(str));
    if(data == NULL){
        printError("PDataStructure.so", "get_treeMoreData", "data is NULL, Memory error");
        return NULL;
    }  
    str = Strsplice(str, " ") ;
    list *list = List();
    size_t cutStart = start - 1;     
    for(ull i = start; i < strlen(str); i++){
        if(str[i] == ' ' && str[i-1] == ' '){
            if(is_str || is_str_dm) data[strlen(data)] = ' ';
            else continue;
        }else if(str[i] == ' ' && str[i-1] != ' ' && !(str[i-1] == '=' || (strlen(Anicts(str, i, '=')) == 0)) && !is_str && !is_str_dm){
            data[strlen(data)] = ',';
            continue;
        }else if(str[i] == '\'' && !is_str_dm){
            is_str = !is_str;
        }else if(str[i] == '\"' && !is_str){
            is_str_dm = !is_str_dm;
        }
        if(str[i] != ' ')
            data[strlen(data)] = str[i];
    }
    printf(data) ;
    endl;
    data[strlen(data)] = '\0';
    list = split(data, ',') ;
    print_list(list) ;
    dirt *dirt = Dirt() ;
    for(size_t i = 0; i < list->len; i++){
        string node_data = get_list_node(list, i)->data ;
        string key = Anicts(node_data, 0, '=') ;
        printf("%s %s\n", node_data, key) ;
        string value = stringcut_(node_data, strlen(key) + 1, strlen(get_list_node(list, i)->data)) ;
        // value = stringcut_(value, 1, strlen(value) - 2);
        append_dirt(dirt, key, value) ;
    }
    // print_list(list) ;
    print_dirt(dirt) ;
    return dirt;
}

int main(){
    _ShellToUTF8() ;
    string str = "<project name='test.c' default='build'><symbol><int name='a' scope='global' value='1'></int><char name = 'b' scope='global' value='a'></char></symbol><text><fun name = 'test' args='' return = 'int'><return>0</return></fun> <fun name='main' args='' return = 'int'><int name='a' scope='local' value='1'></int><char name = 'b' scope = 'local' value = 'a'></char><call name='test' args=''></call><set name='a' value='1'></set><call name='printf'    args='{string:\"d\",int:a}'></call><return fun='main'> 0</return></fun></text></project>";
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
                    tags[len-1] = Anicts(tag, 0, ' ');
                    size_t lenght = strlen(tags[len-1]);
                    // values[len-1] = Nicts(str, tag_start + lenght + 1, i - tag_start - lenght - 1);
                    if(i - tag_start - lenght - 1 > 0)
                        append_dirt(values, intToString(tag_index), stringcut_(tag, lenght, strlen(tag))) ;
                    len++;
                    tags = realloc(tags, SIZE_STRING*len) ;
                    string value = Anicts(str, i + 1, '<');  
                    if(strlen(value) != 0){
                        append_dirt(values, Strsplice("$", intToString(tag_index)), value) ;
                    }
                    if(tag[0] != '/')   tag_index++ ;
                    tag = tags[len-1] ;
                    tag_start = -1;
                }else{
                    printError(
                        "PDataStructure.so",
                        "No find tag start",
                        "In Xml file, no find tag start, please check your file "
                    ) ;
                }
                break;
            default:
                break;
        }
    }
    len--; 
    for(size_t i = 0; i < len; i++){
        printf("%s\n", tags[i]) ;
    }
    print_dirt(values); endl;
    tree *trees = NULL ;
    tag_index = 0;
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
                    "In Xml file, no find tag start, please check your file ! !"
                ) ;
                printf("\n\n%s", tags[i]) ;
            }else{
                if(stringcmp(tags[i], Strsplice("/", get_stack_top(stack)->data))){
                    pop_stack(stack) ;
                }else{
                    printError(
                        "PDataStructure.so",
                        "No find tag start",
                        "In Xml file, no find tag start, please check your file ! !"
                    ) ;
                }
            }
        }else{
            struct dirt_node *value = get_dirt_node(values, Strsplice("$", intToString(tag_index))), *more_value = get_dirt_node(values, intToString(tag_index)) ;
            if(get_stack_top(stack) == NULL){
                trees = Tree(None, tags[i], NULL) ;
                push_stack(stack, tags[i]) ;
                get_stack_top(stack)->more_data = trees;
                trees->data = get_value(value) ;
            }else{
                tree *parent = get_stack_top(stack)->more_data ;
                append_tree(parent, None, tags[i]) ;
                push_stack(stack, tags[i]) ;
                get_stack_top(stack)->more_data = parent->child[parent->child_num-1] ;
                parent->child[parent->child_num-1]->data = get_value(value) ;
                endl;
            }
            tree *tree = get_stack_top(stack)->more_data;
            tree->more = getTreeData(get_value(more_value));
            tag_index ++;
        }
    }
    // free(trees );
    print_tree(trees, 0) ;
} 