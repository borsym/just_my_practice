# reference
My works

The thinking behind the projects:
   
   
   WORD_CHAIN:
    - We need at least two player
    - Hold gamers in a list
    - We will need a random first word
    - If the last letter of the previous word doesn't match to the first letter of the current word, ask again the player (3 heart)
    - Hold the said letters, don't hold it, If the user says again a letter
    - If every condition is correct, append to the list the current letter
    - Handle exceptions
    - Handle if the user give us word like this "eXiT" make it to Upper or Lower case
    
    
  HANGMAN:
  
    - The user has 6 mistake chance
    - I need one random word from an array
    - If the user guessed a word, I need to change every occurrence: _ -> character 
      + loop through the word, if one of the character is matches to our letter we change the underscore to the character and checking If it is a special character 
    - If the user give us a letter that doesn't contains our word, we take it into a list and check If he says the letter again
    - If the player has more than 0 heart and he guessed the word, the player won
  
