// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function s2e(prim) {
  return prim;
}

function Sidebar1(Props) {
  var dispatch = Props.dispatch;
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
                    color: "#404040",
                    fontSize: "2.5vh",
                    marginTop: "1vh"
                  }
                }, "Dealer: "), React.createElement("select", {
                  style: {
                    color: "#404040",
                    fontSize: "2.5vh",
                    marginTop: "1vh"
                  },
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
                    color: "#404040",
                    fontSize: "2.5vh",
                    marginTop: "1vh"
                  },
                  onClick: (function (_e) {
                      return Curry._1(dispatch, /* Deal */4);
                    })
                }, "Deal"));
}

var make = Sidebar1;

exports.s2e = s2e;
exports.make = make;
/* react Not a pure module */
