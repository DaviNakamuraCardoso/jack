
# Loops searching for songs

sub MAIN($dir = "/home/davi/Music") 
{
    
    my @dirents = $dir.IO;
    while (@dirents)
    {
        for (@dirents.pop.dir) -> $path 
        {
            say "\"$path\",0" if ($path.extension eq "mp3");
            @dirents.push: $path if $path.d;
        }
    }
}




