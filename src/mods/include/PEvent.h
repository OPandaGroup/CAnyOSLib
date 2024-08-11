// 
// @date : 2024/08
// @author : writing 
// @copyright : GPL
//


typedef struct Object{
    // @class : Event Object (可以使用函数绑定事件)
    
    void (*bird_event)(struct Object *obj, bool (*Event), void (*dispose)) ;

};
