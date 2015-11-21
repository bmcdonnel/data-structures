#!/bin/bash

mkdir -p build
pushd build
cmake -GNinja .. && ninja
popd
