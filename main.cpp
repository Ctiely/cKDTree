#include <iostream>
#include "src/KDTree.h"
using namespace std;

int main() {
    vector<vector<double> > datas = {{2, 3, 3}, {5, 4, 2}, {9, 6, 7}, {4, 7, 9}, {8, 1, 5},
                                     {7, 2, 6}, {9, 4, 1}, {8, 4, 2}, {9, 7, 8}, {6, 3, 1},
                                     {3, 4, 5}, {1, 6, 8}, {9, 5, 3}, {2, 1, 3}, {8, 7, 6}};

    KDTree tree(3);
    tree.build_tree(datas);
    /*
    vector<vector<unsigned int> > argsort = tree.argsort();
    for (int i = 0; i < argsort.size(); ++i) {
        for (int j = 0; j < argsort[i].size(); ++j) {
            cout << argsort[i][j] << " ";
        }
        cout << endl;
    }
     */
    return 0;
}