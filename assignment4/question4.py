import hashlib

PASSWORD = "CPEN442isAwesome"

original = open('34095117.program2.exe').read()
modified = original.replace("\xB4\xBF\x63\x8B\xE6\x4E\xAA\x3C\x79\xFB\xE2\x16\x86\x45\x62\x2C\x09\x8D\x86\x6E", hashlib.sha1(PASSWORD).digest())
open('34095117.program2.exe', 'wb').write(modified)