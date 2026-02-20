# Log Parsing

This project contains a log parsing solution that reads log entries from stdin and computes statistics about HTTP requests.

## Description

The log parser reads web server log entries in the following format:
```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

It computes and displays:
- **Total file size**: The sum of all file sizes
- **Status code counts**: Number of occurrences for each HTTP status code

Statistics are printed:
- Every 10 lines of input
- When interrupted with `CTRL+C`

## Files

| File | Description |
|------|-------------|
| `0-stats.py` | Script that reads log entries from stdin and computes statistics |
| `0-generator.py` | Test script that generates random log entries for testing |

## Requirements

- Python 3.x
- Linux/Unix environment

## Usage

### Running with the test generator

The simplest way to test the log parser is to pipe the output from the generator:

```bash
./0-generator.py | ./0-stats.py
```

### Running with custom input

You can also pipe any log file or stream that matches the expected format:

```bash
cat /var/log/access.log | ./0-stats.py
```

Or manually input lines (press `CTRL+C` to see final statistics):

```bash
./0-stats.py
```

## Example Output

```
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 3
403: 3
404: 4
405: 2
500: 3
```

## Status Codes Tracked

The parser tracks the following HTTP status codes:
- `200` - OK
- `301` - Moved Permanently
- `400` - Bad Request
- `401` - Unauthorized
- `403` - Forbidden
- `404` - Not Found
- `405` - Method Not Allowed
- `500` - Internal Server Error

## Author

Created for Holberton School interview preparation
