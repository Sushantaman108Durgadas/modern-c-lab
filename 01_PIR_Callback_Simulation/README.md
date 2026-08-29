# PIR Callback Simulation

A small C program that simulates PIR sensor behaviour using
function pointers and callback functions.

## Concepts Used

- Structures
- typedef
- Nested structures
- Function pointers
- Callback functions
- Conditional callback registration
- Return values

## Working

The program asks the user to simulate either:

- Motion detected
- No motion detected

Based on the input, the corresponding callback is registered
with the simulated PIR sensor.

```text
User Input
    ↓
Select Callback
    ↓
PIR.callback_sensor
    ↓
Callback Execution
    ↓
Detection Result
