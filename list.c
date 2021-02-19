/******************************************************************************
 * Doubly Linked List.
 *
 * MIT License
 * 
 * Copyright (c) 2021 Ricardo Cirio (INSTITUTO FEDERAL DE SANTA CATARINA)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

#include "list.h"

list_t *list_new(void) {
    list_t *list = malloc(sizeof(list_t));

    if(list == NULL) {
        //ERROR
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

void list_add(list_t *list, void *data) {
    if(list == NULL || data == NULL) {
        //ERROR
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    if(new_node == NULL) {
        //ERROR
        return;
    }

    new_node->prev = list->tail;
    new_node->next = NULL;
    new_node->data = data;    

    if(list->length == 0) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->length++; 
}

void list_remove(list_t *list, void *data) {
    if(list == NULL || data == NULL) {
        //ERROR
        return;
    }

    node_t *node = list->head;

    for(size_t i = 0; i < list->length; i++) {
        if(node->data == data) {
            if(node->prev == NULL) {
                if(node->next == NULL) {
                    list->head = NULL;
                    list->tail = NULL;
                } else {
                    list->head = node->next;
                    node->next->prev = NULL;
                }
            } else {
                if(node->next == NULL) {
                    list->tail = node->prev;
                } else {
                    node->next->prev = node->prev;
                }
                node->prev->next = node->next;
            } 
            list->length--;
            free((void *)node);
            break;
        }
        node = node->next;
    }
    //NOT FOUND
}

void *list_next(list_t *list) {
    if(list == NULL) {
        //ERROR
        return NULL;
    }

    static node_t *curr_node = NULL;

    if(curr_node == NULL || curr_node == list->tail) {
        curr_node = list->head;
    } else {
        curr_node = curr_node->next;
    }

    return curr_node->data;
}

