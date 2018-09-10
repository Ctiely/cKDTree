//
// Created by Clytie on 2018/9/10.
//

#ifndef CKDTREE_KDTREE_H
#define CKDTREE_KDTREE_H

#include <map>
#include <vector>
#include <utility>
using namespace std;

class KDTree {
public:
    explicit KDTree(int dim)
            : dim(dim), num_samples(0), Datas(), root(nullptr) {}
    ~KDTree() = default;

    void build_tree(vector<vector<double> > & datas);
    unsigned int depth();
    map<unsigned long, double> query(vector<double> & data, unsigned int n);
    map<unsigned long, double> query(vector<double> & data, double distance);
    pair<unsigned long, double> query(vector<double> & data);

    int dim; // number of features
    unsigned int num_samples; // number of samples
    vector<vector<double> > Datas;

private:
    struct KDTreeNode {
        explicit KDTreeNode(size_t index,
                   unsigned int split_axis,
                   KDTreeNode * parent=nullptr,
                   KDTreeNode * left=nullptr,
                   KDTreeNode * right=nullptr)
                : index(index), split_axis(split_axis), parent(parent), left(left), right(right) {}

        size_t index;
        unsigned int split_axis;
        KDTreeNode * parent;
        KDTreeNode * left;
        KDTreeNode * right;
    };

    KDTreeNode * root;
    int depth(KDTreeNode * node);
    void mergesort(vector<vector<double> > & arr, vector<unsigned int> & args, unsigned int axis, unsigned int left, unsigned int right);
    vector<vector<unsigned int> > argsort();

};


#endif //CKDTREE_KDTREE_H
