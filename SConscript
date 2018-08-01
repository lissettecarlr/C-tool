
from building import *

cwd     = GetCurrentDir()
src = Glob('src/*.c') 
CPPPATH = [cwd + '/include']

group = DefineGroup('software_tool', src, depend = ['PKG_USING_SOFTWARE_TOOL'], CPPPATH = CPPPATH)

Return('group')
