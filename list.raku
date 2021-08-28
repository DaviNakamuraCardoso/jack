#! /usr/bin/rakudo

# Loops searching for songs

sub MAIN (
    Str :$path = "$*HOME/Music",
    Str :$grep = "", #= Pattern in name
    Bool :$remove = False,
    Str :$move = ""
) returns int
{
    my IO::Path @list = listall($path);
    my IO::Path @matches = @list.grep({ .Str.contains: $grep; });

    loop (my int $i = 0; $i < @matches.elems; $i++) { say "($i) @matches[$i]"; }

    my &handler;
    my $info = "";
    if ($remove) { &handler = &deletematch; }
    unless ($move eq "") { &handler = &movematch; $info = $move; }

    if (&handler) { commandhandler(@matches, &handler, $info);}
    return 0;
}

my sub commandhandler(
    IO::Path @matches,
    &handler,
    Str $info
) returns int
{
    for lines() {
        given ($_)
        {
            when "q" { exit; }
            when "a" { for @matches -> $match { &handler($match, $info); } }
            default {
                &handler(@matches[$_.Int], $info);
            }
        }
    }

}

my sub deletematch(IO::Path $match, Str $info)
{
    say "Removing $match";
    $match.unlink;
    return;
}

my sub movematch(IO::Path $match, Str $info)
{
    my $filename = $match.basename;
    my IO::Path $path = IO::Path.new("$*HOME/Music/$info/");

    # Check if the path exists
    unless ($path.e)
    {
        mkdir($path);
        say "Creating path $path";
    }
    say "Moving $match to $path";
    unless ($match eq $path.add($filename))
    {
        $match.move($path.add($filename));
    }
    return;

}

my sub listall($dir) returns Array[IO::Path]
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
