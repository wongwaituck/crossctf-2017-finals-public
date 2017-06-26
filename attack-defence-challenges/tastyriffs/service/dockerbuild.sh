#!/bin/bash

python -c 'import random;print str(random.getrandbits(128))' > picpic
docker build -t tastyriffs .
