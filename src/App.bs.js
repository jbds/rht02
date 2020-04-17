// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var Global$ReactHooksTemplate = require("./Global.bs.js");
var Sidebar1$ReactHooksTemplate = require("./Sidebar1.bs.js");
var Sidebar3$ReactHooksTemplate = require("./Sidebar3.bs.js");
var FlipButton$ReactHooksTemplate = require("./FlipButton.bs.js");
var PlayingCardRotatable$ReactHooksTemplate = require("./PlayingCardRotatable.bs.js");

function App(Props) {
  var match = React.useReducer(Global$ReactHooksTemplate.reducer, Global$ReactHooksTemplate.initialState);
  var dispatch = match[1];
  var state = match[0];
  return React.createElement("div", {
              id: "main"
            }, React.createElement("div", undefined, React.createElement(PlayingCardRotatable$ReactHooksTemplate.make, {
                      cardIndex: 0,
                      filePath: "./images/KS.svg",
                      leftVw: 50.0,
                      topVh: 75.0,
                      parentElementWidthPx: window.innerWidth,
                      parentElementHeightPx: window.innerHeight,
                      isFlipSide: state.southIsFlipped,
                      lifecycle: /* Dealer */0,
                      key: String(0)
                    })), React.createElement("div", {
                  style: {
                    left: "50%",
                    position: "absolute",
                    top: "90%"
                  }
                }, React.createElement(FlipButton$ReactHooksTemplate.make, {
                      dispatch: dispatch,
                      location: /* South */2
                    })), React.createElement("div", undefined, React.createElement(PlayingCardRotatable$ReactHooksTemplate.make, {
                      cardIndex: 0,
                      filePath: "./images/QH.svg",
                      leftVw: 25.0,
                      topVh: 50.0,
                      parentElementWidthPx: window.innerWidth,
                      parentElementHeightPx: window.innerHeight,
                      isFlipSide: state.westIsFlipped,
                      lifecycle: /* Dealer */0,
                      key: String(0)
                    })), React.createElement("div", {
                  style: {
                    left: "25%",
                    position: "absolute",
                    top: "65%"
                  }
                }, React.createElement(FlipButton$ReactHooksTemplate.make, {
                      dispatch: dispatch,
                      location: /* West */3
                    })), React.createElement("div", undefined, $$Array.map((function (param) {
                        var match = param[1];
                        var index = param[0];
                        return React.createElement(PlayingCardRotatable$ReactHooksTemplate.make, {
                                    cardIndex: index,
                                    filePath: "./images/" + (match[0] + ".svg"),
                                    leftVw: 50.0,
                                    topVh: 25.0,
                                    parentElementWidthPx: window.innerWidth,
                                    parentElementHeightPx: window.innerHeight,
                                    isFlipSide: state.northIsFlipped,
                                    lifecycle: match[1],
                                    key: String(index)
                                  });
                      }), state.cardsNorth)), React.createElement("div", {
                  style: {
                    left: "50%",
                    position: "absolute",
                    top: "40%"
                  }
                }, React.createElement(FlipButton$ReactHooksTemplate.make, {
                      dispatch: dispatch,
                      location: /* North */0
                    })), React.createElement("div", undefined, React.createElement(PlayingCardRotatable$ReactHooksTemplate.make, {
                      cardIndex: 0,
                      filePath: "./images/JD.svg",
                      leftVw: 75.0,
                      topVh: 50.0,
                      parentElementWidthPx: window.innerWidth,
                      parentElementHeightPx: window.innerHeight,
                      isFlipSide: state.eastIsFlipped,
                      lifecycle: /* Dealer */0,
                      key: String(0)
                    })), React.createElement("div", {
                  style: {
                    left: "75%",
                    position: "absolute",
                    top: "65%"
                  }
                }, React.createElement(FlipButton$ReactHooksTemplate.make, {
                      dispatch: dispatch,
                      location: /* East */1
                    })), React.createElement("div", {
                  id: "sidebar1"
                }, React.createElement(Sidebar1$ReactHooksTemplate.make, {
                      dispatch: dispatch
                    })), React.createElement("div", {
                  id: "sidebar2"
                }), React.createElement("div", {
                  id: "sidebar3"
                }, React.createElement(Sidebar3$ReactHooksTemplate.make, {
                      dispatch: dispatch
                    })));
}

var make = App;

exports.make = make;
/* react Not a pure module */
