# Project Name: Press Your Luck at our Casino
Team Members: Victoria Szymanowski & Theodore Wu    </br>
Systems Period 10    </br>

## Description
We created a casino that has the following games: blackjack, slot machines, and roulette!

## Will I need any libraries?
Nope! 

## Instructions:
```
make
make run
```
You will be taken to the home screen. Further directions will appear, but here's an overview of how to use the home screen:
- 

## DevLogs:
:goat: - Victoria's doing<br/>
:squirrel: - Theodore's doing<br/>
:boat: - Theodore's and Victoria's doing<br/>

### 1/7/2020
:goat: I started working on the blackjack function and header files. I created the structs for a card, a deck, and a player. I'm trying out typedef structs so I won't have to rewrite struct for the functions that have structs as return types. I also wrote a function that prints out a card. This print function is currently for testing purposes to see whether the cards chosen won't be repeated. Later, we'll display the cards in a nicer way. <br/>
:squirrel: I started on the main casino homepage. <br/>
### 1/8/2020
:goat: I attempted to write shuffle by using helper functions that would mix up the cards and then got it to work by using the next card in each deck. I also updated the printDeck function. <br/>
:squirrel: Added more print statements for the main screen so the user can enter input. <br/>
### 1/9/2020
:goat: I merged my edits to the master branch. I worked with changing the structs and adding a new struct for deck which will have an array now, so we're not really using the next and pointers.   <br/>
:boat: We researched which library to use and are deciding between graphics.c, SDL, and possibly termbox (which we're not really sure about).   <br/>
### 1/10/2020
:goat: Created files for networking and client from dwsource.    <br/>
:squirrel: Created files for networking with forking.    <br/>
:boat: We read through the files to try to understand how to incorporate it into our code.    <br/>
### 1/11/2020 - 1/12/2020
:goat: I was able to download and install SDL2 finally. I experimented with making a window.    <br/>
:squirrel: I worked on making the window stay longer.  <br/>
### 1/13/2020
:goat: I tried to load an image and rethought the use of the structs in blackjack.h. We might have to make some changes to that.    <br/>
### 1/14/2020
:goat: I worked on different methods in blackjack but it looks like initiating a game works well (from testing).    <br/>
:squirrel: Corrected makefile so it can be run on mac.    <br/>
:boat: We worked on the slots files together and decided on the rules and symbols we would use.    <br/>
### 1/15/2020
:goat: I added the transfercard method and made sure the deal method was being called correctly.    <br/>
:squirrel: I improved the slots machine file that we started working on in class.    <br/>
### 1/16/2020
:goat: I resolved the issues with blackjack and displaying the card. The pointers are now pointing where they need to and the correct information is being stored.   <br/>
:squirrel:
### 1/17/2020
:goat: I finally found the issue with making the deck by using many, many print statements. I worked on printing a general card and have printCard(card c) but it's not completely working yet.    <br/>
:squirrel:
### 1/18/2020
:goat: I found a really cool way to display the cards but it's going to take a while since each card has a different amount of hearts, spades, clubs, or diamonds on it. I started working on the continous blackjack game function.    <br/>
:squirrel:
### 1/19/2020
:goat: I finished the display card functions but they are so long. I think I need to think of a different approach. I also got rid of some warnings when compiling and added a possible ending to main.c.     <br/>
:squirrel:
### 1/20/2020
:goat: I rewrote the display card methods and now they don't take up 400 lines or something. I finally got it to work correctly with main and the makefile so blackjack is ready to play!! WOOHOO!!
<img src="https://media.giphy.com/media/26gsfdArwyEnXnDGw/source.gif" width="1500" height="500"/>
