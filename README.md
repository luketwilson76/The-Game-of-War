# L4: Game of War
## Code designed to learn to use stacks, queues, and deques correctly

## *FIXME: Author(s) of primary logic and code: add name(s) here*

## Author of deck and sort: Jan Pearce, Berea College

### Authors:

- *FIXME*

### Starter files have been provided for you in C++

1. **HIGH LEVEL DESIGN**
*Complete the high-level design components in the linked Google Doc.*

2. **CRC Cards**
*Complete the CRC Card in the linked Google Doc. Turn on sharing and paste link to completed Google Doc here.*

*https://docs.google.com/document/d/1aptvEiVlEQmGtqSNTZOGWhaMMCtbbcZdM6Qb9MJe15g/edit#*

3. **Big O Analysis**
*Please analyze the Big O of all of the methods of the War class, including constructors. Hint: Your game uses 5 sets of cards, so for most, but possibly not all, of your methods, the input size (n) is the number of possible cards in the pile, but be sure you understand that this number should not be thought of as a constant! Anyone at anytime could possibly change either the number of decks used or even the number of cards in the deck for a game of War. (This is not far-fetched, the number of cards in a standard deck is 52 if you exclude Jokers or 54 if you include Jokers. A standard Tarot deck of cards has 78 cards. The normal Uno deck of cards has 108 cards. And, there are other decks...)*

*The Big O of the War class is O(n) because some loops are based off the size of some data structures but there're no nested loops.'*

4. **PROCESS SUMMARY**
*Briefly summarize your design and implementation process,
including how much your initial design plan evolved,
the final results you achieved, and the amount of time you spent
as a programmer or programmers in accomplishing these results.
This should be one or at most two paragraphs.*

*I spent around 4-5 hours designing my plan. I wasn't sure if I'd use all the methods that I intially wrote in the CRC card. My flow chart however was modeled pretty precisley on 
how my program would work. I made the playing decks stacks, the dealing deck a stack, the loot deck a stack, and the storage decks queues. I made less methods than I intially planned.
In the end, I spent around 15 hours completing this lab.

5. **DESIGN CHALLENGES**
*Describe the primary conceptual challenges that you encountered
in trying to complete this lab and what might have made the
lab easier for you.*

*The biggest problem was understanding that if C++ tries to read an empty data type, it'll give you an error. I did not know this till
I did it about a million times.'*

6. **ERRORS**
*List in bulleted form of all known errors
and deficiencies with a very brief explanation.*

- *I think I debugged the program but I'd say if there is one, it's most likley reading an empty data type. Most likley in the play method.*

8. **OPTIONAL ENHANCMENT**
*If you chose to make an optional enhancement to deal with cycles,
discuss what rule you added, and why you added it. Also, discuss
how well your rule worked.*

*FIXME*

9. **LEARNING AND REACTION**
*A paragraph or so of your own comments
on what you learned and your reactions to this lab.*

*I learned that stacks and queues are very handy when it comes to moving data from one place to another. *

10. **INTEGRITY STATEMENT**
*Please briefly describe ALL help you received and
all help you gave to others in completing this lab.
Also list all other references below.*

*Ala Qasema helped me debug my play method.*

11. **Pairwork statement**
If you worked in a pair of programmers, you are required to use good pair programming practices, always working together and not using a divide and conquer technique in which only one of you does the work and learns. Also, the two programmers roles should be switched frequently--around every 20 minutes or so. If you worked alone, please say so. If you worked in a pair, please describe how you worked together.

*FIXME*

## References:
- This repo contains original deck and sort code by Jan Pearce
- *Ala Qasema- debugging*
