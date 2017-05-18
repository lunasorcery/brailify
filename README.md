# Brailify

Brailify takes images and spits out an approximation of them using Unicode braille characters (U+2800 - U+28FF)

Usage:

    brailify [OPTIONS] file
    
Options:

    --invert : inverts the source image, for use on a terminal with a light background.
    --nodither : disables dithering, ideal if your source image is pure black-and-white.

Example output:

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


