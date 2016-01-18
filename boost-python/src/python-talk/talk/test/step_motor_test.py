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
from talk import StepMotor

class step_motor_test(unittest.TestCase):

    def test_default_construction(self):
        m = StepMotor()
        self.assertAlmostEqual(m.upper_limit,0.0,8)
        self.assertAlmostEqual(m.lower_limit,0.0,8)
        self.assertAlmostEqual(m.position,0.0,8)
        self.assertAlmostEqual(m.step_size,0.0,8)

    def test_construction(self):
        m = StepMotor(0.001,23.44,-90.0,90.0)

        self.assertAlmostEqual(m.upper_limit,90.0)
        self.assertAlmostEqual(m.lower_limit,-90.0)
        self.assertAlmostEqual(m.position,23.44,8)
        self.assertAlmostEqual(m.step_size,0.001,8)

    def test_set_position(self):
        m = StepMotor(0.001,23.44,-90.0,90.0)
        m.position = 33.456
        self.assertAlmostEqual(m.position,33.456,8)
