# Devoir - Listes chaînées en C

## Étudiant
- **Matricule :** 24G2857  
- **Nom :** NKWEBO NGUEPI  
- **Prénom :** Joseph-Michel Shadrak  

---

## Explication du code - Exercice 5

### Sujet
Écrire un programme en C permettant **l’insertion en tête et en queue dans une liste doublement chaînée circulaire**.

### Principe de fonctionnement
Une **liste doublement chaînée circulaire** est une structure de données où :  
- Chaque élément (nœud) possède un pointeur vers le précédent (`prev`) et vers le suivant (`next`).  
- Le premier élément est relié au dernier, et le dernier au premier, créant un cycle.  

L’insertion doit donc respecter deux cas :  
1. **Insertion en tête** :  
   - On crée un nouveau nœud.  
   - On l’insère avant l’actuel premier élément.  
   - On met à jour les pointeurs pour garder la circularité.  

2. **Insertion en queue** :  
   - On crée un nouveau nœud.  
   - On l’insère après l’actuel dernier élément.  
   - On met à jour les pointeurs pour garder la circularité.  

---

## Étapes de réalisation

### 1. Analyse
- Identifier la structure nécessaire (`struct Node` avec `data`, `prev`, `next`).  
- Prévoir les fonctions d’insertion (tête et queue).  
- Gérer les cas particuliers (liste vide).  

### 2. Conception
- Définir un **pointeur `head`** qui représente le début de la liste.  
- Mettre en place des fonctions génériques pour insérer et afficher la liste.  

### 3. Implémentation
- `insertHead(&head, valeur)` : insère un nœud en tête.  
- `insertTail(&head, valeur)` : insère un nœud en queue.  
- `display(head)` : affiche la liste en parcourant jusqu’à revenir au premier nœud.  

### 4. Tests
- Cas 1 : Insertion dans une liste vide.  
- Cas 2 : Insertion multiple en tête et en queue.  
- Vérification que la liste reste circulaire.  

---

## Conclusion
Cet exercice illustre l’importance de la gestion des pointeurs dans les structures chaînées en C.  
La difficulté principale réside dans la **mise à jour correcte des liens `prev` et `next`** afin de maintenir la circularité et d’éviter les erreurs de segmentation.
