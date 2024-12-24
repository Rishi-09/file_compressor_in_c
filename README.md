The code you provided is a complete implementation of a file compressor and decompressor using the Run-Length Encoding (RLE) algorithm in C. Here's a detailed explanation of how it works, usage instructions, and improvements you can consider.

How the Code Works

  Compression (RLE):
      Reads the input file character by character.
      Counts consecutive occurrences of a character.
      Writes the character and its count to the output file (e.g., AAA becomes A3).

  Decompression:
      Reads character and count pairs from the compressed file.
      Expands each pair back into the original sequence (e.g., A3 becomes AAA).

  Command-Line Arguments:
      The program takes three arguments:
          Operation: compress or decompress.
          Input file path.
          Output file path.

  File Handling:
      Uses standard file I/O functions to open, read, write, and close files.
      Handles empty files by checking for EOF.
How to Use

  Compile the Code:

    gcc -o file_compressor file_compressor.c

  Compress a File:

    ./file_compressor compress input.txt compressed.txt

  Decompress a File:

    ./file_compressor decompress compressed.txt output.txt

  Error Messages:

  Displays errors if the input file doesn’t exist or if the wrong arguments are provided.
Example

  Input File (input.txt):

    AAAABBBCCDAA

  Compressed File (compressed.txt):

    A4B3C2D1A2
  
  Decompressed File (output.txt):

    AAAABBBCCDAA
