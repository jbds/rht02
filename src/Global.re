type cardCollection = {
  dealerPlus1: array((int, string)),
  dealerPlus2: array((int, string)),
  dealerPlus3: array((int, string)),
  dealerPlus0: array((int, string)),
};

type state = {
  cardsDealerPlus0: list((int, string))
};

type action =
  | AddItem
  | LogToConsole;

let reducer = (state, action) =>
  {
    switch action {
      | AddItem => {cardsDealerPlus0: [
        (-8, "2S"),
        (-7, "TC"),
        (-6, "AC"),
        (-5, "3C"),
        (-4, "KD"), 
        (-3, "2S"),
        (-2, "4H"),
        (-1, "TS"),
        (0, "2D"),
        (1, "3S"),
        (2, "5C"),
        (3, "QH"),
        (4, "9S"),
        ...state.cardsDealerPlus0, ]}
      | LogToConsole => {
          let fourSetsOfCards = Shuffle.impureShuffleOfPack();
          Js.log(fourSetsOfCards);
          // return the current state unchanged
          state;
      }
    }
  };
