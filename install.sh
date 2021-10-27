#! /bin/env bash


if [ "$(id -u)" != 0 ]; then
    echo "You must run this script with root privileges. Try 'sudo ./install.sh'"
    exit 1
fi

cd compiler && make
cp dcc /usr/bin/ 
cd ../jackvm
make
cp jackvm /usr/bin/jack
cd ..

