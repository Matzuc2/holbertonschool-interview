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


def main():
    """Main function to process log entries."""
    lines = []
    print_line_count = 10
    total_file_size = 0
    valid_status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
    
    try:
        for line in sys.stdin:
            lines.append(line)
            if len(line.split(' ')) == 9:
                file_size = int(line.split(' ')[8])
                total_file_size += file_size
            if len(lines) == print_line_count:
                print_line_count += 10
                status_dict = {}
                for line in lines:
                    if len(line.split(' ')) != 9:
                        continue
                    status_code = line.split(' ')[7]
                    if status_code in valid_status_codes:
                        if status_code not in status_dict:
                            status_dict[status_code] = 1
                        else:
                            status_dict[status_code] += 1
                print(f"File size: {total_file_size}")
                for key, value in sorted(status_dict.items()):
                    print(f"{key}: {value}")
        status_dict = {}
        for line in lines:
            if len(line.split(' ')) != 9:
                continue
            status_code = line.split(' ')[7]
            if status_code in valid_status_codes:
                if status_code not in status_dict:
                    status_dict[status_code] = 1
                else:
                    status_dict[status_code] += 1
        print(f"File size: {total_file_size}")
        for key, value in sorted(status_dict.items()):
            print(f"{key}: {value}")
    except KeyboardInterrupt:
        status_dict = {}
        for line in lines:
            if len(line.split(' ')) != 9:
                continue
            status_code = line.split(' ')[7]
            if status_code in valid_status_codes:
                if status_code not in status_dict:
                    status_dict[status_code] = 1
                else:
                    status_dict[status_code] += 1
        print(f"File size: {total_file_size}")
        for key, value in sorted(status_dict.items()):
            print(f"{key}: {value}")


if __name__ == "__main__":
    main()
