import random

words = ["alma", "ananasz", "kutya", "macska", "cica", "capa", "tornado", "vihar", "etel", "ital"]
letters_need_to_check = ["ny","zs","cs","sz","dz","ty"]
mistakes = []
need_to_guess = random.choice(words)
guessed_letters_array = [None] * len(need_to_guess)
mistake_count = 0
guessed_letters = 0

while mistake_count < 6 and guessed_letters != len(need_to_guess):
    index = 0
    while len(need_to_guess) > index:
        if index < (len(need_to_guess) - 1) and letters_need_to_check.__contains__((need_to_guess[index] + need_to_guess[index + 1])):
            if guessed_letters_array[index] == None:  print("__", end=" ")
            else:
                if(guessed_letters_array[index + 1] == None):  print("{}_".format(guessed_letters_array[index]), end="")
                else:  print(guessed_letters_array[index], guessed_letters_array[index + 1], end =" ")
            index += 2    
        else:
            if guessed_letters_array[index] == None:  print("_", end=" ")
            else:  print(guessed_letters_array[index], end=" ")
            index += 1

    user_input = (input("\nGive me a letter: ")).lower()
   
   

    if not need_to_guess.__contains__(user_input):
        mistake_count += 1
        if mistakes.__contains__(user_input): print("\n\nYou already sad this letter")
        else:
            print("The word doesn't has letter: ", user_input)
            mistakes.append(user_input)
    else:
        for i in range(len(need_to_guess)):
            if user_input == need_to_guess[i]:
                guessed_letters_array[i] = user_input
                guessed_letters += 1
                
    
    if   mistake_count == 0:   print("\n  ___\n |   |\n     |\n ") #            first 
    elif mistake_count == 1:   print("\n  ___\n |   |\n o   |\n ")  #           second 
    elif mistake_count == 2:   print("\n  ___\n |   |\n o   |\n  \\ ") #        third
    elif mistake_count == 3:   print("\n  ___\n |   |\n o   |\n/ \\ ") #        forth
    elif mistake_count == 4:   print("\n  ___\n |   |\n o   |\n/|\\ ") #        fifth
    elif mistake_count == 5:   print("\n  ___\n |   |\n o   |\n/|\\ \n/") #     sixth
    elif mistake_count == 6:   print("\n  ___\n |   |\n o   |\n/|\\ \n/ \\") #  seventh


    print("\nUsed words, that doesn't work:")
    print(*mistakes, sep=", ")
    

if(mistake_count == 6): print("You lost, the word was", need_to_guess)
else: print("\nYou won, Nice!\nThe word was:", need_to_guess)  

