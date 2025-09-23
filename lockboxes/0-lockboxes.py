#!/usr/bin/python3

def canUnlockAll(boxes):
    keys = []
    for i, boxe in enumerate(boxes):
        if i == 0:
            for key in boxe:
                keys.append(key)
        for key in keys:
            if key == i:
                for key in boxe:
                    keys.append(key)
                boolean = True
                break
            else:
                boolean = False
    return boolean 
