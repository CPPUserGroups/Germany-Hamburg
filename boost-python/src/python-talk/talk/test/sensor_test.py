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
from talk import Sensor

class sensor_test(unittest.TestCase):

    def test_default_construction(self):
        s = Sensor()
        self.assertAlmostEqual(s.value,0.0,8)

    def test_construction(self):
        s = Sensor(-234.23)
        self.assertAlmostEqual(s.value,-234.23)

    def test_set_value(self):
        s = Sensor()
        s.set_value(0.3)
        self.assertAlmostEqual(s.get_value(),0.3,8)

    def test_value_property(self):
        s = Sensor()
        s.value = 40.23
        self.assertAlmostEqual(s.value,40.23,8)
