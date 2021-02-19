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

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node {
    struct node *prev;
    struct node *next;
    void *data;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
    size_t length;
} list_t;

/*!
 * @brief   Initializes a new list.
 *
 * @return  pointer to new list.
 */
list_t *list_new(void);

/*!
 * @brief   Add new node to the end of the specified list.
 *
 * @param   list - pointer to list.
 * @param   data - data pointer for new node.
 */
void list_add(list_t *list, void *data);

/*!
 * @brief   Removes node from list.
 *
 * @param   list - pointer to list.
 * @param   data - data pointer of the node to be removed.
 */
void list_remove(list_t *list, void *data);

/*!
 * @brief   Retrieves data from list nodes starting from head. Once it reaches
 *          the tail it goes back to the head.
 *
 * @param   list - pointer to list.
 *
 * @return  pointer to the next node's data.
 */
void *list_next(list_t *list);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* LIST_H */

