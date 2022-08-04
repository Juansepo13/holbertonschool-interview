#!/usr/bin/python3
""" lockboxes challenge """


def canUnlockAll(boxes):
    """ function that open boxes """
    all_keys = []
    for i in range(len(boxes)):
        all_keys.append(i)

    recover_keys = []
    recover_keys.append(0)

    for key in recover_keys:
        for new_key in boxes[key]:
            if ((new_key in all_keys) and (new_key not in recover_keys)):
                recover_keys.append(new_key)
            else:
                continue
        if all_keys == sorted(recover_keys):
            return True
    return False
