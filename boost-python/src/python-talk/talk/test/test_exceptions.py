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
from .. import functions
from .exceptions_test_module import throw_division_by_zero
from .exceptions_test_module import throw_talk_error

class exceptions_test(unittest.TestCase):

    def test_division_by_zero(self):
        self.assertRaises(ZeroDivisionError,throw_division_by_zero)

    def test_talk_error(self):
        self.assertRaises(functions.TalkError,throw_talk_error)

