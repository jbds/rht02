open Ute;
let impureShuffleOfPack = () =>
{
  /* impure! */
  let seed = impureGetRandomSeedUpTo60k();
  /* mutation! */
  let () = shuffleArrayInPlace(arrayOfCards, seed);
  /* show shuffled pack of cards, dependent upon seed value above*/
  /* Js.log(Array.map(cardToString, arrayOfCards)); */
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
  Js.log(Array.map(cardToString, setOfCardsDealerPlus1)); 
  Js.log(Array.map(cardToString, setOfCardsDealerPlus2)); 
  Js.log(Array.map(cardToString, setOfCardsDealerPlus3)); 
  Js.log(Array.map(cardToString, setOfCardsDealerPlus0)); 

  // used on previous console project card06
  // recursive function requires initial suitAsString=""
  // Js.log(displaySetOfCardsOnConsole(setOfCardsDealerPlus1, ""));
  // Js.log(displaySetOfCardsOnConsole(setOfCardsDealerPlus2, ""));
  // Js.log(displaySetOfCardsOnConsole(setOfCardsDealerPlus3, ""));
  //Js.log(displaySetOfCardsOnConsole(setOfCardsDealerPlus0, ""));
};


