#! /usr/bin/perl -w

use v5.14;

my $file = $ARGV[0];

say $file;

my $str = `cat $file`;
$str =~ s/  /\t/g;

say $str;

open (F, '>', $file);

print F $str;
