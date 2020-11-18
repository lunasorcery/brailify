# brailify

**brailify** takes images and prints an approximation using characters from the Unicode [Braille Patterns](https://unicode-table.com/en/blocks/braille-patterns/) block.

## Building & Installing

On macOS and Linux, it _should_ be as simple as running the following inside the `brailify` directory:

```
make && make install
```

Windows is not _officially_ supported, but it'll likely work under WSL.

## Options:

    -i, --invert            Inverts the image, for use with dark text on a light background.
    -w, --width <width>     Sets the output width in chars, useful for large inputs.
    -t, --threshold <value> Uses a harsh black/white cutoff in the 0-255 range.

Example usage:

    $ brailify smile.png -w 28 -t 128
    ⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣶⣿⣿⣿⣿⣶⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀
    ⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠀⠀
    ⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀
    ⢀⣾⣿⣿⣿⣿⣿⡟⠁⠀⠈⣿⣿⣿⣿⣿⣿⠁⠀⠈⢻⣿⣿⣿⣿⣿⣷⡀
    ⢸⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⡇
    ⣿⣿⣿⣿⣿⣿⣿⣿⣦⣤⣴⣿⣿⣿⣿⣿⣿⣦⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⣿⣿⣿⣿⣿⣿
    ⢸⣿⣿⣿⣿⡇⠀⢤⣀⣀⣀⣉⡉⠉⠉⢉⣉⣀⣀⣀⡤⠀⢸⣿⣿⣿⣿⡇
    ⠈⢿⣿⣿⣿⣷⡀⠀⠙⠿⢿⣿⣿⣿⣿⣿⣿⡿⠿⠋⠀⢀⣾⣿⣿⣿⡿⠁
    ⠀⠈⢿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠈⠉⠉⠁⠀⠀⠀⠀⣠⣾⣿⣿⣿⡿⠁⠀
    ⠀⠀⠀⠻⣿⣿⣿⣿⣷⣤⣀⡀⠀⠀⠀⠀⢀⣀⣤⣾⣿⣿⣿⣿⠟⠀⠀⠀
    ⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⠿⣿⣿⣿⣿⠿⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀
