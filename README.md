# RPS_predictor

## Description
This project is a Rock-Paper-Scissors prediction algorithm written in C. It implements many ideas from Daniel Lawrence's [RPS Algorithm write-up](https://daniel.lawrence.lu/programming/rps/). For more information on RPS programming contests, see [rpscontest.com](http://www.rpscontest.com/).

My prediction algorithm is provided in `player_Axyzon.c`. It is based upon various permutations of two algorithms that use historical results to predict future choices (through string matching). It leverages a tournament-style predictor to choose which algorithm is most likely correct. The infrastructure for running matches and tournaments is the property of Binghamton University.

## Repository Contents
| File  | Content |
| ------------- | ------------- |
| `makeRegisterPlayers.py`  | Python script to register players (all files using the format `player_XXX.c`)  |
| `player_Axyzon.c`  | Player that implements my Rock-Paper-Scissors predictor algorithm  |
| `player_random.c`  | Player that always chooses randomly  |
| `player_rock.c`  | Player that always chooses rock  |
| `player_paper.c`  | Player that always chooses paper  |
| `player_scissors.c`  | Player that always chooses scissors  |
| `pool.c`  | Implementation for player pool functions  |
| `pool.h`  | Header file for player pool functions  |
| `rps.c`  | Implementation for tournament/match functions  |
| `rps.h`  | Header file for enumerated types and tournament/match functions  |

## Specifications
Players are implemented via a function `rps player_XXX(int round, rps * myhist, rps * opphist)`

- `round` is the number of the current round
- `myhist` points to an array of your historical choices
- `opphist` points to an array of your opponent's historical choices

To run a RPS match or tournament, compile with `make` and then use the following functions:

- `./rps <player1> <player2>` to run a 50 round match between player1 and player2
- `./rps` to run a tournament with all registered players
