# UTF-8 Validation

This project implements a Python function that checks whether a list of integers
represents a valid UTF-8 encoded byte sequence.

## Description

In UTF-8, a character can use 1 to 4 bytes. This project validates a stream of
integers (each intended to represent one byte) and returns whether the stream
follows UTF-8 encoding rules.

The implementation is in:

- `0-validate_utf8.py`

## Requirements

- OS: Ubuntu 20.04 LTS
- Python: 3.4.3
- Style: PEP 8 (`version 1.7.x`)
- All files are executable

## Prototype

```python
def validUTF8(data):
	"""Returns True if data is a valid UTF-8 encoding, else False."""
```

### Parameters

- `data`: list of integers

### Return

- `True` if `data` is valid UTF-8
- `False` otherwise

## Project Files

- `0-validate_utf8.py`: UTF-8 validation logic.
- `0-main.py`: Example test file provided for quick checks.
- `README.md`: Project documentation.

## Usage

Run the sample checks:

```bash
python3 0-main.py
```

Expected output:

```text
True
True
False
False
```

## Example

```python
#!/usr/bin/python3
validUTF8 = __import__('0-validate_utf8').validUTF8

print(validUTF8([65]))
print(validUTF8([229, 65, 127, 256]))
```

## Notes

- Each integer is treated as one byte candidate.
- Values outside byte range (`0` to `255`) invalidate the sequence.
