import math
import random

import unittest

class Hashmap(object):
    """Universal hash map
    
    Hash function is like this:
    h(i) = trunc(m * (phi * i mod 1))

    where m is 2 powered by random number, and phi is golden ratio.

    This hashmap satisfies the following properties:
        * universal (no worse-case scenarios with same data set)
        * in case of no collisions, takes up to `size` items in array
    """

    phi = (math.sqrt(5) - 1) / 2

    @staticmethod
    def _radix(key):
        """Return radix-encoded key"""

        return sum([ord(k) * (128**i) for i, k in enumerate(str(key))])

    def hash(self, key):
        """Hash a key.
        
        Returns integer, index in the hash.
        """
        ikey = self._radix(key) 
        mod1, _ = math.modf(self.phi * ikey) # take the fraction of phi*ikey
        return math.trunc(self._m * mod1) % self._size

    def __init__(self, size):
        self._m = 2**random.uniform(math.log(size)*2, math.log(size)*9)
        self._size = size
        self._map = [[] for i in range(size)]

    def put(self, key, value):
        """Put to hashmap. Do not check if the value exists."""
        self._map[self.hash(key)].append((key, value))

    def get(self, key):
        for k, v in self._map[self.hash(key)]:
            if k == key:
                return v
        raise KeyError

class TestSimpleHashMap(unittest.TestCase):

    def setUp(self):
        self.h = Hashmap(20)

    def test_na(self):
        self.assertRaises(KeyError, lambda: self.h.get("yoda"))

    def test_simple_get(self):
        self.h.put("labas", "rytas")
        self.h.put("siaip sau", "vakaras")
        self.assertEqual("rytas", self.h.get("labas"))
        self.assertEqual("vakaras", self.h.get("siaip sau"))

if __name__ == '__main__':
    unittest.main()
