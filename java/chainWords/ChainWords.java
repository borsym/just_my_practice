import java.util.*;

/*TODO hibakezelés */
public class ChainWords {
    private int playerNumber;
    private String startWords[] = {"doctor", "paralyzed", "proclaim", "waste", "oak", "fragrant", "offense", "deficiency", "elaborate", "bread"};
    private HashMap<String, Integer> players = new HashMap<String, Integer>();
    private ArrayList<String> playerNames = new ArrayList<>();
    private List<String> wordsUsed = new ArrayList<>();


    void setPlayerNumber(int number) {
        this.playerNumber = number;
    }

    void makePlayers() {
        for (int i = 0; i < playerNumber; i++) {
            System.out.println(i + 1 + ". player name:");
            Scanner sc = new Scanner(System.in);
            String name = sc.nextLine();
            playerNames.add(name);
            this.players.put(name, 2);
        }
    }

    String randomWord() {
        return startWords[(int) (Math.random() * (startWords.length - 1) + 0)];
    }

    String askForWord() {
        System.out.println("Give me a word or say 'exit' or say 'end' to give up");
        Scanner sc = new Scanner(System.in);
        return sc.nextLine();
    }

    void makeGame() {
        wordsUsed.add(randomWord().toUpperCase());
        System.out.println(wordsUsed.get(0));
        int index = 0;
        while (true) {
            boolean isGood = true;
            boolean isPlayerOut = false;
            String currentPlayerName = playerNames.get(index);
            System.out.println(currentPlayerName + ": ");
            String word = askForWord().toUpperCase();

            if (word.equals("EXIT")) {
                System.out.println("\nThanks for gaming");
                break;
            }

            if (word.equals("END")) {
                System.out.println(currentPlayerName + " is out of the game");
                playerNames.remove(currentPlayerName);
                players.remove(currentPlayerName);
                isPlayerOut = true;
            }

            if (word.toUpperCase().charAt(0) != wordsUsed.get(wordsUsed.size() - 1).charAt(wordsUsed.get(wordsUsed.size() - 1).length() - 1)) {
                System.out.println("\nOps the first and last letter doesn't match try again, last letter was: " + wordsUsed.get(wordsUsed.size() - 1).charAt(wordsUsed.get(wordsUsed.size() - 1).length() - 1) + " you steel have " + (players.put(currentPlayerName, players.get(currentPlayerName) - 1)) + " heart");
                isGood = false;
            }

            if (isGood && wordsUsed.contains(word)) {
                System.out.println("\nOps, this word appeared once, say another, you steel have " + (players.put(currentPlayerName, players.get(currentPlayerName) - 1)) + " heart");
                isGood = false;
            }

            if (!isPlayerOut && players.get(currentPlayerName) == -1) {
                System.out.println(currentPlayerName + " is out of the game");
                players.remove(currentPlayerName);
                playerNames.remove(currentPlayerName);
                if (players.size() == 1) {
                    System.out.println("We have a winner! " + playerNames.get(0));
                    break;
                }

            }

            if (isGood) {
                wordsUsed.add(word);
                System.out.println("\nGood Word, Nice!");
                index++;
                if (index >= players.size()) {
                    index = 0;
                }
            }
        }
    }

    public ChainWords(int number) {
        setPlayerNumber(number);
        makePlayers();
        makeGame();
    }
}



