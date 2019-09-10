#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

struct vector {
    void*  array;
    size_t size;
    size_t capacity;
};

#endif

bool is_empty(struct vector v);
void* at(size_t index);
void push(void* item);
void insert(size_t index, void* item);
void* pop();
void* unshift();
void delete(size_t index);
struct vector make(size_t length, size_t capacity);

