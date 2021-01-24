 #!/bin/bash

rsync --human-readable --progress --ignore-existing --recursive  ~/.leetcode/ ./algo_probs/
