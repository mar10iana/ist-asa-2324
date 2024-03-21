# ASA 2023/2024 - Project 1

**Achievement**: This project was awarded a grade of 19,5 out of 20.

## Overview

This project is part of the Analysis and Synthesis of Algorithms course at Instituto Superior Técnico for the 2023/2024 academic year. The goal is to develop an algorithm that optimizes the cutting process of marble slabs at the SuperMarble factory, to maximize the value obtained from each slab by producing pieces with dimensions requested by clients.

### Input Specifications

- The first line contains two positive integers `X` and `Y`, separated by a space, representing the dimensions of the marble slab.
- The second line contains a single positive integer `n`, representing the number of types of pieces that can be produced.
- The following `n` lines describe each type of piece that can be produced, with each line containing three positive integers `ai`, `bi`, and `pi`, separated by spaces, where `ai × bi` are the dimensions of the piece type, and `pi` is the price.

### Output Specifications

- The program should output the maximum value that can be obtained from the given slab. If no pieces can be produced, the output should be `0`.
