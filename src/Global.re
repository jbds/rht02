// state and reducer are used by the top level component App

// this is defined in Shuffle module to avoid a cyclic dependency
// type state = {
//   dealerPlus1: array((int, string)),
//   dealerPlus2: array((int, string)),
//   dealerPlus3: array((int, string)),
//   dealerPlus0: array((int, string)),
//   plus1IsFlipped: bool,
//   plus2IsFlipped: bool,
//   plus3IsFlipped: bool,
//   plus0IsFlipped: bool,
// };

// this is defined in Shuffle module to avoid a cyclic dependency
// type location =
//   | North
//   | East
//   | South
//   | West
// ;

type action =
  | Action1
  | Shuffle
  | Flip (Ute.location)
  | HideAllCards
  | ShowAllCards
  | DealerChange (string)
  | Deal 
;

// utility
let s2e = React.string;

// force to type Shuffle.state
let initialState: Shuffle.state = {
  cardsNorth: [||], 
  cardsEast: [||], 
  cardsSouth: [||], 
  cardsWest: [||],
  northIsFlipped: true,
  eastIsFlipped: true,
  southIsFlipped: true,
  westIsFlipped: true,
  dealer: None,
  cardsDealedCount: 0,
};

// could probably be refactored to something simpler, but works ok
let dealCardByModulo = (k: int, state: Shuffle.state) => {
  if ((state.cardsDealedCount mod 4) == k ) {
    let myArray = state.cardsNorth;
    // destructure and then force Hand
    let (i,(s, _)) = myArray[state.cardsDealedCount/4];
    myArray[state.cardsDealedCount/4] = (i,(s, Hand));
    // at this point myArray should be the updated version of cardsNorth
    let sc = state.cardsDealedCount == 51 ? -1 : state.cardsDealedCount;
    Js.log("cardsNorth sc=" ++ string_of_int(sc));
    {...state, cardsNorth: myArray, cardsDealedCount: sc + 1};
  } else if ((state.cardsDealedCount mod 4) == (k + 1)) {
    let myArray = state.cardsEast;
    let (i,(s, _)) = myArray[state.cardsDealedCount/4];
    myArray[state.cardsDealedCount/4] = (i,(s, Hand));
    let sc = state.cardsDealedCount;
    {...state, cardsEast: myArray, cardsDealedCount: sc + 1};
  } else if ((state.cardsDealedCount mod 4) == (k + 2)) {
    let myArray = state.cardsSouth;
    let (i,(s, _)) = myArray[state.cardsDealedCount/4];
    myArray[state.cardsDealedCount/4] = (i,(s, Hand));
    let sc = state.cardsDealedCount;
    {...state, cardsSouth: myArray, cardsDealedCount: sc + 1};
  } else if ((state.cardsDealedCount mod 4) == (k + 3)) {
    let myArray = state.cardsWest;
    let (i,(s, _)) = myArray[state.cardsDealedCount/4];
    myArray[state.cardsDealedCount/4] = (i,(s, Hand));
    let sc = state.cardsDealedCount;
    {...state, cardsWest: myArray, cardsDealedCount: sc + 1};
  } else if ((state.cardsDealedCount mod 4) == (k + 4)) {
    let myArray = state.cardsNorth;
    let (i,(s, _)) = myArray[state.cardsDealedCount/4];
    myArray[state.cardsDealedCount/4] = (i,(s, Hand));
    let sc = state.cardsDealedCount;
    {...state, cardsNorth: myArray, cardsDealedCount: sc + 1};
  } else if ((state.cardsDealedCount mod 4) == (k + 5)) {
    let myArray = state.cardsEast;
    let (i,(s, _)) = myArray[state.cardsDealedCount/4];
    myArray[state.cardsDealedCount/4] = (i,(s, Hand));
    let sc = state.cardsDealedCount;
    {...state, cardsEast: myArray, cardsDealedCount: sc + 1};
  } else if ((state.cardsDealedCount mod 4) == (k + 6)) {
    let myArray = state.cardsSouth;
    let (i,(s, _)) = myArray[state.cardsDealedCount/4];
    myArray[state.cardsDealedCount/4] = (i,(s, Hand));
    let sc = state.cardsDealedCount;
    {...state, cardsSouth: myArray, cardsDealedCount: sc + 1};
  } else {
    Js.log("should be unreachable k=" ++ string_of_int(k));
    {state}
  }
};

let reducer = (state, action) =>
  {
    switch action {
      | Action1 => {
        Js.log("Action1 trace")
        state;
      }
      | Shuffle => {
          let fourSetsOfCards = Shuffle.impureShuffleOfPack();
          //Js.log(fourSetsOfCards);
          // return the merged state
          fourSetsOfCards;
      }
      | Flip (loc) => {
        Js.log("Flip from some location");
        switch (loc) {
        | North => 
          {
            ...state, 
            northIsFlipped: !state.northIsFlipped, 
          }
        | South =>
          {
            ...state, 
            southIsFlipped: !state.southIsFlipped,
          }
        | East =>
          {
            ...state, 
            eastIsFlipped: !state.eastIsFlipped, 
          }
        | West =>
          {
            ...state, 
            westIsFlipped: !state.westIsFlipped,
          }
        }
      }
      | HideAllCards => {
          {
            ...state, 
            northIsFlipped: true,
            eastIsFlipped: true,
            southIsFlipped: true,
            westIsFlipped: true,
          }
      }
      | ShowAllCards => {
          {
            ...state, 
            northIsFlipped: false,
            eastIsFlipped: false,
            southIsFlipped: false,
            westIsFlipped: false,
          }
      }
      | DealerChange (shortLoc) => {
        //Js.log("DealerChange to " ++ shortLoc);
        switch (shortLoc) {
          | "N" => {...state, dealer: Some(North)}
          | "E" => {...state, dealer: Some(East)}
          | "S" => {...state, dealer: Some(South)}
          | "W" => {...state, dealer: Some(West)}
          | _ => {...state, dealer: None}
        }
      }
      | Deal => {
        switch (state.dealer) {
          | None => {
            state
          }
          | Some(North) => {
            //Js.log("Deal to E"); 
            dealCardByModulo(-1, state)
          }
          | Some(East) => {
            //Js.log("Deal to S"); 
            dealCardByModulo(-2, state)
          }
          | Some(South) => {
            //Js.log("Deal to W"); 
            dealCardByModulo(-3, state)
            }
          | Some(West) => {
            //Js.log("Deal to N"); 
            dealCardByModulo(0, state)
            }
        }
      }
    }
  };
