#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics.

This script processes log entries in the following format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

After every 10 lines and/or a keyboard interruption (CTRL + C),
it prints statistics:
- Total file size: File size: <total size>
- Number of lines by status code (in ascending order)
"""
import sys

lines: list[str] = []

try:
    for index, line in enumerate(sys.stdin):
        # print(index, "hello im index")
        # print(i, "hello im i")
        lines.append(line)
        if (index % 10 == 0 and index != 0):
            status_dict = {}
            total_file_size = 0
            for line in lines:
                status_code = line.split(' ')[7]
                if status_code not in status_dict:
                    status_dict[status_code] = 1
                else:
                    status_dict[status_code] += 1
                file_size = line.split(' ')[8]
            total_file_size += int(file_size) or 0
            print(f"File size: {total_file_size}")
            for key, value in sorted(status_dict.items()):
                print(f"{key}: {value}")
except KeyboardInterrupt:
    status_dict = {}
    total_file_size = 0
    for line in lines:
        status_code = line.split(' ')[7]
        if status_code not in status_dict:
            status_dict[status_code] = 1
        else:
            status_dict[status_code] += 1
        file_size = line.split(' ')[8]
    total_file_size += int(file_size) or 0
    print(f"File size: {total_file_size}")
    for key, value in sorted(status_dict.items()):
        print(f"{key}: {value}")
