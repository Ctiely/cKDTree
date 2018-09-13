#include <iostream>
#include "src/KDTree.h"
using namespace std;

void test_variance() {
    vector<vector<double> > datas1 = {{2, 3, 3}, {5, 4, 2}, {9, 6, 7}, {4, 7, 9}, {8, 1, 5},
                                      {7, 2, 6}, {9, 4, 1}, {8, 4, 2}, {9, 7, 8}, {6, 3, 1},
                                      {3, 4, 5}, {1, 6, 8}, {9, 5, 3}, {2, 1, 3}, {8, 7, 6}};
    cout << utils::variance<double>(datas1, 0) << endl;
    cout << utils::variance<double>(datas1, 1) << endl;
    cout << utils::variance<double>(datas1, 2) << endl;
    vector<vector<double> > datas3 = {{-6.88, -5.40}, {-2.96, -0.50}, {7.75, -22.68}, {17.05, -12.79}, {6.27, 5.50}, {10.80, -5.03},
                                     {1.24, -2.86}, {-4.60, -10.55}, {-4.96, 12.61}, {1.75, 12.26}, {15.31, -13.16}, {7.83, 15.70}, {14.63, -0.35}};
    cout << utils::variance<double>(datas3, 0) << endl;
    cout << utils::variance<double>(datas3, 1) << endl;
}

void test1() {
    vector<vector<double> > datas1 = {{2, 3, 3}, {5, 4, 2}, {9, 6, 7}, {4, 7, 9}, {8, 1, 5},
                                      {7, 2, 6}, {9, 4, 1}, {8, 4, 2}, {9, 7, 8}, {6, 3, 1},
                                      {3, 4, 5}, {1, 6, 8}, {9, 5, 3}, {2, 1, 3}, {8, 7, 6}};
    KDTree tree1(3);
    tree1.build(datas1);
    /*
    vector<vector<unsigned int> > argsort = tree1.argsort();
    for (int i = 0; i < argsort.size(); ++i) {
        for (int j = 0; j < argsort[i].size(); ++j) {
            cout << argsort[i][j] << " ";
        }
        cout << endl;
    }
     */
    tree1.render();
    cout << tree1.depth() << endl;
}

void test2() {
    vector<vector<double> > datas2 = {{2, 3}, {5, 4}, {9, 6}, {4, 7}, {8, 1}, {7, 2}};
    KDTree tree2(2);
    tree2.build(datas2);
    tree2.render();

    vector<double> data = {7, 3};
    unordered_map<unsigned int, double> query_result = tree2.query(data, 4);
    for (const auto & query : query_result) {
        cout << "key " << query.first << " " << "value " << query.second << endl;
    }
    cout << tree2.depth() << endl;
}

void test_heap() {
    vector<int> ivec;
    make_heap(ivec.begin(), ivec.end());
    ivec.emplace_back(10);
    ivec.emplace_back(100);
    push_heap(ivec.begin(), ivec.end());
    pop_heap(ivec.begin(), ivec.end());
    ivec.pop_back();
    cout << ivec[0] << ivec.size() << endl;
}

void test3() {
    vector<vector<double> > data3 = {{-6.88, -5.40}, {-2.96, -0.50}, {7.75, -22.68}, {17.05, -12.79}, {6.27, 5.50}, {10.80, -5.03},
                                     {1.24, -2.86}, {-4.60, -10.55}, {-4.96, 12.61}, {1.75, 12.26}, {15.31, -13.16}, {7.83, 15.70}, {14.63, -0.35}};
    KDTree tree(2);
    tree.build(data3);
    tree.render();
    vector<double> data = {-1, -5};
    unordered_map<unsigned int, double> query_result = tree.query(data, 6);
    for (const auto & query : query_result) {
        cout << "key " << query.first << " " << "value " << query.second << endl;
    }
    pair<unsigned int, double> query = tree.query(data);
    cout << query.first << " " << query.second;
    cout << endl;
    cout << tree.depth() << endl;
}

void test4() {
    vector<vector<double> > data3 = {{-6.88, -5.40}, {-2.96, -0.50}, {7.75, -22.68}, {17.05, -12.79}, {6.27, 5.50}, {10.80, -5.03},
                                     {1.24, -2.86}, {-4.60, -10.55}, {-4.96, 12.61}, {1.75, 12.26}, {15.31, -13.16}, {7.83, 15.70}, {14.63, -0.35}};
    KDTree tree(2);
    tree.build(data3);
    vector<double> data = {-1, -5};
    unordered_map<unsigned int, double> query_result = tree.query_distance(data, 13);
    for (const auto & query : query_result) {
        cout << "key " << query.first << " " << "value " << query.second << endl;
    }
    cout << endl;
}
int main() {
    cout << "test variance: " << endl;
    test_variance();
    cout << endl;
    cout << "test1: " << endl;
    test1();
    cout << endl;
    cout << "test2: " << endl;
    test2();
    cout << endl;
    cout << "test heap " << endl;
    test_heap();
    cout << endl;
    cout << "test3: " << endl;
    test3();
    cout << endl;
    cout << "test4: " << endl;
    test4();
    return 0;
}

