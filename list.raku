#! /usr/bin/rakudo

# Loops searching for songs

subset pat of Str; 

sub MAIN (
    Str :$grep = "", #= Pattern in name 
    Bool :$remove = False
) returns int
{
    my IO::Path @list = listall;  
    my IO::Path @matches = @list.grep({ .Str.contains: $grep; }); 

    loop (my int $i = 0; $i < @matches.elems; $i++) { say "($i) @matches[$i]"; }
    
    if ($remove) {
        for lines() {
            given ($_)
            {
                when "q" { exit; }
                when "a" { for @matches -> $match { $match.unlink; } }
                default {   

                    say "Removing " ~ $_.Int; 
                    @matches[$_.Int].unlink;
                }
            }
        }
    } 
    
    return 0; 
}

my sub listall($dir = "$*HOME/Music") returns Array[IO::Path]
{
    my @dirents = $dir.IO;
    my IO::Path @songs = (); 

    while (@dirents)
    {
        for (@dirents.pop.dir) -> $path 
        {
            @songs.push: $path if ($path.extension eq "mp3");
            @dirents.push: $path if $path.d;
        }
    }

    return @songs;  
}


