# reference
My works

The thinking behind the projects:

  HANGMAN:
  
    - The user has 6 mistake chance
    - I need one random word from an array
    - If the user guessed a word, I need to change every occurrence: _ -> character 
      + loop through the word, if one of the character is matches to our letter we change the underscore to the character and checking If it is a special character 
    - If the user give us a letter that doesn't contains our word, we take it into a list and check If he says the letter again
    - If the player has more than 0 heart and he guessed the word, the player won
  
