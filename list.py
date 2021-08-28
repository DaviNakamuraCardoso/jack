
from sys import exit, argv;
from os import listdir;
from os.path import isdir;

def main(argv) -> int:

    paths: str = getsongs("./");
    return 0;

def getsongs(path: str) -> list:

    songs: str = list();
    paths: str = [path];

    while (len(paths) > 0):
        for path in listdir(path):
        if (isdir(path)):
            paths.push(path);

    return songs;


if __name__ == "__main__":
    exit(main(argv));
