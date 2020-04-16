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

type location =
  | North
  | East
  | South
  | West
;

type action =
  | Action1
  | Action2
  | Flip (location)
  | HideAllCards
  | ShowAllCards
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
};

let reducer = (state, action) =>
  {
    switch action {
      | Action1 => {
        Js.log("Action1 trace")
        state;
      }
      | Action2 => {
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
    }
  };
