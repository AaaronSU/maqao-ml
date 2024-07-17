import cProfile
import re
cProfile.run('re.compile("foo|bar")', 'restats')

import pstats
from pstats import SortKey
p = pstats.Stats('restats')
p.strip_dirs().sort_stats(-1).print_stats()