// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Shuffle$ReactHooksTemplate = require("./Shuffle.bs.js");

function s2e(prim) {
  return prim;
}

var initialState_dealerPlus1 = [];

var initialState_dealerPlus2 = [];

var initialState_dealerPlus3 = [];

var initialState_dealerPlus0 = [];

var initialState = {
  dealerPlus1: initialState_dealerPlus1,
  dealerPlus2: initialState_dealerPlus2,
  dealerPlus3: initialState_dealerPlus3,
  dealerPlus0: initialState_dealerPlus0,
  plus1IsFlipped: true,
  plus2IsFlipped: true,
  plus3IsFlipped: true,
  plus0IsFlipped: true
};

function reducer(state, action) {
  if (typeof action === "number") {
    if (action !== 0) {
      var fourSetsOfCards = Shuffle$ReactHooksTemplate.impureShuffleOfPack(undefined);
      console.log(fourSetsOfCards);
      return fourSetsOfCards;
    }
    console.log("Action1 trace");
    return state;
  }
  console.log("Flip from " + action[0]);
  return {
          dealerPlus1: state.dealerPlus1,
          dealerPlus2: state.dealerPlus2,
          dealerPlus3: state.dealerPlus3,
          dealerPlus0: state.dealerPlus0,
          plus1IsFlipped: !state.plus1IsFlipped,
          plus2IsFlipped: !state.plus2IsFlipped,
          plus3IsFlipped: !state.plus3IsFlipped,
          plus0IsFlipped: !state.plus0IsFlipped
        };
}

exports.s2e = s2e;
exports.initialState = initialState;
exports.reducer = reducer;
/* Shuffle-ReactHooksTemplate Not a pure module */
