# brailify

**brailify** takes images and prints out an approximation of them using characters from the Unicode [Braille Patterns](https://unicode-table.com/en/blocks/braille-patterns/) block.

Usage:

    brailify [options] <path> [path2 [path3...]]
    
Options:

    -i, --invert          Inverts the source image, for use on a terminal with a light background.
    -n, --nodither        Disables dithering, ideal if your source image is pure black-and-white.
    -w, --width <width>   Specifies the output width in chars, useful if your source image is quite large.

Example usage:

    $ brailify -i test-images/kappa.png 
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡠⣸⣤⣨⡠⣢⣢⣠⣠⡠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⡠⠨⢪⡺⡨⠫⠺⠫⡺⡻⡪⣺⣺⡺⠪⣨⣠⡀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠠⡪⡠⠪⡨⡪⣠⡺⣨⣾⣪⣿⣾⣿⣺⣫⣾⣻⣾⣿⣦⡀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠨⠨⠪⣨⣺⣪⣪⣾⣺⣾⣻⣾⣻⣺⡻⡺⡻⣾⣾⣿⣿⣿⡃⠀⠀⠀⠀
    ⠀⠀⠀⠀⢠⣪⣨⣺⣾⣺⣾⣿⣾⡻⣿⡻⡪⠪⠨⠨⠨⠨⠨⠻⣺⣿⣿⡿⠀⠀⠀⠀
    ⠀⠀⠀⠀⢸⣻⣺⣿⣾⣿⣾⣿⡺⡺⠪⠪⠨⠈⠀⠈⠠⠨⠠⠨⡨⡻⣿⡯⠀⠀⠀⠀
    ⠀⠀⠀⠀⠸⣻⣾⣿⣾⣻⡨⠺⠪⠈⠠⠈⠀⠀⠠⠈⠠⠈⠨⠨⠨⠪⣺⡯⠀⠀⠀⠀
    ⠀⠀⠀⠀⠈⣿⣾⣿⣾⡻⠈⠈⠀⠈⠀⣨⣠⣨⡠⠨⠠⡨⣠⣪⣨⣪⣸⡏⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⡨⡻⣿⡪⠀⠀⠨⠠⡺⡮⡾⡺⡺⠪⠊⠨⣺⣾⣿⣺⡿⡪⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠈⠠⠪⠪⠈⠀⠀⠀⠈⠈⠊⠨⠊⠀⠈⠀⠸⡪⠺⠪⠪⠨⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠈⠈⠈⠀⠈⠀⠈⠀⠀⠀⠈⠀⠀⠀⠈⠀⠈⡪⡨⠠⠨⣨⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠈⠀⠈⠀⠈⠠⠨⠠⠨⠨⠈⠺⠺⣠⣪⡪⡪⡪⡺⡪⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠈⠠⠈⠠⠈⠀⠈⠨⠨⣠⡨⣨⣨⣪⣺⣪⡪⠨⡪⡊⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨⠠⡨⠠⠨⡠⠈⠀⠈⠠⡨⡨⡪⡨⡪⣪⠚⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠪⠪⡨⠨⠠⠈⠨⠪⠨⠪⠨⡺⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠊⠪⡪⡠⡪⡪⠺⠺⠊⠀⠀⠀⠀⠀⠀⠀⠀
