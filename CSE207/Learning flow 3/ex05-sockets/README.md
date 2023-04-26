### Explanation


We have the following files here:
- `url.c` - a simple URL parser
- `wgetX.c` - a simple wget implementation
- `makefile` - a makefile to compile the code


### Compilation

To compile the code, simply run `make` in the directory. This will create the executable `wgetX`.

### Usage

To use the program, simply run `./wgetX <url>`. The program will download the file at the given URL and save it in the current directory.

### Example

To download the file at `http://www.google.com`, simply run `./wgetX http://www.google.com`. This will download the file and save it as `index.html` in the current directory.

### Notes

- The program does not support HTTPS URLs.