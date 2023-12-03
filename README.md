# [Advent Of Code 2023](https://adventofcode.com/2023)

Hello and welcome to my git repository for Advent of Code 2023! To add an extra challenge for myself,
I decided to randomly pick a language for each day. This gets me out of my comfort zone and forces me
to learn a new language every now and then.

### [Day 1: trebuchet?!](https://adventofcode.com/2023/day/1) - C++
C++ was a language I had used before, but I had to take a little time just to
refresh my knowledge. I decided that regex would provide a simple solution to 
part one, however on part 2 it was a little more difficult to figure out the
right pattern. One case which caused the most headache was trying to locate the
last occurrence of a written number when it was overlapped with another number,
like so:

abc123oneightple

My initial regex solutions would match the "one", and miss the "eight". Because
I was basically a novice at regex, I needed to do some research. I discovered that
a regex search will, by default, consume characters as it searches a string. I
modified my pattern slightly to avoid this issue, and then it worked perfectly.

### [Day 2: Cube Conundrum](https://adventofcode.com/2023/day/2) - Bash
