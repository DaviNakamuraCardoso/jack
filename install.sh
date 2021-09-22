#! /bin/env bash

cd compiler && make
cp dcc /usr/bin/ 
cd ../jackvm
make
cp jackvm /usr/bin/jack
cd ..

