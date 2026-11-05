# Challenge 2 - Alexa Tell Me a Joke

I started by opening `randomJokes.txt` using an input file stream. Each joke is on a separate line, so I used `getline()` to read the file one line at a time. I stored the lines containing a question mark in a vector called `jokes`. If the file cannot be opened, or there are no lines with a question mark, the program displays a message and stops.

To choose a joke, I used a random number generator. The number is between zero and the last position in the vector. The program uses that number to select a joke, so a user can get a different one each time. The same joke can also appear more than once.

I used a loop to keep asking the user for the phrase `Alexa, tell me a joke`. If they type something different, the program asks them to try again. They can type `quit` at this prompt to end the program.

Once a joke is selected, I use `find()` to locate the question mark and `substr()` to display the setup. The program waits for the user to press Enter before displaying the punchline. I tested it with the supplied joke list and checked that I could ask again and quit.

## Running the program

Keep `randomJokes.txt` in this folder and run the program with this folder as its working directory.
