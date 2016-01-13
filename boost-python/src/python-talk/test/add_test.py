#
# (c) Copyright 2016 Eugen Wintersberger <eugen.wintersberger@gmail.com>
#
# This file is part of python-talk.
#
# python-talk is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# python-talk is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with python-talk.  If not, see <http://www.gnu.org/licenses/>.
# 
# ===========================================================================

import unittest
from talk import add

class add_test(unittest.TestCase):
    def test_add_double(self):
        result = add(4.0,2.0)
        self.assertAlmostEqual(result,6.,places=8)
        self.assertTrue(isinstance(result,float))
        
        result = add(-4.0,2.0)
        self.assertAlmostEqual(result,-2.,places=8)
        self.assertTrue(isinstance(result,float))

        result = add(4.0,-2.0)
        self.assertAlmostEqual(result,2.,places=8)
        self.assertTrue(isinstance(result,float))

    def test_add_integer(self):
        result = add(4,2)
        self.assertEqual(result,6)
        self.assertTrue(isinstance(result,int))

        result = add(-4,2)
        self.assertEqual(result,-2)
        self.assertTrue(isinstance(result,int))

        result = add(4,-2)
        self.assertEqual(result,2)
        self.assertTrue(isinstance(result,int))
