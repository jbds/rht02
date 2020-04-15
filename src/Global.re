// state and reducer are used by the top level component App

type state = {
  dealerPlus1: array((int, string)),
  dealerPlus2: array((int, string)),
  dealerPlus3: array((int, string)),
  dealerPlus0: array((int, string)),
  plus1IsFlipped: bool,
  plus2IsFlipped: bool,
  plus3IsFlipped: bool,
  plus0IsFlipped: bool,
};

type location =
  | North
  | East
  | South
  | West;

type action =
  | Action1
  | Action2
  | Flip (location);

// utility
let s2e = React.string;

// force to type Shuffle.state
let initialState: Shuffle.state = {
  dealerPlus1: [||], 
  dealerPlus2: [||], 
  dealerPlus3: [||], 
  dealerPlus0: [||],
  plus1IsFlipped: true,
  plus2IsFlipped: true,
  plus3IsFlipped: true,
  plus0IsFlipped: true,
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
            plus0IsFlipped: !state.plus0IsFlipped, 
            plus1IsFlipped: !state.plus1IsFlipped, 
            plus2IsFlipped: !state.plus2IsFlipped,
            plus3IsFlipped: !state.plus3IsFlipped,
          }
        | South =>
          {
            ...state, 
            plus0IsFlipped: !state.plus0IsFlipped, 
            plus1IsFlipped: !state.plus1IsFlipped, 
            plus2IsFlipped: !state.plus2IsFlipped,
            plus3IsFlipped: !state.plus3IsFlipped,
          }
        | East =>
          {
            ...state, 
            plus0IsFlipped: !state.plus0IsFlipped, 
            plus1IsFlipped: !state.plus1IsFlipped, 
            plus2IsFlipped: !state.plus2IsFlipped,
            plus3IsFlipped: !state.plus3IsFlipped,
          }
        | West =>
          {
            ...state, 
            plus0IsFlipped: !state.plus0IsFlipped, 
            plus1IsFlipped: !state.plus1IsFlipped, 
            plus2IsFlipped: !state.plus2IsFlipped,
            plus3IsFlipped: !state.plus3IsFlipped,
          }
        }
      }
    }
  };
