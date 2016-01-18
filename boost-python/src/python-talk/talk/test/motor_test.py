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
from talk import Motor

class sensor_test(unittest.TestCase):

    def test_default_construction(self):
        s = Motor()
        self.assertAlmostEqual(s.upper_limit,0.0,8)
        self.assertAlmostEqual(s.lower_limit,0.0,8)

    def test_construction(self):
        s = Motor(-90.0,90.0)
        self.assertAlmostEqual(s.upper_limit,90.0)
        self.assertAlmostEqual(s.lower_limit,-90.0)

    def test_set_upper_limit(self):
        s = Motor()
        s.upper_limit = 230.0
        self.assertAlmostEqual(s.upper_limit,230.0,8)

    def test_set_lower_limit(self):
        s = Motor()
        s.lower_limit = 10.34
        self.assertAlmostEqual(s.lower_limit,10.34,8)
