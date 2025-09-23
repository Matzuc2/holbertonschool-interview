#!/usr/bin/python3

"""
Module: 0-lockboxes

Ce module fournit une fonction pour déterminer si toutes les boîtes d'une liste peuvent être ouvertes.
Chaque boîte peut contenir des clés permettant d'ouvrir d'autres boîtes.
"""

def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes.

    Args:
        boxes (list of list of int): Liste de boîtes, chaque boîte contient des clés (indices d'autres boîtes).

    Returns:
        bool: True si toutes les boîtes peuvent être ouvertes, sinon False.
    """
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
