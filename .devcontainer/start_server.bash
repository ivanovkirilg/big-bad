#!/bin/env bash

python3 -m http.server -d $TEST_OUTPUT_DIR > /tmp/server.out 2> /tmp/server.err & disown

echo View Robot test results here: http://0.0.0.0:8000/
echo which points to build/test_output
