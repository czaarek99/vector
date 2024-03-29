#include <stdlib.h>
#include <string.h>
#include "vector.h"

struct vector* make(size_t item_size, size_t capacity) {

    struct vector* v = malloc(sizeof(struct vector));

    v->array = malloc(item_size * capacity);
    v->item_size = item_size;
    v->capacity = capacity;
    v->size = 0;

    return v;

}

bool is_empty(struct vector* v) {
    return v->size == 0;
}

void* at(struct vector* v, size_t index) {
    return v->array + (v->item_size * index);
}

void push(struct vector* v, void* item) {
    if(v->size == v->capacity) {
        size_t oldArrayCapacity = v->item_size * v->size;
        size_t newArrayCapacity = oldArrayCapacity * 2;

        void** newArray = malloc(newArrayCapacity);
        memcpy(newArray, v->array, oldArrayCapacity);

       v->capacity = newArrayCapacity;

       free(v->array);

       v->array = newArray;
    }

    memcpy(v->array + (v->item_size * v->size), item, v->item_size);
    v->size++;
}

void insert(struct vector* v, size_t index, void* newItem) {

    if (v->size == v->capacity) {
        v->capacity *= 2;
    }

    void* newArray = malloc(v->item_size * v->capacity);

    long item_offset = newArray + (index * v->item_size);

    memcpy(newArray, v->array, index * v->item_size);
    memcpy(newArray + item_offset, newItem, v->item_size);
    memcpy(newArray + item_offset + v->item_size, v->array, v->item_size * (v->size - index));

    free(v->array);
    v->array = newArray;
    v->size++;
}

void* pop(struct vector* v) {
    v->size--;

    void* poppedItem = malloc(v->item_size);

    memcpy(poppedItem, v->array + ((v->size - 1) * v->item_size), v->item_size);

    return poppedItem;
}

void* shift(struct vector* v) {
    void* shiftedItem = malloc(v->item_size);

    memcpy(shiftedItem, v->array, v->item_size);

    void* newArray = malloc(v->item_size * v->capacity);

    memcpy(newArray, v->array + v->item_size, v->item_size * (v->size - 1));

    free(v->array);

    v->array = newArray;
    v->size--;

    return shiftedItem;
}

void delete(struct vector* v, size_t index) {

    void* newArray = malloc(v->item_size * v->capacity);

    long item_offset = newArray + (index * v->item_size);
    memcpy(newArray, v->array, index * v->item_size);
    memcpy(newArray + item_offset + v->item_size, v->array, v->item_size * (v->size - index));

    free(v->array);

    v->array = newArray;
    v->size--;
}
