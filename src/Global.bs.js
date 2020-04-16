// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Shuffle$ReactHooksTemplate = require("./Shuffle.bs.js");

function s2e(prim) {
  return prim;
}

var initialState_cardsNorth = [];

var initialState_cardsEast = [];

var initialState_cardsSouth = [];

var initialState_cardsWest = [];

var initialState = {
  cardsNorth: initialState_cardsNorth,
  cardsEast: initialState_cardsEast,
  cardsSouth: initialState_cardsSouth,
  cardsWest: initialState_cardsWest,
  northIsFlipped: true,
  eastIsFlipped: true,
  southIsFlipped: true,
  westIsFlipped: true
};

function reducer(state, action) {
  if (typeof action === "number") {
    switch (action) {
      case /* Action1 */0 :
          console.log("Action1 trace");
          return state;
      case /* Action2 */1 :
          var fourSetsOfCards = Shuffle$ReactHooksTemplate.impureShuffleOfPack(undefined);
          console.log(fourSetsOfCards);
          return fourSetsOfCards;
      case /* HideAllCards */2 :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: true,
                  eastIsFlipped: true,
                  southIsFlipped: true,
                  westIsFlipped: true
                };
      case /* ShowAllCards */3 :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: false,
                  eastIsFlipped: false,
                  southIsFlipped: false,
                  westIsFlipped: false
                };
      
    }
  } else {
    console.log("Flip from some location");
    switch (action[0]) {
      case /* North */0 :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: !state.northIsFlipped,
                  eastIsFlipped: state.eastIsFlipped,
                  southIsFlipped: state.southIsFlipped,
                  westIsFlipped: state.westIsFlipped
                };
      case /* East */1 :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: state.northIsFlipped,
                  eastIsFlipped: !state.eastIsFlipped,
                  southIsFlipped: state.southIsFlipped,
                  westIsFlipped: state.westIsFlipped
                };
      case /* South */2 :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: state.northIsFlipped,
                  eastIsFlipped: state.eastIsFlipped,
                  southIsFlipped: !state.southIsFlipped,
                  westIsFlipped: state.westIsFlipped
                };
      case /* West */3 :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: state.northIsFlipped,
                  eastIsFlipped: state.eastIsFlipped,
                  southIsFlipped: state.southIsFlipped,
                  westIsFlipped: !state.westIsFlipped
                };
      
    }
  }
}

exports.s2e = s2e;
exports.initialState = initialState;
exports.reducer = reducer;
/* Shuffle-ReactHooksTemplate Not a pure module */
