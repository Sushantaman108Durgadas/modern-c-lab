# 4-Digit 7-Segment Display Multiplexing

A 4-digit 7-segment display implementation originally developed
as a Semester 4 embedded systems assignment.

The project was later revisited while studying C/C++ concepts,
particularly structures and function pointers.

## Hardware Representation

The system consists of:

- 4 digit-selection pins
- 8 shared segment pins
- A 10 × 8 digit lookup table

```text
                 8 Shared Segment Lines
              ┌─────────────────────────┐
              │                         │
           Digit 1                   Digit 4
           Select                    Select
              │                         │
              └────── Multiplexing ─────┘

Version 1 — Original

The original implementation uses:

Structures
Arrays of structures
2D arrays
Lookup tables
Loops
Multiplexing

The four display-selection pins and shared segment pins are
initialized programmatically.

Version 2 — Function Pointer Refactor

The original implementation was revisited after learning
function pointers.

A function-pointer member was introduced into Segment:

int (*call_back)(int);

Functions are assigned to the pointer and invoked through it:

segment[i].call_back = set_select_pin;
segment[i].pin = segment[i].call_back(i);

The function pointer is then reused for segment-pin mapping.
```
## Background

This project was originally written approximately two years ago
as a Semester 4 embedded systems assignment.

I revisited the implementation while studying Modern C/C++ to
understand how my design and programming approach has evolved.

### Original Implementation

The original version demonstrates my approach at the time:

- Structures
- Arrays
- Lookup tables
- Multiplexing
- Programmatic pin configuration

### Refactoring Experiment

The second version was written recently as an experiment in applying
function pointers to the original design.

The goal was not simply to make the code shorter, but to explore
how function pointers can introduce configurable behaviour and
indirection.

### Reflection

The exercise also showed me that abstraction is not automatically
better. For fixed relationships, the original direct implementation
can be clearer.

This project is therefore kept as a before/after comparison of my
programming evolution.
