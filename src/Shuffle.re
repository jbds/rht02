open Ute;

type state = {
  cardsNorth: array((int, (string, lifecycle))),
  cardsEast: array((int, (string, lifecycle))),
  cardsSouth: array((int, (string, lifecycle))),
  cardsWest: array((int, (string, lifecycle))),
  northIsFlipped: bool,
  eastIsFlipped: bool,
  southIsFlipped: bool,
  westIsFlipped: bool,
};

let impureShuffleOfPack = () =>
{
  /* impure! */
  let seed = impureGetRandomSeedUpTo60k();
  //Js.log(Array.map(cardToString,arrayOfCards));
  /* mutation! */
  // skip if we want repeatable set of cards
  //let () = shuffleArrayInPlace(arrayOfCards, seed);
  /* show shuffled pack of cards, dependent upon seed value above*/
  Js.log(Array.map(cardToString, arrayOfCards));
  /* we have to know whether to deal the cards to N,E,S or W first */
  /* impure - requires user input  of  dealer N, E, S or W */
  // Set to West for testing
  let loc = West;
  let () = allocateShuffledToLocation(loc);
  let denomination = NO_TRUMPS; /*SUIT(Clubs);*/
  /* Js.log(compareCardValue((Ace, Hearts),(King, Spades), denomination)); */
  /* mutation */
  /* curried function of 3 params returns func of 2 params */
  let () = Array.sort(compareCardValue(denomination), cardsNorth);
  let () = Array.sort(compareCardValue(denomination), cardsEast);
  let () = Array.sort(compareCardValue(denomination), cardsSouth);
  let () = Array.sort(compareCardValue(denomination), cardsWest);
  // js array values are not helpful!
  //same here - cardToValue expects 2 params, we give it one and it returns
  // a function expecting a single tuple param
  //Js.log(Array.map(cardToValue(denomination), setOfCardsDealerPlus1));

  let cardsNorthAsString = Array.map(cardToString, cardsNorth);
  let cardsEastAsString = Array.map(cardToString, cardsEast);
  let cardsSouthAsString = Array.map(cardToString, cardsSouth);
  let cardsWestAsString = Array.map(cardToString, cardsWest);

  let cardsNorthWithIndex = Array.mapi((k, v) => (k, v), cardsNorthAsString);
  let cardsEastWithIndex = Array.mapi((k, v) => (k, v), cardsEastAsString);
  let cardsSouthWithIndex = Array.mapi((k, v) => (k, v), cardsSouthAsString);
  let cardsWestWithIndex = Array.mapi((k, v) => (k, v), cardsWestAsString);


  //Js.log(setOfCardsWithIndexDealerPlus1);

  // return the four sets of cards as one record aka object
  {
    cardsNorth: cardsNorthWithIndex, 
    cardsEast: cardsEastWithIndex, 
    cardsSouth: cardsSouthWithIndex, 
    cardsWest: cardsWestWithIndex, 
    northIsFlipped: false,
    eastIsFlipped: true,
    southIsFlipped: true,
    westIsFlipped: true,
  };
};


