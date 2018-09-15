import cKDTree
import numpy as np
from scipy.spatial import cKDTree as scipyKDTree


def test_unique():
    n = 1024
    #test k-nearest neighbors
    for dim in range(1, 8):
        data = np.random.rand(n, dim)
        data_unique = np.unique(data, axis=1)

        query_data = np.random.rand(dim)
        mkdtree = cKDTree.cKDTree(dim)
        mkdtree.build(data_unique.copy())
        query = mkdtree.query(query_data, 10)

        kdtree = scipyKDTree(data_unique, leafsize=1)

        dist, index = kdtree.query(query_data, 10)
        result = dict(zip(index, dist))
        assert(query == result)

    #test distance smaller than dist
    for dim in range(1, 8):
        data = np.random.rand(n, dim)
        data_unique = np.unique(data, axis=1)

        dist = np.random.rand() / 4

        query_data = np.random.rand(dim)
        mkdtree = cKDTree.cKDTree(dim)
        mkdtree.build(data_unique.copy())
        query = list(mkdtree.query_distance(query_data, dist).keys())

        kdtree = scipyKDTree(data_unique, leafsize=1)

        result = kdtree.query_ball_point(query_data, dist)
        result.sort()
        assert(query == result)

    for dim in range(1, 8):
        data = np.random.rand(n, dim)
        data_unique = np.unique(data, axis=1)

        query_data = np.random.rand(dim)
        mkdtree = cKDTree.cKDTree(dim)
        mkdtree.build(data_unique.copy())
        query = mkdtree.query_nearest(query_data)[0]

        kdtree = scipyKDTree(data_unique, leafsize=1)

        result = kdtree.query(query_data, 1)[1]

        assert(query == result)