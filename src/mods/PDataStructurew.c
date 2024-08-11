//
// @date:2024/07/16
// @file:PDataStructure.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "./include/PDataStructure.h"

//function of stack
struct stack *Stack(){
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    if(stack == NULL) {
        printError("PDataStructure.so", "Creat Stack", "Stack is NULL, Memory error");
        return NULL;
    }
    stack->top = NULL;
    stack->end = NULL;
    stack->len = 0;
    return stack;
}

void push_stack(struct stack *stack, string data){
    struct stack_node *node = (struct stack_node *)malloc(sizeof(struct stack_node));
    if(stack == NULL) {
        printError("PDataStructure.so", "Creat Stack`s node", "Stack is NULL, Memory error");
        return ;
    }
    node->more_data = NULL;
    node->next = NULL;
    node->last = stack->end;
    node->data = data;
    if(stack->len == 0){
        stack->top = node;
        stack->end = node;
    }else{
        stack->end->next = node;
        stack->end = node;
    }
    node->add_len = 0;
    stack->len++;
    return ;
}

void push_stack_(struct stack *stack, string data, void *more_data){
    push_stack(stack, data);
    return ;
}

void add_stack_data(struct stack *stack, void *data){
    if(stack->len == 0){
        return;
    }else if(stack->len == 1){
        stack->top->more_data = data;
    }else{
        struct stack_node *node = stack->end;
        node->more_data = data;
    }
    return ;
}


void pop_stack(struct stack *stack){
    if(stack->len == 0){
        return;
    }else if(stack->len == 1){
        stack->top = NULL;
        stack->end = NULL;
    }else{
        stack->end = stack->end->last;
        // if(stack->end->next != NULL)
        //     free(stack->end->next);
        //stack->end->next = NULL;
    }
    stack->len--;
    return ;
}

void print_stack(struct stack *stack){
    if(stack->len == 0)  return ;
    struct stack_node *node = stack->top;
    while (node!=NULL){
        printf("%s , ",node->data);
        node = node->next;
    }
}

struct stack_node *get_stack_top(struct stack *stack){
    return stack->end;
}

//function of list
struct list *List(){
    struct list *list = (struct list *)malloc(sizeof(struct list));
    if(list == NULL) {
        printError("PDataStructure.so", "Creat List", "LIst is NULL, Memory error");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

iterator_list *Iterator_list(list *list){
    iterator_list *iter = malloc(sizeof(struct iterator_list)); 
    iter->iter_len = -1;
    iter->list = list;
    iter->node = NULL;
    return iter;
}

iterator_list *Iterator_LIST(list *list, Size_T len){
    iterator_list *iter = Iterator_list(list);
    if(Iter_List_Set(iter, len)) return iter;
    else return NULL;
}

bool Iter_List_Set(iterator_list *iter, Size_T len){
    if(iter->list->len < len){
        return false;
    }else{
        iter->node = iter->list->head ;
        for(Size_T i = 0; i < len; i++){
            if(iter->node == NULL)
                return false;
            iter->node = iter->node->next;
            iter->iter_len++;
        }
    }
    return true ;
}

bool Iter_List_Next(iterator_list *iter, Size_T len){
    if(iter->node == NULL || iter->iter_len == -1){
        iter->node = iter->list->head;
        iter->iter_len = 0;
    }
    Size_T i = 0;
    for(; i < len; i++){
        if(iter->node == NULL)
            return false;
        iter->iter_len++;
        iter->node = iter->node->next;
    }
    if(iter->node == NULL)
        return false;
    else 
        return true;
}
bool Iter_List_Last(iterator_list *iter, Size_T len){
    if(iter->node == NULL || iter->iter_len == 0){
        iter->node = iter->list->tail;
        iter->iter_len = 0;
    }
    Size_T i = 0;
    while(iter->node->last!= NULL && i < len){
        iter->node = iter->node->last ;
        i++;
    }
    if(i < len)
        return false;
    else 
        return true;
}
Size_T Iter_len_list(iterator_list *iter){
    return iter->iter_len;
}
struct list_node *get_Iter_listNode(iterator_list *iter){
    return iter->node ;
}

list *split(string str, char delimiter){
    int i = 0, j = 0, start = 0; // i是游标,j是记录位置,idx是记录string的遍历位置
    list *ls = List();       // 创建一个list
    bool is_str = 0, is_str_dm = 0;
    while (str[i] != '\0'){
        if(str[i] == '\"' && !is_str_dm){
            is_str = !is_str;
        }else if(str[i] == '\'' && !is_str){
            is_str_dm = !is_str_dm;
        }else if(str[i] == delimiter && !is_str && !is_str_dm){
            string tmp = stringcut(str, start, i - start);
            append_list(ls, tmp);
            start = i + 1;
        }
        i++;
    }
    if(str[strlen(str)-1] == delimiter || (start - i == 0)) return ls;
    else append_list(ls, stringcut_(str, start, i - 1));
    return ls;
}

struct list_node *get_list_node(struct list *list, int index){
    if(index >= list->len){
        return NULL;
    }else{
        struct list_node *node = list->head;
        for(int i=0;i<index;i++){
            node = node->next;
        }
        return node;
    }
}

void append_list(struct list *list, string data){
    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    if(node == NULL) {
        printError("PDataStructure.so", "Creat list node", "List is NULL, Memory error");
        return ;
    }
    node->data = data;
    node->next = NULL;
    node->last = list->tail;
    if(list->len == 0){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }
    list->len++;
    return;
}

void append_list_plus(struct list *list, string data){
    if((data == NULL) || (strcmp(data,"None")) || (strcmp(data, "\0"))) return; //无效
}

void remove_list(struct list *list, int index){
    if(index >= list->len){
        return;
    }else if(index == 0){
        list->head = list->head->next;
        free(list->head->last);
        list->head->last = NULL;
    }else if(index == list->len-1){
        list->tail = list->tail->last;
        free(list->tail->next);
        list->tail->next = NULL;
    }else{
        struct list_node *node = list->head;
        for(int i=0;i<index;i++){
            node = node->next;
        }
        node->last->next = node->next;
        node->next->last = node->last;
        free(node);
    }
    list->len--;
    return;
}

void print_list(struct list *list){
    if(list->len == 0)  return ;
    struct list_node *node = list->head;
    printf("[");
    while (node!=NULL){
        if(node->data != NULL)
            printf("%s , ",Strsplice(node->data, "\0"));
            
        node = node->next;
    }
    printf("\b\b]");
}

//function of dirt

dirt *Dirt(){
    dirt *dirt = malloc(sizeof(struct dirt));
    if(dirt == NULL) {
        printError("PDataStructure.so", "Creat dirt", "Dirt is NULL, Memory error");
        return dirt;
    }
    dirt->len = 0;
    dirt->head = NULL;
    dirt->tail = NULL;
    return dirt;
}

void append_dirt(struct dirt *dirt, string key, string value){
    struct dirt_node *node = (struct dirt_node *)malloc(sizeof(struct dirt_node));
    if(node == NULL) {
        printError("PDataStructure.so", "Creat node", "node is NULL, Memory error");
        return ;
    }
    node->key = key;
    node->value = value;
    node->next = NULL;
    node->last = dirt->tail;
    if(dirt->len == 0){
        dirt->head = node;
        dirt->tail = node;
    }else{
        dirt->tail->next = node;
        dirt->tail = node;
        dirt->len++;
    }
    dirt->len++;
    return;
}

void remove_dirt_key(struct dirt *dirt, string key){
    struct dirt_node *node = dirt->head;
    while(node!=NULL){
        if(strcmp(node->key,key) == 0){
            if(node == dirt->head){
                dirt->head = dirt->head->next;
                free(node);
                node = dirt->head;
            }else if(node == dirt->tail){
                dirt->tail = dirt->tail->last;
                free(node);
                node = dirt->tail;
            }else{
                node->last->next = node->next;
                node->next->last = node->last;
            }
            return;
        }
        node = node->next;
    }
}

bool find_dirt_key(struct dirt *dirt, string key){
    struct dirt_node *node = dirt->head;
    while(node!=NULL){
        if(strcmp(node->key,key) == 0){
            return 1;
        }
        node = node->next;
    }
    return 0;
}

string get_key(struct dirt_node *dirt_node){
    if(dirt_node == NULL)
        return None ;
    else
        return dirt_node->key;
}

string get_value(struct dirt_node *dirt_node){
    if(dirt_node == NULL)
        return None ;
    else
        return dirt_node->value;
}

struct dirt_node *get_dirt_node(struct dirt *dirt, string key){
    struct dirt_node *node = dirt->head;
    while(node != NULL){
        if(strcmp(node->key,key) == 0){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void print_dirt(struct dirt *dirt){
    struct dirt_node *node = dirt->head;
    if (dirt->len == 0 || node == NULL){
        printf(None);
        return ;
    }
    printf("{");
    while (node!=NULL){
        putchar('"');printf(node->key);printf("\":");
        putchar('"');printf(node->value);printf("\",");
        node = node->next;
    }
    printf("\b}");
    return ;
}

string get_dirtJSON(struct dirt *dirt){
    string json = malloc(10);memset(json,0,10);
    if(json == NULL) {
        printError("PDataStructure.so", "Creat variable", "variable is NULL, Memory error");
    }
    struct dirt_node *node = dirt->head;
    if(dirt->len == 0 || node == NULL){
        return Strsplice(json,None);
    }
    json = Strsplice(json,"{\n");
    while (node != NULL){
        json = Strsplice(json,"\t\"");json = Strsplice(json,node->key);json = Strsplice(json,"\":");json = Strsplice(json,"\"");json = Strsplice(json,node->value);
        if(node->next != NULL) json = Strsplice(json,"\",\n");
        else json = Strsplice(json,"\"\n");
        node = node->next;
    }
    return Strsplice(json,"}\0");
}

dirt *get_config_File(string conf){
    // list *list = split(conf, '\n');
    // dirt *dirt = Dirt() ;
    // iterator_list *iter = Iterator_list(list) ;
    // for(int i = 0; i < list->len; i++){
    //     if(Iter_List_Next(iter, 1)){
    //         //迭代成功
    //         string str = get_Iter_listNode(iter)->data ;
    //         str = Anicts(str, '\0') ;
    //         if(str[0] == '[' && str[strlen(str) - 1] == ']'){
    //             str = stringcut_(1, strlen(str) - 2) ;
    //             append_dirt(dirt, str) ;
    //             dirt->tail->more_data = Dirt() ;
    //         }
    //     }
    // }
}

//function of tree
struct tree *Tree(string data, string key, struct tree *parent){
    struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
    if(tree == NULL) {
        printError("PDataStructure.so", "Creat Tree", "Tree is NULL, Memory error");
        return NULL;
    }
    tree->child_num = 0;
    tree->data = data;
    tree->child = malloc(sizeof(struct tree *)*1);
    tree->add_data = malloc(sizeof(void *)*1);
    if(tree->child == NULL || tree->add_data == NULL) {
        printError("PDataStructure.so", "Creat variable", "variable is NULL, Memory error");
        return NULL;
    }
    tree->parent = parent;
    tree->more = NULL;
    tree->data_num = 0;
    tree->key = key;
    return tree;
}

void append_tree(struct tree *tree, string data, string key){
    tree->child_num++;
    tree->child = realloc(tree->child,sizeof(struct tree *)*tree->child_num);
    tree->child[tree->child_num-1] = Tree(data, key, tree);
}

void print_tree(struct tree *tree, int level){
    printf("%s data:%s",tree->key, tree->data);
    for(int i = 0 ; i < tree->child_num ; i++){
        printf("\n");
        for(int j = 0 ; j < level ; j++){
            printf("   ");
        }
        printf("└──");
        print_tree(tree->child[i], level+1);
    }
}

void add_tree_data(struct tree *tree, void *data){
    tree->data_num++;
    tree->add_data = realloc(tree->add_data,sizeof(void *)*tree->data_num);
    tree->add_data[tree->data_num-1] = data;
}

void append_more_data(struct tree *tree, string key, string data){
    dirt *dirt = tree->more;
    if(stringcmp(key, "$data")){
        printf("Error: key is $data\n");
        return ;
    }
    if(dirt == NULL){
        tree->more = Dirt();
        append_dirt(tree->more,key,data);
    }else{
        append_dirt(dirt,key,data);
    }
    return ;
}

string get_tree_dirt(struct tree *tree, bool child){
    if(child){
        string str = "\0";
        if(!stringcmp(tree->data,None)){
            str = Strsplice(str,"$data");
            str = Strsplice(str,"=\"");
            str = Strsplice(str,tree->data);
            str = Strsplice(str,"\"");
        } 
        if(tree->more == NULL)  return str;
        if(tree->more->len == 0){
            return str;
        }else{
            str = Strsplice(str, " ");
            for(int i = 0; i < tree->more->len ; i++){
                str = Strsplice(str,tree->more->head->key);
                str = Strsplice(str,"=\"");
                str = Strsplice(str,tree->more->head->value);
                str = Strsplice(str, "\" ");
            }
            str = Strsplice(str,"\b");
            return str;
        }
    }else{
        string str = "\0";
        if(tree->more == NULL){
            return str ;
        }else if(tree->more->len == 0){
            return str;
        }else{
            str = Strsplice(str, " ");
            for(int i = 0; i < tree->more->len ; i++){
                str = Strsplice(str,tree->more->head->key);
                str = Strsplice(str,"=\"");
                str = Strsplice(str,tree->more->head->value);
                str = Strsplice(str, "\" ");
            }
            return str;
        }     
    }
}

string get_tree_XML(struct tree *tree, int level){
    if(tree == NULL)    return None;
    string str = "\0";
    for (int i = 0; i < level; i++){
        str = Strsplice(str, "\t");
    }
    if(tree->child_num == 0){
        str = Strsplice(str, Strsplice("<", Strsplice(tree->key, Strsplice(get_tree_dirt(tree, 0), ">"))));
        if(tree->data != NULL && !stringcmp(tree->data, None))
            str = Strsplice(str, tree->data);
        str = Strsplice(str, Strsplice("</", Strsplice(tree->key, ">\n")));
    }else{
        str = Strsplice(str, Strsplice("<", Strsplice(Strsplice(tree->key, Strsplice(" ", get_tree_dirt(tree, 1))), ">\n")));
        for(int i = 0; i < tree->child_num; i++)    str = Strsplice(str, get_tree_XML(tree->child[i], level+1));
        str = Strsplice(str, Strsplice("</", Strsplice(tree->key, ">\n")));
    }
    return str;
}

tree *get_child(struct tree *tree, int index){
    if(index >= tree->child_num){
        return NULL;
    }else{
        return tree->child[index];
    }
}

dirt *getTreeData(string str){
    if(stringcmp(None, str))
        return NULL ;
    Size_T start = 0, end = 0;
    while(str[start] == ' ')
        start++;
    bool is_str = false, is_str_dm = false;
    string data = malloc(strlen(str)); memset(data, 0, strlen(str));
    if(data == NULL){
        printError("PDataStructure.so", "get_treeMoreData", "data is NULL, Memory error");
        return NULL;
    }  
    str = Strsplice(str, " ") ;
    list *list = List();
    Size_T cutStart = start - 1;     
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
    data[strlen(data)] = '\0';
    list = split(data, ',') ;
    // print_list(list) ;
    dirt *dirt = Dirt() ;
    for(Size_T i = 0; i < list->len; i++){
        string node_data = get_list_node(list, i)->data ;
        string key = Anicts(node_data, 0, '=') ;
        // printf("%s %s\n", node_data, key) ;
        string value = stringcut_(node_data, strlen(key) + 1, strlen(get_list_node(list, i)->data)) ;
        value = stringcut_(value, 1, strlen(value) - 2);
        append_dirt(dirt, key, value) ;
    }
    // print_list(list) ;
    // print_dirt(dirt) ;
    return dirt;
}

tree *get_tree_from_XML(string str){
    Size_T len = 1;
    string *tags = malloc(SIZE_STRING*len);
    dirt *values = Dirt();
    stack *stack = Stack() ;
    Size_T tag_start = -1; //-1就是没有开始
    Size_T tag_index = 0;
    for(Size_T i = 0; i < strlen(str); i++){
        switch (str[i]){
            case '<':
                tag_start = i ;//标记当前位置
                break;
            case '>':
                if(tag_start != -1){
                    string tag = stringcut_(str, tag_start + 1, i - 1);
                    tags[len-1] = Anicts(tag, 0, ' ');
                    Size_T lenght = strlen(tags[len-1]);
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
    tree *trees = NULL ;
    tag_index = 0;
    for(Size_T i = 0; i < len; i++){
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
            }
            tree *tree = get_stack_top(stack)->more_data;
            tree->more = getTreeData(get_value(more_value));
            if((tree->more != NULL)){
                tree->data = get_value(get_dirt_node(tree->more, "$data"));
                remove_dirt_key(tree->more, "$data") ;
            }
            tag_index ++;
        }
    }
    return trees ;
}

//function of resources

resources *Resources(){
    resources *resources = (struct resources *)malloc(sizeof(resources));
    resources->len = 0;
    resources->data = malloc(sizeof(void *)*1);
    if(resources == NULL || resources->data == NULL){
        printError("PDataStructure.so", "Resources", "resources is NULL, Memory error");
        return NULL;
    }
    return resources;
}

void append_resources(resources *resources, void *data){
    resources->len++;
    resources->data = realloc(resources->data, sizeof(void *)*resources->len);
    resources->data[resources->len - 1] = data;
    return ;
}

void remove_resources(resources *resources, int index){
    if(index >= resources->len || index < 0){
        printf("resources error: index out of range");
        return ;   
    }else{
        resources->data[index] = NULL;
        return ;
    }
}

void *get_resources(resources *resources, int index){
    if(index >= resources->len || index < 0){
        printf("resources error: index out of range");
        return NULL;
    }else{
        return resources->data[index];
    }
}