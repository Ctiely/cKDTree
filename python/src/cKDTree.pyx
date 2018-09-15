from libcpp.vector cimport vector
from libcpp.unordered_map cimport unordered_map
from libcpp.utility cimport pair
import logging
import numpy as np


logging.basicConfig(level=logging.DEBUG,
                    format='%(asctime)s %(levelname)s %(message)s',
                    datefmt='%a, %d %b %Y %H:%M:%S')

cdef extern from "../../src/KDTree.h":
    cdef cppclass KDTree:
        KDTree(unsigned int dim);

        unsigned int dim; # number of features
        unsigned int num_samples; # number of samples
        vector[vector[double]] Datas;

        void build(vector[vector[double]] & datas);
        unsigned int depth();
        void render();
        unordered_map[unsigned int, double] query(vector[double] & data, unsigned int k);
        unordered_map[unsigned int, double] query_distance(vector[double] & data, double dist);
        pair[unsigned int, double] query(vector[double] & data);

cdef class cKDTree:
    """
    This class wraps a class implemented by c++.
    k-d trees are a useful data structure for several applications, such as searches involving a multidimensional search key.
    @params:
        - dim:                  unsigned int. number of dimension.
    """
    cdef KDTree * _thisptr

    def __cinit__(self, int dim):
        self._thisptr = new KDTree(dim)

        if self._thisptr == NULL:
            raise MemoryError()

    def __dealloc__(self):
        if self._thisptr != NULL:
            del self._thisptr

    @property
    def dim(self):
        return self._thisptr.dim

    @property
    def depth(self):
        return self._thisptr.depth()

    @property
    def num_samples(self):
        if self.depth:
            return self._thisptr.num_samples
        else:
            return 0

    @property
    def data(self):
        return self._thisptr.Datas

    def build(self, datas):
        datas = np.asarray(datas, dtype=np.double)
        assert(datas.ndim == 2)
        self._thisptr.build(datas)

    def render(self):
        self._thisptr.render()

    def query(self, data, k):
        k = int(k)
        return self._thisptr.query(data, k)

    def query_distance(self, data, distance):
        return self._thisptr.query_distance(data, distance)

    def query_nearest(self, data):
        return self._thisptr.query(data)

