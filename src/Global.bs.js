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
  westIsFlipped: true,
  dealer: undefined
};

function reducer(state, action) {
  if (typeof action === "number") {
    switch (action) {
      case /* Action1 */0 :
          console.log("Action1 trace");
          return state;
      case /* Shuffle */1 :
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
                  westIsFlipped: true,
                  dealer: state.dealer
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
                  westIsFlipped: false,
                  dealer: state.dealer
                };
      case /* Deal */4 :
          console.log("Deal");
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: state.northIsFlipped,
                  eastIsFlipped: state.eastIsFlipped,
                  southIsFlipped: state.southIsFlipped,
                  westIsFlipped: state.westIsFlipped,
                  dealer: undefined
                };
      
    }
  } else if (action.tag) {
    switch (action[0]) {
      case "E" :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: state.northIsFlipped,
                  eastIsFlipped: state.eastIsFlipped,
                  southIsFlipped: state.southIsFlipped,
                  westIsFlipped: state.westIsFlipped,
                  dealer: /* East */1
                };
      case "N" :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: state.northIsFlipped,
                  eastIsFlipped: state.eastIsFlipped,
                  southIsFlipped: state.southIsFlipped,
                  westIsFlipped: state.westIsFlipped,
                  dealer: /* North */0
                };
      case "S" :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: state.northIsFlipped,
                  eastIsFlipped: state.eastIsFlipped,
                  southIsFlipped: state.southIsFlipped,
                  westIsFlipped: state.westIsFlipped,
                  dealer: /* South */2
                };
      case "W" :
          return {
                  cardsNorth: state.cardsNorth,
                  cardsEast: state.cardsEast,
                  cardsSouth: state.cardsSouth,
                  cardsWest: state.cardsWest,
                  northIsFlipped: state.northIsFlipped,
                  eastIsFlipped: state.eastIsFlipped,
                  southIsFlipped: state.southIsFlipped,
                  westIsFlipped: state.westIsFlipped,
                  dealer: /* West */3
                };
      default:
        return {
                cardsNorth: state.cardsNorth,
                cardsEast: state.cardsEast,
                cardsSouth: state.cardsSouth,
                cardsWest: state.cardsWest,
                northIsFlipped: state.northIsFlipped,
                eastIsFlipped: state.eastIsFlipped,
                southIsFlipped: state.southIsFlipped,
                westIsFlipped: state.westIsFlipped,
                dealer: undefined
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
                  westIsFlipped: state.westIsFlipped,
                  dealer: state.dealer
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
                  westIsFlipped: state.westIsFlipped,
                  dealer: state.dealer
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
                  westIsFlipped: state.westIsFlipped,
                  dealer: state.dealer
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
                  westIsFlipped: !state.westIsFlipped,
                  dealer: state.dealer
                };
      
    }
  }
}

exports.s2e = s2e;
exports.initialState = initialState;
exports.reducer = reducer;
/* Shuffle-ReactHooksTemplate Not a pure module */
