// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");

function s2e(prim) {
  return prim;
}

function FlipButton(Props) {
  Props.dispatch;
  var $$location = Props.location;
  return React.createElement("div", undefined, React.createElement("button", {
                  style: {
                    color: "Black",
                    fontSize: "2vh",
                    marginTop: "1vh",
                    marginLeft: "-3vh"
                  },
                  onClick: (function (_e) {
                      console.log("Flip action trace location: " + $$location);
                      
                    })
                }, "Flip"));
}

var make = FlipButton;

exports.s2e = s2e;
exports.make = make;
/* react Not a pure module */
