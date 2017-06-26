#!/usr/bin/python

import random

file("/picpic", "w").write(str(random.getrandbits(128)))
