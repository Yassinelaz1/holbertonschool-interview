#!/usr/bin/python3
"""a script that reads stdin line by line and computes metrics:"""
import sys

if __name__ == "__main__":
    total_size = 0
    status_codes = {"200": 0,
                    "301": 0,
                    "400": 0,
                    "401": 0,
                    "403": 0,
                    "404": 0,
                    "405": 0,
                    "500": 0}
    line_count = 1

    def parse_line(line):
        """ Read, parse and grab data"""
        try:
            parsed_line = line.split()
            status_code = parsed_line[-2]
            if status_code in status_codes.keys():
                status_codes[status_code] += 1
            return int(parsed_line[-1])
        except Exception:
            return 0

    def print_stats():
        """Print the metrics"""
        print("File size: {}".format(total_size))
        for key in sorted(status_codes.keys()):
            if status_codes[key]:
                print("{}: {}".format(key, status_codes[key]))

    try:
        for line in sys.stdin:
            total_size += parse_line(line)
            if line_count % 10 == 0:
                print_stats()
            line_count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
