//
// @date:2024/07/16
// @file:PDataStructure.c
// @author:Writing 
// @copyright: Panda, 2024
//

#include "../include/Widgets/PClassw.h"

class *Class(char *name, void *Constructor, void *Fiction, ...){
    class *__CLASS__ = malloc(sizeof(class));
    __CLASS__->name = name;
    __CLASS__->Constructor = Constructor;
    __CLASS__->Fiction = Fiction;
    __CLASS__->__VAR__ = NULL;
    
}