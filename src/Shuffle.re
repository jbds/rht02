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
  dealer: option(location),
  shuffleCount: int,
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
  // TO DO - the sorting of the hands is NOT a function of the denomination, but NO_TRUMPS works
  let denomination = NO_TRUMPS; /*SUIT(Clubs);*/
  /* mutation */
  /* curried function of 3 params returns func of 2 params */
  let () = Array.sort(compareCardValue(denomination), cardsNorth);
  let () = Array.sort(compareCardValue(denomination), cardsEast);
  let () = Array.sort(compareCardValue(denomination), cardsSouth);
  let () = Array.sort(compareCardValue(denomination), cardsWest);
  // At this point the four hands are sorted in the correct order S, H, C, D
  // js array values are not helpful!
  //same here - cardToValue expects 2 params, we give it one and it returns
  // a function expecting a single tuple param
  //Js.log(Array.map(cardToValue(denomination), cardsNorth));

  let cardsNorthAsString = Array.map(cardToString, cardsNorth);
  let cardsEastAsString = Array.map(cardToString, cardsEast);
  let cardsSouthAsString = Array.map(cardToString, cardsSouth);
  let cardsWestAsString = Array.map(cardToString, cardsWest);
  // Now the cards are identified by their filename and lifecycle eg [|("AS", Dealer), ....|]

  let cardsNorthWithIndex = Array.mapi((k, v) => (k, v), cardsNorthAsString);
  let cardsEastWithIndex = Array.mapi((k, v) => (k, v), cardsEastAsString);
  let cardsSouthWithIndex = Array.mapi((k, v) => (k, v), cardsSouthAsString);
  let cardsWestWithIndex = Array.mapi((k, v) => (k, v), cardsWestAsString);
  // Add an index to use when rendering the card [| 0, ("AS", Dealer), 1, (), 


  //Js.log(setOfCardsWithIndexDealerPlus1);

  // return the four sets of cards as one record aka object
  // we do not need to know who is dealer when shuffling the pack
  {
    cardsNorth: cardsNorthWithIndex, 
    cardsEast: cardsEastWithIndex, 
    cardsSouth: cardsSouthWithIndex, 
    cardsWest: cardsWestWithIndex, 
    northIsFlipped: false,
    eastIsFlipped: false,
    southIsFlipped: false,
    westIsFlipped: false,
    dealer: None,
    shuffleCount: 0
  };
};


