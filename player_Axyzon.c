#include "rps.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static float alg1score = 1;
static float alg2score = 0.8;
static float alg3score = 0.5;
static float alg4score = 0.5;
static float alg5score = 0.3;
static float alg6score = 0.3;

static rps alg1predict = Paper;
static rps alg2predict = Paper;
static rps alg3predict = Paper;
static rps alg4predict = Paper;
static rps alg5predict = Paper;
static rps alg6predict = Paper;

static int wasrandom = 0;
long mixer = 238921324;

rps player_Axyzon(int round,rps *myhist,rps *opphist) {
  mixer = (mixer * 1103515245 + 12345) % 3;
  int fall = mixer;
  if (round < 3) {
      wasrandom = 0;
      switch(fall) {
        case 0: return Rock;
        case 1: return Scissors;
        case 2: return Paper;
        case 3: return Paper;
      }
  }
  else {
    if (round > 4 && wasrandom != 0) {
      if (eval_round(alg1predict, opphist[round - 1]) == Player1) {
	alg1score+=0.8;
      }
      else if (eval_round(alg1predict, opphist[round - 1]) == Player2) {
	alg1score-=0.8;
      }
      if (eval_round(alg2predict, opphist[round - 1]) == Player1) {
	alg2score+=0.8;
      }
      else if (eval_round(alg2predict, opphist[round - 1]) == Player2) {
	alg2score-=0.8;
      }
      if (eval_round(alg3predict, opphist[round - 1]) == Player1) {
	alg3score+=0.8;
      }
      else if (eval_round(alg3predict, opphist[round - 1]) == Player2) {
	alg3score-=0.8;
      }
      if (eval_round(alg4predict, opphist[round - 1]) == Player1) {
	alg4score+=0.8;
      }
      else if (eval_round(alg4predict, opphist[round - 1]) == Player2) {
	alg4score-=0.8;
      }
      if (eval_round(alg5predict, opphist[round - 1]) == Player1) {
	alg5score+=0.8;
      }
      else if (eval_round(alg5predict, opphist[round - 1]) == Player2) {
	alg5score-=0.8;
      }
      if (eval_round(alg6predict, opphist[round - 1]) == Player1) {
	alg6score+=0.8;
      }
      else if (eval_round(alg6predict, opphist[round - 1]) == Player2) {
	alg6score-=0.8;
      }
      alg1score = alg1score * 0.8;
      alg2score = alg2score * 0.8;
      alg3score = alg3score * 0.8;
      alg4score = alg4score * 0.8;
      alg5score = alg5score * 0.8;
      alg6score = alg6score * 0.8;
    }
  char myhistory[51] = "";
  char opphistory[51] = "";
  char myseek2[3] = "";
  char myseek3[4] = "";
  char myseek4[5] = "";
  char myseek5[6] = "";
  char oppseek2[3] = "";
  char oppseek3[4] = "";
  char oppseek4[5] = "";
  char oppseek5[6] = "";
  char pap[] = "P";
  char roc[] = "R";
  char sci[] = "S";
  for (int i = round; i > -1; i--) {
    if (myhist[i] == Paper) {
      if (i != round) {
	strcat(myhistory, &pap);
      }
      if (i > round - 5) {
	strcat(myseek5, &pap);
	if (i > round - 4) {
	  strcat(myseek4, &pap);
	  if (i > round - 3) {
	    strcat(myseek3, &pap);
	    if (i > round - 2) {
	      strcat(myseek2, &pap);
	    }
	  }
	}
      }
    }
    else if (myhist[i] == Rock) {
      if (i != round) {
	strcat(myhistory, &roc);
      }
      if (i > round - 5) {
	strcat(myseek5, &roc);
	if (i > round - 4) {
	  strcat(myseek4, &roc);
	  if (i > round - 3) {
	    strcat(myseek3, &roc);
	    if (i > round - 2) {
	      strcat(myseek2, &roc);
	    }
	  }
	}
      }
    }
    else if (myhist[i] == Scissors) {
      if (i != round) {
	strcat(myhistory, &sci);
      }
      if (i > round - 5) {
	strcat(myseek5, &sci);
	if (i > round - 4) {
	  strcat(myseek4, &sci);
	  if (i > round - 3) {
	    strcat(myseek3, &sci);
	    if (i > round - 2) {
	      strcat(myseek2, &sci);
	    }
	  }
	}
      }
    }
    if (opphist[i] == Paper) {
      if (i != round) {
	strcat(opphistory, &pap);
      }
      if (i > round - 5) {
	strcat(oppseek5, &pap);
	if (i > round - 4) {
	  strcat(oppseek4, &pap);
	  if (i > round - 3) {
	    strcat(oppseek3, &pap);
	    if (i > round - 2) {
	      strcat(oppseek2, &pap);
	    }
	  }
	}
      }
    }
    else if (opphist[i] == Rock) {
      if (i != round) {
	strcat(opphistory, &roc);
      }
      if (i > round - 5) {
	strcat(oppseek5, &roc);
	if (i > round - 4) {
	  strcat(oppseek4, &roc);
	  if (i > round - 3) {
	    strcat(oppseek3, &roc);
	    if (i > round - 2) {
	      strcat(oppseek2, &roc);
	    }
	  }
	}
      }
    }
    else if (opphist[i] == Scissors) {
      if (i != round) {
	strcat(opphistory, &sci);
      }
      if (i > round - 5) {
	strcat(oppseek5, &sci);
	if (i > round - 4) {
	  strcat(oppseek4, &sci);
	  if (i > round - 3) {
	    strcat(oppseek3, &sci);
	    if (i > round - 2) {
	      strcat(oppseek2, &sci);
	    }
	  }
	}
      }
    }
  }
  int foundmy2 = -1;
  int foundmy3 = -1;
  int foundmy4 = -1;
  int foundmy5 = -1;
  int foundopp2 = -1;
  int foundopp3 = -1;
  int foundopp4 = -1;
  int foundopp5 = -1;
  if (strstr(myhistory, myseek2)) {
    foundmy2 = strstr(myhistory, myseek2) - myhistory;
  }
  if (strstr(myhistory, myseek3)) {
    foundmy3 = strstr(myhistory, myseek3) - myhistory;
  }
  if (strstr(myhistory, myseek4)) {
    foundmy4 = strstr(myhistory, myseek4) - myhistory;
  }
  if (strstr(myhistory, myseek5)) {
    foundmy5 = strstr(myhistory, oppseek5) - myhistory;
  }
  if (strstr(opphistory, oppseek2)) {
    foundopp2 = strstr(opphistory, oppseek2) - opphistory;
  }
  if (strstr(opphistory, oppseek3)) {
    foundopp3 = strstr(opphistory, oppseek3) - opphistory;
  }
  if (strstr(opphistory, oppseek4)) {
    foundopp4 = strstr(opphistory, oppseek4) - opphistory;
  }
  if (strstr(opphistory, oppseek5)) {
    foundopp5 = strstr(opphistory, oppseek5) - opphistory;
  }
  if (foundmy2 == -1 && foundmy3 == -1 && foundmy4 == -1 && foundmy5 == -1 && foundopp2 == -1 && foundopp3 == -1 && foundopp4 == -1 && foundopp5 == -1) {
    wasrandom = 0;
    switch(fall) {
        case 0: return Rock;
        case 1: return Scissors;
        case 2: return Paper;
        case 3: return Paper;
    }
  }
  else {
    wasrandom = 1;
    int foundmys[4] = {foundmy2, foundmy3, foundmy4, foundmy5};
    int foundopps[4] = {foundopp2, foundopp3, foundopp4, foundopp5};
    int mytarget = 999;
    int opptarget = 999;
    for (int i = 3; i > -1; i--) {
      if (foundmys[i] != -1) {
	if (foundmys[i] < mytarget && (mytarget - foundmys[i]) > 3) {
	  mytarget = foundmys[i];
	}
	if (foundmys[i] == 0) {
	  mytarget = foundmys[i];
	}
      }
      if (foundopps[i] != -1) {
	if (foundopps[i] < opptarget && (opptarget - foundopps[i]) > 3) {
	  opptarget = foundopps[i];
	}
	if (foundopps[i] == 0) {
	  opptarget = foundopps[i];
	}
      }
    }
    rps mychoice = myhist[(round - 1) - mytarget];
    rps oppchoice = opphist[(round - 1) - opptarget];
    if (mychoice == Paper) {
      alg1predict = Scissors;
      alg3predict = Rock;
      alg5predict = Paper;
    }
    else if (mychoice == Rock) {
      alg1predict = Paper;
      alg3predict = Scissors;
      alg5predict = Rock;
    }
    else {
      alg1predict = Rock;
      alg3predict = Paper;
      alg5predict = Scissors;
    }
    if (oppchoice == Paper) {
      alg2predict = Scissors;
      alg4predict = Rock;
      alg6predict = Paper;
    }
    else if (oppchoice == Rock) {
      alg2predict = Paper;
      alg4predict = Scissors;
      alg6predict = Rock;
    }
    else {
      alg2predict = Paper;
      alg4predict = Scissors;
      alg6predict = Rock;
    }
  }
  int scoring[6] = {alg1score, alg2score, alg3score, alg4score, alg5score, alg6score};
  float highest = -100;
  int choice = 0;
  for (int i = 0; i < 6; i++) {
    if (scoring[i] > highest) {
      highest = scoring[i];
      choice = i + 1;
    }
  }
  if (highest < 0) {
    switch(fall) {
        case 0: return Rock;
        case 1: return Scissors;
        case 2: return Paper;
        case 3: return Paper;
    }
  }
  switch(choice) {
    case 1: return alg1predict;
    case 2: return alg2predict;
    case 3: return alg3predict;
    case 4: return alg4predict;
    case 5: return alg5predict;
    case 6: return alg6predict;
  }
  }
  return Paper;
}

