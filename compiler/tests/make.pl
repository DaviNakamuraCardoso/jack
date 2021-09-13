#! /usr/bin/perl -w

use v5.14;

my $var = $ARGV[0] || "hello";
my $path = $ARGV[1] || "T";
my $path_header = $ARGV[2] || "TH";
my $path_source = $ARGV[3] || "TS"; 

my $make_objects = "
# Test the $var
\$(O)\$($path)test_$var.o: \$(S)\$($path)test_$var.c
	gcc -I\$($path_header) -c \$(S)\$($path)test_$var.c -o \$(O)\$($path)test_$var.o

# Get the $var module
\$(O)\$($path)test_module_$var.o: \$($path_source)\$($path)$var.c
	gcc -I\$($path_header) -c \$($path_source)\$($path)$var.c -o \$(O)\$($path)test_module_$var.o
";

my $make_archive = "
    \$(O)\$($path)test_$var.o \$(O)\$($path)test_module_$var.o
";


say $make_objects;
say $make_archive;
