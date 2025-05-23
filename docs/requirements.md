# Voodoo
`voodoo` is a program that prints out a text file with optional transformations.

---


## Functional requirements

- **`REQ-FN-01`**
  Voodoo shall be able to output the content of an ASCII-containing file.

- **`REQ-FN-02`**
  Voodoo shall be able to transform all alphabet characters to uppercase.

- **`REQ-FN-03`**
  Voodoo shall be able to transform all alphabet characters to lowercase.

- **`REQ-FN-04`**
  Voodoo shall be able to limit the width of each line of its output
  to a specified maximum number of characters.


## Interface Requirements

- **`REQ-IF-01`**
  Voodoo shall accept as a required argument the file to be processed.
  - Exception: `REQ-IF-03`

- **`REQ-IF-02`**
  Voodoo shall accept the following optional arguments:
  - `-U` or `--upper`: print in UPPERCASE (`REQ-FN-02`),
  - `-l` or `--lower`: print in lowercase (`REQ-FN-03`),
  - `-w WIDTH` or `--width WIDTH`: maximum line width (`REQ-FN-04`).

- **`REQ-IF-03`**
  Voodoo shall, if given argument `--argfile ARGFILE`,
  read all other arguments from the `ARGFILE`.
