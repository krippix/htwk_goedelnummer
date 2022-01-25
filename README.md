# 22 Gödelnummer

# Implemented features
- [x] Parsing prime numbers
- [x] Checking file for errors
- [x] converting userinput to Gödel number
- [x] Detecting when Gödel number overflows

## Error codes
Error Codes are implemented to be similar to HTTP:

- 404: File not found
- 416: Number is out of range
- 418: I'm a teapot
- 422: File contains unprocessable char

## Limitations
- Integers within the formula cannot be larger than 4,294,967,295 as conversion would fail
- But we cant get to this point either, as the file only contains around 9.000 prime numbers
- And due to the way Godel numbers are calculated, the result itself would overflow first
- Only the variables 'a' and 'b' are implemented