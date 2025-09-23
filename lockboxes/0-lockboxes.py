#!/usr/bin/python3
"""hello world """

def canUnlockAll(boxes):
    total_boxes = len(boxes)
    opened_boxes = {0}
    keys_to_use = list(boxes[0])

    while keys_to_use:
        current_key = keys_to_use.pop()
        if current_key < total_boxes:
            if current_key not in opened_boxes:
                opened_boxes.add(current_key)
                for new_key in boxes[current_key]:
                    keys_to_use.append(new_key)

    return len(opened_boxes) == total_boxes
