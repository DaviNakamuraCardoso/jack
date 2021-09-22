#! /bin/env bash

cd compiler && make
cp dcc ../
cd ../jackvm
make
cp jackvm ../jack
cd ..
