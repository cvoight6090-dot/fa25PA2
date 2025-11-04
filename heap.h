//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        //empty list check
        if (size == 0) {
            return -1;
        }
        //save root
        int min = data[0];
        //put last element at root
        data[0] = data[size-1];
        size--;
        downheap(0, weightArr);
        return min;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        //data[pos/parent] might be needed here
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[parent]] > weightArr[data[pos]]) {
                //swapping
                int temp = data[parent];
                data[parent] = data[pos];
                data[pos] = temp;
                pos = parent;
            }
            else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int small = pos;
            //left child
            if (left < size && weightArr[data[left]] < weightArr[data[small]]) {
                small = left;
            }
            //right child
            if (right < size && weightArr[data[right]] < weightArr[data[small]]) {
                small = right;
            }
            if (small != pos) {
                //swapping
                int temp = data[small];
                data[small] = data[pos];
                data[pos] = temp;

                pos = small;
            }
            else {
                break;
            }
        }
    }
};

#endif