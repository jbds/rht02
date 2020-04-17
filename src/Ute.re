/* type definitions */
type playingCardRank =
  | Ace
  | King
  | Queen
  | Jack
  | Ten
  | Nine
  | Eight
  | Seven
  | Six
  | Five
  | Four
  | Three
  | Two
  | NoRank
;

type playingCardSuit =
  | Spades
  | Hearts
  | Diamonds
  | Clubs
  | NoSuit
;

type lifecycle =
  | Dealer
  | Hand
;

type location =
  | North
  | East
  | South
  | West
;


type playingCard = (playingCardRank, playingCardSuit, lifecycle);

type gameDenomination =
  | NO_TRUMPS
  | SUIT(playingCardSuit)
;

/* value definitions */
let orderedListOfCards: list(playingCard) = [
  (Ace,Spades, Dealer),
  (King, Spades, Dealer),
  (Queen, Spades, Dealer),
  (Jack, Spades, Dealer),
  (Ten, Spades, Hand),
  (Nine, Spades, Dealer),
  (Eight, Spades, Dealer),
  (Seven, Spades, Dealer),
  (Six, Spades, Dealer),
  (Five, Spades, Dealer),
  (Four, Spades, Dealer),
  (Three, Spades, Dealer),
  (Two, Spades, Dealer),
  (Ace, Hearts, Dealer),
  (King, Hearts, Dealer),
  (Queen, Hearts, Dealer),
  (Jack, Hearts, Dealer),
  (Ten, Hearts, Dealer),
  (Nine, Hearts, Dealer),
  (Eight, Hearts, Dealer),
  (Seven, Hearts, Dealer),
  (Six, Hearts, Dealer),
  (Five, Hearts, Dealer),
  (Four, Hearts, Dealer),
  (Three, Hearts, Dealer),
  (Two, Hearts, Dealer),
  (Ace, Clubs, Dealer),
  (King, Clubs, Dealer),
  (Queen, Clubs, Dealer),
  (Jack, Clubs, Dealer),
  (Ten,Clubs, Dealer),
  (Nine, Clubs, Dealer),
  (Eight,Clubs, Dealer),
  (Seven,Clubs, Dealer),
  (Six, Clubs, Dealer),
  (Five, Clubs, Dealer),
  (Four, Clubs, Dealer),
  (Three, Clubs, Dealer),
  (Two, Clubs, Dealer),
  (Ace, Diamonds, Dealer), 
  (King, Diamonds, Dealer),
  (Queen, Diamonds, Dealer),
  (Jack, Diamonds, Dealer),
  (Ten, Diamonds, Dealer), 
  (Nine, Diamonds, Dealer),
  (Eight, Diamonds, Dealer),
  (Seven, Diamonds, Dealer), 
  (Six, Diamonds, Dealer),
  (Five, Diamonds, Dealer),
  (Four, Diamonds, Dealer),
  (Three, Diamonds, Dealer),
  (Two, Diamonds, Dealer),
];

/* mutable */
let arrayOfCards = Array.of_list(orderedListOfCards);

/* unicode for Spades, Hearts, Diamonds and Clubs and hair space glyphs */
/*
Js.log({js|\u2660 A|js});
Js.log({js|\u2665 K|js});
Js.log({js|\u2666 3|js});
Js.log({js|\u2663 2|js});
Js.log({js|\u200A|js})
*/

/* used below and also in console display recursive function */
let suitToString(playingCardSuit) = {
  switch (playingCardSuit) {
  | Spades => "S"
  | Hearts => "H"
  | Diamonds => "D"
  | Clubs => "C"
  | NoSuit => "!"
  }
};

// let suitToStringUnicode(playingCardSuit) = {
//   switch (playingCardSuit) {
//   | Spades => {js|\u2660|js}
//   | Hearts => {js|\u2665|js}
//   | Diamonds => {js|\u2666|js}
//   | Clubs => {js|\u2663|js}
//   | NoSuit => "!"
//   }
// };


let rankToString(playingCardRank) = {
  switch (playingCardRank) {
  | Ace => "A"
  | King => "K"
  | Queen => "Q"
  | Jack => "J"
  | Ten => "T"
  | Nine => "9"
  | Eight => "8"
  | Seven => "7"
  | Six => "6"
  | Five => "5"
  | Four => "4"
  | Three => "3"
  | Two => "2"
  | NoRank => "!"
  }
};

let cardToString(playingCard: playingCard) = {
  let (fst, snd, lc) = playingCard;
  (rankToString(fst) ++ suitToString(snd), lc)
};

// TO DO - this sort is for the hand sort, not the scoring
let cardToValue(gameDenomination, playingCard: playingCard) = {
  let suitToValue(playingCardSuit, gameDenomination) = {
    switch (playingCardSuit, gameDenomination) {
    | (Spades, _) => 42
    | (Hearts, SUIT(Hearts)) => 56
    | (Hearts, _) => 28
    | (Clubs, SUIT(Clubs)) => 56
    | (Clubs, _) => 14
    | (Diamonds, SUIT(Diamonds)) => 56
    | (Diamonds, _) => 0
    | (NoSuit, _) => -14
    }
  };
  let rankToValue(playingCardRank) = {
    switch (playingCardRank) {
    | Ace => 14
    | King => 13
    | Queen => 12
    | Jack => 11
    | Ten => 10
    | Nine => 9
    | Eight => 8
    | Seven => 7
    | Six => 6
    | Five => 5
    | Four => 4
    | Three => 3
    | Two => 2
    | NoRank => 0
    }
  };
  let (fst, snd, _) = playingCard;
  rankToValue(fst) + suitToValue(snd, gameDenomination)
};

let compareCardValue= (denom, cardA, cardB) => {
  cardToValue(denom, cardA) > cardToValue(denom, cardB) ? -1 : 1
};


/* Fisher–Yates shuffle */
/* polymorhic function */
let shuffleArrayInPlace = (arr, seed) => {
  Random.init(seed);
  for (n in Array.length(arr) - 1 downto 1) {
    let k = Random.int(n + 1);
    let temp = arr[n];
    arr[n] = arr[k];
    arr[k] = temp;
  };
};

let cardsNorth = Array.make(13, (NoRank, NoSuit, Dealer));
let cardsEast = Array.make(13, (NoRank, NoSuit, Dealer));
let cardsSouth = Array.make(13, (NoRank, NoSuit, Dealer));
let cardsWest = Array.make(13, (NoRank, NoSuit, Dealer));

let shuffleByModulo = (k) => {
  for (i in 0 to 51) {
    if (i mod 4 == k){
      cardsNorth[i/4] = arrayOfCards[i];
    } else if (i mod 4 == k + 1) {
      cardsEast[i/4] = arrayOfCards[i];
    } else if (i mod 4 == k + 2) {
      cardsSouth[i/4] = arrayOfCards[i];
    } else if (i mod 4 == k + 3){
      cardsWest[i/4] = arrayOfCards[i];
    } else {
      Js.log("should be unreachable, i=" ++ string_of_int(i));
    }
  };
};

// dealer deals to next clockwise location
let allocateShuffledToLocation = (loc) => {
  switch (loc) {
    | North => shuffleByModulo(3)
    | East => shuffleByModulo(2)
    | South => shuffleByModulo(1)
    | West => shuffleByModulo(0)
  }
};




// used on prev console only project card06 
// let rec displaySetOfCardsOnConsole = (arr, suitAsString) => {
//   let l = Array.to_list(arr);
//   switch l {
//   | [] => ""
//   | [hd, ...tl] => {
//       let remainder = displaySetOfCardsOnConsole(Array.of_list(tl), suitToStringUnicode(snd(hd)));
//       suitAsString == suitToStringUnicode(snd(hd)) 
//       ?
//       rankToString(fst(hd)) ++ " " ++ remainder
//       :
//       "  " ++ suitToStringUnicode(snd(hd)) ++ " " ++ rankToString(fst(hd)) ++ " " ++ remainder
//     }
//   }
// };

let impureGetRandomSeedUpTo60k = () => {
  let now = Js.Date.make();
  int_of_float((Js.Date.getSeconds(now) *. 1000.0) +. Js.Date.getMilliseconds(now));
};
