// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function s2e(prim) {
  return prim;
}

function Sidebar3(Props) {
  var dispatch = Props.dispatch;
  return React.createElement("div", undefined, React.createElement("button", {
                  style: {
                    color: "Grey",
                    fontSize: "2vh",
                    marginTop: "1vh"
                  },
                  onClick: (function (_e) {
                      return Curry._1(dispatch, /* HideAllCards */2);
                    })
                }, "Hide All Cards"), React.createElement("br", undefined), React.createElement("button", {
                  style: {
                    color: "Grey",
                    fontSize: "2vh",
                    marginTop: "1vh"
                  },
                  onClick: (function (_e) {
                      return Curry._1(dispatch, /* ShowAllCards */3);
                    })
                }, "Show All Cards"));
}

var make = Sidebar3;

exports.s2e = s2e;
exports.make = make;
/* react Not a pure module */