// state and reducer are used by the top level component App

type state = {
  dealerPlus1: array((int, string)),
  dealerPlus2: array((int, string)),
  dealerPlus3: array((int, string)),
  dealerPlus0: array((int, string)),
};

type action =
  | Action1
  | LogToConsole;

// utility
let s2e = React.string;

// force to type Shuffle.state
let initialState: Shuffle.state = {
  dealerPlus1: [||], 
  dealerPlus2: [||], 
  dealerPlus3: [||], 
  dealerPlus0: [||]
};

let reducer = (state, action) =>
  {
    switch action {
      | Action1 => {
        Js.log("Action1 trace")
        state;
      }
      | LogToConsole => {
          let fourSetsOfCards = Shuffle.impureShuffleOfPack();
          Js.log(fourSetsOfCards);
          // return the merged state
          fourSetsOfCards;
      }
    }
  };
