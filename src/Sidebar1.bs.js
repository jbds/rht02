// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_int32 = require("bs-platform/lib/js/caml_int32.js");

function s2e(prim) {
  return prim;
}

function Sidebar1(Props) {
  var dispatch = Props.dispatch;
  var state = Props.state;
  var isNotShuffled = state.cardsNorth.length === 0;
  return React.createElement("div", undefined, React.createElement("button", {
                  style: {
                    color: "#404040",
                    fontSize: "2.5vh",
                    marginTop: "1vh"
                  },
                  onClick: (function (_e) {
                      return Curry._1(dispatch, /* Shuffle */1);
                    })
                }, "Shuffle"), React.createElement("br", undefined), React.createElement("label", {
                  style: {
                    color: isNotShuffled ? "#C0C0C0" : "#404040",
                    fontSize: "2.5vh",
                    marginTop: "1vh"
                  }
                }, "Dealer: "), React.createElement("select", {
                  style: {
                    color: isNotShuffled ? "#C0C0C0" : "#404040",
                    fontSize: "2.5vh",
                    marginTop: "1vh"
                  },
                  disabled: isNotShuffled,
                  onChange: (function (e) {
                      return Curry._1(dispatch, /* DealerChange */Block.__(1, [e.target.value]));
                    })
                }, React.createElement("option", {
                      value: "?"
                    }, "?"), React.createElement("option", {
                      value: "N"
                    }, "N"), React.createElement("option", {
                      value: "E"
                    }, "E"), React.createElement("option", {
                      value: "S"
                    }, "S"), React.createElement("option", {
                      value: "W"
                    }, "W")), React.createElement("br", undefined), React.createElement("button", {
                  style: {
                    color: state.dealer === undefined ? "#C0C0C0" : "#404040",
                    fontSize: "2.5vh",
                    marginTop: "1vh"
                  },
                  disabled: state.dealer === undefined,
                  onClick: (function (_e) {
                      for(var x = 0; x <= 51; ++x){
                        setTimeout((function (param) {
                                return Curry._1(dispatch, /* Deal */4);
                              }), Caml_int32.imul(60, x));
                      }
                      
                    })
                }, "Deal"), React.createElement("br", undefined));
}

var make = Sidebar1;

exports.s2e = s2e;
exports.make = make;
/* react Not a pure module */
