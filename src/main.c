#include "./include/PDataStructure.h"

int main(int argc, char const *argv[]){
    string conf = "[MAIN]\nhello=    \"true\"\n #hello" ;
    list *list = split(conf, '\n');
    print_list(list) ;
    dirt *dirt = Dirt() ;
    iterator_list *iter = Iterator_LIST(list, 0) ;
    for(size_t i = 0;i < list->len; i++){
        string line = get_Iter_listNode(iter)->data ;
        get_Iter_listNode(iter)->data = line = Anicts(line, 0, '\0') ;
        string key = Anicts(line, 0, '=') ;
        Bool is_str = false, is_str_dm = false, is_num_ = false, is_str_ = false, flag = false;
        for(Size_T j = strlen(key);j < strlen(line); j++){
            // if(flag && line)
            switch(line[j]){
                case '\"':
                    if(!is_str)
                        is_str_dm = !is_str_dm ;
                    break;
                case '#':
                    if(!is_str_dm && !is_str)
                        flag = true ;
                    break;
                case ' ':
                    if(!is_str_dm && !is_str)
                        flag = true ;
                    break;
                        
            }
        }
        printf("%s\n", line) ;
        if(i != list->len - 1 && !Iter_List_Next(iter, 1))
            printError("CONF ERROR", "INVALID CONF", "SYSTEM ERROR") ;
    }
    return 0;
}