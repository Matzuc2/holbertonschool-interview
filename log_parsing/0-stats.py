#!/usr/bin/python3
import sys
lines: list[str] = []
try:
    for index, line in enumerate(sys.stdin):
        # print(index, "hello im index")
        # print(i, "hello im i")
        lines.append(line)
        if (index % 10 == 0 and index != 0) :
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
        






        
