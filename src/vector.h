#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

struct vector {
    void*  array;
    size_t item_size;
    size_t size;
    size_t capacity;
};

#endif

struct vector* make(size_t item_size, size_t capacity);
bool is_empty(struct vector* v);
void* at(struct vector* v, size_t index);
void push(struct vector* v, void* newItem);
void insert(struct vector* v, size_t index, void* item);
void* pop(struct vector* v);
void* shift(struct vector* v);
void delete(struct vector* v, size_t index);

