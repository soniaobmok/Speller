# Speller
This program reads texts and checks if the words from this text match to the words from dictionary. 

Speller can load text files, split them into words and check if they are present in a dictionary. 
The purpose is to compare search methods: a dictionary can be stored in a vector from STL, in an 
unordered set (also from STL) or in custom containers - binary search tree and hash table.
Words from texts, which were not found in dictionary, are written in a new file.

/* don't try to load all files from "texts" directory (in Checker.cpp). My laptop started to do that 36 minutes ago and it hasn't finished even first checking yet */
/* or just don't load file "tolstoy.txt" - it is "War and Peace"!!1! */
