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
          Js.log(fourSetsOfCards);
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
        Js.log("Deal");
        // TO DO
        {
          ...state,
          dealer: None,
        }
      }
    }
  };
