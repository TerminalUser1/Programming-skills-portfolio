# Challenge 3 - Book Manager

I created a Book class to hold each book's title, author, page count, ID and borrowed status. The display function prints those details and shows whether the book is available or borrowed. I stored the ID as a string so that IDs such as 001 keep their leading zeros.

The program opens bookData.txt and reads it one line at a time. Each line is split at the commas using a string stream. I convert the page count to a number and check that the borrowed status is either true or false. If the file cannot be opened or a line has invalid data, the program displays a message. I store the books in a vector so the menu can look through them.

The menu lets the user display every book or find one by entering its ID. It also has options to borrow and return a book. The program checks the current status before changing it and tells the user if the book already has that status. When a status changes, the program writes the books back to the file so the change can be seen next time it runs. The user can choose quit to finish.

Keep bookData.txt in the working directory when running the program.
