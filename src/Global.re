type state = {
  dealerPlus1: array((int, string)),
  dealerPlus2: array((int, string)),
  dealerPlus3: array((int, string)),
  dealerPlus0: array((int, string)),
};

type action =
  | AddItem
  | LogToConsole;

let reducer = (state, action) =>
  {
    switch action {
      | AddItem => {
        state }
      | LogToConsole => {
          let fourSetsOfCards = Shuffle.impureShuffleOfPack();
          Js.log(fourSetsOfCards);
          // return the current state unchanged
          state;
      }
    }
  };
