# grepcopy

This is a small project that I started with the aim of making a command like 'grep' that we used in terminal.
it is still under construction, not fully made.
but you can take it and change it for however you like.
here grepcopy5.c is the latest one that works better than rest of the other files.

# What is it?
For those who have never used grep in terminal, it's a command that can find any type of pattern inside files. Any string pattern you put, it can tell you where is it and in which file. I tried to make one such program, but till now, I can do it only for text files.

So, you can use it to search any word, sentence, phrase or any string inside any number of text files.

# How to use?
You can use it like we use grep in linux terminal.
Just compile it, and run it using terminal and writing the pattern and file names (files to be searched) alongside it using single space.
For example, you wanna search the word 'Home' from 2 files 'Summer.txt' and 'Winter.txt'. Then you can write like:-

(Program Name) Home Summer.txt Winter.txt

If there's more than one word, like a phrase/sentence, for example "Home sweet home." You have to mention it using double-quotations. Example:-

(Program Name) "Home sweet home." Summer.txt Winter.txt

If you have to search it from all the existing files, then just put an asterisk (\*) instead of the file names. Example

(Program Name) "Home sweet home." \*

If you use windows, then you can use it in Windows Power Shell or what we commonly call the Command Prompt. Compile the program first, and then run the program using command prompt in a similar way as explained above. 

If you're searching in the files in same folder, then just writing file names is enough. But if you're to search within the files that are present somewhere else, then you have to mention the full address of the files.
