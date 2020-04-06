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

type playingCard = (playingCardRank, playingCardSuit);

type gameDenomination =
  | NO_TRUMPS
  | SUIT(playingCardSuit)
;

/* value definitions */
let orderedListOfCards = [
  (Ace,Spades),
  (King, Spades),
  (Queen, Spades),
  (Jack, Spades),
  (Ten, Spades),
  (Nine, Spades),
  (Eight, Spades),
  (Seven, Spades),
  (Six, Spades),
  (Five, Spades),
  (Four, Spades),
  (Three, Spades),
  (Two, Spades),
  (Ace, Hearts),
  (King, Hearts),
  (Queen, Hearts),
  (Jack, Hearts),
  (Ten, Hearts),
  (Nine, Hearts),
  (Eight, Hearts),
  (Seven, Hearts),
  (Six, Hearts),
  (Five, Hearts),
  (Four, Hearts),
  (Three, Hearts),
  (Two, Hearts),
  (Ace, Diamonds),
  (King, Diamonds),
  (Queen, Diamonds),
  (Jack, Diamonds),
  (Ten,Diamonds),
  (Nine, Diamonds),
  (Eight,Diamonds),
  (Seven,Diamonds),
  (Six, Diamonds),
  (Five, Diamonds),
  (Four, Diamonds),
  (Three, Diamonds),
  (Two, Diamonds),
  (Ace, Clubs), 
  (King, Clubs),
  (Queen, Clubs),
  (Jack, Clubs),
  (Ten, Clubs), 
  (Nine, Clubs),
  (Eight, Clubs),
  (Seven, Clubs), 
  (Six, Clubs),
  (Five, Clubs),
  (Four, Clubs),
  (Three, Clubs),
  (Two, Clubs),
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

let suitToStringUnicode(playingCardSuit) = {
  switch (playingCardSuit) {
  | Spades => {js|\u2660|js}
  | Hearts => {js|\u2665|js}
  | Diamonds => {js|\u2666|js}
  | Clubs => {js|\u2663|js}
  | NoSuit => "!"
  }
};


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

let cardToString(playingCard) = {
  rankToString(fst(playingCard)) ++ suitToString(snd(playingCard))
};

let cardToValue(gameDenomination, playingCard) = {
  let suitToValue(playingCardSuit, gameDenomination) = {
    switch (playingCardSuit, gameDenomination) {
    | (Spades, _) => 42
    | (Hearts, SUIT(Hearts)) => 56
    | (Hearts, _) => 28
    | (Diamonds, SUIT(Diamonds)) => 56
    | (Diamonds, _) => 14
    | (Clubs, SUIT(Clubs)) => 56
    | (Clubs, _) => 0
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
  rankToValue(fst(playingCard)) + suitToValue(snd(playingCard), gameDenomination)
};

let compareCardValue= (denom, cardA, cardB) => {
  cardToValue(denom, cardA) > cardToValue(denom, cardB) ? -1 : 1
};


/* Fisher–Yates shuffle */
let shuffleArrayInPlace = (arr, seed) => {
  Random.init(seed);
  for (n in Array.length(arr) - 1 downto 1) {
    let k = Random.int(n + 1);
    let temp = arr[n];
    arr[n] = arr[k];
    arr[k] = temp;
  };
};

let setOfCardsDealerPlus1 = Array.make(13, (NoRank, NoSuit));
let setOfCardsDealerPlus2 = Array.make(13, (NoRank, NoSuit));
let setOfCardsDealerPlus3 = Array.make(13, (NoRank, NoSuit));
let setOfCardsDealerPlus0 = Array.make(13, (NoRank, NoSuit));


let deal = () => {
  for (i in 0 to 51) {
    if (i mod 4 == 0){
      setOfCardsDealerPlus1[i/4] = arrayOfCards[i];
    } else if (i mod 4 == 1) {
      setOfCardsDealerPlus2[i/4] = arrayOfCards[i];
    } else if (i mod 4 == 2) {
      setOfCardsDealerPlus3[i/4] = arrayOfCards[i];
    } else if (i mod 4 == 3){
      setOfCardsDealerPlus0[i/4] = arrayOfCards[i];
    } else {
      Js.log("should be unreachable");
    }
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

// used on prev console only project card 06
// let impureGetRandomSeedUpTo60k = () => {
//   let now = Js.Date.make();
//   int_of_float((Js.Date.getSeconds(now) *. 1000.0) +. Js.Date.getMilliseconds(now));
// };
