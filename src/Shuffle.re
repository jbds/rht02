open Ute;

type state = {
  cardsNorth: array((int, string)),
  cardsEast: array((int, string)),
  cardsSouth: array((int, string)),
  cardsWest: array((int, string)),
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
  let () = shuffleArrayInPlace(arrayOfCards, seed);
  /* show shuffled pack of cards, dependent upon seed value above*/
  Js.log(Array.map(cardToString, arrayOfCards));
  /* deal to DealerPlus1, DealerPlus2, DealerPlus3, DealerPlus0 */
  let () = deal();
  /* Js.log(Array.map(cardToString, setOfCardsDealerPlus1)); 
  Js.log(Array.map(cardToString, setOfCardsDealerPlus2));
  Js.log(Array.map(cardToString, setOfCardsDealerPlus3));
  Js.log(Array.map(cardToString, setOfCardsDealerPlus0));  */
  /* Js.log(Array.map(cardToValue, setOfCardsDealerPlus1)); */
  let denomination = NO_TRUMPS; /*SUIT(Clubs);*/
  /* Js.log(compareCardValue((Ace, Hearts),(King, Spades), denomination)); */
  /* mutation */
  /* curried function of 3 params returns func of 2 params */
  let () = Array.sort(compareCardValue(denomination), setOfCardsDealerPlus1);
  let () = Array.sort(compareCardValue(denomination), setOfCardsDealerPlus2);
  let () = Array.sort(compareCardValue(denomination), setOfCardsDealerPlus3);
  let () = Array.sort(compareCardValue(denomination), setOfCardsDealerPlus0);
  // js array values are not helpful!
  //same here - cardToValue expects 2 params, we give it one and it returns
  // a function expecting a single tuple param
  //Js.log(Array.map(cardToValue(denomination), setOfCardsDealerPlus1));
  // to work with filenames this cannot use the unicode symbols
  // Js.log(Array.map(cardToString, setOfCardsDealerPlus1)); 
  // Js.log(Array.map(cardToString, setOfCardsDealerPlus2)); 
  // Js.log(Array.map(cardToString, setOfCardsDealerPlus3)); 
  // Js.log(Array.map(cardToString, setOfCardsDealerPlus0)); 

  let setOfCardsAsStringDealerPlus1 = Array.map(cardToString, setOfCardsDealerPlus1);
  let setOfCardsAsStringDealerPlus2 = Array.map(cardToString, setOfCardsDealerPlus2);
  let setOfCardsAsStringDealerPlus3 = Array.map(cardToString, setOfCardsDealerPlus3);
  let setOfCardsAsStringDealerPlus0 = Array.map(cardToString, setOfCardsDealerPlus0);

  let setOfCardsWithIndexDealerPlus1 = Array.mapi((k, v) => (k, v), setOfCardsAsStringDealerPlus1);
  let setOfCardsWithIndexDealerPlus2 = Array.mapi((k, v) => (k, v), setOfCardsAsStringDealerPlus2);
  let setOfCardsWithIndexDealerPlus3 = Array.mapi((k, v) => (k, v), setOfCardsAsStringDealerPlus3);
  let setOfCardsWithIndexDealerPlus0 = Array.mapi((k, v) => (k, v), setOfCardsAsStringDealerPlus0);


  //Js.log(setOfCardsWithIndexDealerPlus1);

  // return the four sets of cards as one record aka object
  {
    cardsNorth: setOfCardsWithIndexDealerPlus1, 
    cardsEast: setOfCardsWithIndexDealerPlus2, 
    cardsSouth: setOfCardsWithIndexDealerPlus3, 
    cardsWest: setOfCardsWithIndexDealerPlus0, 
    northIsFlipped: true,
    eastIsFlipped: true,
    southIsFlipped: true,
    westIsFlipped: true,
  };
};


