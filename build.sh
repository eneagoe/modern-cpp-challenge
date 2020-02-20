#!/usr/bin/env bash

set -e

if [ $# -gt 0 ]
then
  g++ -pipe -O2 -std=c++17 -Wno-unused-result -Wall $1
fi
