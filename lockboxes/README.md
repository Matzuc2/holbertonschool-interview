# 0x01. Lockboxes

## Description
Ce projet consiste à déterminer si toutes les boîtes d'une liste peuvent être ouvertes. Chaque boîte peut contenir des clés permettant d'ouvrir d'autres boîtes. La première boîte (index 0) est toujours ouverte.

## Prototype
```python
canUnlockAll(boxes)
```
- `boxes` est une liste de listes, où chaque sous-liste représente une boîte et contient les clés qu'elle possède.
- Retourne `True` si toutes les boîtes peuvent être ouvertes, sinon `False`.

## Exemple d'utilisation
```python
boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))  # False
```

## Fichiers
- `0-lockboxes.py` : contient la fonction principale `canUnlockAll`.
- `main_0.py` : fichier de test pour valider la fonction.

## Auteur
- Matzuc2
