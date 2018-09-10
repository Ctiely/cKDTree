//
// Created by Clytie on 2018/9/10.
//

#include <cassert>
#include <iostream>
#include "KDTree.h"


void KDTree::build_tree(vector<vector<double> > & datas) {
    Datas.swap(datas);
    num_samples = (unsigned int)Datas.size();
    assert(num_samples > 0 && dim > 0 && dim <= Datas.front().size());
}

void KDTree::mergesort(vector<vector<double> > & arr,
                       vector<unsigned int> & args,
                       unsigned int axis,
                       unsigned int left,
                       unsigned int right) {
    if (left < right) {
        unsigned int pivot = (left + right) / 2;
        mergesort(arr, args, axis, left, pivot);
        mergesort(arr, args, axis, pivot + 1, right);
        vector<unsigned int> C(right - left + 1);
        unsigned int Actr = left, Bctr = pivot + 1, Cctr = 0;
        while (Actr <= pivot && Bctr <= right) {
            if (arr[args[Actr]][axis] < arr[args[Bctr]][axis]) {
                C[Cctr++] = args[Actr++];
            } else if (arr[args[Actr]][axis] > arr[args[Bctr]][axis]) {
                C[Cctr++] = args[Bctr++];
            } else {
                unsigned int next_axis = (axis == dim - 1)? 0 : (axis + 1);
                while (arr[args[Actr]][next_axis] == arr[args[Bctr]][next_axis]) {
                    next_axis = (next_axis == dim - 1)? 0 : (next_axis + 1);
                }
                if (arr[args[Actr]][next_axis] < arr[args[Bctr]][next_axis]) {
                    C[Cctr++] = args[Actr++];
                } else {
                    C[Cctr++] = args[Bctr++];
                }
            }
        }
        for (; Actr <= pivot;) {
            C[Cctr++] = args[Actr++];
        }
        for (; Bctr <= right;) {
            C[Cctr++] = args[Bctr++];
        }
        for (unsigned int i = left; i <= right; ++i) {
            args[i] = C[i - left];
        }
    }
}

vector<vector<unsigned int> > KDTree::argsort() {
    vector<vector<unsigned int> > argsorts;
    for (unsigned int i = 0; i < dim; ++i) {
        vector<unsigned int> args;
        for (unsigned int j = 0; j < num_samples; ++j) {
            args.emplace_back(j);
        }
        mergesort(Datas, args, i, 0, num_samples - 1);
        argsorts.emplace_back(args);
    }
    return argsorts;
}