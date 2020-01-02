# Project Name: Press Your Luck at our Casino
Team Members: Victoria Szymanowski & Theodore Wu    </br>
Systems Period 10    </br>
## Higher-level Description: 
We will make blackjack and some additional games (such as roulette and slot machines) that the user can play.    </br>
## Description of User Interface:
When the user enters make run, they will be taken to the home screen where we will have some decorations and the option to choose a game to play. The user can choose a game by entering the name of the game (or possibly a shortcut that we have not decided on yet). They will then be taken to a new screen where the game will appear. 
#### BLACKJACK: 
The user begins by typing in their initial bet. The bet will be displayed in the bottom right corner. The user will be given their 2 initial cards. They can type in “hit”, “stand”, “double down”, and “surrender”. “Hit” will give them another card, “stand” will not give them any card but move onto the dealer’s hand, “double down” will allow the user to increase their original bet after receiving one card but they will have to stand after that, and “surrender” will result in the user ending the game which can lead to them starting a new game or returning to the main/home screen.
#### SLOT MACHINES: 
The screen will display 3 numbers and they will scroll or change. Then they will stop and if the user gets 2 numbers that are the same, they win the amount they bet while if they get all 3 to be the same, they get ten times the amount they bet? If none of the numbers are the same, the user loses the amount of money they bet
#### ROULETTE: 
The user will enter the number that they want to bet on or whether they want to bet on an odd or even number. This is a simplified version of roulette where color does not play a role. The user can bet how much they want. The screen will display a circle and once it’s spun and finishes spinning, the number that the ball lands on will appear inside of a rectangle. The user will type whether they want to keep playing or return to the home screen.
## Technical Design
Topics covered in class:
- Allocating memory
  - We will allocate memory for the deck of cards and each individual card.
- Working with files
  - To save the highscore or personal best.
- Finding information about files (stat and such)
  - We will find information about the highscore file.
- Processes
  - Each game will be a child process of the main casino homepage
- Networking possibly
  - To make multiplayer blackjack (this would be an extension)
## Data structures & Algorithms:
- Arrays: hold numbers or possibilities for each specific game and will help us when selecting values for blackjack, slot machines, and roulette
- Struct: We can use structs for the cards, deck, and player to make shuffling a little easier
- New Tool: This would be an enhancement and would make us not need to use structs. We could use the do loop when shuffling cards and when playing blackjack
## Timeline:
1/2: Proposal is due.    </br>
1/8: Finish the homepage of the casino (Theodore) and make structs and simple print function for cards in blackjack (Victoria)    </br>
1/12: Finish Blackjack shuffle, display, and hit methods (Victoria) and freeing along with main function for testing (Theodore)    </br>
1/13: Finish the roulette  (Theodore)    </br>
1/14: Finish the slot machines and add the highscores (Theodore)    </br>
1/15: Final check and run through to ensure our project functions to its maximum ability (Victoria & Theodore)  ~ if time remains, we will try to include networking for multiplayer blackjack    </br>
